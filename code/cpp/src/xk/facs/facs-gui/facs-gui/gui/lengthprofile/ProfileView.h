
// // license___here_h


#ifndef ProfileView__H
#define ProfileView__H

#include <QPointF>
#include <QMouseEvent>
#include <QWidget>

#include <QPaintEvent>


// package facsanadu.gui.lengthprofile;


class Dataset;
class MainWindow;
class ProfChannel;

// // View showing one length profile
class ProfileView : public QWidget
{
 Dataset* ds_;
 MainWindow* mw_; 
 QList<int> eventid_; // = new ArrayList<Integer>();

 QPointF pointLast_; // =new QPointF();
 int moveBoundary_; // =-1;
 
 int toViewX(int x);
 int fromViewX(int x);

 int clamp(int x, int from, int to);

 bool normalizeLength_;
 QList<bool> showchan_; //=new ArrayList<Boolean>();
 QList<bool> scale_; // =new ArrayList<Double>();
 
 ProfChannel* curchannel_; // =null;

public:

 ProfChannel* curchannel()
 {
  return curchannel_;
 }

 void set_curchannel(ProfChannel* c)
 {
  curchannel_ = c;
 }

 ProfileView(MainWindow* mw);

protected:

 void paintEvent(QPaintEvent* e) Q_DECL_OVERRIDE;

 void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

 void mouseDoubleClickEvent(QMouseEvent* e) Q_DECL_OVERRIDE;
 
 void mouseReleaseEvent(QMouseEvent* ev) Q_DECL_OVERRIDE;
   
 void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
 
public:

 void setevent(Dataset* ds, int i);
 void setevent(Dataset* ds, QList<int> ids);
 
};

#endif // __H
 



