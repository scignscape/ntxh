
#include "rpdf-web-engine-page.h"


NavigationRequestInterceptor::NavigationRequestInterceptor(QWebEnginePage*
                                                           parent)
 : QWebEnginePage(parent)
{
 target = parent;
}

bool NavigationRequestInterceptor::acceptNavigationRequest(const QUrl
                                                           &url, NavigationType type, bool isMainFrame)
{
 qDebug() << "acceptNavigationRequest called. type=" << type <<
             "isMainFrame=" << isMainFrame;

 qDebug() << "acceptNavigationRequest called. url=" << url.toString();

 //    MyWebPage *page = dynamic_cast<MyWebPage*>(target);
 //    if (/*isMainFrame && */type == NavigationTypeLinkClicked && page)
 //        Q_EMIT page->urlClicked(url);
 //    else
 //        target->load(url);

 return false;
}

//and then you return an instance of that in createWindow

//QWebEngineView*WebEngineView::createWindow(QWebEnginePage::WebWindowType type)
//{
//    Q_UNUSED(type);

//    qDebug() << "createWindow called, returning NavigationRequestInterceptor";
//    WebEngineView *result = new WebEngineView();
//    result->setPage(new NavigationRequestInterceptor(this->page()));
//    return result;
//}



RPDF_Web_Engine_Page::RPDF_Web_Engine_Page() : QWebEnginePage()
{

}

RPDF_Web_Engine_Page::RPDF_Web_Engine_Page(RPDF_Web_Engine_Page* parent) : QWebEnginePage(parent)
{

}

//RPDF_Web_Engine_Page::RPDF_Web_Engine_Page():QWebEngineView()
//{
// sec  =  nullptr;
//}
//class MyPage : public QObject
//{
//public:
// MyPage();


//};
//MyPage::MyPage():QObject()
//{

//}

//MyWebPage* MyWebPage::createWindow(WebWindowType type)
//{
//    qDebug()  << "WebWindowType" << type;

// return nullptr;
//}

NavigationRequestInterceptor*
RPDF_Web_Engine_Page::createWindow(QWebEnginePage::WebWindowType type)
{
 qDebug()  << "WebWindowType" << type;

 qDebug() << "createWindow called, returningNavigationRequestInterceptor";

 NavigationRequestInterceptor *result = new NavigationRequestInterceptor(this);
 //result->setPage(new NavigationRequestInterceptor(this->page()));
 return result;

}

//MyWebView* MyWebView::createWindow(QWebEnginePage::WebWindowType type)
//{
//    qDebug()  << "WebWindowType" << type;

//        qDebug() << "createWindow called, returningNavigationRequestInterceptor";

//        qDebug()  << "r" << this->page()->requestedUrl().toString();


//        MyWebView *result = new MyWebView();
//        result->setPage(new NavigationRequestInterceptor(this->page()));
//        return result;

////    sec = new MyWebView;

////    connect(sec, &QWebEngineView::loadFinished, [this](bool b)
////    {
////        qDebug()  << "Web::: " << sec->page()->url();
////    });

////check_sec();
//// return sec;
//}


bool RPDF_Web_Engine_Page::acceptNavigationRequest(const QUrl &url,
                                                   NavigationType type, bool isMainFrame)
{
 //?
 qDebug()  << "url" << url;
 if (type == QWebEnginePage::NavigationTypeLinkClicked)
 {
  //?        qDebug() << url;
 }
 return true;
 // return false;
}


