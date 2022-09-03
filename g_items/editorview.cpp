#include "editorview.h"

#include <QGraphicsScene>
#include <QDebug>
#include <QWheelEvent>

EditorView::EditorView(QWidget *parent) : QGraphicsView(parent) {
    _scene = new QGraphicsScene();

    _item = new EMSItem(25, 25);

    auto f = new EMSItem(50, 50);
    f->moveBy(100, 100);

    _scene->addItem(_item);
    _scene->addItem(f);

    this->setScene(_scene);
}

void EditorView::wheelEvent(QWheelEvent *event) {
    qDebug() << event->angleDelta();
    _item->moveBy(event->angleDelta().x(), event->angleDelta().y());
    QGraphicsView::wheelEvent(event);
    this->repaint();
}

void EditorView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
}
