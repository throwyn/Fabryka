#include "oknoglowne.h"
#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    oknoglowne w;
    w.show();

    return a.exec();
}
