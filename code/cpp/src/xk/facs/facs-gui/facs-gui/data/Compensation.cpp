
// // license___here_h

#include "Compensation.h"

#include "Dataset.h"

#include "FacsanaduProject.h"
#include "ChannelInfo.h"



Compensation::Compensation()
{
}


int Compensation::getSize()
{
 return matrix_.n_cols();
}

void Compensation::updateMatrix(FacsanaduProject* p)
{
 QList<ChannelInfo*> chaninfo = p->getChannelInfo();
 QStringList new_cnames;
 for(ChannelInfo* ci : chaninfo)
 {
  new_cnames.push_back(ci->formatName());
 }
 if(new_cnames != cnames_)
 {
  int n = new_cnames.size();
  QVector_Matrix_R8 new_matrix(n, n);
  new_matrix.fill_diagonal();
  //Copy old values whenever possible
  for(int i=0; i<n; i++)
  {
   for(int j=0; j<n; j++)
   {
    int oldi = cnames_.indexOf(new_cnames.at(i));
    int oldj = cnames_.indexOf(new_cnames.at(j));
    if( (oldi != -1) && (oldj != -1) )
      new_matrix[i][j] = matrix_[oldi](oldj);
   }
  }
  cnames_ = new_cnames;
  matrix_.reset(new_matrix);
  new_matrix.retire();
 }
}

void Compensation::apply(FacsanaduProject* p)
{
 for( Dataset* ds : p->datasets() )
 {
  apply(ds);
 }
 //Q_UNUSED(p)
}

void Compensation::apply(Dataset* ds)
{
 //Q_UNUSED(ds)
 int n = matrix_.n_cols();

 QVector_Matrix_R8* ef = ds->eventsFloat();

 int rows = ef->n_rows();
 //Multiply each event with the unmixing matrix
 //ArrayList<double[]> out=new ArrayList<double[]>(ds.eventsFloat.size());
 QVector_Matrix_R8* comp = new QVector_Matrix_R8(rows, n);
 for(int oi = 1; oi <= rows; ++oi)
 {
  QVector<r8> from_row;
  ds->eventsFloat()->get_row(oi, from_row);
  QVector<r8> to_row;
  matrix_.multiply(from_row, to_row);
  comp->merge_row(to_row, oi);
 }
 ds->set_eventsFloatCompensated(comp);
 ds->set_numCompensated(rows);
}

double Compensation::get(int to, int from)
{
 return matrix_[to][from];
}

void Compensation::set(int to, int from, double v)
{
 matrix_[to][from] = v;
}


