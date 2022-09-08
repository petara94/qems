#include "editorview.h"

#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QPen>
#include <QWheelEvent>

EditorView::EditorView(QWidget *parent) : QGraphicsView(parent) {
    _scene = new QGraphicsScene(0, 0, 600, 600);

    _item = new EMSItem(50, 50);

    _scene->addRect(0, 0, _scene->width(), _scene->height(), QPen(Qt::black), Qt::white);
    _scene->addItem(_item);

    this->setScene(_scene);
}

void EditorView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
}
