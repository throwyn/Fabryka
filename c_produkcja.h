#ifndef C_PRODUKCJA_H
#define C_PRODUKCJA_H

#include <QObject>
#include <QProgressBar>
#include "c_ceny.h"
#include "c_sklad.h"
#include "c_zakup.h"
#include "my_qlabel.h"

class C_produkcja
{
public:
    C_produkcja();

public slots:
void Buduj_pudlo(C_sklad*, QProgressBar*, QLabel*);
void buduj_kabel(C_sklad*, QLabel*);
void C_produkcja::buduj_beton(C_sklad* sklad,QProgressBar* proggress_beton,QLabel* s1_beton,QLabel* s2_beton);

void C_produkcja::buduj_pas(C_sklad* sklad,QProgressBar* proggress_pas,QLabel* s1_pas);

void C_produkcja::buduj_uklad(C_sklad* sklad,QProgressBar* proggress_uklad,QLabel* s1_uklad,QLabel* s2_uklad);

void C_produkcja::buduj_koloz(C_sklad* sklad,QProgressBar* proggress_koloz,QLabel* s1_koloz);

void C_produkcja::buduj_waz(C_sklad* sklad,QProgressBar* proggress_waz,QLabel* s1_waz);

void C_produkcja::buduj_kolom(C_sklad* sklad,QProgressBar* proggress_kolom,QLabel* s1_kolom);

void C_produkcja::buduj_silnik(C_sklad* sklad,QProgressBar* proggress_silnik,QLabel* s1_silnik,QLabel* s2_silnik,QLabel* s3_silnik);

void C_produkcja::buduj_kolop(C_sklad* sklad,QProgressBar* proggress_kolop,QLabel* s1_kolop);

void C_produkcja::buduj_pompa(C_sklad* sklad,QProgressBar* proggress_pompa,QLabel* s1_pompa,QLabel* s2_pompa,QLabel* s3_pompa);

void C_produkcja::buduj_krasnal(C_sklad* sklad,QProgressBar* proggress_krasnal,QLabel* s1_krasnal,QLabel* s2_krasnal,QLabel* s3_krasnal);

void C_produkcja::buduj_glosniki(C_sklad* sklad,QProgressBar* proggress_glosniki,QLabel* s1_glosniki,QLabel* s2_glosniki,QLabel* s3_glosniki,QLabel* s4_glosniki);

void C_produkcja::buduj_toster(C_sklad* sklad,QProgressBar* proggress_toster,QLabel* s1_toster,QLabel* s2_toster,QLabel* s3_toster);

void C_produkcja::buduj_ramie(C_sklad* sklad,QProgressBar* proggress_ramie,QLabel* s1_ramie,QLabel* s2_ramie,QLabel* s3_ramie);

void C_produkcja::buduj_tasma(C_sklad* sklad,QProgressBar* proggress_tasma,QLabel* s1_tasma,QLabel* s2_tasma,QLabel* s3_tasma,QLabel* s4_tasma);

void C_produkcja::buduj_samoch(C_sklad* sklad,QProgressBar* proggress_samoch,QLabel* s1_samoch,QLabel* s2_samoch,QLabel* s3_samoch,QLabel* s4_samoch,QLabel* s5_samoch);

void C_produkcja::buduj_pistolet(C_sklad* sklad,QProgressBar* proggress_pistolet,QLabel* s1_pistolet,QLabel* s2_pistolet,QLabel* s3_pistolet,QLabel* s4_pistolet);

void C_produkcja::buduj_wieza(C_sklad* sklad,QProgressBar* proggress_wieza,QLabel* s1_wieza,QLabel* s2_wieza,QLabel* s3_wieza);

void C_produkcja::buduj_ukladlo(C_sklad* sklad,QProgressBar* proggress_ukladlo,QLabel* s1_ukladlo,QLabel* s2_ukladlo);

void C_produkcja::buduj_widzet(C_sklad* sklad,QProgressBar* proggress_widzet,QLabel* s1_widzet,QLabel* s2_widzet,QLabel* s3_widzet,QLabel* s4_widzet,QLabel* s5_widzet);

void C_produkcja::buduj_budowniczy(C_sklad* sklad,QProgressBar* proggress_budowniczy,QLabel* s1_budowniczy,QLabel* s2_budowniczy,QLabel* s3_budowniczy,QLabel* s4_budowniczy,QLabel* s5_budowniczy);

void C_produkcja::buduj_automatk(C_sklad* sklad,QProgressBar* proggress_automatk,QLabel* s1_automatk,QLabel* s2_automatk,QLabel* s3_automatk,QLabel* s4_automatk,QLabel* s5_automatk);

void C_produkcja::buduj_automats(C_sklad* sklad,QProgressBar* proggress_automats,QLabel* s1_automats,QLabel* s2_automats,QLabel* s3_automats,QLabel* s4_automats,QLabel* s5_automats);

};

#endif // C_PRODUKCJA_H
