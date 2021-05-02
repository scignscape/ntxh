
#include "rpdf-web-engine-view.h"

#include "context-menu-provider.h"

RPDF_Web_Engine_View::RPDF_Web_Engine_View()
  :  QWebEngineView(), context_menu_provider_(nullptr)
{
 sec  =  nullptr;
}

void RPDF_Web_Engine_View::check_sec()
{
 if(sec)
 {
  qDebug()  << "sec: "  <<   sec->page()->url().toString();
 }
 else
 {
  qDebug()  << "xsec";
 }
}

void RPDF_Web_Engine_View::contextMenuEvent(QContextMenuEvent *event)
{
 //
 qDebug()<< "event->reason()";
 qDebug()<< event->reason();

 QWebEngineContextMenuData cd = page()->contextMenuData();

 QString url = page()->url().toString();

 QVector<Context_Menu_Provider::Action_Info> info;

 context_menu_provider_->check_url_patterns(url.prepend("contextMenu!"), info);

 QMenu* menu = new QMenu(this);//

 for(Context_Menu_Provider::Action_Info& ai : info)
 {
  menu->addAction(ai.option_label, [this, &ai]
  {
   context_menu_provider_->run_callback(ai);
  });
  qDebug() << ai.option_label;
 }


//   page()->createStandardContextMenu();

// for(QAction* a : menu->actions())
// {
//  qDebug()<< a->text();
// }

// QWebEngineContextMenuData cd = page()->contextMenuData();

// QUrl test = //cd.d->frameUrl();
//   cd.frameUrl();


 if(this->url().toString().contains("www.google.com/maps/place"))
 {
  qDebug() << "TU:" << this->url().toString();
  qDebug() << "TU:" << this->page()->url().toString();
 }


// qDebug() << "ST:" << cd.selectedText();

// if(!cd.linkText().isEmpty())
//   qDebug() << "LT:" << cd.linkText();

// if(!cd.linkUrl().isEmpty())
//   qDebug() << "LU:" << cd.linkUrl().toString();

// qDebug() << "mT:" << cd.mediaType();
// qDebug() << "mU:" << cd.mediaUrl().toString();


// menu->addAction("Test");

 menu->popup(event->globalPos());

}

