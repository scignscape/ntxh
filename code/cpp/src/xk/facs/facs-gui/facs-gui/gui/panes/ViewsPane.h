
// // license___here_h


#ifndef ViewsPane__H
#define ViewsPane__H

#include "view/tool/ViewToolChoice.h"


#include <QWidget>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>
#include <QButtonGroup>
#include <QList>
#include <QScrollArea>

#include <QWidget>
#include <QLabel>

// package facsanadu.gui.panes;

class ViewsMatrix;
class ViewToolChoice;

class MainWindow;
class Dataset;


// //
class ViewsPane : public QWidget
{
 Q_OBJECT

 MainWindow* mw_;

 QSpinBox* spMaxEvents_; // =new QSpinBox();
 QCheckBox* cbMaxEvents_; // =new QCheckBox(tr("Show max events:"));

 QSpinBox* x_index_spin_box_;
 QSpinBox* y_index_spin_box_;
 QLabel* x_index_label_;
 QLabel* y_index_label_;

 QLabel* x_name_;
 QLabel* y_name_;

 QLabel* shifts_skews_label_;
 QLineEdit* shifts_skews_line_edit_;

 QPushButton* indices_go_;

 QLabel* total_index_label_;

 ViewsMatrix* matrix_;

 QScrollArea* scrollArea_;

 QButtonGroup* bgroup_; //  =new QButtonGroup(this);

 QPushButton* bGateSelect_; // =new QPushButton(new QIcon(ImgResource.gateSelect),"");
 QPushButton* bGatePoly_; // =new QPushButton(new QIcon(ImgResource.gatePolygon),"");
 QPushButton* bGateRect_; // =new QPushButton(new QIcon(ImgResource.gateRect),"");
 QPushButton* bGateEllipse_; // =new QPushButton(new QIcon(ImgResource.gateEllipse),"");
 QPushButton* bGateRange_; // =new QPushButton(new QIcon(ImgResource.gateRange),"");
 
 QList<QPushButton*> tb_; // =new QPushButton[]{bGateSelect, bGatePoly, bGateRect, bGateEllipse, bGateRange};
 



public: 

 ViewsPane(MainWindow* mw);

 void test_one_view();

 void get_mpf_data(int& xcol, int& ycol,
   signed int& xsk, signed int& ysk,
   signed int& xsh, signed int& ysh);

 void reset_index_data(Dataset* ds = nullptr);

 void updateViews();
 void valuesupdated();
 void actionSetTool();
 void setTool(ViewToolChoice::Enum t);
 void invalidateCache();

public Q_SLOTS:

 void update_draw_with_new_indices();

 void update_x_name(int i);
 void update_y_name(int i);
};

#endif // __H

