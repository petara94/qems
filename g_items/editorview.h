#ifndef EDITORVIEW_H
#define EDITORVIEW_H

#include <QGraphicsView>

#include "emsitem.h"

class EditorView : public QGraphicsView {
Q_OBJECT
private:
    EMSItem *_item;
    QGraphicsScene *_scene;

public:
    explicit EditorView(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

    void dragEnterEvent(QDragEnterEvent *event) override;

    void dragLeaveEvent(QDragLeaveEvent *event) override;

    void dragMoveEvent(QDragMoveEvent *event) override;

    void dropEvent(QDropEvent *event) override;
};

#endif // EDITORVIEW_H
