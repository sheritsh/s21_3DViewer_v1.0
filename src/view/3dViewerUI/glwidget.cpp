#include "glwidget.h"

GlWidget::GlWidget(QWidget *parent) : QOpenGLWidget{parent} {}

void GlWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST); // depth buffer for z coordinate
}

void GlWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h); // set the viewport, if the size is fixed could be skipped
}

void GlWidget::paintGL()
{
    glClearColor(0, 0, 0, 1);
    glVertexPointer(3, GL_DOUBLE, 0, data.vertices_arr); // number of coordinates per vertex, type of data in array, distance between vertices in array, pointer to array
    glEnableClientState(GL_VERTEX_ARRAY); // enable open gl state
    glOrtho(-2, 2, -2, 2, 0.1f, 1000);
    glDrawElements(GL_LINES, data.vertex_indices_count * 2, GL_UNSIGNED_INT, data.vertex_indices_arr); // multiply by two because we draw lines that close
    glDisableClientState(GL_VERTEX_ARRAY);
}

void GlWidget::parse_obj()
{
    char *filename = "/Volumes/sheritsh/C8_3DViewer_v1.0-1/src/tmp/skull.obj";
    parse_obj_file(filename, &this->data);
    update();
//    print_data(&this->data);
}
