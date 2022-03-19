#include "compass.h"

Compass::Compass(QObject *obj) : QObject(obj) , QGraphicsPixmapItem(){

}

void Compass::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                    QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing); // сглаживание
    painter->setRenderHint(QPainter::SmoothPixmapTransform);
    painter->drawPixmap(-31, -150, QPixmap(":/стрелка1.png").scaled(63, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation), 0, 0, 126, 300);
}
