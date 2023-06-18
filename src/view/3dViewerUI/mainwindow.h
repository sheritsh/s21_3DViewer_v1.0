#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QWidget>
#include <glwidget.h>
#include <QDialog>
#include <QFileDialog>
#include <glwidget.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *ui;


    /* VARIABLES FOR OPENGL LOGIC */
    bool isObjFile;
    int vertices_count;
    int edges_count;

    /* END OF VARIABLES FOR OPENGL LOGIC */


    ~MainWindow();


private slots:
    void on_openObjBtn_clicked();
    void on_renderBtn_clicked();

private:
    void set_mainwindow_attributes();
    void set_fonts();
    void bind_slots();

    // Windows transition
    QPoint cur_pos;
    QPoint new_pos;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);



};
#endif // MAINWINDOW_H
