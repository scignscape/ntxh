
// // license___here

#include "ViewsMatrix.h"

#include "view/ViewWidget.h"

#include "MainWindow.h"

#include "data/Dataset.h"

#include <QDebug>


// package facsanadu.gui.panes;


// //

ViewsMatrix::ViewsMatrix(MainWindow* mw)
  : mw_(mw)
{ 
 layViews_ = new QGridLayout();

// headerHorizontal = new LinkedList<QLabel>();
// headerVertical = new LinkedList<QVLabel>();
// ArrayList<ArrayList<ViewWidget>> prevChanWidget = new ArrayList<ArrayList<ViewWidget>>();

 orderDataset_ = false;

 currentTool_ = ViewToolChoice::SELECT;
 
 layViews_->setMargin(2);
 layViews_->setSpacing(2);

 //layViews_->addWidget(lab, 0, 0);

// QLabel* lbl = new QLabel("qwerty", this);
// layViews_->addWidget(lbl, 0, 0);

// QLabel* lbl1 = new QLabel("qwerty .", this);
// layViews_->addWidget(lbl1, 0, 1);


 setLayout(layViews_);
 setStyleSheet("QWidget {background: white;}");
}

void ViewsMatrix::test_one_view()
{
// QLabel* lbl = new QLabel("qwerty ...", this);
// layViews_->addWidget(lbl, 1, 0);


 ViewWidget* lab = new ViewWidget(mw_);
 lab->setTool(currentTool_);
 lab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
 lab->setMinimumHeight(200);
 lab->setMinimumWidth(200);
 //onerow.add(lab);

 Dataset* ds =  mw_->get_last_dataset();

 lab->setDataset(ds);

 qDebug() << "N cols:" << ds->getNumChannels();

 layViews_->addWidget(lab, 0, 0);

 //QLabel* lbl = new QLabel

}

// // Update the layout of everything
void ViewsMatrix::updateViews()
{

 qDebug() << "I: " << QString("%1/%2").arg("DEFAULT_ICON_FOLDER").arg("name");
 
/*
 //FacsanaduProject project=mw.project;
 LinkedList<Dataset> selds=mw.getSelectedDatasets();
 LinkedList<ViewSettings> selviews=mw.getSelectedViews();
  
 //Autoscale all views to the same size
 ViewSettings.autoscale(selds, selviews);

 int numrow=selds.size();
 int numcol=selviews.size();
 if(orderDataset)
 {
  numrow=selds.size();
  numcol=selviews.size();
 }
 else
 {
  numcol=selds.size();
  numrow=selviews.size();
 }

 //Adjust horizontal header size
 //Add columns
 for(;headerHorizontal.size()<numcol;)
 {
  int i=headerHorizontal.size();
  QLabel lab=new QLabel(this);
  lab.setAlignment(AlignmentFlag.AlignCenter);
  QFont font=new QFont();
  font.setBold(true);
  lab.setFont(font);
  headerHorizontal.add(lab);
  layViews.addWidget(lab, 0, i+1);
 }

 //Remove columns
 for(;headerHorizontal.size()>numcol;)
 {
  int i=headerHorizontal.size()-1;
  QLabel lab=headerHorizontal.get(i);
  lab.setVisible(false);
  layViews.removeWidget(lab);
  headerHorizontal.remove(i);
 }


 //Adjust vertical header size
 //Add rows
 for(;headerVertical.size()<numrow;)
 {
  int i=headerVertical.size();
  QVLabel lab=new QVLabel(this);
  headerVertical.add(lab);
  layViews.addWidget(lab, i+1, 0);
 }
 //Remove rows
 for(;headerVertical.size()>numrow;)
 {
  int col=headerVertical.size()-1;
  QVLabel lab=headerVertical.get(col);
  lab.setVisible(false);
  layViews.removeWidget(lab);
  headerVertical.remove(col);
 }
  
 //Adjust number of view rows
 while(prevChanWidget.size()<numrow)
 {
  prevChanWidget.add(new ArrayList<ViewWidget>());
 }

 while(prevChanWidget.size()>numrow)
 {
  int row=prevChanWidget.size()-1;
  ArrayList<ViewWidget> onerow=prevChanWidget.get(row);
  for(;onerow.size()>0;)
  {
   int col=onerow.size()-1;
   ViewWidget lab=onerow.get(col);
   lab.setVisible(false);
   layViews.removeWidget(lab);
   onerow.remove(col);
  }
  prevChanWidget.remove(row);
 }
  
 //Fix number of columns
 for(int row=0; row < prevChanWidget.size(); row++)
 {
  //Add columns
  ArrayList<ViewWidget> onerow=prevChanWidget.get(row);
  for(; onerow.size()<numcol; )
  {
   int col=onerow.size();
   ViewWidget lab=new ViewWidget(mw);
   lab.setTool(currentTool);
   lab.setSizePolicy(Policy.Expanding, Policy.Expanding);
   lab.setMinimumHeight(200);
   lab.setMinimumWidth(200);
   onerow.add(lab);
   layViews.addWidget(lab, row+1, col+1);
  }
  //Remove columns
  for(;onerow.size()>numcol;)
  {
   int col=onerow.size()-1;
   ViewWidget lab=onerow.get(col);
   lab.setVisible(false);
   layViews.removeWidget(lab);
   onerow.remove(col);
  }
 }
  
 int indexA = 0;

 for(Dataset ds:selds)
 {
  for(int indexB=0;indexB<selviews.size();indexB++)
  {
   ViewSettings vs=selviews.get(indexB);
   int posRow,posCol;
   if(orderDataset)
   {
    posRow=indexA;
    posCol=indexB;
   }
   else
   {
    posCol=indexA;
    posRow=indexB;
   }
      
   ViewWidget lab=prevChanWidget.get(posRow).get(posCol);
   lab.setSettings(vs);
   lab.setDataset(ds);
  }
  indexA++;
 }

 //Update headers
 for(int i=0;i<selds.size();i++)
 {
  String name=selds.get(i).getName();
  if(orderDataset)
    headerVertical.get(i).setText(name);
  else
    headerHorizontal.get(i).setText(name);
 }

 for(int i=0; i<selviews.size(); i++)
 {
  Gate g=selviews.get(i).gate;
  if(orderDataset)
    headerHorizontal.get(i).setText(g.name);
  else
    headerVertical.get(i).setText(g.name);
 }
  
 //Get the size of one. rescale. then rerender all
 for(ArrayList<ViewWidget> row:prevChanWidget)
 {
  for(ViewWidget w:row)
  {
   w.maxevents=maxevents;
   w.render();
  }
 }
*/
}

void ViewsMatrix::setMaxEvents(int maxevents)
{
 maxevents_ = maxevents;
 updateViews();
}

 
void ViewsMatrix::setTool(ViewToolChoice::Enum choice)
{
 currentTool_ = choice;
 for(QList<ViewWidget*> row : prevChanWidget_)
 {
  for(ViewWidget* w : row)
  {
   w->setTool(currentTool_);
  }
 }
}

void ViewsMatrix::invalidateCache()
{
 for(QList<ViewWidget*> list : prevChanWidget_)
 {
  for(ViewWidget* w : list)
  {
   w->invalidateCache();
  }
 }
}


