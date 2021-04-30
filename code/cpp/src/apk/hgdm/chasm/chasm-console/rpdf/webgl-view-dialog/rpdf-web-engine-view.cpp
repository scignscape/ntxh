
#include "rpdf-web-engine-view.h"

RPDF_Web_Engine_View::RPDF_Web_Engine_View():QWebEngineView()
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
 QMenu* menu = page()->createStandardContextMenu();

 for(QAction* a : menu->actions())
 {
  qDebug()<< a->text();
 }

 QWebEngineContextMenuData cd = page()->contextMenuData();

 qDebug() << "ST:" << cd.selectedText();
 qDebug() << "LT:" << cd.linkText();
 qDebug() << "LU:" << cd.linkUrl().toString();
 qDebug() << "mT:" << cd.mediaType();
 qDebug() << "mU:" << cd.mediaUrl().toString();

 menu->popup(event->globalPos());

}

