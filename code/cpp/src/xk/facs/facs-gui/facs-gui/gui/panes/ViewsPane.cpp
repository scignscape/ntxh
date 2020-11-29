
// // license___here

#include "ViewsPane.h"

#include "ViewsMatrix.h"

#include "view/ViewWidget.h"

#include "view/ViewSettings.h"

#include "../resource/ImgResource.h"

#include "facs-bridge/mpf-package.h"

#include "MainWindow.h"

#include "facs-bridge/mpf-package.h"

USING_KANS(MPF)

#include "data/Dataset.h"

#include <QHBoxLayout>
#include <QDebug>
#include <QLineEdit>


// package facsanadu.gui.panes;

#define connect_this(x, y, z) connect(y, &x, \
   this, &ViewsPane::z);

// //

ViewsPane::ViewsPane(MainWindow* mw)
 :  mw_(mw)
{
 spMaxEvents_ = new QSpinBox();
 cbMaxEvents_ = new QCheckBox(tr("Show max events:"));

 x_index_spin_box_ = new QSpinBox();
 y_index_spin_box_ = new QSpinBox();

 x_index_label_ = new QLabel("x", this);
 y_index_label_ = new QLabel("y", this);

 total_index_label_ = new QLabel(tr("channels  (of 0):"), this);


// indices_go_ = new QPushButton("go");
// indices_go_->setMaximumWidth(30);

 matrix_ = new ViewsMatrix(mw);
 bgroup_ = new QButtonGroup(this);

 bGateSelect_ = new QPushButton(QIcon(ImgResource::gateSelect()),"");
 bGatePoly_ = new QPushButton(QIcon(ImgResource::gatePolygon()),"");
 bGateRect_ = new QPushButton(QIcon(ImgResource::gateRect()),"");
 bGateEllipse_ = new QPushButton(QIcon(ImgResource::gateEllipse()),"");
 bGateRange_ = new QPushButton(QIcon(ImgResource::gateRange()),"");
 QList<QPushButton*> tb {bGateSelect_, bGatePoly_, 
   bGateRect_, bGateEllipse_, bGateRange_};
  
 for(QPushButton* t : tb)
 {
  bgroup_->addButton(t);
 }

 for(QPushButton* t : tb)
 {
  t->setCheckable(true);
 }

 bGateSelect_->setChecked(true);
 
 for(QPushButton* t : tb)
 {
  connect_this(QPushButton ::toggled ,t ,actionSetTool)
  //t.toggled.connect(this,"actionSetTool()");
 }
  
 spMaxEvents_->setMinimum(100);
 spMaxEvents_->setMaximum(10000000);
 spMaxEvents_->setValue(100000);
 cbMaxEvents_->setChecked(true);
  
 QHBoxLayout* laytop = new QHBoxLayout();
 
 for(QPushButton* t : tb)
 {
  laytop->addWidget(t);
 }

 laytop->addSpacing(10);
 laytop->addStretch();

 laytop->addWidget(total_index_label_);

 x_index_spin_box_->setMinimum(1);
 x_index_spin_box_->setMaximum(1);
 y_index_spin_box_->setMinimum(1);
 y_index_spin_box_->setMaximum(1);

 laytop->addWidget(x_index_label_);
 laytop->addWidget(x_index_spin_box_);

 laytop->addWidget(y_index_label_);
 laytop->addWidget(y_index_spin_box_);

 x1_percent_label_ = new QLabel("%(gate): x1", this);
 x1_percent_spin_box_ = new QSpinBox(this);
 x1_percent_spin_box_->setMinimum(0);
 x1_percent_spin_box_->setMaximum(100);
 x1_percent_spin_box_->setMinimum(0);
 x1_percent_spin_box_->setValue(0);
 x1_percent_spin_box_->setMaximumWidth(45);

 x2_percent_label_ = new QLabel("x2", this);
 x2_percent_spin_box_ = new QSpinBox(this);
 x2_percent_spin_box_->setMinimum(0);
 x2_percent_spin_box_->setMaximum(100);
 x2_percent_spin_box_->setValue(100);
 x2_percent_spin_box_->setMaximumWidth(45);

 y1_percent_label_ = new QLabel("y1", this);
 y1_percent_spin_box_ = new QSpinBox(this);
 y1_percent_spin_box_->setMinimum(0);
 y1_percent_spin_box_->setMaximum(100);
 y1_percent_spin_box_->setValue(0);
 y1_percent_spin_box_->setMaximumWidth(45);

 y2_percent_label_ = new QLabel("y2", this);
 y2_percent_spin_box_ = new QSpinBox(this);
 y2_percent_spin_box_->setMinimum(0);
 y2_percent_spin_box_->setMaximum(100);
 y2_percent_spin_box_->setValue(100);
 y2_percent_spin_box_->setMaximumWidth(45);

 laytop->addSpacing(5);
 laytop->addStretch();

 laytop->addWidget(x1_percent_label_);
 laytop->addWidget(x1_percent_spin_box_);

 laytop->addWidget(x2_percent_label_);
 laytop->addWidget(x2_percent_spin_box_);

 laytop->addSpacing(5);
 laytop->addStretch();

 laytop->addWidget(y1_percent_label_);
 laytop->addWidget(y1_percent_spin_box_);

 laytop->addWidget(y2_percent_label_);
 laytop->addWidget(y2_percent_spin_box_);

 laytop->addSpacing(5);
 laytop->addStretch();

 gate_go_ = new QPushButton("add", this);
 gate_go_->setMaximumWidth(30);

 laytop->addSpacing(5);
 laytop->addWidget(gate_go_);

 //connect_this(QPushButton ::clicked ,indices_go_ ,update_draw_with_new_indices)
 connect_this(QPushButton ::clicked ,gate_go_ ,add_proportionate_gate)

 laytop->addSpacing(5);
 laytop->addStretch();

/*
 x_name_ = new QLabel("(x name)"); 
 y_name_ = new QLabel("(y name)"); 

 x_name_->setMinimumWidth(50);
 y_name_->setMinimumWidth(50);

 laytop->addWidget(x_name_);
 laytop->addWidget(y_name_);


 laytop->addWidget(indices_go_);

 shifts_skews_label_ = new QLabel("skews/shifts:", this);
 shifts_skews_line_edit_ = new QLineEdit("300:300:0:0", this);
 shifts_skews_line_edit_->setMinimumWidth(120);
 laytop->addWidget(shifts_skews_label_);
 laytop->addWidget(shifts_skews_line_edit_);
*/


//? connect(x_index_spin_box_, SIGNAL(valueChanged(int)), this, SLOT(update_x_name(int)));
//? connect(y_index_spin_box_, SIGNAL(valueChanged(int)), this, SLOT(update_y_name(int)));
 
 //connect_this(QSpinBox ::valueChanged(int) ,y_index_spin_box_ ,update_y_name(int))

 laytop->addSpacing(10);
 laytop->addStretch();

 laytop->addWidget(cbMaxEvents_);
 laytop->addWidget(spMaxEvents_);
 laytop->setMargin(2);
 laytop->setSpacing(2);  
  
 scrollArea_ = new QScrollArea();
 scrollArea_->setWidgetResizable(true);
 scrollArea_->setWidget(matrix_);
 scrollArea_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
 scrollArea_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

 QVBoxLayout* lay = new QVBoxLayout();
 lay->addLayout(laytop);
 lay->addWidget(scrollArea_);
 lay->setMargin(0);
 lay->setSpacing(2);
 setLayout(lay);
  
//? spMaxEvents.valueChanged.connect(this,"valuesupdated()");
//? cbMaxEvents.stateChanged.connect(this,"valuesupdated()");
 valuesupdated();
}

void ViewsPane::update_x_name(int i)
{
 QVector<QString>& cns = mw_->current_column_names();
 //? x_name_->setText(cns.value(i));
}

void ViewsPane::update_y_name(int i)
{
 QVector<QString>& cns = mw_->current_column_names();
 //? y_name_->setText(cns.value(i));
}

void ViewsPane::reset_current_index_data(u4 x, u4 y)
{
 x_index_spin_box_->setValue(x + 1);
 y_index_spin_box_->setValue(y + 1);
}

void ViewsPane::reset_index_data(Dataset* ds)
{
 if(!ds) 
   ds = mw_->get_last_dataset();

 int nc = ds->getNumChannels();
// qDebug() << "nc = " << nc;
 total_index_label_->setText(tr("channels (of %1):").arg(nc));

// QVector<QString>& cns = mw_->current_column_names();
// qDebug() << "cns = " << cns;

 x_index_spin_box_->setRange(1, nc);
 y_index_spin_box_->setRange(1, nc);

 // // here, for indices?
#ifdef HIDE
 MPF_Package* mpf = mw_->mpf_package();
 x_index_spin_box_->setValue(mpf->columns()[0]);
 y_index_spin_box_->setValue(mpf->columns()[1]);

 shifts_skews_line_edit_->setText(QString("%1:%2:%3:%4")
   .arg(mpf->dimension_skews()[0]).arg(mpf->dimension_skews()[1])
   .arg(mpf->dimension_shifts()[0]).arg(mpf->dimension_shifts()[1]));
#endif // HIDE
}

void ViewsPane::reset_proportionate_gate_data(int xcol, int ycol, 
  u1 x1, u1 x2, u1 y1, u1 y2)
{
 x_index_spin_box_->setValue(xcol);
 y_index_spin_box_->setValue(ycol);
 reset_proportionate_gate_data(x1, x2, y1, y2);
}

void ViewsPane::reset_proportionate_gate_data(u1 x1, u1 x2, u1 y1, u1 y2)
{
 x1_percent_spin_box_->setValue(x1);
 x2_percent_spin_box_->setValue(x2);

 y1_percent_spin_box_->setValue(y1);
 y2_percent_spin_box_->setValue(y2);
}

void ViewsPane::get_proportionate_gate_data(int& xcol, int& ycol,
  u1& x1, u1& x2, u1& y1, u1& y2)
{
 xcol = x_index_spin_box_->value();
 ycol = y_index_spin_box_->value();

 x1 = x1_percent_spin_box_->value();
 x2 = x2_percent_spin_box_->value();

 y1 = y1_percent_spin_box_->value();
 y2 = y2_percent_spin_box_->value();

}

void ViewsPane::get_mpf_data(int& xcol, int& ycol,
  signed int& xsk, signed int& ysk,
  signed int& xsh, signed int& ysh)
{
 xcol = x_index_spin_box_->value();
 ycol = y_index_spin_box_->value();


/*
 QStringList qsl = shifts_skews_line_edit_->text().split(':');

 signed int skews[2];
 signed int shifts[2];

 int i = 0;
 for(QString qs : qsl)
 {
  if(i < 2)
    skews[i] = qs.toInt();
  else
    shifts[i - 2] = qs.toUInt();
  ++i;
 }

 xsk = skews[0];
 ysk = skews[1];

 xsh = shifts[0];
 ysh = shifts[1];
*/
}

void ViewsPane::add_proportionate_gate()
{
 int xcol, ycol;
 u1 x1, x2, y1, y2;
 
 get_proportionate_gate_data(xcol, ycol, x1, x2, y1, y2);
 
 if(ViewWidget* vw = matrix_->get_current_view()) 
   vw->add_proportionate_gate(x1, x2, y1, y2);

 EventViewsChanged ev;
 mw_->handleEvent(ev);

}

void ViewsPane::update_draw_with_new_indices()
{
 int xcol, ycol;
 signed int xsk, ysk, xsh, ysh;

 get_mpf_data(xcol, ycol, xsk, ysk, xsh, ysh);

 mw_->update_pane_views(xcol, ycol, xsk, ysk,
   &xsh, &ysh);

 //qDebug() << "uuu " << xv << ", " << yv;
}

void ViewsPane::load_view_from_mpf(MPF_Package* mpfp)
{
 if(ViewWidget* vw = matrix_->get_current_view())
 {
  u1 ix = mpfp->columns()[0];
  u1 iy = mpfp->columns()[1]; 

  //?vw->setChannels(ix, iy);

  vw->setChannels(ix, iy);
  vw->reset_pane_current_index_data();

  updateViews();

  auto it = mpfp->prop_points().find({ix, iy});
  
  if(it != mpfp->prop_points().end())
  {
   QVector<QPair<u1, u1>>& vp = *it;
   if(vp.size() < 2)
     return;
   
   vw->add_proportionate_gate(vp[0].first, vp[1].first, vp[0].second, vp[1].second); 
   reset_proportionate_gate_data(vp[0].first, vp[1].first, vp[0].second, vp[1].second);

   EventViewsChanged ev;
   mw_->handleEvent(ev);
  }
 
 }
 
}


MPF_Package* ViewsPane::view_to_mpf()
{
 ViewWidget* vw = matrix_->get_current_view();

 QVector<u1>& pgs = vw->proportionate_gate_points();
 
 if(pgs.size() < 6)
   return nullptr;

 QVector<u1> one_gate = pgs.mid(0, 6);

 qDebug() << "one gate = " << one_gate;

 MPF_Package* result = new MPF_Package(2);
 
 result->add_prop_point(one_gate[0], one_gate[1], one_gate[2], one_gate[4]);
 result->add_prop_point(one_gate[0], one_gate[1], one_gate[3], one_gate[5]);

 result->columns()[0] = vw->viewsettings()->indexX();
 result->columns()[1] = vw->viewsettings()->indexY();

 return result;
}

void ViewsPane::test_one_view()
{
 //reset_index_data();
 matrix_->test_one_view();
}

void ViewsPane::updateViews()
{
 matrix_->updateViews();
}

void ViewsPane::valuesupdated()
{
 int maxevents = std::numeric_limits<int>::max();
 if(cbMaxEvents_->isChecked())
   maxevents = spMaxEvents_->value();
 matrix_->setMaxEvents(maxevents);
}

void ViewsPane::actionSetTool()
{
 if(bgroup_->checkedButton() == bGatePoly_)
   setTool(ViewToolChoice::POLY);
 else if(bgroup_->checkedButton() == bGateSelect_)
   setTool(ViewToolChoice::SELECT);
 else if(bgroup_->checkedButton() == bGateRect_)
   setTool(ViewToolChoice::RECT);
 else if(bgroup_->checkedButton() == bGateEllipse_)
   setTool(ViewToolChoice::ELLIPSE);
 else if(bgroup_->checkedButton() == bGateRange_)
   setTool(ViewToolChoice::RANGE);
}

void ViewsPane::setTool(ViewToolChoice::Enum t)
{
 if(t == ViewToolChoice::SELECT)
   bGateSelect_->setChecked(true);
 else if(t == ViewToolChoice::POLY)
   bGatePoly_->setChecked(true);
 else if(t == ViewToolChoice::RECT)
   bGateRect_->setChecked(true);
 matrix_->setTool(t);
}

 
void ViewsPane::invalidateCache()
{
 matrix_->invalidateCache();
}


