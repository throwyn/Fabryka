#ifndef C_SKLAD_H
#define C_SKLAD_H


class C_sklad
{
public:
    C_sklad();




public:
    double fundusze = 50;
    //materialy
    int karton = 0;
    int cement = 0;
    int magnes = 0;
   int metal = 0;
    int farba = 0;
    int plastik = 0;
    int rzadki_metal=0;
    int guma = 0;
    int drut = 0;
    //polprodukty
    int pas = 0;
    int beton = 0;
    int pudlo = 0;
    int kabel = 0;
    int uklad = 0;
    int koloz = 0;
    int waz = 0;
    int kolom = 0;
    int silnik = 0;
    int kolop = 0;
    int pompa = 0;

    //produkty
    int krasnal = 0;
    int glosniki = 0;
    int toster = 0;
    int ramie = 0;
    int tasma = 0;
    int samoch = 0;
    int pistolet = 0;
    int wieza = 0;
    int ukladlo = 0;
    int widzet = 0;

    //przedmioty wykonujace czynnosci
    int budowniczy = 0;
    int automatk = 0;
    int automats = 0;
};

#endif // C_SKLAD_H
