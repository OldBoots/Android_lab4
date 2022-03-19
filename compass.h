#ifndef COMPASS_H
#define COMPASS_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class Compass : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Compass(QObject *obj = nullptr);

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
        QWidget* widget) override;
};

#endif // COMPASS_H
