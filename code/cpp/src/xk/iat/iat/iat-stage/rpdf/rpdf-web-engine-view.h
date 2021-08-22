
#ifndef RPDF_WEB_ENGINE_VIEW__H
#define RPDF_WEB_ENGINE_VIEW__H

#include <QWebEngineView>
#include <QMainWindow>
#include <QApplication>
#include <QTabWidget>
#include <QWebChannel>
#include <QWebEnginePage>
#include <QContextMenuEvent>
#include <QMenu>
#include <QWebEngineContextMenuData>
#include <QScrollArea>

#include "accessors.h"

#include "global-types.h"

// //class NavigationRequestInterceptor;
//class NavigationRequestInterceptor : public QWebEnginePage
//{
// QWebEnginePage* target;
//public:
// NavigationRequestInterceptor(QWebEnginePage* parent);
// bool acceptNavigationRequest(const QUrl &url, NavigationType type,
//                              bool isMainFrame) Q_DECL_OVERRIDE;
//};

class Context_Menu_Provider;
class Pattern_Matcher_Runtime;


class RPDF_Web_Engine_View : public QWebEngineView
{
 Q_OBJECT


 Context_Menu_Provider* context_menu_provider_;
 Pattern_Matcher_Runtime* pm_runtime_;

 QDialog* parent_dialog_;

 struct Context_Menu_Info
 {
  QMap<QString, QString> string_info_;
  QMap<QString, n8> flags_info_;
 };

 QMap<QPair<int, int>, Context_Menu_Info*> context_menu_info_;

 QScrollArea* scroll_container_;

public:

 RPDF_Web_Engine_View(QDialog* parent_dialog);

 ACCESSORS(Context_Menu_Provider* ,context_menu_provider)
 ACCESSORS(Pattern_Matcher_Runtime* ,pm_runtime)

 ACCESSORS(QScrollArea* ,scroll_container)

 RPDF_Web_Engine_View* sec;

 bool eventFilter(QObject *object, QEvent *event) override;


 void contextMenuEvent(QContextMenuEvent *event) override;

 //?    MyWebView* createWindow(QWebEnginePage::WebWindowType type) override;
 void check_sec();

 void check_url_patterns(QString url);

 void generate_context_menu(const QPoint& pos, n8 origin,
   Context_Menu_Info* cmi, QMouseEvent* mev = nullptr);

 void mousePressEvent(QMouseEvent* mouseEvent) Q_DECL_OVERRIDE;
 void mouseReleaseEvent(QMouseEvent* mouseEvent) Q_DECL_OVERRIDE;

 void grab_snapshot(QWidget* full_size = nullptr);

Q_SIGNALS:

 void snapshot_saved(QString file_path);

};


#endif
