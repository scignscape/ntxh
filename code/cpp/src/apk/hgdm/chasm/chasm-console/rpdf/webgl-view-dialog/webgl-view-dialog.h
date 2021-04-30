
#ifndef WEBGL_VIEW_DIALOG__H
#define WEBGL_VIEW_DIALOG__H

#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QDialog>

#include <QTabWidget>

#include "rpdf-web-engine-view.h"
#include "rpdf-web-engine-page.h"
#include "my-page.h"


class WebGL_View_Dialog : public QDialog
{
 Q_OBJECT

 //Fore_Geometric1D_Panel fore_panel_;
 QDialogButtonBox* button_box_;
 QPushButton* button_ok_;
 QPushButton* button_cancel_;
 QVBoxLayout* main_layout_;

 RPDF_Web_Engine_View* wev_;
 //wev->setGeometry(0,0,700,600);

 QWebEngineView* iwev_;

//?
 RPDF_Web_Engine_Page* wep_;
 MyPage* myp_;

 QTabWidget* qtw_;

public:


 WebGL_View_Dialog(QWidget* parent);
 ~WebGL_View_Dialog();

};

#endif
