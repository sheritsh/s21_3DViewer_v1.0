#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_mainwindow_attributes();
    set_fonts();
    bind_slots();


}

MainWindow::~MainWindow()
{
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
    ui->vert_numb_val->setText();
    ui->edges_numb_val->setText();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    new_pos = QPoint(event->globalPosition().toPoint() - cur_pos);
    move(x() + new_pos.x(), y() + new_pos.y());
    cur_pos = event->globalPosition().toPoint();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    cur_pos = event->globalPosition().toPoint();
}


