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

    enum display_method {NONE, CIRCLE, SQUARE};
    enum projection_type {PARALLEL, CENTRAL};
    enum edges_type {SOLID, DASHED};


    ~MainWindow();


private slots:
    void on_openObjBtn_clicked();
    void on_renderBtn_clicked();

    void on_projection_types_currentIndexChanged(int index);
    void on_vert_color_val_clicked();

    void on_vert_circle_val_clicked();

    void on_vert_none_val_clicked();

    void on_vert_square_val_clicked();

    void on_vert_size_val_valueChanged(int value);

    void on_edge_solid_val_clicked();

    void on_edge_dashed_val_clicked();

    void on_edge_thic_val_valueChanged(int value);

    void on_edge_color_val_clicked();

    void on_background_color_val_clicked();

    void on_scale_val_valueChanged(int value);

    void on_rotate_x_val_valueChanged(int value);

    void on_rotate_y_val_valueChanged(int value);

    void on_rotate_z_val_valueChanged(int value);

    void on_translate_x_val_valueChanged(int value);

    void on_translate_y_val_valueChanged(int value);

    void on_translate_z_val_valueChanged(int value);

private:
    void set_mainwindow_attributes();
    void set_fonts();
    void bind_slots();
    void assign_values();

    // Windows transition
    QPoint cur_pos;
    QPoint new_pos;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);



};
#endif // MAINWINDOW_H
