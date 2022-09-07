#include "editorview.h"

#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QWheelEvent>

EditorView::EditorView(QWidget *parent) : QGraphicsView(parent) {
    _scene = new QGraphicsScene();

    _item = new EMSItem(25, 25);

    _scene->addItem(_item);

    this->setScene(_scene);

    auto *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(16);
}

void EditorView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
}
