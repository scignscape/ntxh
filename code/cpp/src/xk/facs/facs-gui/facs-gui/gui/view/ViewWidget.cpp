
// // license___here

#include "ViewWidget.h"
#include "ViewSettings.h"

#include "tool/ViewToolChoice.h"
#include "tool/ViewTool.h"

#include "gate/GateHandle.h"
#include "gates/GateSet.h"
#include "gates/gate-info.h"

#include <QDebug>

#include "data/Dataset.h"
#include "data/ChannelInfo.h"


#include "FacsanaduProject.h"
#include "MainWindow.h"

#include "ViewRenderer.h"

#include "transformations/Transformation.h"
#include "transformations/TransformationStack.h"
#include "transformations/TransformationLog.h"
#include "transformations/TransformationLinear.h"

#include "gates/GatingResult.h"
#include "gates/GateRect.h"


#include <limits>


#include <QImage>
#include <QPainter>


// package facsanadu.gui.view;


ViewWidget::ViewWidget(MainWindow* mw)
 :  blank_img_(nullptr), paint_img_(nullptr),
    lastChannelX_(-1), lastChannelY_(-1)

{
 //Dataset dataset;

 // setchans_; // = new LinkedList<Callback*>();
 //ViewTool tool_ ;

 trans_ = new ViewTransform();
 viewsettings_ = new ViewSettings();

 // handles_ = new LinkedList<GateHandle>();
 curhandle_ = nullptr;

 // pointLast_; // = new QPointF();
 // temp ... maxevents_ = 0; //?
 maxevents_ = 1000;

 mainWindow_ = mw;

 lastGatingTime_ = 0;
 img_ = nullptr;


 setMouseTracking(true);
 setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
 setTool(ViewToolChoice::SELECT);
}

void ViewWidget::setDataset(Dataset* ds)
{
 dataset_ = ds;
}

void ViewWidget::render()
{
 qDebug() << "ViewWidget::render ...";
 update();
 repaint();
}


void ViewWidget::updatePointImage()
{
  //?
 FacsanaduProject* project = mainWindow_->project();
  //?
 GatingResult* gr = project->get_GatingResult(dataset_);  

 //GatingResult* gr = nullptr;

  // // GatingResult not yet impl ...
 long newGatingTime = gr->lastGatingCalculationTime();

// System.out.println("last view "+lastGatingTime+"   last g "+newGatingTime+ "    "+(lastGatingTime<newGatingTime));

 bool channels_updated = false;

  qDebug() << "updating point image? ...";

 if(viewsettings_->indexX() != lastChannelX_)
 {
  lastChannelX_ = viewsettings_->indexX();
  channels_updated = true;
 }  
 if(viewsettings_->indexY() != lastChannelY_)
 {
  lastChannelY_ = viewsettings_->indexY();
  channels_updated = true;
 }  


 if(channels_updated || img_ == nullptr || lastGatingTime_ < newGatingTime 
   || img_->width() != width() || img_->height() != height())
 {
  qDebug() << "updating point image ...";

  img_ = new QImage(width(), height(), QImage::Format_RGB32); //, Format.Format_RGB32);

  QPainter pm2(img_);
//?  pm2.begin(img_);
  pm2.setBrush(QBrush(QColor(225, 210, 200)));
  pm2.drawRect(-5,-5,10000,10000);

  if(!blank_img_)
  {
   blank_img_ = new QImage;
   *blank_img_ = img_->copy();
  }

  ViewRenderer::renderData(mainWindow_, viewsettings_, dataset_, gr, trans_, pm2, maxevents_);
//?  pm2.end();


/*
  System.out.println("update cache");
  img= QImage(width(), height(), Format.Format_RGB32);
  QPainter pm2=new QPainter(img);
  pm2.setBrush(new QBrush(QColor.white));
  pm2.drawRect(-5,-5,10000,10000);
  ViewRenderer.renderData(viewsettings, dataset, gr, trans, pm2, maxevents); 
pm2.end();
  lastGatingTime=newGatingTime;
*/
 }
}

void ViewWidget::clear_image()
{
 if(!blank_img_)
   return;

 paint_img_ = blank_img_;
 repaint();
}


void ViewWidget::paintEvent(QPaintEvent* pe)
{
 if( paint_img_ && (paint_img_ == blank_img_) )
 {
  paint_img_ = nullptr;
  QPainter pm; //=new QPainter(this);
  pm.begin(this);
  pm.drawImage(QPoint {0, 0}, *blank_img_);
  pm.end();
  return;
 }

 QWidget::paintEvent(pe);
  //? super.paintEvent(pe);
  //?

 FacsanaduProject* project = mainWindow_->project();

  //?

// GatingResult* gr = project->get_GatingResult(dataset_);

  // // maybe have to do it ...
 GatingResult* gr = project->check_get_gating_result(dataset_);

 trans_->setTotalHeight(contentsRect().height());
 trans_->setTotalWidth(contentsRect().width());
 trans_->set_viewsettings(viewsettings_);

 LinkedList<GateHandle*> handles; // =new LinkedList<GateHandle>();
 QPainter pm; //=new QPainter(this);

 qDebug() << "ix1: " << viewsettings_->indexX();
 qDebug() << "iy1: " << viewsettings_->indexY();

 updatePointImage();

 qDebug() << "ix2: " << viewsettings_->indexX();
 qDebug() << "iy2: " << viewsettings_->indexY();


 qDebug() << "drawing ...";

 pm.begin(this);
 pm.drawImage(QPoint {0, 0}, *img_);


 ViewRenderer::renderGates(viewsettings_, dataset_, gr, trans_, pm, handles_, maxevents_); 

 qDebug() << "HS: "  << handles_.size();

 //Now render handles?
 for(GateHandle* h : handles_)
 {
  pm.setBrush(QBrush(QColor(Qt::transparent)));
  pm.setPen(QColor(Qt::red));

  qDebug() << "HX: " << h->getX();
  qDebug() << "HY: " << h->getY();


  int size = 2;
  pm.drawRect(QRectF(h->getX() - size, h->getY() - size, 2*size, 2*size));
 }

 pm.end();
}


void ViewWidget::add_proportionate_gate(u1 x1, u1 x2, u1 y1, u1 y2)
{ 
 proportionate_gate_points_ << viewsettings_->indexX()
   << viewsettings_->indexY() << x1 << x2 << y1 << y2;


 r8 rx1 = ( (r8)x1 / 100);
 r8 rx2 = ( (r8)x2 / 100);

 r8 ry1 = ( (r8)y1 / 100);
 r8 ry2 = ( (r8)y2 / 100);

 qDebug() << "rx1 = " << rx1;
 qDebug() << "rx2 = " << rx2;

 qDebug() << "ry1 = " << ry1;
 qDebug() << "ry2 = " << ry2;

  // // get viewing area ...
 int off2 = 5;

// QPointF tl (trans_->graphOffsetXY(), off2);
// QPointF br (trans_->getTotalWidth() - off2, 
//   trans_->getTotalHeight() - trans_->graphOffsetXY());

 r8 width = ( trans_->getTotalWidth() - off2 ) - trans_->graphOffsetXY();  
 r8 height = ( trans_->getTotalHeight() - trans_->graphOffsetXY() ) - off2;  

 r8 width_adjusted_1 = width * rx1;
 r8 width_adjusted_2 = width * rx2;

 r8 height_adjusted_1 = height * ry1;
 r8 height_adjusted_2 = height * ry2; 

 r8 fx1 = trans_->graphOffsetXY() + width_adjusted_1;
 r8 fx2 = trans_->graphOffsetXY() + width_adjusted_2;

 r8 fy1 = off2 + height_adjusted_1;
 r8 fy2 = off2 + height_adjusted_2;

// pm.drawLine(
//  trans_->graphOffsetXY(), off2, 
//  trans->graphOffsetXY(), trans->getTotalHeight() - trans->graphOffsetXY() );

// pm.drawLine(
//  trans->graphOffsetXY(), trans->getTotalHeight() - trans->graphOffsetXY(), 
//  trans->getTotalWidth() - off2, 
//  trans->getTotalHeight() - trans->graphOffsetXY() );


 qDebug() << "x1 = " << fx1;
 qDebug() << "x2 = " << fx2;

 qDebug() << "y1 = " << fy1;
 qDebug() << "y2 = " << fy2;
 
 QRectF* qrf = new QRectF(fx1, fy1, fx2 - fx1, fy2 - fy1);
 
 GateRect* gate = new GateRect(qrf);

 addGate(gate);

}



GateHandle* ViewWidget::getClosestHandle(const QPointF& pos, double cutoff)
{
 if(!tool_->allowHandle())
   return nullptr;

 GateHandle* ch = nullptr;

 double cd = std::numeric_limits<double>::max();

 for(GateHandle* h : handles_)
 {
  double dx = pos.x() - h->getX();
  double dy = pos.y() - h->getY();
  double d2 = (dx * dx) + (dy * dy);

  if(d2 < cd)
  {
   cd = d2;
   ch = h;
  }
 }
 if(cd < (cutoff * cutoff))
   return ch;
 else
   return nullptr;
}

void ViewWidget::mousePressEvent(QMouseEvent* event)
{
 pointLast_ = event->localPos(); //posF();

  // super.mousePressEvent(event);
 QWidget::mousePressEvent(event);

 bool lbtn = event->buttons() == Qt::LeftButton;
 bool rbtn = event->buttons() == Qt::RightButton;

 if(lbtn || rbtn)
 {
  GateHandle* handle = nullptr;
  if(lbtn)
  {
   curhandle_ = nullptr;
   GateHandle* handle = getClosestHandle(event->localPos(), 10);
  }

  if(handle)
  {
   //Move a handle
   curhandle_ = handle;
  }
  else if(mousePosInBoundary(event->pos()))
  {
   setchans_.clear();
   FacsanaduProject* project = mainWindow_->project();
   int invy = height() - event->pos().y();
   QMenu* menu = new QMenu();

   //Menu to set axis, and histogram
   QMenu* menuAxis = menu->addMenu(tr("Set axis"));
   QMenu* menuHist = new QMenu(tr("Set histogram"));
   bool lastwasx = true;
   if(event->pos().x()>invy)
     lastwasx=true;
   else
     lastwasx=false;

   menu->addAction(tr("Swap axis"), this, SLOT(actionSwapAxis()));


   QList<ChannelInfo*> chans = dataset_->getChannelInfo();

   for(int i=0; i < chans.size(); i++)
   {
    ChannelInfo* ci = chans.at(i);
    CallbackSetChannel* set = new CallbackSetChannel(this, lastwasx, i);
    //?set->chanid = i;
    //?set->forx = lastwasx;

    menuAxis->addAction(ci->formatName(), set, &CallbackSetChannel::actionSet); 

//    menuAxis->addAction(ci->formatName(), [set]()
//    {
//     qDebug() << "set: " << &CallbackSetChannel::actionSet;
//     set->actionSet();
//    });

      //this //&set
      //, Q_SLOT("actionSet()") );
    setchans_.append(set);

    CallbackSetHistogram* sethist = new CallbackSetHistogram(this, i);
    //?sethist->chanid = i;

    menuHist->addAction(ci->formatName(), sethist,
      &CallbackSetHistogram::actionSet);

      //sethist, "actionSet()");
    setchans_.append(sethist);
   }

   //Menu to set source population
   QMenu* mSetSource = menu->addMenu(tr("Set source population"));
   for(Gate* g : project->gateset()->getGates())
   {
    CallbackSetGate* sg = new CallbackSetGate(this, g);
    //?sg->g = g;
    setchans_.append(sg);
      // 
    mSetSource->addAction("g->name", sg, &CallbackSetGate::actionSet); 
     //sg, "actionSet()");
   } 

   //Menu to set scaling
   QMenu* mSetScaling = menu->addMenu(tr("Set zoom"));
   for(double d : QList<double> {0.1,0.5,1,2,5,10,20,50})
   {
    CallbackSetZoom* sg = new CallbackSetZoom(this, d, lastwasx);
    //? sg->scale = d;
    //? sg->isx = lastwasx;
    setchans_.append(sg);
    mSetScaling->addAction(QString::number(d), sg, &CallbackSetZoom::actionSet); 
      //"actionSet()");
   } 

   QMenu* menuTrans = menu->addMenu(tr("Set transform"));

   CallbackSetTransformation* tLin = new CallbackSetTransformation
     (this, "Linear" , //TransformationType::LINEAR, 
      lastwasx); 
   CallbackSetTransformation* tLog = new CallbackSetTransformation
     (this,  "Log" ,  // TransformationType::LOG,
      lastwasx);


   menuTrans->addAction("Linear", tLin, &CallbackSetTransformation::actionSet);
      // tlin, "actionSet()");

//?   menuTrans->addAction("Log", tLog, &CallbackSetTransformation::actionSet); 

   menuTrans->addAction("Log", tLog, &CallbackSetTransformation::actionSet); 

   QMenu* mHistBins = new QMenu(tr("Set histogram bins"));

   for(int d : QList<int>{5,10,15,20,30,40,50,100,200,300})
   {
    CallbackSetBins* sg = new CallbackSetBins(this, d);
    //? sg->bins=d;
    setchans_.append(sg);
    mHistBins->addAction(QString::number(d), sg, &CallbackSetBins::actionSet); 
      //sg, "actionSet()");
   }

   menu->addSeparator();
   menu->addMenu(menuHist);
   menu->addMenu(mHistBins);
   menu->exec(event->globalPos());
  }
  else
  {
   tool_->mousePressEvent(event);
  }
 }
}

void ViewWidget::mouseDoubleClickEvent(QMouseEvent* e)
{
  //super.mouseDoubleClickEvent(e);
 QWidget::mouseDoubleClickEvent(e);
 tool_->mouseDoubleClickEvent(e);
}

void ViewWidget::mouseReleaseEvent(QMouseEvent* ev)
{
  //super.mouseReleaseEvent(ev);
 QWidget::mouseReleaseEvent(ev);
 curhandle_ = nullptr;
 tool_->mouseReleaseEvent(ev);
 
  //? mainWindow_->handleEvent(EventGatesChanged());
}


void ViewWidget::mouseMoveEvent(QMouseEvent* event)
{
 QWidget::mouseMoveEvent(event);
 
 if(curhandle_ != nullptr)
 {
  QPointF p = trans_->mapScreenToFcs(event->localPos());
  curhandle_->move2(mainWindow_, p.x(), p.y());
 }
 else
   tool_->mouseMoveEvent(event);

 pointLast_ = event->localPos();
}


bool ViewWidget::mousePosInBoundary(const QPoint& pos)
{
 int invy = height() - pos.y();
 return ( pos.x() < trans_->graphOffsetXY() ) 
  || ( invy < trans_->graphOffsetXY() );
}

void ViewWidget::setChannels(int indexX, int indexY)
{
 viewsettings_->set_indexX(indexX);
 viewsettings_->set_indexY(indexY);
}

void ViewWidget::setSettings(ViewSettings* vs)
{
 viewsettings_ = vs;
}


void ViewWidget::reset_pane_current_index_data()
{
 mainWindow_->reset_pane_views_current_index_data(viewsettings_->indexX(), 
   viewsettings_->indexY());
}



//interface Callback
//{
// void actionSet();
//}

// // Callback: Set channel

void ViewWidget::CallbackSetChannel::actionSet()
{

 vw->clear_image();

 qDebug() << "chanid = " << chanid;


 if(forx)
   vw->viewsettings_->set_indexX(chanid);
 
 else
   vw->viewsettings_->set_indexY(chanid);

 qDebug() << "ix: " << vw->viewsettings_->indexX();
 qDebug() << "iy: " << vw->viewsettings_->indexY();

 vw->reset_pane_current_index_data();


 if(vw->viewsettings_->indexX() == 4)
 {
//?  vw->add_proportionate_gate(4, 30, 45, 78);
/*
  GateRect* g = new GateRect();
  g->set_indexX(vw->viewsettings_->indexX());
  g->set_indexY(vw->viewsettings_->indexY());
  g->set_x1(100);
  g->set_x2(5000);
  g->set_y1(20);
  g->set_y2(80000);
  vw->addGate(g);
*/
 }

 EventViewsChanged ev;
 vw->mainWindow_->handleEvent(ev);

}


void ViewWidget::CallbackSetHistogram::actionSet()
{
 vw->viewsettings_->setHistogram(chanid);
 EventViewsChanged ev;
 vw->mainWindow_->handleEvent(ev);
}


void ViewWidget::CallbackSetGate::actionSet()
{
 vw->viewsettings_->set_gate(g);
 EventViewsChanged ev;
 vw->mainWindow_->handleEvent(ev);
}

ViewWidget::CallbackSetTransformation::CallbackSetTransformation(
  ViewWidget* _this, QString tt, // TransformationType t, 
  bool f)
 :  Callback(_this), ttype(tt), forx(f)
{
}

void ViewWidget::CallbackSetTransformation::actionSet()
{
  qDebug() << " ... ... FacsanaduEvent::Description::EventViewsChanged ...";

 int index;

 if(forx)
   index = vw->viewsettings()->indexX();
 else
   index = vw->viewsettings()->indexY();

// Q_UNUSED(index)


  qDebug() << "index = " << index;

 Transformation* trans = nullptr;

//?
 if(ttype == "Log")
//?
   trans = new TransformationLog();

// 
 else if(ttype == "Linear")
//?
   trans = new TransformationLinear();

// else if(t==TransformationType.LOG)
 if(trans)
   vw->viewsettings()->transformation()->set_for_index(index, trans);

  qDebug() << "... FacsanaduEvent::Description::EventViewsChanged ...";

 EventViewsChanged ev;
 vw->mainWindow_->handleEvent(ev);
}

void ViewWidget::CallbackSetZoom::actionSet()
{
 if(isx)
   vw->viewsettings_->set_zoomX(scale);
 else
   vw->viewsettings_->set_zoomY(scale);

 vw->mainWindow_->handleEvent(new EventViewsChanged());
}

void ViewWidget::CallbackSetBins::actionSet()
{
 vw->viewsettings_->set_numHistBins(bins);
 EventViewsChanged ev;
 vw->mainWindow_->handleEvent(ev);
}

int ViewWidget::getIndexX()
{
 return viewsettings_->indexX();
}

int ViewWidget::getIndexY()
{
 return viewsettings_->indexY();
}

void ViewWidget::sendEvent(FacsanaduEvent& event)
{
 mainWindow_->handleEvent(event);
}

void ViewWidget::actionSwapAxis()
{
 viewsettings_->swapAxis();
 EventViewsChanged ev;
 mainWindow_->handleEvent(ev);
}

void ViewWidget::setTool(ViewToolChoice::Enum e)
{
 tool_ = ViewToolChoice::getTool(this, e);
}

void ViewWidget::addGate(Gate* g)
{
 mainWindow_->addGate(viewsettings_->gate(), g);
}

void ViewWidget::invalidateCache()
{
 img_ = nullptr;
}

