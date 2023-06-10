#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    int id = QFontDatabase::addApplicationFont(":/res/assets/fonts/SpaceCrusadersItalic-ZV1Zx.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont titleFont(family);
    int id2 = QFontDatabase::addApplicationFont(":/res/assets/fonts/Montserrat-Regular.ttf");
    QString family2 = QFontDatabase::applicationFontFamilies(id2).at(0);
    QFont mainFont(family2);
    ui->h1->setFont(titleFont);
    ui->obj_info->setFont(mainFont);
    this->setAutoFillBackground(true);
    ui->OpenGlWidget->parse_obj();
}

MainWindow::~MainWindow()
{
    delete ui;
}

