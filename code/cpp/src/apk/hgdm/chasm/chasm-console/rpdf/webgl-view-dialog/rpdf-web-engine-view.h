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

////class NavigationRequestInterceptor;
//class NavigationRequestInterceptor : public QWebEnginePage
//{
// QWebEnginePage* target;
//public:
// NavigationRequestInterceptor(QWebEnginePage* parent);
// bool acceptNavigationRequest(const QUrl &url, NavigationType type,
//                              bool isMainFrame) Q_DECL_OVERRIDE;
//};


class RPDF_Web_Engine_View : public QWebEngineView
{
public:
 RPDF_Web_Engine_View();

 RPDF_Web_Engine_View* sec;

 void contextMenuEvent(QContextMenuEvent *event) override;
 //?    MyWebView* createWindow(QWebEnginePage::WebWindowType type) override;
 void check_sec();

};


#endif
