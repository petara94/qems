#include "emsitem.h"

#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

EMSItem::EMSItem(QGraphicsItem *parent) : QGraphicsItem(parent) {
    _w = 100;
    _h = 100;
    color = Qt::red;
}

EMSItem::EMSItem(int w, int h) : EMSItem() {
    _w = w;
    _h = h;
}

void EMSItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(color);
    painter->drawEllipse(int(x()), int(y()), _w, _h);
}

QRectF EMSItem::boundingRect() const {
    return QRectF(x() - EMS_ITEM_MARGIN,
                  y() - EMS_ITEM_MARGIN,
                  _w + EMS_ITEM_MARGIN,
                  _h + EMS_ITEM_MARGIN);
}

void EMSItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << event->pos().x() << event->pos().y() << " | "
             << event->scenePos().x() << event->scenePos().y() << " | "
             << event->buttonDownPos(Qt::MouseButton::LeftButton).x() << " | "
             << event->buttonDownPos(Qt::MouseButton::LeftButton).y();
    if (event->button() == Qt::MouseButton::LeftButton) {
        color = Qt::blue;
        update(boundingRect());
    }
}

void EMSItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << event->button();
    if (event->button() == Qt::MouseButton::LeftButton) {
//        qDebug() << event->pos().x() << event->pos().y() << " | "
//                  << event->scenePos().x() << event->scenePos().y() << " | " << std::endl;
//                 << event->buttonDownPos(Qt::MouseButton::LeftButton).x() << " | "
//                 << event->buttonDownPos(Qt::MouseButton::LeftButton).y();
        setPos(event->pos());
        update(boundingRect());
    }
}

void EMSItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        color = Qt::red;
        update(boundingRect());
    }
}

EMSItem::~EMSItem() {

}
