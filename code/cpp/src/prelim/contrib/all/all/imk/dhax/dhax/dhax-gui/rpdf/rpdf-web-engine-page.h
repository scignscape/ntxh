
#ifndef RPDF_WEB_ENGINE_PAGE__H
#define RPDF_WEB_ENGINE_PAGE__H

#include <QWebEngineView>
#include <QMainWindow>
#include <QApplication>
#include <QTabWidget>
#include <QWebChannel>
#include <QWebEnginePage>
#include <QContextMenuEvent>
#include <QMenu>
#include <QWebEngineContextMenuData>

//class NavigationRequestInterceptor;
class NavigationRequestInterceptor : public QWebEnginePage
{
 QWebEnginePage* target;
public:
 NavigationRequestInterceptor(QWebEnginePage* parent);
 bool acceptNavigationRequest(const QUrl &url, NavigationType type,
                              bool isMainFrame) Q_DECL_OVERRIDE;
};


class RPDF_Web_Engine_Page : public QWebEnginePage
{
 Q_OBJECT

 QString last_youtube_link_;

public:
 RPDF_Web_Engine_Page();
 RPDF_Web_Engine_Page(RPDF_Web_Engine_Page* parent);

 bool acceptNavigationRequest(const QUrl &url, NavigationType type,
                              bool isMainFrame) override;

 NavigationRequestInterceptor*
 createWindow(QWebEnginePage::WebWindowType type) override;

 void emit_navRequest(const QUrl &url);

 void reset_last_youtube_link(const QUrl &url);

 QString last_youtube_link_as_non_embed();

Q_SIGNALS:

 void navRequest(const QUrl &url);

};

#endif
