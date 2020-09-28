
// // license___here

#include "ProfilePane.h"

#include "ProfileView.h"

#include "FacsanaduProject.h"

#include "../gates/GateSet.h"


#include "MainWindow.h"

#include "../resource/ImgResource.h"

#include "../data/ProfChannel.h"

// package facsanadu.gui.lengthprofile;

ProfilePane::ProfilePane(MainWindow* mw)
 :  mw_(mw)
{
 bPrevProf_ = new QPushButton(QIcon(ImgResource::moveLeft()), "");
 bNextProf_ = new QPushButton(QIcon(ImgResource::moveRight()), "");
 tfID_ = new QLineEdit("0");
 cbNormalizeLength_ = new QCheckBox();
 cbShowAll_ = new QCheckBox();
  
 laychans_ = new QGridLayout();
 //cbShowChannel_ = new QList<QCheckBox*>;
 //sScaleChannel_ = new QList<QSlider*>;

 view_ = new ProfileView(mw);
  
  //? tfID.setValidator(new QIntValidator(this));
 tfID_->setMaximumWidth(100);
  
 for(int i=0; i<10; i++)
 {
  QCheckBox* cb = new QCheckBox();
  //cb.stateChanged.connect(this,"updateViews()");
  cb->setChecked(true);
  cbShowChannel_.push_back(cb);
  laychans_->addWidget(cb, i, 0);
   
  QSlider* s = new QSlider();
  s->setOrientation(Qt::Horizontal);
  s->setMaximum(10000);
  s->setValue(2000);
  laychans_->addWidget(s, i, 1);
  sScaleChannel_.append(s);
   //?s.sliderMoved.connect(this,"updateViews()");
 }

 QHBoxLayout* blay = new QHBoxLayout();
 blay->addWidget(new QLabel(tr("Show all")));
 blay->addWidget(cbShowAll_);
 blay->addWidget(new QLabel(tr("Normalize length")));
 blay->addWidget(cbNormalizeLength_);
 blay->addStretch();
 blay->addWidget(new QLabel(tr("Event ID:")));
 blay->addWidget(tfID_);
 blay->addWidget(bPrevProf_);
 blay->addWidget(bNextProf_);
  
 QVBoxLayout* lay = new QVBoxLayout();
 lay->addLayout(blay);
 lay->addWidget(view_);
 lay->addLayout(laychans_);
 
  //tfID_->editingFinished.connect(this,"updateViews()");
  //bNextProf.clicked.connect(this,"actionNextProf()");
  //bPrevProf.clicked.connect(this,"actionPrevProf()");
  //cbNormalizeLength.stateChanged.connect(this,"cbNormalizeLength()");
  //cbShowAll.stateChanged.connect(this,"updateViews()");
 
 setLayout(lay);
}

void ProfilePane::cbNormalizeLength()
{
 if(view_->curchannel())
   view_->curchannel()->set_forNormalized( cbNormalizeLength_->isChecked() );
 updateViews();
}
 
 
Gate* ProfilePane::getCurrentGate()
{
 QList<Gate*> gates = mw_->getSelectedGates();
 Gate* g;
 if(gates.isEmpty())
   g = mw_->project()->gateset()->getRootGate();
 else
   g = gates.first();
 return g;
}

/* 
void ProfilePane::actionPrevProf()
{
  int id=getCurrentID();
  Dataset ds=getCurrentDataset();
  if(ds!=null)
   {
   GatingResult gres=mw.project.getGatingResult(ds);
   IntArray arr=gres.getAcceptedFromGate(getCurrentGate());
   for(int i=arr.size()-1;i>=0;i--)
    if(arr.get(i)<id)
     {
     setEventID(arr.get(i));
     break;
     }
   }
  }

void ProfilePane::actionNextProf()
  {
  int id=getCurrentID();
  Dataset ds=getCurrentDataset();
  if(ds!=null)
   {
   GatingResult gres=mw.project.getGatingResult(ds);
   IntArray arr=gres.getAcceptedFromGate(getCurrentGate());
   for(int i=0;i<arr.size();i++)
    if(arr.get(i)>id)
     {
     setEventID(arr.get(i));
     break;
     }
   }
  }

List<Integer> ProfilePane::getAllFromGate()
  {
  Dataset ds=getCurrentDataset();
  if(ds!=null)
   {
   GatingResult gres=mw.project.getGatingResult(ds);
   IntArray arr=gres.getAcceptedFromGate(getCurrentGate());
   ArrayList<Integer> list=new ArrayList<Integer>(arr.size());
   for(int i=0;i<arr.size();i++)
    list.add(arr.get(i));
   return list;
   }
  else
   return new ArrayList<Integer>();
  }
 
void ProfilePane::setEventID(int id)
  {
  tfID.setText(""+id);
  updateViews();
  }
 
Dataset ProfilePane::getCurrentDataset()
  {
  List<Dataset> listds=mw.getSelectedDatasets();
  if(!listds.isEmpty())
   return listds.get(0);
  else
   return null;
  }

int ProfilePane::getCurrentID()
  {
  int id=-1;
  try
   {
   id=Integer.parseInt(tfID.text());
   }
  catch (NumberFormatException e)
   {
   e.printStackTrace();
   }
  return id;
  }
*/

void ProfilePane::updateViews()
{
/*
  Dataset ds=getCurrentDataset();
  if(ds!=null)
   {
   ArrayList<Boolean> showchan=new ArrayList<Boolean>();
   ArrayList<Double> scale=new ArrayList<Double>();
   for(int i=0;i<ds.getNumLengthProfiles();i++)
    {
    showchan.add(cbShowChannel.get(i).isChecked());
    double pos=sScaleChannel.get(i).value()/1000.0;
    scale.add(pos/400000.0);
    }
   view.showchan=showchan;
   view.scale=scale;
   view.normalizeLength=cbNormalizeLength.isChecked();
   if(cbShowAll.isChecked())
    {
    view.setevent(ds, getAllFromGate());
    }
   else
    {
    int id=getCurrentID();
    view.setevent(ds, id);
    }
   }
  else
   {
   view.setevent(null, 0);
   ds=new Dataset();
   }
  
  //Update name and visibility of checkboxes for channels
  for(int i=0;i<cbShowChannel.size();i++)
   {
   QCheckBox cb=cbShowChannel.get(i);
   QSlider s=sScaleChannel.get(i);
   boolean visible=i<ds.lengthprofsInfo.size();
   cb.setVisible(visible);
   s.setVisible(visible);
   if(visible)
    cb.setText(ds.lengthprofsInfo.get(i).name);
   }
   
*/
}

QList<int> ProfilePane::getSelChans()
{
 return {};
}
 
/* 
ArrayList<Integer> ProfilePane::getSelChans()
  {
  Dataset ds=getCurrentDataset();
  ArrayList<Integer> showchan=new ArrayList<Integer>();
  if(ds!=null)
   for(int i=0;i<ds.getNumLengthProfiles();i++)
    {
    if(cbShowChannel.get(i).isChecked())
     showchan.add(i);
    }
  return showchan;
  }
 
 
void ProfilePane::setCurChan(ProfChannel pc)
  {
  view.curchannel=pc;
  view.repaint();
  }
*/

void ProfilePane::setCurChan(ProfChannel* pc)
{
 view_->set_curchannel(pc);
 view_->repaint();
}




