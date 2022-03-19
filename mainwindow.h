#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>
#include <QSensor>
#include <QCompass>
#include <QGraphicsPixmapItem>
#include "compass.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sig_arrow_rotated(qreal degree);

private  slots:
    void slot_arrow_rotated(qreal degree);
    void slot_change_detected();
    void slot_butt_cliced();
private:
    QGraphicsScene *scene;
    QCompass *sensor;
    QGraphicsPixmapItem *degree;
    Compass *compass;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
