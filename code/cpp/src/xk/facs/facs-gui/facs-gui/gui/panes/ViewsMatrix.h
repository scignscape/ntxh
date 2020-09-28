
// // license___here_h


#ifndef ViewsMatrix__H
#define ViewsMatrix__H

#include "view/tool/ViewToolChoice.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class MainWindow;

// package facsanadu.gui.panes;

// //
class ViewsMatrix : public QWidget
{
 QGridLayout* layViews_;// = new QGridLayout();
 MainWindow* mw_;

 QList<QLabel> headerHorizontal_; //=new LinkedList<QLabel>();
 QList<QLabel> headerVertical_; //=new LinkedList<QVLabel>();
 QList<QList<ViewWidget*>> prevChanWidget_; // = new ArrayList<ArrayList<ViewWidget>>();
 bool orderDataset_; // = false;
 int maxevents_;

 ViewToolChoice::Enum currentTool_; // =ViewToolChoice.SELECT;

public: 
 
 ViewsMatrix(MainWindow* mw); 

 void test_one_view();
 
 // // Update the layout of everything
 void updateViews();

 void setMaxEvents(int maxevents);
 void setTool(ViewToolChoice::Enum choice);
 void invalidateCache();
};

#endif // __H
 



