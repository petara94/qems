#include "editorview.h"

#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QPen>
#include <QWheelEvent>
#include <QDropEvent>
#include <QMimeData>

EditorView::EditorView(QWidget *parent) : QGraphicsView(parent) {
    _scene = new QGraphicsScene(0, 0, 600, 600);

    _item = new EMSItem(50, 50);

    _scene->addRect(0, 0, _scene->width(), _scene->height(), QPen(Qt::black), Qt::white);
    _scene->addItem(_item);

    setScene(_scene);

    qDebug() << backgroundBrush();

    setBackgroundBrush(Qt::white);
}

void EditorView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
}

void EditorView::dragEnterEvent(QDragEnterEvent *event) {
    setBackgroundBrush(Qt::black);
    event->accept();
}

void EditorView::dragLeaveEvent(QDragLeaveEvent *event) {
    setBackgroundBrush(Qt::white);
    event->accept();
}

void EditorView::dragMoveEvent(QDragMoveEvent *event) {
    event->acceptProposedAction();
}

void EditorView::dropEvent(QDropEvent *event) {
    if (event->isAccepted()) {
        qDebug() << "accepted";
        return;
    }

    auto w = event->mimeData()->property("width");
    auto h = event->mimeData()->property("height");

    if (!w.canConvert<int>() || !h.canConvert<int>()) {
        event->accept();
        return;
    }

    auto *e = new EMSItem(w.toInt(), h.toInt());

    _scene->addItem(e);

    qDebug() << "adding" << event->isAccepted();

    e->moveBy(event->position().x() - w.toInt() / 2, event->position().y() - h.toInt() / 2);

    event->acceptProposedAction();
    QGraphicsView::dropEvent(event);
}
