
#ifndef WEBGL_VIEW_DIALOG__H
#define WEBGL_VIEW_DIALOG__H

#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QDialog>

#include <QTableWidget>
#include <QFrame>

#include <QTabWidget>

#include "rpdf-web-engine-view.h"
#include "rpdf-web-engine-page.h"
#include "my-page.h"

#include "accessors.h"

class Context_Menu_Provider;

class WebGL_View_Dialog : public QDialog
{
 Q_OBJECT

 Context_Menu_Provider* context_menu_provider_;

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

 QFrame* url_patterns_frame_;
 QTableWidget* url_patterns_table_;
 QVBoxLayout* url_patterns_layout_;

 QVector<QMap<QString, QString>> url_patterns_;

 void add_fixed_url_pattern(QString pattern,
   QString procedure, QString arguments);

public:


 WebGL_View_Dialog(QWidget* parent);
 ~WebGL_View_Dialog();

 ACCESSORS__RGET(MACRO_PASTE( QVector<QMap<QString, QString>> ) ,url_patterns)

 ACCESSORS__SDECLARE(Context_Menu_Provider* ,context_menu_provider)

 ACCESSORS(RPDF_Web_Engine_View* ,wev)

 void handle_edit_url_patterns_row(int rc);
 void handle_save_url_patterns_row(int rc);
 void handle_cancel_remove_url_patterns_row(int rc);
 void handle_add_url_patterns_row();

 void check_url_patterns(QString url);


Q_SIGNALS:

 void url_patterns_changed();

 void url_pattern_match(QString procedure_name, QString arguments);


};

#endif
