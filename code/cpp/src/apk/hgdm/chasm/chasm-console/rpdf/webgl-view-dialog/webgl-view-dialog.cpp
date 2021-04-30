
#include "webgl-view-dialog.h"

#include <QPushButton>
#include <QTabBar>

#include "styles.h"


WebGL_View_Dialog::WebGL_View_Dialog(QWidget* parent)
  :  QDialog(parent)
{
 main_layout_ = new QVBoxLayout;
 wev_ = new RPDF_Web_Engine_View();
 //wev->setGeometry(0,0,700,600);

//?
 wep_ = new RPDF_Web_Engine_Page;

 QObject::connect(wep_, &RPDF_Web_Engine_Page::urlChanged,[](const QUrl &url){
  qDebug() << "r:" << url.toString();
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
 //wep_->load(QUrl("file:///" + url));

 wep_->load(QUrl("https://www.google.com/maps/place/Philadelphia,+PA/@39.9558052,-75.1581506,13.75z/data=!4m5!3m4!1s0x89c6b7d8d4b54beb:0x89f514d88c3e58c1!8m2!3d39.9525839!4d-75.1652215"));

 qtw_ = new QTabWidget(this);
 qtw_->addTab(wev_, "Tour");

 iwev_ = new QWebEngineView(this);
 iwev_->page()->load(QUrl("https://matterport.com/"));
 qtw_->addTab(iwev_, "Matterport Info");

 qtw_->tabBar()->setShape(QTabBar::TriangularNorth);
 //?
 qtw_->setStyleSheet(tab_style_sheet_());

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

