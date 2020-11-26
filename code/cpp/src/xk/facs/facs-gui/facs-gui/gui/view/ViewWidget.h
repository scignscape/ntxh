
// // license___here_h


#ifndef ViewWidget__H
#define ViewWidget__H


#include <QPointF>
#include <QImage>
#include <QPaintEvent>
#include <QMouseEvent>

#include <QWidget>
#include <QPointF>
#include <QImage>

#include "../events/FacsanaduEvent.h"

#include "accessors.h"

#include "ViewTransform.h"
#include "tool/ViewToolChoice.h"


#include "global-types.h"


// // temp
#include<QList>
#define LinkedList QList

// package facsanadu.gui.view;

// //

class Dataset;
class GateHandle; 
class ViewTool;
class MainWindow;
class ViewTransform;
class ViewSettings;
class Gate;
class TransformationType;


class ViewWidget_Callback : public QObject
{
 Q_OBJECT

public:

 ViewWidget_Callback(ViewWidget* _this)
 {
  vw = _this;
 }

 ViewWidget* vw;
 virtual void actionSet() {};
};


class ViewWidget : public QWidget
{
 Q_OBJECT

public:
 typedef ViewWidget_Callback Callback;

private:

 Dataset* dataset_;
 LinkedList<Callback*> setchans_; // = new LinkedList<Callback>();
 ViewTool* tool_;

 LinkedList<GateHandle*> handles_; //=new LinkedList<GateHandle>();
 
 GateHandle* curhandle_; //=null;
 
 QPointF pointLast_; // =new QPointF();

 long lastGatingTime_;  // =0;
 QImage* img_; // = nullptr;

 QImage* blank_img_;
 QImage* paint_img_;

 int lastChannelX_;
 int lastChannelY_;

 void updatePointImage();

 bool mousePosInBoundary(const QPoint& pos);

 MainWindow* mainWindow_;
 ViewTransform* trans_; // =new ViewTransform();
 ViewSettings* viewsettings_; // =new ViewSettings();
 int maxevents_;

 void clear_image();


protected:

 void paintEvent(QPaintEvent* pe)  Q_DECL_OVERRIDE;
 void mousePressEvent(QMouseEvent* event)  Q_DECL_OVERRIDE;
 void mouseDoubleClickEvent(QMouseEvent* e)  Q_DECL_OVERRIDE;
 void mouseReleaseEvent(QMouseEvent* ev)  Q_DECL_OVERRIDE;
 void mouseMoveEvent(QMouseEvent* event)  Q_DECL_OVERRIDE;


public:

 ViewWidget(MainWindow* mw);
 void setDataset(Dataset* ds);
 void render();

 ACCESSORS(int ,maxevents)

 void add_proportionate_gate(u1 x1, u1 x2, u1 y1, u1 y2);
 
 void set_trans(ViewTransform* trans)
 {
  trans_ = trans;
 }

 ViewTransform* trans()
 {
  return trans_;
 }

 ViewSettings* viewsettings()
 {
  return viewsettings_;
 }


 GateHandle* getClosestHandle(const QPointF& pos, double cutoff);
 
 void setChannels(int indexX, int indexY);

 void setSettings(ViewSettings* vs);

 void reset_pane_current_index_data();



// interface Callback
//  {
//  void actionSet();
//  }

//*

//*/

 // //
 class CallbackSetChannel : public Callback  //implements Callback
 {
//  Q_OBJECT

 public:

  CallbackSetChannel(ViewWidget* _this, // TransformationType* t, 
    bool i, int c)
   : Callback(_this), forx(i), chanid(c)
  {
 
  }

  bool forx;
  int chanid;
  void actionSet() Q_DECL_OVERRIDE;
 };

 // // Callback: Set histogram
 class CallbackSetHistogram : public Callback // implements Callback
 {
 public:

  CallbackSetHistogram(ViewWidget* _this, // TransformationType* t, 
    int c)
   : Callback(_this), chanid(c)
  {
 
  }

  int chanid;
  void actionSet() Q_DECL_OVERRIDE;
 };

 // // Callback: set displayed gate
 class CallbackSetGate : public Callback // implements Callback
 {
 public:

  CallbackSetGate(ViewWidget* _this, // TransformationType* t, 
    Gate* gate)
   : Callback(_this), g(gate)
  {
 
  }

  Gate* g;
  void actionSet() Q_DECL_OVERRIDE;
 };

 // // Callback: set transformation
 class CallbackSetTransformation : public Callback //implements Callback
 {
 public:
  QString ttype;  // TransformationType* t;
  bool forx;
  
  CallbackSetTransformation(ViewWidget* _this, QString ttype, // TransformationType* t, 
    bool forx);
  
  void actionSet() Q_DECL_OVERRIDE;
 };

 
 class CallbackSetZoom : public Callback //implements Callback
 {
 public:

  CallbackSetZoom(ViewWidget* _this, double s, // TransformationType* t, 
    bool i)
   : Callback(_this), scale(s), isx(i)
  {
 
  }

  double scale;
  bool isx;
  void actionSet() Q_DECL_OVERRIDE;
 };

 class CallbackSetBins : public Callback  // implements Callback
 {
 public:

  CallbackSetBins(ViewWidget* _this, int b) // TransformationType* t, 
   : Callback(_this), bins(b)
  {
 
  }


  int bins;
  void actionSet() Q_DECL_OVERRIDE;
 };
 
 int getIndexX();
 int getIndexY();
 void sendEvent(FacsanaduEvent& event);

 void actionSwapAxis();

 void setTool(ViewToolChoice::Enum e);

 void addGate(Gate* g);

 void invalidateCache();

};

#endif // __H
 



