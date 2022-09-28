#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H

#include <QWidget>
#include <QPointer>
#include <QSharedPointer>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QList>
#include <QContextMenuEvent>
#include <QVector3D>
#include <QStringBuilder>
#include <QHash>

#include "MapGraphicsScene.h"
#include "MapGraphicsObject.h"
#include "MapTileSource.h"
#include "MapGraphics_global.h"

#include "guts/MapTileGraphicsObject.h"
#include "guts/PrivateQGraphicsInfoSource.h"

#include "accessors.h"

#include <functional>


class Main_Window_Controller;

class QMT_Client_Layer_Base;
class QMT_Client_Context_Menu_Handler_Base;


class MAPGRAPHICSSHARED_EXPORT MapGraphicsView : public QWidget, public PrivateQGraphicsInfoSource
{
 Q_OBJECT
public:
 enum DragMode
 {
  NoDrag,
  ScrollHandDrag,
  RubberBandDrag
 };

 enum ZoomMode
 {
  CenterZoom,
  MouseZoom,
  Force_Reset
 };

public:
 explicit MapGraphicsView(MapGraphicsScene * scene=0, QWidget * parent = 0);
 virtual ~MapGraphicsView();

 QPointF center() const;
 void centerOn(const QPointF& pos);
 void centerOn(qreal longitude, qreal latitude);
 void centerOn(const MapGraphicsObject * item);

 void force_reset();

 QPointF mapToScene(const QPoint viewPos) const;

 MapGraphicsView::DragMode dragMode() const;
 void setDragMode(MapGraphicsView::DragMode);

 MapGraphicsScene * scene() const;
 void setScene(MapGraphicsScene *);

 //pure-virtual from PrivateQGraphicsInfoSource
 QSharedPointer<MapTileSource> tileSource() const;

 /**
     * @brief Sets the tile source that this view will pull from.
     * MapGraphicsView does NOT take ownership of the tile source.
     *
     * @param tSource
     */
 void setTileSource(QSharedPointer<MapTileSource> tSource);

 //pure-virtual from PrivateQGraphicsInfoSource
 quint8 zoomLevel() const;
 void setZoomLevel(quint8 nZoom, ZoomMode zMode = CenterZoom);

 void zoomIn(ZoomMode zMode = CenterZoom);
 void zoomOut(ZoomMode zMode = CenterZoom);

 ACCESSORS(QMT_Client_Layer_Base* ,qmt_client_layer_base)
 ACCESSORS(QMT_Client_Context_Menu_Handler_Base* ,qmt_client_context_menu_handler_base)

 void rotate(qreal rotation);

 std::function<void (const QPointF&)> coords_notify_callback_;

 void handle_context_menu(QGraphicsSceneContextMenuEvent* event, MapGraphicsObject* mgo);
 QPointF map_ll_to_scene(const QPointF &pos);
 QPoint map_ll_to_view(const QPointF &pos);


signals:
 void zoomLevelChanged(quint8 nZoom);

public Q_SLOTS:

protected Q_SLOTS:
 virtual void handleChildMouseDoubleClick(QMouseEvent * event);
 virtual void handleChildMouseMove(QMouseEvent * event);
 virtual void handleChildMousePress(QMouseEvent * event);
 virtual void handleChildMouseRelease(QMouseEvent * event);
 virtual void handleChildViewContextMenu(QContextMenuEvent * event);
 virtual void handleChildViewScrollWheel(QWheelEvent * event);

private Q_SLOTS:
 void renderTiles();

protected:
 void doTileLayout();
 void resetQGSSceneSize();

private:
 QPointer<MapGraphicsScene> _scene;
 QPointer<QGraphicsView> _childView;
 QPointer<QGraphicsScene> _childScene;
 QSharedPointer<MapTileSource> _tileSource;

 QSet<MapTileGraphicsObject *> _tileObjects;

 quint8 _zoomLevel;

 DragMode _dragMode;

 Main_Window_Controller* main_window_controller_;

 QMT_Client_Layer_Base* qmt_client_layer_base_;
 QMT_Client_Context_Menu_Handler_Base* qmt_client_context_menu_handler_base_;

};

inline uint qHash(const QPointF& key)
{
 const QString temp = QString::number(key.x()) % "," % QString::number(key.y());
 return qHash(temp);
}

#endif // MAPGRAPHICSVIEW_H
