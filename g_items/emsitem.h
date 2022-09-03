#ifndef EMSITEM_H
#define EMSITEM_H

#include <QGraphicsItem>

class EMSItem : public QGraphicsItem {
private:
    int _w;
    int _h;

public:
    explicit EMSItem(QGraphicsItem *parent = nullptr);

    EMSItem(int w, int h);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;
};

#endif // EMSITEM_H
