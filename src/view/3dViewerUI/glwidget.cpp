#include "glwidget.h"

GlWidget::GlWidget(QWidget *parent) : QOpenGLWidget{parent} {}

void GlWidget::initializeGL()
{
    initializeOpenGLFunctions();
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1 * normalize_coef, 1 * normalize_coef, -1 * normalize_coef, 1 * normalize_coef, -1 * normalize_coef, 1000 * normalize_coef);
    glEnableClientState(GL_VERTEX_ARRAY); // enable open gl state
    glDrawElements(GL_LINES, data.vertex_indices_count * 2, GL_UNSIGNED_INT, data.vertex_indices_arr); // multiply by two because we draw lines that close
    glDisableClientState(GL_VERTEX_ARRAY);
}

void GlWidget::parse_obj()
{
//    char *filename = "n/Volumes/sheritsh/C8_3DViewer_v1.0-1/src/tmp/skull.obj";
    data = {0, NULL, 0, NULL};
    if (this->filename[0] != '\0') {
        parse_obj_file(this->filename, &this->data);
//        vertices = data.vertices_count;
//        edges = data.vertex_indices_count;
        set_normalize_coef();
        update();
    } else {
        QMessageBox warning = QMessageBox();
        warning.setWindowTitle("Error");
        warning.setText("Please choose .obj file");
        warning.setIcon(QMessageBox::Warning);
        warning.exec();
    }


//    set_max_vert();

    //    print_data(&this->data);
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

void GlWidget::mouseMoveEvent(QMouseEvent *event) {

}

void GlWidget::render_ui_stats()
{

}

void GlWidget::mousePressEvent(QMouseEvent *event) {

}

