#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 344, 344);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setFixedSize(350, 350);

    compass = new Compass;
    compass->setPos(172, 172);

    degree = new QGraphicsPixmapItem;
    degree->setPixmap(QPixmap(":/degree.jpeg").scaled(344, 344, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    degree->setPos(0, 0);

    scene->addItem(degree);
    scene->addItem(compass);

    sensor = new QCompass;

    ui->pushButton->setStyleSheet("QPushButton { background-color: #9aff5a }");
    ui->pushButton->setText("START");
    ui->pushButton->setFixedHeight(60);

    connect(sensor, SIGNAL(readingChanged()), this ,SLOT(slot_change_detected()));
    connect(this, SIGNAL(sig_arrow_rotated(qreal)), this ,SLOT(slot_arrow_rotated(qreal)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_butt_cliced()));
}

void MainWindow::slot_butt_cliced(){
    if(ui->pushButton->isChecked()){
        ui->pushButton->setStyleSheet("QPushButton { background-color: #ca2222 }");
        ui->pushButton->setText("STOP");
        sensor->setActive(true);
    } else {
        ui->pushButton->setStyleSheet("QPushButton { background-color: #9aff5a }");
        ui->pushButton->setText("START");
        sensor->setActive(false);
    }
}

void MainWindow::slot_change_detected(){
    qreal azimuth = sensor->reading()->azimuth();
    emit sig_arrow_rotated(180 - azimuth);

    if(-azimuth >= 0){
        ui->label->setText(QString::number(-azimuth) + "°");
    } else {
        ui->label->setText(QString::number(360 - azimuth) + "°");
    }
}

void MainWindow::slot_arrow_rotated(qreal degree){
    compass->setRotation(degree);
    scene->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
