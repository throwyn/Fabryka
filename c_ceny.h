#ifndef C_CENY_H
#define C_CENY_H


class C_ceny
{
public:
    C_ceny();

public:

    //Cena za zakup materialow
    double karton_kup = 0.24;
    double cement_kup = 4.19;
    double magnes_kup = 5.68;
    double metal_kup = 3.40;
    double farba_kup = 2.26;
    double plastik_kup = 0.60;
    double rzadki_metal_kup = 7.81;
    double guma_kup = 1.10;
    double drut_kup = 1.71;

    //Cena za sprzedaż materiałów
    double karton_sprzedaj = 0.18;
    double cement_sprzedaj = 3.14;
    double magnes_sprzedaj = 4.26;
    double metal_sprzedaj = 2.55;
    double farba_sprzedaj = 1.70;
    double plastik_sprzedaj = 0.45;
    double rzadki_metal_sprzedaj = 5.86;
    double guma_sprzedaj = 0.83;
    double drut_sprzedaj = 1.28;

    //Cena za spprzedaż produkow
    double beton_sprzedaj = 14.47;
    double pas_sprzedaj = 2.60;
    double pudlo_sprzedaj = 2.21;
    double kabel_sprzedaj = 3.28;
    double uklad_sprzedaj = 3.54;
    double koloz_sprzedaj = 6.56;
    double waz_sprzedaj = 2.60;
    double kolom_sprzedaj = 6.56;
    double silnik_sprzedaj = 17.40;
    double kolop_sprzedaj = 1.72;
    double pompa_sprzedaj = 8.72;
    double krasnal_sprzedaj = 15.90;
    double glosniki_sprzedaj = 29.42;
    double toster_sprzedaj = 22.74;

    double ramie_sprzedaj = 51;
    double tasma_sprzedaj = 100;
    double samoch_sprzedaj = 35;
    double pistolet_sprzedaj = 29;
    double wieza_sprzedaj = 414;
    double ukladlo_sprzedaj = 26.75;
    double widzet_sprzedaj = 15.78;
    double budowniczy_sprzedaj = 400;
    double automatk_sprzedaj = 80;
    double automats_sprzedaj = 100;
};

#endif // C_CENY_H
