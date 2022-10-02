
#include "MapGraphicsView.h"

#include <QVBoxLayout>
#include <QTimer>
#include <QtDebug>
#include <cmath>
#include <QQueue>
#include <QSet>
#include <QWheelEvent>
#include <QCoreApplication>
#include <QThread>
#include <QMenu>

#include <QGuiApplication>

#include <QScreen>

#include <QDialog>

#include "guts/PrivateQGraphicsScene.h"
#include "guts/PrivateQGraphicsView.h"
#include "guts/Conversions.h"

#include "guts/CompositeTileSourceConfigurationWidget.h"

#include "qmt/main-window-controller.h"

#include "qmt/qmt-client-layer-base.h"
#include "qmt/qmt-client-context-menu-handler-base.h"
#include "qmt/qmt-client-location-focus-base.h"

#include "web-engine/qmt-web-engine-view.h"
#include "web-engine/qmt-web-engine-page.h"
#include "web-engine/qmt-my-page.h"

#include "global-types.h"


MapGraphicsView::MapGraphicsView(MapGraphicsScene *scene, QWidget *parent) :
  QWidget(parent), coords_notify_callback_(nullptr),
  qmt_client_location_focus_base_(nullptr)
{
 main_window_controller_ = new Main_Window_Controller(this);

 //Setup the given scene and set the default zoomLevel to 3
 this->setScene(scene);
 _zoomLevel = 2;

 setContextMenuPolicy(Qt::CustomContextMenu);

 connect(this, &QGraphicsView::customContextMenuRequested,
         [this](const QPoint& qp)
 {
  QMenu* menu = new QMenu;

  menu->addAction("Reset Map Style", [this, qp]()
  {
   main_window_controller_->reset_map_style(qp);
  });

  QStringList locs = qmt_client_location_focus_base_->get_short_choice_list();
  if(!locs.isEmpty())
  {
   QMenu* loc_menu = menu->addMenu("Reset Location");
   for(QString loc : locs)
   {
    QString text = loc; text.replace('$', ' ');
    loc_menu->addAction(text, [this, loc]
    {
     QString name = qmt_client_location_focus_base_->adopt_location(loc);
     if(!name.isEmpty() && coords_notify_callback_)
     {
      coords_notify_callback_({
        qmt_client_location_focus_base_->current_central_longitude(),
        qmt_client_location_focus_base_->current_central_latitude()});
     }
    });
   }

  };

  menu->addAction("Show Latitude/Longitude Coordinates", [this, qp]()
  {
   main_window_controller_->show_llcoords(qp);
  });

  menu->addAction("Load Single-File Data Set", [this, qp]()
  {
   main_window_controller_->load_single_file_data_set();
  });

  menu->addAction("Show/Hide Marking Outlines", [this, qp]()
  {
   main_window_controller_->toggle_marking_outline_visibility();
  });

  QMenu* dialogs =  menu->addMenu("Preview Dialogs");

  dialogs->addAction("Lanternfly Configuration", [this, qp]()
  {
   Q_EMIT preview_dialogs_requested("Lanternfly_Configuration_Dialog");
  });

  dialogs->addAction("Lanternfly Sighting", [this, qp]()
  {
   Q_EMIT preview_dialogs_requested("Lanternfly_Sighting_Dialog");
  });

  dialogs->addAction("Lanternfly Sighting Filter", [this, qp]()
  {
   Q_EMIT preview_dialogs_requested("Lanternfly_Sighting_Filter_Dialog");
  });

  menu->addAction("Activate Local Tile Server", [this, qp]()
  {
   main_window_controller_->activate_local_tile_server();
  });

  QString current_location_name = qmt_client_location_focus_base_->current_location_name();

  // //  a hack to demo switching between features for different locations.
  //    Presumably in production there would be a better way to
  //    map locations to context menu options
  if(current_location_name == "Bergen$County")
  {
   menu->addAction("Lookup Street Address", [this, qp]()
   {
    main_window_controller_->llcoords_to_street_address(qp);
   });

   menu->addAction("Load Bus Data", [this]()
   {
    main_window_controller_->load_bus_data();
   });

   menu->addAction("Find Bus Stops", [this, qp]()
   {
    //main_window_controller_->set_info_file("bus", "/home/nlevisrael/gits/acle/bus_data/stops.txt");
    QPointF ll = mapToScene(qp);
    main_window_controller_->find_bus_stops(ll.y(), ll.x());
   });

   menu->addAction("Show Bus Routes", [this, qp]()
   {
    QPointF ll = mapToScene(qp);
    u1 zl = zoomLevel();

    main_window_controller_->load_web_engine_view(QUrl("https://www.openstreetmap.org/#map=%1/%2/%3&layers=T"_qt
      .arg(zl).arg(ll.y()).arg(ll.x())));

   });
  }
  else if(current_location_name == "Kherson")
  {
   menu->addAction("Load Incident Reports", [this]()
   {
    main_window_controller_->load_incident_reports();
   });

   QMenu* menu1 = menu->addMenu("Track Incidents");

   menu1->addAction("From earliest", [this, qp]()
   {
    QPointF ll = mapToScene(qp);
    main_window_controller_->track_incidents(ll.y(), ll.x(), -1);
   });

   menu1->addAction("From latest", [this, qp]()
   {
    QPointF ll = mapToScene(qp);
    main_window_controller_->track_incidents(ll.y(), ll.x(), 1);
   });

  }

  menu->addAction("Take Screenshot", [this]()
  {
   QScreen* screen = QGuiApplication::primaryScreen();
   if (!screen)
    return;
   int target_window_id  = ((QWidget*)this->parent())->winId();

   QTimer::singleShot(10000, [=]
   {
    QPixmap pixmap = screen->grabWindow(target_window_id );
    QString path = SCREENSHOTS_FOLDER "/ss.png";
    qDebug() << "Saving to path: " << path;

    QFile file(path);
    if(file.open(QIODevice::WriteOnly))
    {
     pixmap.save(&file, "PNG");
    }
   });
  });

  menu->popup(this->mapToGlobal(qp));

//  QPointF coords = this->mapToScene(qp);

//  qDebug() << "qp = " << qp;

//  qDebug() << "coords = " << coords;

//  QPoint qp1 = this->map_ll_to_view(coords);

//  //  QPoint qp2 = _childView->mapFromScene(qp1);

//  qDebug() << "qp1 = " << qp1;


 }
 );

 //The default drag mode allows us to drag the map around to move the view
 this->setDragMode(MapGraphicsView::ScrollHandDrag);

 //Start the timer that will cause the tiles to periodically move to follow the view
 QTimer * renderTimer = new QTimer(this);
 connect(renderTimer,
         SIGNAL(timeout()),
         this,
         SLOT(renderTiles()));
 renderTimer->start(200);
}

MapGraphicsView::~MapGraphicsView()
{
 qDebug() << this << "Destructing";
 //When we die, take all of our tile objects with us...
 foreach(MapTileGraphicsObject * tileObject, _tileObjects)
 {
  if (!_childScene.isNull())
   _childScene->removeItem(tileObject);
  delete tileObject;
 }
 _tileObjects.clear();

 if (!_tileSource.isNull())
 {
  //Find the tileSource's thread
  QPointer<QThread> tileSourceThread = _tileSource->thread();

  /*
         Clear the QSharedPointer to the tilesource. Unless there's a serious problem, we should be the
         last thing holding that reference and we expect it to be deleted
        */
  _tileSource.clear();

  //After the tilesource is deleted, we wait for the thread it was running in to shut down
  int count = 0;
  const int maxCount = 100;
  while (!tileSourceThread.isNull() && !tileSourceThread->wait(100))
  {
   //We have to process events while it's shutting down in case it uses signals/slots to shut down
   //Hint: it does
   QCoreApplication::processEvents(QEventLoop::ExcludeSocketNotifiers | QEventLoop::ExcludeUserInputEvents);
   if(++count == maxCount)
    break;
  }
 }
}

void MapGraphicsView::set_qmt_client_data_set_base(QMT_Client_Data_Set_Base* qmt_client_data_set_base)
{
 //?qmt_client_data_set_base_ = qmt_client_data_set_base;
 main_window_controller_->push_data_set(qmt_client_data_set_base);
}

void MapGraphicsView::set_qmt_client_layer_base(QMT_Client_Layer_Base* qmt_client_layer_base)
{
 qmt_client_layer_base_ = qmt_client_layer_base;
 main_window_controller_->set_qmt_client_layer_base(qmt_client_layer_base_);
}

void MapGraphicsView::handle_context_menu(QGraphicsSceneContextMenuEvent* event, MapGraphicsObject* mgo)
{
 qmt_client_context_menu_handler_base_->handle_context_menu_on_mgo(event, mgo);
}

QPointF MapGraphicsView::center() const
{
 QPointF centerGeoPos = this->mapToScene(QPoint(this->width()/2,this->height()/2));
 return centerGeoPos;
}

void MapGraphicsView::centerOn(const QPointF &pos)
{
 if (_tileSource.isNull())
  return;

 //Find the QGraphicsScene coordinate of the position and then tell the childView to center there
 QPointF qgsPos = _tileSource->ll2qgs(pos,this->zoomLevel());

 _childView->centerOn(qgsPos);
}

QPointF MapGraphicsView::map_ll_to_scene(const QPointF &pos)
{
 if (_tileSource.isNull())
  return {};

 return _tileSource->ll2qgs(pos,this->zoomLevel());
}


QPoint MapGraphicsView::map_ll_to_view(const QPointF &pos)
{
 QPointF qp = map_ll_to_scene(pos);
 if(qp.isNull())
  return {};
 return _childView->mapFromScene(qp.toPoint());
}



void MapGraphicsView::centerOn(qreal longitude, qreal latitude)
{
 this->centerOn(QPointF(longitude,latitude));
}

void MapGraphicsView::centerOn(const MapGraphicsObject *item)
{
 if (item)
  this->centerOn(item->pos());
}

QPointF MapGraphicsView::mapToScene(const QPoint viewPos) const
{
 if (_tileSource.isNull())
 {
  qWarning() << "No tile source --- Transformation cannot work";
  return QPointF(0,0);
 }

 QPointF qgsScenePos = _childView->mapToScene(viewPos);

 //Convert from QGraphicsScene coordinates to geo (MapGraphicsScene) coordinates
 const quint8 zoom = this->zoomLevel();

 return _tileSource->qgs2ll(qgsScenePos,zoom);
}

MapGraphicsView::DragMode MapGraphicsView::dragMode() const
{
 return _dragMode;
}

void MapGraphicsView::setDragMode(MapGraphicsView::DragMode mode)
{
 _dragMode = mode;

 QGraphicsView::DragMode qgvDragMode;
 if (_dragMode == MapGraphicsView::NoDrag)
  qgvDragMode = QGraphicsView::NoDrag;
 else if (_dragMode == MapGraphicsView::ScrollHandDrag)
  qgvDragMode = QGraphicsView::ScrollHandDrag;
 else
  qgvDragMode = QGraphicsView::RubberBandDrag;

 if (_childView.isNull())
  return;

 _childView->setDragMode(qgvDragMode);
}

MapGraphicsScene *MapGraphicsView::scene() const
{
 return _scene;
}

void MapGraphicsView::setScene(MapGraphicsScene * scene)
{
 /*
      Create New Stuff
    */
 //Create a private QGraphicsScene that our (also private) QGraphicsView will use
 PrivateQGraphicsScene * childScene = new PrivateQGraphicsScene(scene,
                                                                this,
                                                                this);
 //The QGraphicsScene needs to know when our zoom level changes so it can notify objects
 connect(this,
         SIGNAL(zoomLevelChanged(quint8)),
         childScene,
         SLOT(handleZoomLevelChanged()));

 //Create a QGraphicsView that handles drawing for us
 PrivateQGraphicsView * childView = new PrivateQGraphicsView(childScene, this);
 connect(childView,
         SIGNAL(hadMouseDoubleClickEvent(QMouseEvent*)),
         this,
         SLOT(handleChildMouseDoubleClick(QMouseEvent*)));
 connect(childView,
         SIGNAL(hadMouseMoveEvent(QMouseEvent*)),
         this,
         SLOT(handleChildMouseMove(QMouseEvent*)));
 connect(childView,
         SIGNAL(hadMousePressEvent(QMouseEvent*)),
         this,
         SLOT(handleChildMousePress(QMouseEvent*)));
 connect(childView,
         SIGNAL(hadMouseReleaseEvent(QMouseEvent*)),
         this,
         SLOT(handleChildMouseRelease(QMouseEvent*)));
 connect(childView,
         SIGNAL(hadWheelEvent(QWheelEvent*)),
         this,
         SLOT(handleChildViewScrollWheel(QWheelEvent*)));
 connect(childView,
         SIGNAL(hadContextMenuEvent(QContextMenuEvent*)),
         this,
         SLOT(handleChildViewContextMenu(QContextMenuEvent*)));

 //Insert new stuff
 if (this->layout() != 0)
  delete this->layout();
 this->setLayout(new QVBoxLayout(this));
 this->layout()->addWidget(childView);
 // set resize anchor of child QGraphicsView to center so the center
 // position doesn't change when the view gets resized
 childView->setResizeAnchor(QGraphicsView::AnchorViewCenter);


 //Delete old stuff if applicable
 if (!_childView.isNull())
  delete _childView;
 if (!_childScene.isNull())
  delete _childScene;


 //Set new stuff
 _childView = childView;
 _childScene = childScene;
 _scene = scene;

 this->resetQGSSceneSize();

 //Reset the drag mode for the new child view
 this->setDragMode(this->dragMode());
}

QSharedPointer<MapTileSource> MapGraphicsView::tileSource() const
{
 return _tileSource;
}

void MapGraphicsView::setTileSource(QSharedPointer<MapTileSource> tSource)
{
 _tileSource = tSource;

 if (!_tileSource.isNull())
 {
  //Create a thread just for the tile source
  QThread * tileSourceThread = new QThread();
  tileSourceThread->start();
  _tileSource->moveToThread(tileSourceThread);

  //Set it up so that the thread is destroyed when the tile source is!
  connect(_tileSource.data(),
          SIGNAL(destroyed()),
          tileSourceThread,
          SLOT(quit()));
  connect(tileSourceThread,
          SIGNAL(finished()),
          tileSourceThread,
          SLOT(deleteLater()));
 }

 //Update our tile displays (if any) about the new tile source
 foreach(MapTileGraphicsObject* tileObject, _tileObjects)
  tileObject->setTileSource(tSource);
}

quint8 MapGraphicsView::zoomLevel() const
{
 return _zoomLevel;
}


void MapGraphicsView::force_reset()
{
 for(MapTileGraphicsObject* tileObject : _tileObjects)
  tileObject->reset_tile_source();

 setZoomLevel(_zoomLevel, Force_Reset);
}


void MapGraphicsView::setZoomLevel(quint8 nZoom, ZoomMode zMode)
{
 if (_tileSource.isNull())
  return;

 //This stuff is for handling the re-centering upong zoom in/out
 const QPointF  centerGeoPos = this->mapToScene(QPoint(this->width()/2,this->height()/2));
 QPointF mousePoint = _childView->mapToScene(_childView->mapFromGlobal(QCursor::pos()));
 QRectF sceneRect = _childScene->sceneRect();
 const float xRatio = mousePoint.x() / sceneRect.width();
 const float yRatio = mousePoint.y() / sceneRect.height();
 const QPointF centerPos = _childView->mapToScene(QPoint(_childView->width()/2,_childView->height()/2));
 const QPointF offset = mousePoint - centerPos;

 if(zMode != Force_Reset)
 {
  //Change the zoom level
  nZoom = qMin(_tileSource->maxZoomLevel(),qMax(_tileSource->minZoomLevel(),nZoom));
  if (nZoom == _zoomLevel)
   return;
 }

 _zoomLevel = nZoom;

 //Disable all tile display temporarily. They'll redisplay properly when the timer ticks
 //foreach(MapTileGraphicsObject * tileObject, _tileObjects)
 for(MapTileGraphicsObject* tileObject : _tileObjects)
 {
  //  if(zMode == Force_Reset)
  //  {
  //   delete tileObject;
  //  }
  //  else
  tileObject->setVisible(false);
 }

 //?
 // if(zMode == Force_Reset)
 //   _tileObjects.clear();

 //Make sure the QGraphicsScene is the right size
 this->resetQGSSceneSize();


 //Re-center the view where we want it
 sceneRect = _childScene->sceneRect();
 mousePoint = QPointF(sceneRect.width()*xRatio,
                      sceneRect.height()*yRatio) - offset;

 if ( (zMode == MouseZoom) || (zMode == Force_Reset) )
  _childView->centerOn(mousePoint);
 else
  this->centerOn(centerGeoPos);

 //Make MapGraphicsObjects update
 this->zoomLevelChanged(nZoom);
}

void MapGraphicsView::zoomIn(ZoomMode zMode)
{
 if (_tileSource.isNull())
  return;

 if (this->zoomLevel() < _tileSource->maxZoomLevel())
  this->setZoomLevel(this->zoomLevel()+1,zMode);
}

void MapGraphicsView::zoomOut(ZoomMode zMode)
{
 if (_tileSource.isNull())
  return;

 if (this->zoomLevel() > _tileSource->minZoomLevel())
  this->setZoomLevel(this->zoomLevel()-1,zMode);
}

void MapGraphicsView::rotate(qreal rotation)
{
 _childView->rotate(rotation);
}

//protected slot
void MapGraphicsView::handleChildMouseDoubleClick(QMouseEvent *event)
{
 event->setAccepted(false);
}

//protected slot
void MapGraphicsView::handleChildMouseMove(QMouseEvent* event)
{
 QPoint qp = event->pos();

 //? qDebug() << "qp = " << qp;

 QPointF coords = this->mapToScene(qp);

 //? qDebug() << "coords = " << coords;

 if(coords_notify_callback_)
   coords_notify_callback_(coords);


 event->setAccepted(false);
}

//protected slot
void MapGraphicsView::handleChildMousePress(QMouseEvent *event)
{
 event->setAccepted(false);
}

//protected slot
void MapGraphicsView::handleChildMouseRelease(QMouseEvent *event)
{
 event->setAccepted(false);
}

//protected slot
void MapGraphicsView::handleChildViewContextMenu(QContextMenuEvent *event)
{
 event->setAccepted(false);
}

//protected slot
void MapGraphicsView::handleChildViewScrollWheel(QWheelEvent *event)
{
 event->setAccepted(true);

 this->setDragMode(MapGraphicsView::ScrollHandDrag);
 if (event->delta() > 0)
  this->zoomIn(MouseZoom);
 else
  this->zoomOut(MouseZoom);
}

//private slot
void MapGraphicsView::renderTiles()
{
 if (_scene.isNull())
 {
  qDebug() << "No MapGraphicsScene to render";
  return;
 }

 if (_tileSource.isNull())
 {
  qDebug() << "No MapTileSource to render";
  return;
 }


 //Layout the tile objects
 this->doTileLayout();
}

//protected
void MapGraphicsView::doTileLayout()
{
 //Calculate the center point and polygon of the viewport in QGraphicsScene coordinates
 const QPointF centerPointQGS = _childView->mapToScene(_childView->width()/2.0,
                                                       _childView->height()/2.0);
 QPolygon viewportPolygonQGV;
 viewportPolygonQGV << QPoint(0,0) << QPoint(0,_childView->height()) << QPoint(_childView->width(),_childView->height()) << QPoint(_childView->width(),0);

 const QPolygonF viewportPolygonQGS = _childView->mapToScene(viewportPolygonQGV);
 const QRectF boundingRect = viewportPolygonQGS.boundingRect();

 //We exaggerate the bounding rect for some purposes!
 QRectF exaggeratedBoundingRect = boundingRect;
 exaggeratedBoundingRect.setSize(boundingRect.size()*2.0);
 exaggeratedBoundingRect.moveCenter(boundingRect.center());

 //We'll mark tiles that aren't being displayed as free so we can use them
 QQueue<MapTileGraphicsObject *> freeTiles;

 QSet<QPointF> placesWhereTilesAre;
 foreach(MapTileGraphicsObject * tileObject, _tileObjects)
 {
  if (!tileObject->isVisible() || !exaggeratedBoundingRect.contains(tileObject->pos()))
  {
   freeTiles.enqueue(tileObject);
   tileObject->setVisible(false);
  }
  else
   placesWhereTilesAre.insert(tileObject->pos());
 }

 const quint16 tileSize = _tileSource->tileSize();
 const quint32 tilesPerRow = sqrt((long double)_tileSource->tilesOnZoomLevel(this->zoomLevel()));
 const quint32 tilesPerCol = tilesPerRow;

 const qint32 perSide = qMax(boundingRect.width()/tileSize,
                             boundingRect.height()/tileSize) + 3;
 const qint32 xc = qMax((qint32)0,
                        (qint32)(centerPointQGS.x() / tileSize) - perSide/2);
 const qint32 yc = qMax((qint32)0,
                        (qint32)(centerPointQGS.y() / tileSize) - perSide/2);
 const qint32 xMax = qMin((qint32)tilesPerRow,
                          xc + perSide);
 const qint32 yMax = qMin(yc + perSide,
                          (qint32)tilesPerCol);

 for (qint32 x = xc; x < xMax; x++)
 {
  for (qint32 y = yc; y < yMax; y++)
  {
   const QPointF scenePos(x*tileSize + tileSize/2,
                          y*tileSize + tileSize/2);


   bool tileIsThere = false;
   if (placesWhereTilesAre.contains(scenePos))
    tileIsThere = true;

   if (tileIsThere)
    continue;

   //Just in case we're running low on free tiles, add one
   if (freeTiles.isEmpty())
   {
    MapTileGraphicsObject * tileObject = new MapTileGraphicsObject(tileSize);
    tileObject->setTileSource(_tileSource);
    _tileObjects.insert(tileObject);
    _childScene->addItem(tileObject);
    freeTiles.enqueue(tileObject);
   }
   //Get the first free tile and make it do its thing
   MapTileGraphicsObject * tileObject = freeTiles.dequeue();
   if (tileObject->pos() != scenePos)
    tileObject->setPos(scenePos);
   if (tileObject->isVisible() != true)
    tileObject->setVisible(true);
   tileObject->setTile(x,y,this->zoomLevel());
  }
 }

 //If we've got a lot of free tiles left over, delete some of them
 while (freeTiles.size() > 2)
 {
  MapTileGraphicsObject * tileObject = freeTiles.dequeue();
  _tileObjects.remove(tileObject);
  _childScene->removeItem(tileObject);
  delete tileObject;
 }

}

//protected
void MapGraphicsView::resetQGSSceneSize()
{
 if (_tileSource.isNull())
  return;

 //Make sure the size of our QGraphicsScene is correct
 const quint64 dimension = sqrt((long double)_tileSource->tilesOnZoomLevel(this->zoomLevel()))*_tileSource->tileSize();
 if (_childScene->sceneRect().width() != dimension)
  _childScene->setSceneRect(0,0,dimension,dimension);
}


//      qmt_client_layer_base_->define_and_adopt_style("bus-stop",
//        typeid(QGraphicsEllipseItem),
//        { QColor(34, 159, 201) }, {30} ); // 80, 105, 155

//      qmt_client_layer_base_->define_and_adopt_style("bus-stop",
//        typeid(QGraphicsPolygonItem),
//        { QColor(34, 159, 201) }, {30} ); // 80, 105, 155

//    main_window_controller_->match_locations_in_text_file("/home/nlevisrael/gits/acle/bus_data/stops.txt",
//      ll.y(), ll.x(), stops_size, 4, 5, ',', info);

#ifdef HIDE
    QFile infile(path);

    //QVector<QPair<QStringList, QPointF>> stops(10);
    if(!infile.open(QIODevice::ReadOnly))
     return;

    static u1 stops_size = 20;

    QVector<QByteArray> stops(stops_size);
    QVector<double> deltas(stops_size);

    // // get stops_size closest stops
    //   presumably this will be a separate procedure
    {
     double max_delta = 0;
     u1 max_delta_index = 0;
     u1 stops_active_size = 0;
     u1 stops_max_size = stops.size();


     //u1 count = 0;
     if(!infile.atEnd())
      // //  read the header line
      infile.readLine();
     while(!infile.atEnd())
     {
      QByteArray qba = infile.readLine();
      QList<QByteArray> fields = qba.split(',');
      // //  stop_id,stop_code,stop_name,stop_desc,stop_lat,stop_lon,zone_id
      r8 lat = fields[4].toDouble();
      r8 lon = fields[5].toDouble();

      r8 dlat = lat - ll.y();
      r8 dlon = lon - ll.x();

      QVector2D v2d(dlat, dlon);
      double len = v2d.length();
      if(stops_active_size < stops_max_size)
      {
       // // there's room for any candidate no matter how distant
       stops[stops_active_size] = qba;
       deltas[stops_active_size] = len;
       if(len > max_delta)
       {
        max_delta_index = stops_active_size;
        max_delta = len;
       }
       ++stops_active_size;
      }
      else if(len < max_delta)
      {
       // //  replace the most distant match
       //    don't bother sorting, we'll just calculate the new largest distance
       stops[max_delta_index] = qba;
       deltas[max_delta_index] = len;
       auto it = std::max_element(deltas.begin(), deltas.end());
       max_delta_index = std::distance(deltas.begin(), it);
       max_delta = *it;
      }
     }
    }
    infile.close();

    u1 index = 0;
    QVector<QPair<QVector<r8>, QStringList>> info(stops.length());
    std::transform(stops.begin(), stops.end(), info.begin(),
                   [&deltas, &index] (const QByteArray qba) -> decltype (info.value(0))
    {
     QList<QByteArray> fields = qba.split(',');
     return {{ fields[4].toDouble(), fields[5].toDouble(), deltas[index++] },
      { "", QString::fromLatin1(fields[0]),
         QString::fromLatin1(fields[1]),QString::fromLatin1(fields[2]),
         QString::fromLatin1(fields[3]) },
     };
    });
    std::sort(info.begin(), info.end(), [](QPair<QList<r8>, QStringList>& lhs, QPair<QList<r8>, QStringList>& rhs)
    {
     return lhs.second[2] < rhs.second[2];
    });
#endif



    //    QMT_Web_Engine_View* wev = new QMT_Web_Engine_View(nullptr);
    //    QMT_Web_Engine_Page* wep = new QMT_Web_Engine_Page(nullptr);
    //    QObject::connect(wep, &QMT_Web_Engine_Page::urlChanged,[this](const QUrl &url){
    //     qDebug() << "r:" << url.toString();
    //     //? check_url_patterns(url.toString().prepend("urlChanged!"));
    //    });

    //    QObject::connect(wep, &QMT_Web_Engine_Page::navRequest,[this](const QUrl &url){
    //     qDebug() << "req:" << url.toString();
    //     //? check_url_patterns(url.toString().prepend("navRequest!"));
    //    });

    //    QObject::connect(wep, &QMT_Web_Engine_Page::linkHovered,[](const QUrl &url){
    //     qDebug() << "H:" << url.toString();
    //    });


    //    //     wev->page()->load(QUrl("https://www.openstreetmap.org/#map=%1/%2/%3&layers=T"_qt
    //    //       .arg(zl).arg(ll.y()).arg(ll.x())));
    //    //     wev->setPage(wep);

    //    QMT_My_Page* myp = new QMT_My_Page;
    //    QWebChannel* channel = new QWebChannel(wev);
    //    channel->registerObject(QStringLiteral("content"), myp);
    //    wep->setWebChannel(channel);

    //    wev->setPage(wep);

    //    wep->load(QUrl("https://www.openstreetmap.org/#map=%1/%2/%3&layers=T"_qt
    //                   .arg(zl).arg(ll.y()).arg(ll.x())));

    //    //wep->show();
    //    wev->show();

    //?
    //  menu->addAction("Composite", [this, qp]()
    //  {
    //   QDialog* d = new QDialog;
    //   QVBoxLayout* v = new QVBoxLayout;
    //   CompositeTileSourceConfigurationWidget* w = new CompositeTileSourceConfigurationWidget;
    //   v->addWidget(w);
    //   d->setLayout(v);
    //   d->show();
    //  });


    //     menu->addAction("Launch Configuration Dialog");
    //     menu->addAction("Save Current Session");
    //     menu->addAction("Launch Filter/Search Dialog");
    //     menu->addAction("Set Zoom/Pan Settings");
    //     menu->addAction("View Coordinates and Civil-Geographic Info");
