
#include "rpdf-web-engine-view.h"

#include "context-menu-provider.h"

#include "url-or-event-pattern.h"

#include <QDialog>

#include <QThread>

#include <QTimer>


RPDF_Web_Engine_View::RPDF_Web_Engine_View(QDialog* parent_dialog)
  :  QWebEngineView(), parent_dialog_(parent_dialog), context_menu_provider_(nullptr)
{
 current_mouse_event_ = nullptr;
 current_context_menu_event_ = nullptr;

 sec  =  nullptr;

 QApplication::instance()->installEventFilter(this);
 setMouseTracking(true);

// setContextMenuPolicy(Qt::CustomContextMenu);
// connect(this, &QWidget::customContextMenuRequested,
//         [](const QPoint &pos)
// {
//  qDebug() << "pos = " << pos;
// });
}

void RPDF_Web_Engine_View::run_shot_context_menu(const QPoint& pos)
{
 QMenu* menu = new QMenu(this);//

 menu->addAction("Annotate (2D)", [this]
 {
  qDebug() << "annotate ...";
 });

 menu->addAction("Save (2D)", [this]
 {
  qDebug() << "save ...";
 });

 menu->popup(pos);

}

bool RPDF_Web_Engine_View::eventFilter(QObject *object, QEvent *event)
{
 static int count = 0;
 if (object->parent() == this && event->type() == QEvent::MouseMove)
 {
             mouseMoveEvent(static_cast<QMouseEvent *>(event));
 }
 if (object->parent() == this)
  //&& event->type() == QEvent::MouseButtonRelease)
 {

  if(event->type() == QEvent::MouseButtonPress)
  {
   QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

   if(mouseEvent->button() == Qt::RightButton)
   {
    qDebug() << "====";
    qDebug() << mouseEvent->button();

//    if(current_mouse_event_)
//    {
//     current_mouse_event_ = nullptr;
//     return true;
//     //    QThread * th = QThread::currentThread();
//     //    th->sleep(11);
//    }

    QPoint pos = mapToGlobal(mouseEvent->pos());

    qDebug() << "pos = " << pos;

    QTimer::singleShot(1000, this, [this, pos] ()
    {
     qDebug() << "pos = " << pos;

     if(current_context_menu_event_)
     {
      current_context_menu_event_ = nullptr;
     }
     else
     {
      run_shot_context_menu(pos);
     }
    });

//    current_mouse_event_ = mouseEvent;
//    QApplication::sendEvent(object, event);
    return false;



//    return true;
   }
  }
  if(event->type() == QEvent::MouseButtonRelease)
  {
   QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

   if(mouseEvent->button() == Qt::RightButton)
   {
    qDebug() << "----";
    qDebug() << mouseEvent->button();
   }
  }
  if(event->type() == QEvent::NonClientAreaMouseButtonPress)
  {
   QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
   qDebug() << mouseEvent->button() << "NonClientAreaMouseButtonPress";
  }
  if(event->type() == QEvent::NonClientAreaMouseButtonRelease)
  {
   QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
   qDebug() << mouseEvent->button();
   qDebug() << mouseEvent->button() << "NonClientAreaMouseButtonRelease";
  }


  //           mouseMoveEvent(static_cast<QMouseEvent *>(event));
 }

 return false;
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

void RPDF_Web_Engine_View::contextMenuEvent(QContextMenuEvent* event)
{
 //
 current_context_menu_event_ = event;

 qDebug()<< "event->reason()";
 qDebug()<< event->reason();

 event->type() == QEvent::ContextMenu;

 QWebEngineContextMenuData cd = page()->contextMenuData();

 QString url = page()->url().toString();

 QVector<Pattern_Matcher_Runtime::Action_Info> info;

 auto check = [this, &event](QString& args)
 {
  args.replace("$winid$", QString::number(parent_dialog_->winId()));
  args.replace("$gx$", QString::number(event->globalX()));
  args.replace("$gy$", QString::number(event->globalY()));
 };

 if(cd.linkUrl().isEmpty())
   pm_runtime_->check_url_patterns(
     URL_Or_Event_Pattern::Pattern_Contexts::Context_Menu_Formation, url, info, check);

 else
   pm_runtime_->check_url_patterns(
     URL_Or_Event_Pattern::Pattern_Contexts::Link_Context_Menu_Formation,
     cd.linkUrl().toString(), info, check, cd.linkText());

 QMenu* menu = new QMenu(this);//

 for(Pattern_Matcher_Runtime::Action_Info& ai : info)
 {
  menu->addAction(ai.option_label, [this, ai]
  {
   context_menu_provider_->run_callback(ai);
  });
  qDebug() << ai.option_label;
 }

// if(info.isEmpty())
// {
//  menu->addAction("Review Matterport Tags");
//  menu->addAction("Launch Tag Dialog");
//  menu->addAction("View Sensor Data");
//  menu->addAction("View Pattern Match Data");
// }


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

