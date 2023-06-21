#include "glwidget.h"

GlWidget::GlWidget(QWidget *parent) : QOpenGLWidget{parent} {}

void GlWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST); // depth buffer for z coordinate
}

void GlWidget::resizeGL(int w, int h)
{
//    glViewport(0, 0, w, h); // set the viewport, if the size is fixed could be skipped
}

void GlWidget::paintGL()
{
    glClearColor(bg_red, bg_green, bg_blue, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glVertexPointer(3, GL_DOUBLE, 0, data.vertices_arr); // number of coordinates per vertex, type of data in array, distance between vertices in array, pointer to array
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (this->projection_type == 0) {
        glFrustum(-1 * normalize_coef, 1 * normalize_coef, -1 * normalize_coef, 1 * normalize_coef, 120 * normalize_coef , 1000 * normalize_coef);
        glTranslatef(0, 0, -130 * normalize_coef);
    } else {
        glOrtho(-1 * normalize_coef, 1 * normalize_coef, -1 * normalize_coef, 1 * normalize_coef, -1 * normalize_coef, 1000 * normalize_coef);
    }
    glEnableClientState(GL_VERTEX_ARRAY); // enable open gl state
    if (this->v_display_method != 0) {
        build_points();
    }
    build_lines();
    glDisableClientState(GL_VERTEX_ARRAY);
}

void GlWidget::parse_obj()
{
    data_destructor(&this->data);
    data = {0, NULL, 0, NULL};
    if (this->filename[0] != '\0') {
        parse_obj_file(this->filename, &this->data);
        set_normalize_coef();
        update();
    } else {
        QMessageBox warning = QMessageBox();
        warning.setWindowTitle("Error");
        warning.setText("Please choose .obj file");
        warning.setIcon(QMessageBox::Warning);
        warning.exec();
    }

}

void GlWidget::set_normalize_coef()
{
    normalize_coef = -10; // scarecrow

    for (size_t i = 0; i < data.vertices_count * 3; i++) {
        if (abs(data.vertices_arr[i]) > normalize_coef) {
            normalize_coef = abs(data.vertices_arr[i]);
        }
    }

}


void GlWidget::build_lines()
{
    if (this->edges_type == 1) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00FF);
    }
    glLineWidth(this->edges_thickness);
    glColor3f(this->e_red, this->e_green, this->e_blue);
    glDrawElements(GL_LINES, data.vertex_indices_count * 2, GL_UNSIGNED_INT, data.vertex_indices_arr); // multiply by two because we draw lines that close
    if (this->edges_type == 1) {
        glDisable(GL_LINE_STIPPLE);
    }
}

void GlWidget::build_points()
{
    if (this->v_display_method == 1) {
        glEnable(GL_POINT_SMOOTH);
    }
    glPointSize(this->vertices_size);
    glColor3f(this->v_red, this->v_green, this->v_blue);
    glDrawArrays(GL_POINTS, 0, data.vertices_count);
    if (this->v_display_method == 1) {
        glDisable(GL_POINT_SMOOTH);
    }
}

void GlWidget::mouseMoveEvent(QMouseEvent *event) {

}

void GlWidget::mousePressEvent(QMouseEvent *event) {

}

