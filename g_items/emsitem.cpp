#include "emsitem.h"

#include <QPainter>

EMSItem::EMSItem(QGraphicsItem *parent) : QGraphicsItem(parent) {
    _w = 50;
    _h = 50;
}

EMSItem::EMSItem(int w, int h) : _w(w), _h(h) {}

void EMSItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::red);
    painter->drawEllipse(int(x()), int(y()), _w, _h);
}

QRectF EMSItem::boundingRect() const {
    return QRectF(x() - 10, y() - 10, _w + 10, _h + 10);
}
