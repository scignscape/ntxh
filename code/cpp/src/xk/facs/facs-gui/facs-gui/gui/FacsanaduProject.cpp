
// // license___here

#include "FacsanaduProject.h"

#include "../data/Dataset.h"

#include "../data/Compensation.h"

#include "facs-bridge/qvector-matrix-r8.h"
//#include "cytolib/MemCytoFrame.hpp"

#include <QMutexLocker>
#include <QDebug>
#include <QFileInfo>

//package facsanadu.gui;


FacsanaduProject::FacsanaduProject()
{
// gateset_ = new GateSet();
// datasets_ = new LinkedList<Dataset*>();
// views_ = new LinkedList<ViewSettings>();
// profchan_ = new LinkedList<ProfChannel>();

// gatingResult_ = new HashMap<Dataset, GatingResult>();

 compensation_ = new Compensation(); //nullptr; // hold off ... new Compensation();
}

GatingResult* FacsanaduProject::getGatingResult(Dataset* ds)
{
 return getCreateGatingResult(ds); //Why a separate method here??
}

GatingResult* FacsanaduProject::getCreateGatingResult(Dataset* ds)
{
//? synchronized (gatingResult)
// {
 QMutexLocker lock(&gatingResult_mutex_);

 GatingResult* gr = gatingResult_.value(ds);

 if(gr == nullptr) 
 {
    // gr = new GatingResult(gateset);
  gatingResult_.insert(ds, gr);
 }

 return gr; // gatingResult->get(ds);
 //}
}

void FacsanaduProject::performGating(LinkedList<Dataset*> listDatasets)
{
 gatingResult_.clear();
 for(Dataset* ds : listDatasets)
 {
  GatingResult* gr = getCreateGatingResult(ds);//new GatingResult();
   // gr->perform(gateset, ds);
  gatingResult_.insert(ds, gr);
 }
}


void FacsanaduProject::addDataset(QFile& path) // throws IOException
{
/*
 cytolib::FCS_READ_HEADER_PARAM hp;
 cytolib::FCS_READ_DATA_PARAM dp;
 cytolib::FCS_READ_PARAM rp;
*/

 QFileInfo qfi(path);
 

// test_cyto();

 //
 //

 QString file_name = qfi.absoluteFilePath() + ".txt";

 QVector_Matrix_R8* qvm = new QVector_Matrix_R8;
 qvm->load_from_file(file_name);

 //"/home/nlevisrael/hypergr/pgvm/ar/extra/facs/Live_cells.fcs";

// cytolib::MemCytoFrame mcf(qfi.absoluteFilePath().toStdString(), rp);
// mcf.read_fcs();
// QVector_Matrix_R8* qvm = mcf.data_to_qvmatrix(); 

 r8 test = (*qvm)[2][3];
 qDebug() << "R: " << qvm->n_rows();
 qDebug() << "C: " << qvm->n_cols();

 qDebug() << "T: " << test;
 
 qDebug() << "OK ...";

 Dataset* ds = new Dataset(qvm);

 addDataset(ds);
 

// Q_UNUSED(path)
 /*
 if(FCSFile::isFCSfile(path))
 {
  //Assume it is an FCS file
  addDataset(FCSFile::load(path));
 }
 else if(CopasIO.isCopasFile(path))
 {
  //Assume COPAS file
  addDataset(CopasIO::readAll(path));
 }
 else
   ;// throw Facs_IOException("Cannot recognize file");
 */
}

void FacsanaduProject::updateCompensation()
{
 //? compensation_->updateMatrix(this);
 //? compensation_->apply(this);
}


void FacsanaduProject::addDataset(Dataset* ds)
{
  //? ds->computeProfChannel(this, nullptr);
 
 datasets_.append(ds);
 //recalcProfChan();
 updateCompensation();
 //What about gating?
}

int FacsanaduProject::getNumChannels()
{
 if(datasets_.isEmpty())
   return 0;
 else
   return datasets_.first()->getChannelInfo().size();
}


QList<ChannelInfo*> FacsanaduProject::getChannelInfo()
{
 QList<ChannelInfo*> names; // = new ArrayList<ChannelInfo>();
 if(!datasets_.isEmpty())
 {
  Dataset* ds = datasets_.first();
  names = ds->getChannelInfo();
 }
 return names;
}


void FacsanaduProject::recalcProfChan()
{
 recalcProfChan(nullptr);
}

void FacsanaduProject::recalcProfChan(ProfChannel* chChanged)
{
 for(Dataset* ds : datasets_)
 {
  ds->computeProfChannel(this, chChanged);
 }
}


