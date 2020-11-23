
// // license___here_h

#include "Dataset.h"

#include "ChannelInfo.h"

#include "FacsanaduProject.h"

#include "ProfChannel.h"


#include "facs-bridge/qvector-matrix-r8.h"
#include "facs-bridge/mpf-package.h"


#include "qcytolib/include/cytolib/MemCytoFrame.hpp"

#include <algorithm>

#include <QDebug>


Dataset::Dataset(QVector_Matrix_R8* eventsFloat)
  :  eventsFloat_(eventsFloat), cyto_frame_(nullptr), 
     current_column_names_(nullptr),eventsFloatCompensated_(nullptr)
{
 if(eventsFloat_)
   numChannel_ = eventsFloat_->n_cols();
 else
   numChannel_ = 0;
 numPc_ = 0;

 numCompensated_ = 0;

/*
  // //  skip doing any compensation!
 if(eventsFloat_)
   eventsFloatCompensated_ = eventsFloat_->new_from_dimensions();
 else
   eventsFloatCompensated_ = nullptr;

 if(eventsFloat_)
 {
  test_compensation_matrix_ = new QVector_Matrix_R8(
    eventsFloat_->n_cols(), eventsFloat_->n_cols());
  test_compensation_matrix_->fill_diagonal();
  do_preliminary_compensation();
 }
*/
}

void Dataset::do_preliminary_compensation()
{
 qDebug() << "prelim ...";
 for(u4 r = 1; r <= eventsFloat_->n_rows(); ++r)
 {
  QVector<r8> row;
  eventsFloat_->get_row(r, row);
  QVector<r8> mrow;
  test_compensation_matrix_->multiply(row, mrow);
  eventsFloatCompensated_->merge_row(row, r);  
 }

// qDebug() << "getting extrema ..." << eventsFloat_->n_cols() 
//   << ", " << eventsFloat_->n_rows()
//   << ", " << eventsFloatCompensated_->n_cols() 
//   << ", " << eventsFloatCompensated_->n_rows() ;

/*
 for(u4 c = 1; c <= eventsFloat_->n_cols(); ++c)
 {
  QPair<r8, r8> pr = eventsFloat_->get_extrema_in_column(c);
  qDebug() << "Min, Max for EF col " << c << ": " << pr;
 }


 for(u4 c = 1; c <= eventsFloatCompensated_->n_cols(); ++c)
 {
  QPair<r8, r8> pr = eventsFloatCompensated_->get_extrema_in_column(c);
  qDebug() << "Min, Max for EFC col " << c << ": " << pr;
 }
*/

 eventsFloatCompensated_->get_column_extrema(extrema_);

 qDebug() << "Extrema: " << extrema_;

  // // temp ...
 numCompensated_ = numChannel_;
}

void Dataset::read_channel_info()
{
 // // in lieu of the code in FCSFile.java ...
 for(int id = 1; id <= numChannel_; ++id)
 {
  ChannelInfo* ch = new ChannelInfo();
  QString label = QString("Label%1").arg(id); //nameForPar.get(id);
  QString name = QString("Name%1").arg(id); // shortNameForPar.get(id);
  ch->set_label(label);
  ch->set_name(name);
  channelInfo_.push_back(ch);
 }
}

QList<ChannelInfo*> Dataset::getChannelInfo()
{
 qDebug() << "get Channel Info: " << channelInfo_.size();
 return channelInfo_;
}


int Dataset::getNumObservations()
{
// return eventsFloat_.size();
 return eventsFloat_->n_rows();
}


int Dataset::getNumChannels()
{
 return numCompensated_;
//  return numChannel+numPc;
}


int Dataset::getNumLengthProfiles()
{
 return lengthprofsInfo_.size();
}


QString Dataset::getName()
{
 return file_source_name_;
}
/*
QString Dataset::get_file_source_name()
{
 // // ok?
 return source_.fileName();
}
*/


double Dataset::getAsFloatCompensated(int obs, int indexChan)
{
 return (*eventsFloatCompensated_)[obs + 1](indexChan);
}


QVector<double> Dataset::getAsFloatCompensated(int obs)
{
 QVector<double> result;
 eventsFloatCompensated_->get_row(obs + 1, result);
 return result;
//  return eventsFloat.get(obs);
}

void Dataset::getAsFloatCompensated(int obs, QVector<double>& row)
{
 if(!eventsFloatCompensated_)
   return; 

 eventsFloatCompensated_->get_row(obs + 1, row);
}

// // Compute profile channels. or only one if not null
void Dataset::computeProfChannel(FacsanaduProject* proj, ProfChannel* forPc)
{
// Q_UNUSED(proj)
// Q_UNUSED(forPc)

 QSet<ProfChannel*> oldPc; //=new HashSet<ProfChannel>();
 
 for(ChannelInfo* ci : channelInfo_)
 {
  if(ci->pc())
    oldPc.insert(ci->pc());
 }

 if(oldPc != QSet<ProfChannel*>::fromList(proj->profchan()) ) 
   //equals(new HashSet<ProfChannel>(proj.profchan)))
 {
  //Recompute all channels
  for(ChannelInfo* ci : channelInfo_)
  {
   if(ci->pc())
     channelInfo_.removeOne(ci);
   // //? and delete ci?
  }


  qDebug() << "prof channel length: " << proj->profchan(); 
  for(ProfChannel* pc : proj->profchan() )
  {
   ChannelInfo* ci = new ChannelInfo();
   ci->set_label(pc->getName());
   ci->set_pc(pc);
   channelInfo_.push_back(ci);
  }

  //Add new channels
  numPc_ = proj->profchan().size();
  resizeEvents(numChannel_ + numPc_);
  for(int i = 0; i < numPc_; ++i)
  {
   int toi = numChannel_ + i;
   ChannelInfo* ci = channelInfo_.at(toi);
   for(int j=0;j<getNumObservations();j++)
   {
//?    double[] d=eventsFloat.get(j);
//?    d[toi] = ci.pc.calc(lengthprofsData.get(j));
   }
  }
 }

 else if(forPc)
 {
   //Update only one channel
  ChannelInfo* ci = getChannelInfoForProf(forPc);
  int toi = channelInfo_.indexOf(ci);
  for(int j=0; j < getNumObservations(); ++j)
  {
   // double[] d=eventsFloat.get(j);
   // d[toi]=forPc.calc(lengthprofsData.get(j));
  }
 }
 else
 {
  qDebug() << "hmmm. prof chan nothing to do";
 }

 /*
  //If deleting or adding a channel... I find it fine enough to recompute everything. But this should
  //not be done if just modifying a gate
  HashSet<ProfChannel> oldPc=new HashSet<ProfChannel>();
  for(ChannelInfo i:channelInfo)
   if(i.pc!=null)
    oldPc.add(i.pc);
  if(!oldPc.equals(new HashSet<ProfChannel>(proj.profchan)))
   {
   //System.out.println("Recomp all chan");
   
   //Recompute all channels
   for(ChannelInfo i:new ArrayList<ChannelInfo>(channelInfo))
    if(i.pc!=null)
     channelInfo.remove(i);
   for(ProfChannel pc:proj.profchan)
    {
    ChannelInfo i=new ChannelInfo();
    i.label=pc.getName();
    i.pc=pc;
    channelInfo.add(i);
    }
   //Add new channels
   numPc=proj.profchan.size();
   resizeEvents(numChannel+numPc);
   for(int i=0;i<numPc;i++)
    {
    int toi=numChannel+i;
    ChannelInfo ci=channelInfo.get(toi);
    for(int j=0;j<getNumObservations();j++)
     {
     double[] d=eventsFloat.get(j);
     d[toi]=ci.pc.calc(lengthprofsData.get(j));
     }
    }
   }
  else if(forPc!=null)
   {
   //Update only one channel
   ChannelInfo ci=getChannelInfoForProf(forPc);
   int toi=channelInfo.indexOf(ci);
   for(int j=0;j<getNumObservations();j++)
    {
    double[] d=eventsFloat.get(j);
    d[toi]=forPc.calc(lengthprofsData.get(j));
    }
   }
  else
   {
   System.out.println("hmmm. prof chan nothing to do");
   }
*/
}

ChannelInfo* Dataset::getChannelInfoForProf(ProfChannel* pc)
{
 for(ChannelInfo* ci : channelInfo_)
 {
  if(ci->pc() == pc)
    return ci;
 }
 //throw new RuntimeException("No channel info for prof channel");
 return nullptr;
}

void Dataset::setEvents(QVector_Matrix_R8* e)  // QList<QList<double>> e)
{
 eventsFloat_ = e;
//? numChannel_ = 0;
//? if(getNumObservations() > 0)
 //?  numChannel_ = eventsFloat_.first().length();
 numChannel_ = eventsFloat_->n_cols();
}

 // // Resize the events. Used to make space for virtual channels
void Dataset::resizeEvents(int newsize)
{
 QList<QList<double>> newEventsFloat; // =new ArrayList<double[]>(eventsFloat.size());

/*
 for(QList<double> o : eventsFloat_)
 {
  QVector<double> n(newsize); // =new double[newsize];
  std::copy_n(o.begin(), numChannel_, n.begin());

  //?System.arraycopy(o, 0, n, 0, numChannel);
  newEventsFloat.push_back(n.toList());
 }
  //? eventsFloat_ = newEventsFloat;
 */

}


