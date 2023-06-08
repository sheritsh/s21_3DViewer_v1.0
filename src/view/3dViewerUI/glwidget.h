#ifndef GLWIDGET_H
#define GLWIDGET_H


#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QWidget>

extern "C" {
#include "../../modules/model_loading.h"
}

class GlWidget : public QOpenGLWidget
{
//    Q_OBJECT

public:
    explicit GlWidget(QWidget *parent = nullptr);
    obj_data data = {0, NULL, 0, NULL};
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void parse_obj();

private:

signals:
};

#endif // GLWIDGET_H
