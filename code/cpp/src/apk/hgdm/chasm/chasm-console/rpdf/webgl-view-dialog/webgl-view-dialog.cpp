
#include "webgl-view-dialog.h"

#include <QPushButton>
#include <QTabBar>

#include <QHeaderView>

#include <QRegularExpression>

#include "context-menu-provider.h"


#include "styles.h"

void WebGL_View_Dialog::check_url_patterns(QString url)
{
 if(url_patterns_.isEmpty())
   return;

 if(url.contains("/maps/place"))
   qDebug() << url;

 QVector<Context_Menu_Provider::Action_Info> info;

 for(int i = url_patterns_.size() - 1; i >= 0; --i) //const QMap<QString, QString>& m : url_patterns_)
 {
  QMap<QString, QString>& m = url_patterns_[i];
  QString pattern = m.value("pattern");

  if(pattern.isEmpty())
    continue;

  QRegularExpression rx(pattern);

  QRegularExpressionMatch rxm = rx.match(url);

  if(rxm.hasMatch())
  {
   QString proc = m.value("procedure");
   QString arguments = m.value("arguments");
   for(int i = 0; i < 10; ++i)
     arguments.replace(QString("`.%1").arg(i), rxm.captured(i));
   qDebug() << "Proc = " << proc;
   qDebug() << "Arguments = " << arguments;

   QStringList action_procedures;
   QStringList option_labels;

   context_menu_provider_->check_url(proc, arguments, info);

   if(!info.isEmpty())
     break;
   //Q_EMIT url_pattern_match(proc, arguments);
  }
 }

 if(info.isEmpty())
   return;



 for(Context_Menu_Provider::Action_Info& ai : info)
 {
  qDebug() << ai.option_label;
 }

}



WebGL_View_Dialog::WebGL_View_Dialog(QWidget* parent)
  :  QDialog(parent), context_menu_provider_(nullptr)
{
 main_layout_ = new QVBoxLayout;
 wev_ = new RPDF_Web_Engine_View();
 //wev->setGeometry(0,0,700,600);

//?
 wep_ = new RPDF_Web_Engine_Page;

 QObject::connect(wep_, &RPDF_Web_Engine_Page::urlChanged,[this](const QUrl &url){
  qDebug() << "r:" << url.toString();
  //? check_url_patterns(url.toString().prepend("urlChanged!"));
 });

 QObject::connect(wep_, &RPDF_Web_Engine_Page::navRequest,[this](const QUrl &url){
  qDebug() << "req:" << url.toString();
  //? check_url_patterns(url.toString().prepend("navRequest!"));
 });


 QObject::connect(wep_, &RPDF_Web_Engine_Page::linkHovered,[](const QUrl &url){
  qDebug() << "H:" << url.toString();
 });

 myp_ = new MyPage;
 QWebChannel* channel = new QWebChannel(wev_);
 channel->registerObject(QStringLiteral("content"), myp_);
 wep_->setWebChannel(channel);

 //?
 wev_->setPage(wep_);

//?

 QString url = ROOT_FOLDER "/../testdia/matterport/examples.html";



 qDebug() << "url = " << url;
 //
 wep_->load(QUrl("file:///" + url));

// wep_->load(QUrl("https://www.google.com/maps/place/Philadelphia,+PA/@39.9558052,-75.1581506,13.75z/data=!4m5!3m4!1s0x89c6b7d8d4b54beb:0x89f514d88c3e58c1!8m2!3d39.9525839!4d-75.1652215"));

 qtw_ = new QTabWidget(this);
 qtw_->addTab(wev_, "Tour");

 iwev_ = new QWebEngineView(this);
 iwev_->page()->load(QUrl("https://matterport.com/"));
 qtw_->addTab(iwev_, "Matterport Info");

 qtw_->tabBar()->setShape(QTabBar::TriangularNorth);
 //?
 qtw_->setStyleSheet(tab_style_sheet_());


 url_patterns_frame_ = new QFrame(this);
 url_patterns_table_ = new QTableWidget(this);
 url_patterns_layout_ = new QVBoxLayout;
 url_patterns_layout_->addWidget(url_patterns_table_);
 url_patterns_frame_->setLayout(url_patterns_layout_);

 qtw_->addTab(url_patterns_frame_, "URL Patterns");

 url_patterns_table_->setColumnCount(4);
 url_patterns_table_->setRowCount(0);

 // // urlChanged!.*www.google.com/maps/place/([\w+]+) <QString-> PN:`.1
 url_patterns_table_->setHorizontalHeaderLabels({"Pettern Expression", "C++ Procedure", "Arguments", ""});

 url_patterns_table_->setColumnWidth(0, 130);
// url_patterns_table_->setSt

 url_patterns_table_->setColumnWidth(3, 150);
// url_patterns_table_->setColumnWidth(4, 50);
// url_patterns_table_->setColumnWidth(5, 60);


 url_patterns_table_->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

 add_fixed_url_pattern("contextMenu!.*www.google.com/maps/place/([\\w+]+)", "map_places",
   "<QString-> `.1");

 QHBoxLayout* add_row_layout = new QHBoxLayout;
 QPushButton* add_row_button = new QPushButton("Add", this);
 add_row_layout->addStretch();
 add_row_layout->addWidget(add_row_button);
 add_row_layout->addStretch();

 url_patterns_layout_->addLayout(add_row_layout);

 connect(add_row_button, &QPushButton::clicked,
   [this]()
   {
    handle_add_url_patterns_row();
   });


 url_patterns_layout_->addStretch();

// url_patterns_table_->horizontalHeaderItem(3)->set



 main_layout_->addWidget(qtw_);

 button_box_ = new QDialogButtonBox(this);

 //?url_label_ = new QLabel(this);
  //?url_label_->setText(url);

// name_qle_ = new QLineEdit(this);

 button_ok_ = new QPushButton("OK");
 //? button_proceed_ = new QPushButton("Proceed");
 button_cancel_ = new QPushButton("Cancel");

 button_ok_->setDefault(false);
 button_ok_->setAutoDefault(false);

 //?button_proceed_->setDefault(false);
 //?button_proceed_->setAutoDefault(false);

 button_cancel_->setDefault(true);

 button_ok_->setStyleSheet(basic_button_style_sheet_());
 button_cancel_->setStyleSheet(basic_button_style_sheet_());


 //?button_ok_->setEnabled(false);

 button_box_->addButton(button_ok_, QDialogButtonBox::AcceptRole);
 //?button_box_->addButton(button_proceed_, QDialogButtonBox::ApplyRole);
 button_box_->addButton(button_cancel_, QDialogButtonBox::RejectRole);


 //?connect(button_proceed_, SIGNAL(clicked()), this, SLOT(proceed()));
 connect(button_box_, SIGNAL(accepted()), this, SLOT(accept()));
 connect(button_box_, SIGNAL(rejected()), this, SLOT(close()));

 main_layout_->addWidget(button_box_);

 setLayout(main_layout_);

 //->setCentralWidget(qtw);
 //mw->setGeometry(5,50,900,650);

 //wev->show();
 this->show();

}


WebGL_View_Dialog::~WebGL_View_Dialog()
{

}

void WebGL_View_Dialog::set_context_menu_provider(Context_Menu_Provider *context_menu_provider)
{
 context_menu_provider_ = context_menu_provider;
 wev_->set_context_menu_provider(context_menu_provider_);
 context_menu_provider_->url_patterns() = url_patterns_;
}

void WebGL_View_Dialog::add_fixed_url_pattern(QString pattern,
  QString procedure, QString arguments)
{
 url_patterns_.push_back({{"pattern", pattern}, {"procedure", procedure},
   {"arguments", arguments} });
 int rc = url_patterns_table_->rowCount();
 url_patterns_table_->insertRow(rc);

 for(int i = 0; i < 3; ++i)
 {
  QTableWidgetItem* twi = new QTableWidgetItem();
  url_patterns_table_->setItem(rc, i, twi);
  twi->setFlags(twi->flags() & (~ (Qt::ItemIsEditable | Qt::ItemIsSelectable)));
  switch (i)
  {
  case 0: twi->setText(pattern); break;
  case 1: twi->setText(procedure); break;
  case 2: twi->setText(arguments); break;
  }
 }

}


void WebGL_View_Dialog::handle_add_url_patterns_row()
{
 url_patterns_.push_back({});
 int rc = url_patterns_table_->rowCount();
 url_patterns_table_->insertRow(rc);

 QPushButton* edit_row_button = new QPushButton("Edit", this);
 edit_row_button->setMaximumWidth(45);
 edit_row_button->setMaximumHeight(20);

 connect(edit_row_button, &QPushButton::clicked,
  [this, rc](){ handle_edit_url_patterns_row(rc); });

 QPushButton* save_row_button = new QPushButton("Save", this);

 save_row_button->setMaximumWidth(45);
 save_row_button->setMaximumHeight(20);

 connect(save_row_button, &QPushButton::clicked,
  [this, rc](){ handle_save_url_patterns_row(rc); });

 QPushButton* cancel_remove_row_button = new QPushButton("Remove", this);
 connect(cancel_remove_row_button, &QPushButton::clicked,
  [this, rc](){ handle_cancel_remove_url_patterns_row(rc); });

 cancel_remove_row_button->setMaximumWidth(45);
 cancel_remove_row_button->setMaximumHeight(20);

 QWidget* cell_widget = new QWidget(this);
 QHBoxLayout* cell_widget_layout = new QHBoxLayout;//(cell_widget);
// QHBoxLayout* cell_widget_vlayout = new QHBoxLayout;//(cell_widget);

 cell_widget_layout->addStretch();
 cell_widget_layout->addWidget(edit_row_button);
 cell_widget_layout->addWidget(save_row_button);
 cell_widget_layout->addWidget(cancel_remove_row_button);
 cell_widget_layout->addStretch();
 cell_widget_layout->setAlignment(Qt::AlignCenter); //set Alignment layout
 cell_widget_layout->setContentsMargins(0,0,0,0);
 cell_widget->setLayout(cell_widget_layout);
 url_patterns_table_->setCellWidget(rc, 3, cell_widget);



// url_patterns_table_->item(rc, 5)->setTextAlignment(Qt::AlignHCenter | Qt::AlignCenter);
// cancel_remove_row_button->setStyleSheet( "text-align: center; margin-left:50%; margin-right:50%;" );

for(int i = 0; i < 3; ++i)
 {
  QTableWidgetItem* twi = new QTableWidgetItem();
  url_patterns_table_->setItem(rc, i, twi);
  twi->setFlags(twi->flags() & (~ (Qt::ItemIsEditable | Qt::ItemIsSelectable)));
 }


}


void WebGL_View_Dialog::handle_edit_url_patterns_row(int rc)
{
 qDebug() << "rc = " << rc;

 for(int i = 0; i < 3; ++i)
 {
  QTableWidgetItem* twi = url_patterns_table_->item(rc, i);
  twi->setFlags(twi->flags() | (Qt::ItemIsEditable | Qt::ItemIsSelectable));
 }

// QTableWidgetItem* twi = url_patterns_table_->item(rc, 5);
 qobject_cast<QPushButton*>(url_patterns_table_->cellWidget(rc, 5))->setText("Cancel");
}

void WebGL_View_Dialog::handle_cancel_remove_url_patterns_row(int rc)
{
 QString text = qobject_cast<QPushButton*>(url_patterns_table_->cellWidget(rc, 5))->text();
 if(text == "Cancel")
 {
  for(int i = 0; i < 3; ++i)
  {
   QTableWidgetItem* twi = url_patterns_table_->item(rc, i);
   twi->setFlags(twi->flags() & (~ (Qt::ItemIsEditable | Qt::ItemIsSelectable)));
  }
 }
 else if(text == "Remove")
 {
  url_patterns_.remove(rc);
  url_patterns_table_->removeRow(rc);
  Q_EMIT url_patterns_changed();
 }
}


void WebGL_View_Dialog::handle_save_url_patterns_row(int rc)
{
 for(int i = 0; i < 3; ++i)
 {
  QTableWidgetItem* twi = url_patterns_table_->item(rc, i);
  twi->setFlags(twi->flags() & (~ (Qt::ItemIsEditable | Qt::ItemIsSelectable)));
 }

 url_patterns_[rc]["pattern"] = url_patterns_table_->item(rc, 0)->text();
 url_patterns_[rc]["procedure"] = url_patterns_table_->item(rc, 1)->text();
 url_patterns_[rc]["arguments"] = url_patterns_table_->item(rc, 2)->text();

 qobject_cast<QPushButton*>(url_patterns_table_->cellWidget(rc, 5))->setText("Remove");

 Q_EMIT url_patterns_changed();
}



