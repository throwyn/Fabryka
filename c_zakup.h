#ifndef C_ZAKUP_H
#define C_ZAKUP_H

#include <QEvent>
#include <QObject>
#include <QLineEdit>
#include "c_ceny.h"
#include "c_sklad.h"
#include "c_zakup.h"
#include "my_qlabel.h"

class C_zakup
{
public:
    C_zakup();
public slots:
    void mniej_material(double,double,double,QLineEdit*,QLabel*, QLabel*);
    void wiecej_material(double,double,QLineEdit*,QLabel*, QLabel*);
};

#endif // C_ZAKUP_H
