#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define GL_SILENCE_DEPRECATION
#include <QMainWindow>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QWidget>
#include <QFlags>

extern "C" {
#include "../../modules/s21_3dviewer.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    obj_data data = {0, NULL, 0, NULL};

};
#endif // MAINWINDOW_H
