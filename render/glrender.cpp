#include "glrender.h"

#include <QOpenGLFunctions>


[[maybe_unused]]
GLRender::GLRender(QWidget *parent) : QOpenGLWidget(parent) {
    _w = this->width();
    _h = this->height();
}


void GLRender::initializeGL() {
    _w = this->width();
    _h = this->height();

    glClearColor(0, 0.001f * float(_w), 0.001f * float(_h), float(_h) / float(_w));
}

void GLRender::resizeGL(int w, int h) {
    _w = w;
    _h = h;

    glClearColor(0, 0.001f * float(_w), 0.001f * float(_h), float(_h) / float(_w));
}

void GLRender::paintGL() {
    glClearColor(0, 0.001f * float(_w), 0.001f * float(_h), float(_h) / float(_w));

    glBegin(GL_TRIANGLES);
    glColor3f(0, GLfloat(1) - 0.001f * float(_w), GLfloat(1) - 0.001f * float(_h));
    glVertex2d(0, 0);
    if (_h > _w) {
        glVertex2d(1, -1);
        glVertex2d(1, 1);
    } else {
        glVertex2d(-1, -1);
        glVertex2d(-1, 1);
    }
    glEnd();
}