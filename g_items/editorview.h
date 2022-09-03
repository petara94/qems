#ifndef EDITORVIEW_H
#define EDITORVIEW_H

#include <QGraphicsView>

#include "emsitem.h"

class EditorView : public QGraphicsView {
private:
    EMSItem *_item;
    QGraphicsScene *_scene;

public:
    explicit EditorView(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;
};

#endif // EDITORVIEW_H
