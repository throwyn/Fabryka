#include "c_zakup.h"

C_zakup::C_zakup()
{

}


void C_zakup::mniej_material(double ilosc, double cena_kup, double cena_sprzedaj, QLineEdit * zakup_ile, QLabel *koszt_zysk, QLabel *cena_za_ilosc)
{
    QString text = zakup_ile->text();
    int a = text.toInt();

         if ((ilosc + a) <= 0)
         {
           QString temp = QString::number((-1)*ilosc);
             zakup_ile->setText(temp);
          }
         else
         {

             a--;
             QString sa = QString::number(a);
             zakup_ile->setText(sa);

             if (a < 0)
             {
                 koszt_zysk->setText("Zysk");
                 QString cena = QString::number(abs(a*cena_sprzedaj));
                 cena_za_ilosc->setText(cena );
             }
             else
             {
                 QString cena = QString::number(a*cena_kup);
                 cena_za_ilosc->setText(cena ) ;
             }

         }
}

void C_zakup::wiecej_material(double cena_kup, double cena_sprzedaj, QLineEdit * zakup_ile, QLabel *koszt_zysk, QLabel *cena_za_ilosc)
{
    QString text = zakup_ile->text();
    int a = text.toInt();

        a++;
        QString sa = QString::number(a);
        zakup_ile->setText(sa);

        if (a < 0)
        {
            QString cena = QString::number(abs(a*cena_sprzedaj));
            cena_za_ilosc->setText(cena );
        }
        else
        {
            koszt_zysk->setText("Koszt");
            QString cena = QString::number(a*cena_kup);
            cena_za_ilosc->setText(cena ) ;
        }
}
