#ifndef GLWIDGET_H
#define GLWIDGET_H


#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QWidget>
#include <iostream>
#include <QMessageBox>

extern "C" {
#include "../../modules/model_loading.h"
}

class GlWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
//    Q_OBJECT

public:
    // 3D OBJ
    char *filename;
    explicit GlWidget(QWidget *parent = Q_NULLPTR);
    obj_data data = {0, NULL, 0, NULL};
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void parse_obj();
    GLfloat normalize_coef;

private:
    void set_normalize_coef();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;



signals:
};

#endif // GLWIDGET_H
