#include "c_magazyn.h"

c_magazyn::c_magazyn()
{

}

void c_magazyn::sprzedaj_mniej(double &ceny, QLineEdit* sprzedaj_ilosc, QLabel* msuma_przedmiowtow, QLabel* msuma_zysk)
{
    int a = sprzedaj_ilosc->text().toInt();
    if(a > 0)
    {
        a--;
        sprzedaj_ilosc->setText(QString::number(a));

        int b = msuma_przedmiowtow->text().toInt();
        b--;
        msuma_przedmiowtow->setText(QString::number(b));

        double c = msuma_zysk->text().toDouble();
        c-=ceny;
        msuma_zysk->setText(QString::number(c));



    }
}

void c_magazyn::sprzedaj_wiecej(double &ceny,int &sklad, QLineEdit* sprzedaj_ilosc, QLabel* msuma_przedmiowtow, QLabel* msuma_zysk)
{
    int a = sprzedaj_ilosc->text().toInt();
    if(sklad > a)
    {
        a++;
        sprzedaj_ilosc->setText(QString::number(a));

        int b = msuma_przedmiowtow->text().toInt();
        b++;
        msuma_przedmiowtow->setText(QString::number(b));

        double c = msuma_zysk->text().toDouble();
        c+=ceny;
        msuma_zysk->setText(QString::number(c));



    }
}

void c_magazyn::nowa_gra(C_sklad *sklad)
{
    sklad->fundusze = 50;
    sklad->karton = 0;
    sklad->cement = 0;
    sklad->magnes = 0;
    sklad->metal = 0;
    sklad->farba = 0;
    sklad->plastik = 0;
    sklad->rzadki_metal=0;
    sklad->guma = 0;
    sklad->drut = 0;
    sklad->pas = 0;
    sklad->beton = 0;
    sklad->pudlo = 0;
    sklad->kabel = 0;
    sklad->uklad = 0;
    sklad->koloz = 0;
    sklad->waz = 0;
    sklad->kolom = 0;
    sklad->silnik = 0;
    sklad->kolop = 0;
    sklad->pompa = 0;
    sklad->krasnal = 0;
    sklad->glosniki = 0;
    sklad->toster = 0;
    sklad->ramie = 0;
    sklad->tasma = 0;
    sklad->samoch = 0;
    sklad->pistolet = 0;
    sklad->wieza = 0;
    sklad->ukladlo = 0;
    sklad->widzet = 0;
    sklad->budowniczy = 0;
    sklad->automatk = 0;
    sklad->automats = 0;
}


