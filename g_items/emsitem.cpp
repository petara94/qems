#include "emsitem.h"

#include <QPainter>
#include <QTimer>
#include <QGraphicsScene>
#include <QCursor>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

EMSItem::EMSItem(QGraphicsItem *parent) : QGraphicsItem(parent) {
    _w = 100;
    _h = 100;
    color = Qt::red;

    setAcceptHoverEvents(true);
}

EMSItem::EMSItem(int w, int h) : EMSItem() {
    _w = w;
    _h = h;
}

void EMSItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    if (hovered) {
        painter->setBrush(Qt::transparent);
        painter->setPen(Qt::PenStyle::DashLine);
        painter->drawRect(0 - EMS_ITEM_MARGIN,
                          0 - EMS_ITEM_MARGIN,
                          _w + EMS_ITEM_MARGIN * 2,
                          _h + EMS_ITEM_MARGIN * 2);

        painter->setBrush(Qt::black);
        painter->drawText(0, -10, "123");
    }

    painter->setBrush(color);
    painter->setPen(Qt::black);
    painter->drawEllipse(0, 0, _w, _h);
}

QRectF EMSItem::boundingRect() const {
    return QRectF(0 - EMS_ITEM_MARGIN,
                  0 - EMS_ITEM_MARGIN,
                  _w + EMS_ITEM_MARGIN * 2,
                  _h + EMS_ITEM_MARGIN * 2);
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
        if (pos.x() + this->scale() * _w > scene()->width())
            pos.setX(scene()->width() - this->scale() * _w);
        if (pos.y() + this->scale() * _h > scene()->height())
            pos.setY(scene()->height() - this->scale() * _h);
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

void EMSItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    hovered = true;
    color = Qt::green;
    setCursor(Qt::CursorShape::PointingHandCursor);
    update(boundingRect());
}

void EMSItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    hovered = false;
    color = Qt::red;
    setCursor(QCursor(Qt::ArrowCursor));
    update(boundingRect());
}

void EMSItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    setCursor(Qt::CursorShape::PointingHandCursor);
}
