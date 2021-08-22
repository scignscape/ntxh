
#include "rpdf-web-engine-view.h"

//#include "context-menu-provider.h"
//#include "url-or-event-pattern.h"

#include <QDialog>
#include <QTimer>

#include <QScreen>
#include <QWebEngineSettings>

#include <QAbstractScrollArea>
#include <QScrollBar>

#include <QOpenGLWidget>

// //  note: in case there is a need to inspect the QWebEngineView
 //    parent classes ...
 //    #include "render_widget_host_view_qt_delegate_widget.h"

#include <QLayout>

RPDF_Web_Engine_View::RPDF_Web_Engine_View(QDialog* parent_dialog)
 :  QWebEngineView(), parent_dialog_(parent_dialog), context_menu_provider_(nullptr),
    scroll_container_(nullptr)
{
 sec  =  nullptr;

 QApplication::instance()->installEventFilter(this);
 setMouseTracking(true);

 connect(this, &QWebEngineView::loadFinished, [this](bool ok)
 {
  if(ok)
  {
   QSize qs = page()->contentsSize().toSize();
   if(!qs.isEmpty())
     resize(qs);
  }
 });
}

bool RPDF_Web_Engine_View::eventFilter(QObject *object, QEvent *event)
{
// if(page())
// {
//  if(page()->settings())
//    page()->settings()->setAttribute(QWebEngineSettings::ShowScrollBars, false);
// }

 if (object->parent() == this && event->type() == QEvent::MouseButtonPress)
 {
  QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
  Qt::MouseButton mb = mouseEvent->button();

  if(mb == Qt::RightButton)
  {
   QPoint qp = mouseEvent->globalPos();

   QTimer::singleShot(250, [this, qp]
   {
    Context_Menu_Info* cmi = context_menu_info_.value({qp.x(), qp.y()});
    generate_context_menu(qp, (n8) this, cmi);
   });
   event->ignore();
  }
 }
 return false;
}

void RPDF_Web_Engine_View::grab_snapshot(QWidget* full_size)
{
 // //  full_size is only non-null if user explicitly requests
  //    complete image; otherwise assume user wants image
  //    from the visible part of the view, inside the
  //    scroll container's viewport.
 if(!full_size)
   full_size = scroll_container_->viewport();

 QPixmap pm = full_size->grab();

 QString path = SCREENSHOTS_FOLDER "/iat-chasm.png";
 qDebug() << "Saving to path: " << path;

 QFile file(path);
 if(file.open(QIODevice::WriteOnly))
 {
  pm.save(&file, "PNG");
 }
 file.close();

 Q_EMIT snapshot_saved(path);
}


void RPDF_Web_Engine_View::generate_context_menu(const QPoint& pos,
  n8 origin, Context_Menu_Info* cmi, QMouseEvent* mev)
{
 QWidget* origin_widget = nullptr;

 if(origin != (n8) this)
 {
  origin_widget = (QWidget*) origin;
  // //
 }

 QMenu* menu = new QMenu(this);
 menu->addAction("2D Snapshot", [this]()
 {
  grab_snapshot();
 });

 menu->addAction("2D Snapshot (full size)", [this]()
 {
  QLayout* lay = layout();
  QWidget* child = nullptr;
  for (int i = 0; i < lay->count(); ++i)
  {
   child = qobject_cast<QWidget*>(lay->itemAt(i)->widget());
   if(child)
   {
    // There should be only one QWidget under QWebEngineView, but break just in case
    break;
   }
  }
//  if(child)
//    grab_snapshot(child);
//  else
    grab_snapshot(this);
 });

 menu->popup(pos);
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


 void RPDF_Web_Engine_View::mouseReleaseEvent(QMouseEvent* mouseEvent)
 {
  mouseEvent->ignore();
 }


 void RPDF_Web_Engine_View::mousePressEvent(QMouseEvent* mev)
 {
  Qt::MouseButton mb = mev->button();

  if(mb == Qt::RightButton)
  {
   qDebug() << "internal ... ";
   generate_context_menu(mev->globalPos(), (n8) this, nullptr, mev);
   mev->accept();
  }
  else
  mev->ignore();

  // qDebug() << "mb = " << mb;

  // const QWebEngineContextMenuData& cd = page()->contextMenuData();

  // QString url = page()->url().toString();

  // if(url.isEmpty())
  // {
  //  QMenu* menu = new QMenu(this);//
  //  menu->addAction("Test ...");
  //  menu->popup(mouseEvent->globalPos());

  // }
  // else
  // {
  //  mouseEvent->ignore();
  // }

  // QMenu* menu = new QMenu(this);//
  // menu->popup(event->globalPos());

 }

 void RPDF_Web_Engine_View::contextMenuEvent(QContextMenuEvent* event)
 {
  const QWebEngineContextMenuData& cd = page()->contextMenuData();

  QPoint qp = event->globalPos();

  static QMap<QWebEngineContextMenuData::MediaType, QString> media_types {
   { QWebEngineContextMenuData::MediaTypeNone, "None" },
   { QWebEngineContextMenuData::MediaTypeVideo, "Video" },
   { QWebEngineContextMenuData::MediaTypeAudio, "Audio" },
   { QWebEngineContextMenuData::MediaTypeCanvas, "Canvas" },
   { QWebEngineContextMenuData::MediaTypeFile, "File" },
   { QWebEngineContextMenuData::MediaTypePlugin, "Plugin" },
  };

  Context_Menu_Info* cmi = new Context_Menu_Info({
   {{"selected-text", cd.selectedText()},
    {"link-text", cd.linkText()},
    {"link-url", cd.linkUrl().toString()},
    {"media-type", media_types.value(cd.mediaType())}
   },
   {
    {"media-flags", (n8) cd.mediaFlags()},
    {"edit-flags", (n8) cd.editFlags()},
    {"generic-flags", (n8) cd.isValid() + ((n8)cd.isContentEditable() << 1)}
   }});

  context_menu_info_[{qp.x(), qp.y()}] = cmi;
 }

