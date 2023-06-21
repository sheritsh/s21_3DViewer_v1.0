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
#include <mainwindow.h>

extern "C" {
#include "../../modules/model_loading.h"
#include "../../modules/affine_transformations.h"
}

class GlWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
//    Q_OBJECT

public:
    /* 3D MODEL DATA START */
    double scale = 50;
    double rotate_x;
    double rotate_y;
    double rotate_z;
    double translate_x;
    double translate_y;
    double translate_z;
    double vertices_size = 1;
    double edges_thickness = 1;
    int projection_type = 0;
    int v_display_method = 0;
    int edges_type = 0;
    double v_red = 1, v_green = 1, v_blue = 1;
    double e_red = 1, e_green = 1, e_blue = 1;
    double bg_red = 0, bg_green = 0, bg_blue = 0;
    /* 3D MODEL DATA END  */


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
    void render_ui_stats();
    void build_lines();
    void build_points();




signals:
};

#endif // GLWIDGET_H
