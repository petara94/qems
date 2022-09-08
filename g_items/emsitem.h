#ifndef EMSITEM_H
#define EMSITEM_H

#include <QGraphicsItem>

#define EMS_ITEM_MARGIN 10

class EMSItem : public QGraphicsItem {
private:
    bool moving = false;
    int _w;
    int _h;
    Qt::GlobalColor color;


public:
    explicit EMSItem(QGraphicsItem *parent = nullptr);

    ~EMSItem();

    EMSItem(int w, int h);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;



    QRectF boundingRect() const override;

};

#endif // EMSITEM_H
