#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_mainwindow_attributes();
    set_fonts();
    bind_slots();
    assign_values();

}

MainWindow::~MainWindow()
{
    data_destructor(&ui->OpenGlWidget->data);
    delete ui;
}

void MainWindow::set_mainwindow_attributes()
{
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAutoFillBackground(true);
}

void MainWindow::set_fonts()
{
    // creating
    int id = QFontDatabase::addApplicationFont(":/res/assets/fonts/SpaceCrusadersItalic-ZV1Zx.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont titleFont(family);
    int id2 = QFontDatabase::addApplicationFont(":/res/assets/fonts/Montserrat-Regular.ttf");
    QString family2 = QFontDatabase::applicationFontFamilies(id2).at(0);
    QFont mainFont(family2);
    int id3 = QFontDatabase::addApplicationFont(":/res/assets/fonts/TechnoCharmDemoVersionRegular-ALaZm.otf");
    QString family3 = QFontDatabase::applicationFontFamilies(id3).at(0);
    QFont footerFont(family3);

    // applying
    ui->h1->setFont(titleFont);
    ui->obj_info->setFont(mainFont);
    ui->filename_val->setFont(footerFont);
    ui->edges_numb_val->setFont(footerFont);
    ui->vert_numb_val->setFont(footerFont);
}

void MainWindow::bind_slots()
{
    connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->minimizeBtn, SIGNAL(clicked()), this,
            SLOT(showMinimized()));
}

void MainWindow::assign_values()
{

}

void MainWindow::on_openObjBtn_clicked()
{
    QString QString_filename = QFileDialog::getOpenFileName(this, tr("Open .obj file:"), "~/", tr("Obj Files (*.obj)"));
    ui->pathObj->setText(QString_filename);
}

void MainWindow::on_renderBtn_clicked()
{
    std::string std_filename = ui->pathObj->text().toStdString();
    ui->OpenGlWidget->filename = (char *)std_filename.c_str();
    ui->OpenGlWidget->parse_obj();
    ui->filename_val->setText("dancing Zalupa 3d model tancuet za 300 bucks");
    ui->vert_numb_val->setText(QString::number(ui->OpenGlWidget->data.vertices_count));
    ui->edges_numb_val->setText(QString::number(ui->OpenGlWidget->data.vertex_indices_count));
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    new_pos = QPoint(event->globalPosition().toPoint() - cur_pos);
    move(x() + new_pos.x(), y() + new_pos.y());
    cur_pos = event->globalPosition().toPoint();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    cur_pos = event->globalPosition().toPoint();
}



void MainWindow::on_projection_types_currentIndexChanged(int index)
{
    if (index == 0) {
        ui->OpenGlWidget->projection_type = PARALLEL;
    } else if (index == 1) {
        ui->OpenGlWidget->projection_type = CENTRAL;
    }
    ui->OpenGlWidget->update();
}


void MainWindow::on_vert_color_val_clicked()
{
    QColor vert_color = QColorDialog::getColor(Qt::white, this->ui->tabWidget, "Choose color");
    if (vert_color.isValid()) {
        ui->OpenGlWidget->v_red = vert_color.redF();
        ui->OpenGlWidget->v_green = vert_color.greenF();
        ui->OpenGlWidget->v_blue = vert_color.blueF();
        char rgba_color[40];
        sprintf(rgba_color, "background-color: rgb(%d,%d,%d)", vert_color.red(), vert_color.green(), vert_color.blue());
        ui->vert_color_val->setStyleSheet(rgba_color);
        ui->OpenGlWidget->update();
    }
}


void MainWindow::on_vert_none_val_clicked()
{
    ui->OpenGlWidget->v_display_method = NONE;
    ui->OpenGlWidget->update();
}


void MainWindow::on_vert_circle_val_clicked()
{
    ui->OpenGlWidget->v_display_method = CIRCLE;
    ui->OpenGlWidget->update();
}


void MainWindow::on_vert_square_val_clicked()
{
    ui->OpenGlWidget->v_display_method = SQUARE;
    ui->OpenGlWidget->update();
}

void MainWindow::on_vert_size_val_valueChanged(int value)
{
    ui->OpenGlWidget->vertices_size = value;
    ui->OpenGlWidget->update();
}


void MainWindow::on_edge_solid_val_clicked()
{
    ui->OpenGlWidget->edges_type = SOLID;
    ui->OpenGlWidget->update();
}


void MainWindow::on_edge_dashed_val_clicked()
{
    ui->OpenGlWidget->edges_type = DASHED;
    ui->OpenGlWidget->update();
}


void MainWindow::on_edge_thic_val_valueChanged(int value)
{
    ui->OpenGlWidget->edges_thickness = value/10;
    ui->OpenGlWidget->update();
}


void MainWindow::on_edge_color_val_clicked()
{
    QColor edge_color = QColorDialog::getColor(Qt::white, this->ui->tabWidget, "Choose color");
    if (edge_color.isValid()) {
        ui->OpenGlWidget->e_red = edge_color.redF();
        ui->OpenGlWidget->e_green = edge_color.greenF();
        ui->OpenGlWidget->e_blue = edge_color.blueF();
        char rgba_color[40];
        sprintf(rgba_color, "background-color: rgb(%d,%d,%d)", edge_color.red(), edge_color.green(), edge_color.blue());
        ui->edge_color_val->setStyleSheet(rgba_color);
        ui->OpenGlWidget->update();
    }
}


void MainWindow::on_background_color_val_clicked()
{
    QColor bg_color = QColorDialog::getColor(Qt::white, this->ui->tabWidget, "Choose color");
    if (bg_color.isValid()) {
        ui->OpenGlWidget->bg_red = bg_color.redF();
        ui->OpenGlWidget->bg_green = bg_color.greenF();
        ui->OpenGlWidget->bg_blue = bg_color.blueF();
        char rgba_color[40];
        sprintf(rgba_color, "background-color: rgb(%d,%d,%d)", bg_color.red(), bg_color.green(), bg_color.blue());
        ui->background_color_val->setStyleSheet(rgba_color);
        ui->OpenGlWidget->update();
    }
}


void MainWindow::on_scale_val_valueChanged(int value)
{
    double val = (double)value / ui->OpenGlWidget->scale;
    scale(&ui->OpenGlWidget->data, val);
    ui->OpenGlWidget->scale = value;
    ui->OpenGlWidget->update();
}


void MainWindow::on_rotate_x_val_valueChanged(int value)
{
    rotate_X(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->rotate_x));
    ui->OpenGlWidget->rotate_x = value;
    ui->OpenGlWidget->update();
}


void MainWindow::on_rotate_y_val_valueChanged(int value)
{
    rotate_Y(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->rotate_y));
    ui->OpenGlWidget->rotate_y = value;
    ui->OpenGlWidget->update();
}


void MainWindow::on_rotate_z_val_valueChanged(int value)
{
    rotate_Z(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->rotate_z));
    ui->OpenGlWidget->rotate_z = value;
    ui->OpenGlWidget->update();
}


void MainWindow::on_translate_x_val_valueChanged(int value)
{
    move_X(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->translate_x) * ui->OpenGlWidget->normalize_coef / 100);
    ui->OpenGlWidget->translate_x = value;
    ui->OpenGlWidget->update();
}


void MainWindow::on_translate_y_val_valueChanged(int value)
{
    move_Y(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->translate_y) * ui->OpenGlWidget->normalize_coef / 100);
    ui->OpenGlWidget->translate_y = value;
    ui->OpenGlWidget->update();
}


void MainWindow::on_translate_z_val_valueChanged(int value)
{
    move_Z(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->translate_z) * ui->OpenGlWidget->normalize_coef / 100);
    ui->OpenGlWidget->translate_z = value;
    ui->OpenGlWidget->update();
}

