#ifndef GLRENDER_H
#define GLRENDER_H

#include <QOpenGLWidget>

class GLRender : public QOpenGLWidget
{
private:
    int _w, _h;

public:
    [[maybe_unused]] explicit GLRender(QWidget* parent = nullptr);



    // QOpenGLWidget interface
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

};

#endif // GLRENDER_H
