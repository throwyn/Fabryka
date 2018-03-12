#include "labelclick.h"
#include <QMessageBox>

LabelClick::LabelClick(QObject *parent) : QObject(parent)
{
    this->setMouseTracking(true);
}
LabelClick::~LabelClick()
{

}




void LabelClick::mouseMoveEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_pos = mouse_event->pos();

    if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <=this->size().height())
    {
        if(mouse_pos.x() > 0 && mouse_pos.y() > 0)
        {
            emit sendMousePosition(mouse_pos);
        }
    }
}

void LabelClick::mousePressEvent(QMouseEvent *mouse_event)
{
    if(mouse_event->button() == Qt::LeftButton)
    {
        QMessageBox msg;
        msg.setText("leelellelele");
        msg.exec();
    }

}

