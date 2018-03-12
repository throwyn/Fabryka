#ifndef C_MAGAZYN_H
#define C_MAGAZYN_H

#include <QEvent>
#include <QObject>
#include <QLineEdit>
#include "c_ceny.h"
#include "c_sklad.h"
#include "c_zakup.h"
#include "my_qlabel.h"
#include <QScrollArea>

class c_magazyn
{
public:
    c_magazyn();

    void sprzedaj_mniej(double&, QLineEdit*,QLabel*,QLabel*);
    void sprzedaj_wiecej(double&, int&, QLineEdit*,QLabel*,QLabel*);
  //  void sprzedaj_button(QScrollArea*,QLabel*,C_sklad&,QLabel*);


    void nowa_gra(C_sklad*);
};

#endif // C_MAGAZYN_H
