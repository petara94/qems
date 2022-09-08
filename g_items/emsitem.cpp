#include "emsitem.h"

#include <QPainter>
#include <QTimer>
#include <QGraphicsScene>
#include <QCursor>
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
    painter->drawEllipse(0, 0, _w, _h);
}

QRectF EMSItem::boundingRect() const {
    return QRectF(0,
                  0,
                  _w,
                  _h);
}

void EMSItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons().testFlag(Qt::LeftButton)) {
        color = Qt::blue;
        this->setCursor(QCursor(Qt::ClosedHandCursor));
        update(boundingRect());
    }
    Q_UNUSED(event);
}

void EMSItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons().testFlag(Qt::LeftButton)) {
        auto pos = mapToScene(event->pos()) - event->buttonDownPos(Qt::LeftButton);
        if (pos.x() < 0)
            pos.setX(0);
        if (pos.y() < 0)
            pos.setY(0);
        if (pos.x() + _h > scene()->width())
            pos.setX(scene()->width() - _w);
        if (pos.y() + _h > scene()->height())
            pos.setY(scene()->height() - _h);
        this->setPos(pos);
        this->setPos(pos);

        update(boundingRect());
    }
    Q_UNUSED(event);
}

void EMSItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        color = Qt::red;
        this->setCursor(QCursor(Qt::ArrowCursor));
        update(boundingRect());
    }
    Q_UNUSED(event);
}

EMSItem::~EMSItem() {

}
