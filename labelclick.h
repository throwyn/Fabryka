#ifndef LABELCLICK_H
#define LABELCLICK_H

#include <QObject>
#include <QWidget>
#include <QLabel>

#include <QMouseEvent>

class LabelClick : public QObject
{
    Q_OBJECT
public:
    LabelClick(QWidget * parent = 0 );
    ~LabelClick(){}


protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);


signals:
    void sendMousePosition(QPoint&);


    };
#endif // LABELCLICK_H
