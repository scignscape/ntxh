#ifndef CIRCLEOBJECT_H
#define CIRCLEOBJECT_H

#include "MapGraphics_global.h"
#include "MapGraphicsObject.h"

class MapGraphicsView;

class MAPGRAPHICSSHARED_EXPORT CircleObject : public MapGraphicsObject
{
    Q_OBJECT

 void* ref_;
 int outline_code_;

public:
    explicit CircleObject(MapGraphicsView* containing_view, qreal radius,bool sizeIsZoomInvariant=true, QColor fillColor = QColor(0,0,0,0),MapGraphicsObject *parent = 0);
    virtual ~CircleObject();

    //pure-virtual from MapGraphicsObject
    QRectF boundingRect() const;

    //pure-virtual from MapGraphicsObject
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    qreal radius() const;
    void setRadius(qreal radius);


    ACCESSORS(int ,outline_code)
    ACCESSORS(void* ,ref)

signals:
    
public slots:

protected:
    //virtual from MapGraphicsObject
    virtual void keyReleaseEvent(QKeyEvent *event);

private:
    qreal _radius;
    QColor _fillColor;
    
};

#endif // CIRCLEOBJECT_H
