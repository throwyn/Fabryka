#include "oknoglowne.h"
#include "ui_oknoglowne.h"
#include <QString>







oknoglowne::oknoglowne(QWidget *parent) : QMainWindow(parent), ui(new Ui::oknoglowne)
{
    ui->setupUi(this);

    QTimer *automaty = new QTimer(this);
    connect(automaty,SIGNAL(timeout()),this,SLOT(automaty_funkcje_timera()));
    automaty->start(100);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(odswiez()));
    timer->start(100);

    //Buduj przyciski
    connect(ui->buduj_pudlo,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_pudlo()));
    connect(ui->buduj_kabel,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_kabel()));
    connect(ui->buduj_beton,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_beton()));
    connect(ui->buduj_uklad,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_uklad()));
    connect(ui->buduj_koloz,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_koloz()));
    connect(ui->buduj_pas,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_pas()));
    connect(ui->buduj_waz,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_waz()));
    connect(ui->buduj_kolom,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_kolom()));
    connect(ui->buduj_silnik,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_silnik()));
    connect(ui->buduj_kolop,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_kolop()));
    connect(ui->buduj_pompa,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_pompa()));
    connect(ui->buduj_krasnal,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_krasnal()));
    connect(ui->buduj_glosniki,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_glosniki()));
    connect(ui->buduj_toster,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_toster()));
    connect(ui->buduj_ramie,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_ramie()));
    connect(ui->buduj_tasma,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_tasma()));
    connect(ui->buduj_samoch,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_samoch()));
    connect(ui->buduj_pistolet,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_pistolet()));
    connect(ui->buduj_wieza,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_wieza()));
    connect(ui->buduj_ukladlo,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_ukladlo()));
    connect(ui->buduj_widzet,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_widzet()));
    connect(ui->buduj_budowniczy,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_budowniczy()));
    connect(ui->buduj_automatk,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_automatk()));
    connect(ui->buduj_automats,SIGNAL(Mouse_Pressed()),this,SLOT(buduj_automats()));
}

oknoglowne::~oknoglowne()
{
    delete ui;
}


void oknoglowne::odswiez()
{
                                                                                            //odswieża aktualne saldo
    ui->fundusze->setText(QString::number(sklad.fundusze) + "zł");

    /*  double a =(      (ui->cena_za_ilosc_karton->text()).toDouble()
               +  (ui->cena_za_ilosc_cement->text()).toDouble()
               +  (ui->cena_za_ilosc_magnes->text()).toDouble()
               +  (ui->cena_za_ilosc_metal->text()).toDouble()
               +  (ui->cena_za_ilosc_farba->text()).toDouble()
               +  (ui->cena_za_ilosc_plastik->text()).toDouble()
               +  (ui->cena_za_ilosc_rzadki_metal->text()).toDouble()
               +  (ui->cena_za_ilosc_guma->text()).toDouble()
               +  (ui->cena_za_ilosc_drut->text()).toDouble());
*/

                                                                                            //Sprawdza czy mozliwa produkcja
        //pudlo
           if (sklad.karton >= 1)
               ui->s1_pudlo->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_pudlo->setStyleSheet("QLabel{color:red}");

        //kabel
           if (sklad.metal >= 1)
               ui->s1_kabel->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_kabel->setStyleSheet("QLabel{color:red}");

        //beton

           if (sklad.cement >= 1)
               ui->s1_beton->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_beton->setStyleSheet("QLabel{color:red}");
           if (sklad.metal >= 1)
               ui->s2_beton->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_beton->setStyleSheet("QLabel{color:red}");

        //pas
           if (sklad.guma >= 1)
               ui->s1_pas->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_pas->setStyleSheet("QLabel{color:red}");

        //uklad
           if (sklad.plastik >= 1)
               ui->s1_uklad->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_uklad->setStyleSheet("QLabel{color:red}");

           if (sklad.drut >= 1)
               ui->s2_uklad->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_uklad->setStyleSheet("QLabel{color:red}");

        //koło zębate
           if (sklad.metal >= 1)
               ui->s1_koloz->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_koloz->setStyleSheet("QLabel{color:red}");

        //waz
           if (sklad.guma >= 1)
               ui->s1_waz->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_waz->setStyleSheet("QLabel{color:red}");

        //koło metalowe
           if (sklad.metal >= 1)
               ui->s1_kolom->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_kolom->setStyleSheet("QLabel{color:red}");

        //silnik
           if (sklad.magnes >= 1)
               ui->s1_silnik->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_silnik->setStyleSheet("QLabel{color:red}");

           if (sklad.metal >= 1)
               ui->s2_silnik->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_silnik->setStyleSheet("QLabel{color:red}");

           if (sklad.drut >= 1)
               ui->s3_silnik->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_silnik->setStyleSheet("QLabel{color:red}");

        //koło plastikowe
           if (sklad.plastik >= 1)
               ui->s1_kolop->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_kolop->setStyleSheet("QLabel{color:red}");

        //pompa
           if (sklad.metal >= 1)
               ui->s1_pompa->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_pompa->setStyleSheet("QLabel{color:red}");

           if (sklad.plastik >= 1)
               ui->s2_pompa->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_pompa->setStyleSheet("QLabel{color:red}");

           if (sklad.guma >= 1)
               ui->s3_pompa->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_pompa->setStyleSheet("QLabel{color:red}");

        //glosniki

           if (sklad.magnes >= 1)
               ui->s1_glosniki->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_glosniki->setStyleSheet("QLabel{color:red}");

           if (sklad.plastik >= 1)
               ui->s2_glosniki->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_glosniki->setStyleSheet("QLabel{color:red}");

           if (sklad.drut >= 1)
               ui->s3_glosniki->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_glosniki->setStyleSheet("QLabel{color:red}");
           if (sklad.pudlo >= 1)
               ui->s4_glosniki->setStyleSheet("QLabel{color:white}");
           else
               ui->s4_glosniki->setStyleSheet("QLabel{color:red}");

        //toster
           if (sklad.metal >= 1)
               ui->s1_toster->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_toster->setStyleSheet("QLabel{color:red}");

           if (sklad.drut >= 1)
               ui->s2_toster->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_toster->setStyleSheet("QLabel{color:red}");

           if (sklad.pudlo >= 1)
               ui->s3_toster->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_toster->setStyleSheet("QLabel{color:red}");

        //krasnal
           if (sklad.cement >= 1)
               ui->s1_krasnal->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_krasnal->setStyleSheet("QLabel{color:red}");

           if (sklad.farba >= 1)
               ui->s2_krasnal->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_krasnal->setStyleSheet("QLabel{color:red}");

           if (sklad.pudlo >= 1)
               ui->s3_krasnal->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_krasnal->setStyleSheet("QLabel{color:red}");


        //ramie
           if (sklad.metal >= 1)
               ui->s1_ramie->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_ramie->setStyleSheet("QLabel{color:red}");

           if (sklad.uklad >= 1)
               ui->s2_ramie->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_ramie->setStyleSheet("QLabel{color:red}");

           if (sklad.silnik >= 1)
               ui->s3_ramie->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_ramie->setStyleSheet("QLabel{color:red}");

        //tasma
           if (sklad.pas >= 1)
               ui->s1_tasma->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_tasma->setStyleSheet("QLabel{color:red}");

           if (sklad.silnik >= 1)
               ui->s2_tasma->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_tasma->setStyleSheet("QLabel{color:red}");

           if (sklad.koloz >= 1)
               ui->s3_tasma->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_tasma->setStyleSheet("QLabel{color:red}");

           if (sklad.kolom >= 1)
               ui->s4_tasma->setStyleSheet("QLabel{color:white}");
           else
               ui->s4_tasma->setStyleSheet("QLabel{color:red}");


        //widzet
           if (sklad.metal >= 1)
               ui->s1_widzet->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_widzet->setStyleSheet("QLabel{color:red}");

           if (sklad.plastik >= 1)
               ui->s2_widzet->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_widzet->setStyleSheet("QLabel{color:red}");

           if (sklad.drut >= 1)
               ui->s3_widzet->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_widzet->setStyleSheet("QLabel{color:red}");

           if (sklad.uklad >= 1)
               ui->s4_widzet->setStyleSheet("QLabel{color:white}");
           else
               ui->s4_widzet->setStyleSheet("QLabel{color:red}");

           if (sklad.ukladlo >= 1)
               ui->s5_widzet->setStyleSheet("QLabel{color:white}");
           else
               ui->s5_widzet->setStyleSheet("QLabel{color:red}");

        //ukladlo
           if (sklad.drut >= 1)
               ui->s1_ukladlo->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_ukladlo->setStyleSheet("QLabel{color:red}");

           if (sklad.uklad >= 1)
               ui->s2_ukladlo->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_ukladlo->setStyleSheet("QLabel{color:red}");

        //samoch
           if (sklad.metal >= 1)
               ui->s1_samoch->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_samoch->setStyleSheet("QLabel{color:red}");

           if (sklad.farba >= 1)
               ui->s2_samoch->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_samoch->setStyleSheet("QLabel{color:red}");

           if (sklad.plastik >= 1)
               ui->s3_samoch->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_samoch->setStyleSheet("QLabel{color:red}");

           if (sklad.kolop >= 1)
               ui->s4_samoch->setStyleSheet("QLabel{color:white}");
           else
               ui->s4_samoch->setStyleSheet("QLabel{color:red}");

           if (sklad.pudlo >= 1)
               ui->s5_samoch->setStyleSheet("QLabel{color:white}");
           else
               ui->s5_samoch->setStyleSheet("QLabel{color:red}");

        //budowniczy
           if (sklad.silnik >= 1)
               ui->s1_budowniczy->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_budowniczy->setStyleSheet("QLabel{color:red}");

           if (sklad.ramie >= 1)
               ui->s2_budowniczy->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_budowniczy->setStyleSheet("QLabel{color:red}");

           if (sklad.widzet >= 1)
               ui->s3_budowniczy->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_budowniczy->setStyleSheet("QLabel{color:red}");

           if (sklad.tasma >= 1)
               ui->s4_budowniczy->setStyleSheet("QLabel{color:white}");
           else
               ui->s4_budowniczy->setStyleSheet("QLabel{color:red}");

           if (sklad.pompa >= 1)
               ui->s5_budowniczy->setStyleSheet("QLabel{color:white}");
           else
               ui->s5_budowniczy->setStyleSheet("QLabel{color:red}");

        //automatk
           if (sklad.farba >= 1)
               ui->s1_automatk->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_automatk->setStyleSheet("QLabel{color:red}");

           if (sklad.drut >= 1)
               ui->s2_automatk->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_automatk->setStyleSheet("QLabel{color:red}");

           if (sklad.uklad >= 1)
               ui->s3_automatk->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_automatk->setStyleSheet("QLabel{color:red}");

           if (sklad.ukladlo >= 1)
               ui->s4_automatk->setStyleSheet("QLabel{color:white}");
           else
               ui->s4_automatk->setStyleSheet("QLabel{color:red}");

           if (sklad.widzet >= 1)
               ui->s5_automatk->setStyleSheet("QLabel{color:white}");
           else
               ui->s5_automatk->setStyleSheet("QLabel{color:red}");

        //automats
           if (sklad.farba >= 1)
               ui->s1_automats->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_automats->setStyleSheet("QLabel{color:red}");

           if (sklad.drut >= 1)
               ui->s2_automats->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_automats->setStyleSheet("QLabel{color:red}");

           if (sklad.uklad >= 1)
               ui->s3_automats->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_automats->setStyleSheet("QLabel{color:red}");

           if (sklad.ukladlo >= 1)
               ui->s4_automats->setStyleSheet("QLabel{color:white}");
           else
               ui->s4_automats->setStyleSheet("QLabel{color:red}");

           if (sklad.widzet >= 1)
               ui->s5_automats->setStyleSheet("QLabel{color:white}");
           else
               ui->s5_automats->setStyleSheet("QLabel{color:red}");

        //pistolet
           if (sklad.farba >= 1)
               ui->s1_pistolet->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_pistolet->setStyleSheet("QLabel{color:red}");

           if (sklad.plastik >= 1)
               ui->s2_pistolet->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_pistolet->setStyleSheet("QLabel{color:red}");

           if (sklad.waz >= 1)
               ui->s3_pistolet->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_pistolet->setStyleSheet("QLabel{color:red}");

           if (sklad.pudlo >= 1)
               ui->s4_pistolet->setStyleSheet("QLabel{color:white}");
           else
               ui->s4_pistolet->setStyleSheet("QLabel{color:red}");

        //wieza
           if (sklad.metal >= 1)
               ui->s1_wieza->setStyleSheet("QLabel{color:white}");
           else
               ui->s1_wieza->setStyleSheet("QLabel{color:red}");

           if (sklad.kabel >= 1)
               ui->s2_wieza->setStyleSheet("QLabel{color:white}");
           else
               ui->s2_wieza->setStyleSheet("QLabel{color:red}");

           if (sklad.beton >= 1)
               ui->s3_wieza->setStyleSheet("QLabel{color:white}");
           else
               ui->s3_wieza->setStyleSheet("QLabel{color:red}");


                                                                                      //Aktualizowanie ilosci materialow

    ui->zmagazyn_ile_karton->setText(QString::number(sklad.karton));
    ui->zmagazyn_ile_cement->setText(QString::number(sklad.cement));
    ui->zmagazyn_ile_magnes->setText(QString::number(sklad.magnes));
    ui->zmagazyn_ile_metal->setText(QString::number(sklad.metal));
    ui->zmagazyn_ile_farba->setText(QString::number(sklad.farba));
    ui->zmagazyn_ile_plastik->setText(QString::number(sklad.plastik));
    ui->zmagazyn_ile_rzadki_metal->setText(QString::number(sklad.rzadki_metal));
    ui->zmagazyn_ile_guma->setText(QString::number(sklad.guma));
    ui->zmagazyn_ile_drut->setText(QString::number(sklad.drut));

                                                                                      //Aktualizowanie ilosc produktow produkcja
    ui->pmagazyn_ile_automatk->setText(QString::number(sklad.automatk));
    ui->pmagazyn_ile_pudlo->setText(QString::number(sklad.pudlo));
    ui->pmagazyn_ile_kabel->setText(QString::number(sklad.kabel));
    ui->pmagazyn_ile_beton->setText(QString::number(sklad.beton));
    ui->pmagazyn_ile_uklad->setText(QString::number(sklad.uklad));
    ui->pmagazyn_ile_koloz->setText(QString::number(sklad.koloz));
    ui->pmagazyn_ile_waz->setText(QString::number(sklad.waz));
    ui->pmagazyn_ile_pas->setText(QString::number(sklad.pas));
    ui->pmagazyn_ile_kolom->setText(QString::number(sklad.kolom));
    ui->pmagazyn_ile_silnik->setText(QString::number(sklad.silnik));
    ui->pmagazyn_ile_kolop->setText(QString::number(sklad.kolop));
    ui->pmagazyn_ile_pompa->setText(QString::number(sklad.pompa));
    ui->pmagazyn_ile_krasnal->setText(QString::number(sklad.krasnal));
    ui->pmagazyn_ile_glosniki->setText(QString::number(sklad.glosniki));
    ui->pmagazyn_ile_toster->setText(QString::number(sklad.toster));
    ui->pmagazyn_ile_ramie->setText(QString::number(sklad.ramie));
    ui->pmagazyn_ile_tasma->setText(QString::number(sklad.tasma));
    ui->pmagazyn_ile_samoch->setText(QString::number(sklad.samoch));
    ui->pmagazyn_ile_pistolet->setText(QString::number(sklad.pistolet));
    ui->pmagazyn_ile_wieza->setText(QString::number(sklad.wieza));
    ui->pmagazyn_ile_ukladlo->setText(QString::number(sklad.ukladlo));
    ui->pmagazyn_ile_widzet->setText(QString::number(sklad.widzet));
    ui->pmagazyn_ile_budowniczy->setText(QString::number(sklad.budowniczy));
    ui->pmagazyn_ile_automatk->setText(QString::number(sklad.automatk));
    ui->pmagazyn_ile_automats->setText(QString::number(sklad.automats));

                                                                                      //Aktualizowanie ilosc produktow magazyn
    ui->mmagazyn_ile_pudlo->setText(QString::number(sklad.pudlo));
    ui->mmagazyn_ile_kabel->setText(QString::number(sklad.kabel));
    ui->mmagazyn_ile_beton->setText(QString::number(sklad.beton));
    ui->mmagazyn_ile_uklad->setText(QString::number(sklad.uklad));
    ui->mmagazyn_ile_koloz->setText(QString::number(sklad.koloz));
    ui->mmagazyn_ile_waz->setText(QString::number(sklad.waz));
    ui->mmagazyn_ile_pas->setText(QString::number(sklad.pas));
    ui->mmagazyn_ile_kolom->setText(QString::number(sklad.kolom));
    ui->mmagazyn_ile_silnik->setText(QString::number(sklad.silnik));
    ui->mmagazyn_ile_kolop->setText(QString::number(sklad.kolop));
    ui->mmagazyn_ile_pompa->setText(QString::number(sklad.pompa));
    ui->mmagazyn_ile_krasnal->setText(QString::number(sklad.krasnal));
    ui->mmagazyn_ile_glosniki->setText(QString::number(sklad.glosniki));
    ui->mmagazyn_ile_toster->setText(QString::number(sklad.toster));
    ui->mmagazyn_ile_ramie->setText(QString::number(sklad.ramie));
    ui->mmagazyn_ile_tasma->setText(QString::number(sklad.tasma));
    ui->mmagazyn_ile_samoch->setText(QString::number(sklad.samoch));
    ui->mmagazyn_ile_pistolet->setText(QString::number(sklad.pistolet));
    ui->mmagazyn_ile_wieza->setText(QString::number(sklad.wieza));
    ui->mmagazyn_ile_ukladlo->setText(QString::number(sklad.ukladlo));
    ui->mmagazyn_ile_widzet->setText(QString::number(sklad.widzet));
    ui->mmagazyn_ile_budowniczy->setText(QString::number(sklad.budowniczy));
    ui->mmagazyn_ile_automatk->setText(QString::number(sklad.automatk));
    ui->mmagazyn_ile_automats->setText(QString::number(sklad.automats));
                                                                                      //Aktualizowanie ilosc automatow automaty
    ui->automaty_ilosc_autob->setText(QString::number(sklad.budowniczy));
    ui->automaty_ilosc_autok->setText(QString::number(sklad.automatk));
    ui->automaty_ilosc_autos->setText(QString::number(sklad.automats));
}


////////////////////////////////////////////BUDOWA//////////////////////////////////////////////
void oknoglowne::buduj_pudlo(){buduj.Buduj_pudlo(&sklad,ui->proggress_pudlo,ui->s1_pudlo);}
void oknoglowne::buduj_kabel(){buduj.buduj_kabel(&sklad,ui->s1_kabel);}
void oknoglowne::buduj_beton(){buduj.buduj_beton(&sklad,ui->proggress_beton,ui->s1_beton,ui->s2_beton);}
void oknoglowne::buduj_pas(){buduj.buduj_pas(&sklad,ui->proggress_pas,ui->s1_pas);}
void oknoglowne::buduj_uklad(){buduj.buduj_uklad(&sklad,ui->proggress_uklad,ui->s1_uklad,ui->s2_uklad);}
void oknoglowne::buduj_koloz(){buduj.buduj_koloz(&sklad,ui->proggress_koloz,ui->s1_koloz);}
void oknoglowne::buduj_waz(){buduj.buduj_waz(&sklad,ui->proggress_waz,ui->s1_waz);}
void oknoglowne::buduj_kolom(){buduj.buduj_kolom(&sklad,ui->proggress_kolom,ui->s1_kolom);}
void oknoglowne::buduj_silnik(){buduj.buduj_silnik(&sklad,ui->proggress_silnik,ui->s1_silnik,ui->s2_silnik,ui->s3_silnik);}
void oknoglowne::buduj_kolop(){buduj.buduj_kolop(&sklad,ui->proggress_kolop,ui->s1_kolop);}
void oknoglowne::buduj_pompa(){buduj.buduj_pompa(&sklad,ui->proggress_pompa,ui->s1_pompa,ui->s2_pompa,ui->s3_pompa);}
void oknoglowne::buduj_krasnal(){buduj.buduj_krasnal(&sklad,ui->proggress_krasnal,ui->s1_krasnal,ui->s2_krasnal,ui->s3_krasnal);}
void oknoglowne::buduj_glosniki(){buduj.buduj_glosniki(&sklad,ui->proggress_glosniki,ui->s1_glosniki,ui->s2_glosniki,ui->s3_glosniki,ui->s4_glosniki);}
void oknoglowne::buduj_toster(){buduj.buduj_toster(&sklad,ui->proggress_toster,ui->s1_toster,ui->s2_toster,ui->s3_toster);}
void oknoglowne::buduj_ramie(){buduj.buduj_ramie(&sklad,ui->proggress_ramie,ui->s1_ramie,ui->s2_ramie,ui->s3_ramie);}
void oknoglowne::buduj_tasma(){buduj.buduj_tasma(&sklad,ui->proggress_tasma,ui->s1_tasma,ui->s2_tasma,ui->s3_tasma,ui->s4_tasma);}
void oknoglowne::buduj_samoch(){buduj.buduj_samoch(&sklad,ui->proggress_samoch,ui->s1_samoch,ui->s2_samoch,ui->s3_samoch,ui->s4_samoch,ui->s5_samoch);}
void oknoglowne::buduj_pistolet(){buduj.buduj_pistolet(&sklad,ui->proggress_pistolet,ui->s1_pistolet,ui->s2_pistolet,ui->s3_pistolet,ui->s4_pistolet);}
void oknoglowne::buduj_wieza(){buduj.buduj_wieza(&sklad,ui->proggress_wieza,ui->s1_wieza,ui->s2_wieza,ui->s3_wieza);}
void oknoglowne::buduj_ukladlo(){buduj.buduj_ukladlo(&sklad,ui->proggress_ukladlo,ui->s1_ukladlo,ui->s2_ukladlo);}
void oknoglowne::buduj_widzet(){buduj.buduj_widzet(&sklad,ui->proggress_widzet,ui->s1_widzet,ui->s2_widzet,ui->s3_widzet,ui->s4_widzet,ui->s5_widzet);}
void oknoglowne::buduj_budowniczy(){buduj.buduj_budowniczy(&sklad,ui->proggress_budowniczy,ui->s1_budowniczy,ui->s2_budowniczy,ui->s3_budowniczy,ui->s4_budowniczy,ui->s5_budowniczy);}
void oknoglowne::buduj_automatk(){buduj.buduj_automatk(&sklad,ui->proggress_automatk,ui->s1_automatk,ui->s2_automatk,ui->s3_automatk,ui->s4_automatk,ui->s5_automatk);}
void oknoglowne::buduj_automats(){buduj.buduj_automats(&sklad,ui->proggress_automats,ui->s1_automats,ui->s2_automats,ui->s3_automats,ui->s4_automats,ui->s5_automats);}



//////////////////////////////////////////////////////ZAKUP SPRZEDAZ MATERIALOW/////////////////////////////////////////////////////





void oknoglowne::on_kup_mniej_karton_clicked(){zakup.mniej_material(sklad.karton,ceny.karton_kup,ceny.karton_sprzedaj,ui->zakup_ile_karton,ui->koszt_zysk_karton,ui->cena_za_ilosc_karton);}
void oknoglowne::on_kup_mniej_cement_clicked(){zakup.mniej_material(sklad.cement,ceny.cement_kup,ceny.cement_sprzedaj,ui->zakup_ile_cement,ui->koszt_zysk_cement,ui->cena_za_ilosc_cement);}
void oknoglowne::on_kup_mniej_drut_clicked(){zakup.mniej_material(sklad.drut,ceny.drut_kup,ceny.drut_sprzedaj,ui->zakup_ile_drut,ui->koszt_zysk_drut,ui->cena_za_ilosc_drut);}
void oknoglowne::on_kup_mniej_farba_clicked(){zakup.mniej_material(sklad.farba,ceny.farba_kup,ceny.farba_sprzedaj,ui->zakup_ile_farba,ui->koszt_zysk_farba,ui->cena_za_ilosc_farba);}
void oknoglowne::on_kup_mniej_guma_clicked(){zakup.mniej_material(sklad.guma,ceny.guma_kup,ceny.guma_sprzedaj,ui->zakup_ile_guma,ui->koszt_zysk_guma,ui->cena_za_ilosc_guma);}
void oknoglowne::on_kup_mniej_magnes_clicked(){zakup.mniej_material(sklad.magnes,ceny.magnes_kup,ceny.magnes_sprzedaj,ui->zakup_ile_magnes,ui->koszt_zysk_magnes,ui->cena_za_ilosc_magnes);}
void oknoglowne::on_kup_mniej_metal_clicked(){zakup.mniej_material(sklad.metal,ceny.metal_kup,ceny.metal_sprzedaj,ui->zakup_ile_metal,ui->koszt_zysk_metal,ui->cena_za_ilosc_metal);}
void oknoglowne::on_kup_mniej_plastik_clicked(){zakup.mniej_material(sklad.plastik,ceny.plastik_kup,ceny.plastik_sprzedaj,ui->zakup_ile_plastik,ui->koszt_zysk_plastik,ui->cena_za_ilosc_plastik);}
void oknoglowne::on_kup_mniej_rzadki_metal_clicked(){zakup.mniej_material(sklad.rzadki_metal,ceny.rzadki_metal_kup,ceny.rzadki_metal_sprzedaj,ui->zakup_ile_rzadki_metal,ui->koszt_zysk_rzadki_metal,ui->cena_za_ilosc_rzadki_metal);}




void oknoglowne::on_kup_wiecej_karton_clicked(){zakup.wiecej_material(ceny.karton_kup,ceny.karton_sprzedaj,ui->zakup_ile_karton,ui->koszt_zysk_karton,ui->cena_za_ilosc_karton);}
void oknoglowne::on_kup_wiecej_cement_clicked(){zakup.wiecej_material(ceny.cement_kup,ceny.cement_sprzedaj,ui->zakup_ile_cement,ui->koszt_zysk_cement,ui->cena_za_ilosc_cement);}
void oknoglowne::on_kup_wiecej_drut_clicked(){zakup.wiecej_material(ceny.drut_kup,ceny.drut_sprzedaj,ui->zakup_ile_drut,ui->koszt_zysk_drut,ui->cena_za_ilosc_drut);}
void oknoglowne::on_kup_wiecej_farba_clicked(){zakup.wiecej_material(ceny.farba_kup,ceny.farba_sprzedaj,ui->zakup_ile_farba,ui->koszt_zysk_farba,ui->cena_za_ilosc_farba);}
void oknoglowne::on_kup_wiecej_guma_clicked(){zakup.wiecej_material(ceny.guma_kup,ceny.guma_sprzedaj,ui->zakup_ile_guma,ui->koszt_zysk_guma,ui->cena_za_ilosc_guma);}
void oknoglowne::on_kup_wiecej_magnes_clicked(){zakup.wiecej_material(ceny.magnes_kup,ceny.magnes_sprzedaj,ui->zakup_ile_magnes,ui->koszt_zysk_magnes,ui->cena_za_ilosc_magnes);}
void oknoglowne::on_kup_wiecej_metal_clicked(){zakup.wiecej_material(ceny.metal_kup,ceny.metal_sprzedaj,ui->zakup_ile_metal,ui->koszt_zysk_metal,ui->cena_za_ilosc_metal);}
void oknoglowne::on_kup_wiecej_plastik_clicked(){zakup.wiecej_material(ceny.plastik_kup,ceny.plastik_sprzedaj,ui->zakup_ile_plastik,ui->koszt_zysk_plastik,ui->cena_za_ilosc_plastik);}
void oknoglowne::on_kup_wiecej_rzadki_metal_clicked(){zakup.wiecej_material(ceny.rzadki_metal_kup,ceny.rzadki_metal_sprzedaj,ui->zakup_ile_rzadki_metal,ui->koszt_zysk_rzadki_metal,ui->cena_za_ilosc_rzadki_metal);}

void oknoglowne::on_kup_sprzedaj_clicked()
{

    //zapisywanie do int ilosc zaznaczonych materialow
    QString tk = ui->zakup_ile_karton->text();
    QString tme = ui->zakup_ile_metal->text();
    QString tc = ui->zakup_ile_cement->text();
    QString td = ui->zakup_ile_drut->text();
    QString tf = ui->zakup_ile_farba->text();
    QString tg = ui->zakup_ile_guma->text();
    QString tma = ui->zakup_ile_magnes->text();
    QString tp = ui->zakup_ile_plastik->text();
    QString tr = ui->zakup_ile_rzadki_metal->text();


    int karton = tk.toInt();
    int metal = tme.toInt();
    int cement = tc.toInt();
    int drut = td.toInt();
    int farba = tf.toInt();
    int guma = tg.toInt();
    int magnes = tma.toInt();
    int plastik = tp.toInt();
    int rzadki = tr.toInt();


    //inicjacja cen materialow

    double cena_karton = 0;
    double cena_metal = 0;
    double cena_cement = 0;
    double cena_drut = 0;
    double cena_farba = 0;
    double cena_guma = 0;
    double cena_magnes = 0;
    double cena_plastik = 0;
    double cena_rzadki = 0;


        if (karton < 0)
            cena_karton = karton*ceny.karton_sprzedaj;
        else
            cena_karton = karton*ceny.karton_kup;

        if (metal < 0)
            cena_metal = metal*ceny.metal_sprzedaj;
        else
            cena_metal = metal*ceny.metal_kup;

        if (cement < 0)
            cena_cement = cement*ceny.cement_sprzedaj;
        else
            cena_cement = cement*ceny.cement_kup;

        if (drut < 0)
            cena_drut = drut*ceny.drut_sprzedaj;
        else
            cena_drut = drut*ceny.drut_kup;

        if (farba < 0)
            cena_farba = farba*ceny.farba_sprzedaj;
        else
            cena_farba = farba*ceny.farba_kup;

        if (guma < 0)
            cena_guma = guma*ceny.guma_sprzedaj;
        else
            cena_guma = guma*ceny.guma_kup;

        if (magnes < 0)
            cena_magnes = magnes*ceny.magnes_sprzedaj;
        else
            cena_magnes = magnes*ceny.magnes_kup;

        if (plastik < 0)
            cena_plastik = plastik*ceny.plastik_sprzedaj;
        else
            cena_plastik = plastik*ceny.plastik_kup;

        if (rzadki < 0)
            cena_rzadki = rzadki*ceny.rzadki_metal_sprzedaj;
        else
            cena_rzadki = rzadki*ceny.rzadki_metal_kup;

        double suma = cena_karton + cena_metal + cena_cement + cena_drut + cena_farba + cena_guma + cena_magnes + cena_plastik + cena_rzadki;

        if (suma <= sklad.fundusze)
        {
            sklad.fundusze -= suma;


            ui->zakup_ile_karton->setText("0");
            ui->zakup_ile_metal->setText("0");
            ui->zakup_ile_cement->setText("0");
            ui->zakup_ile_drut->setText("0");
            ui->zakup_ile_farba->setText("0");
            ui->zakup_ile_guma->setText("0");
            ui->zakup_ile_magnes->setText("0");
            ui->zakup_ile_plastik->setText("0");
            ui->zakup_ile_rzadki_metal->setText("0");


            ui->cena_za_ilosc_karton->setText("0.00 ");
            ui->cena_za_ilosc_metal->setText("0.00 ");
            ui->cena_za_ilosc_cement->setText("0.00 ");
            ui->cena_za_ilosc_drut->setText("0.00 ");
            ui->cena_za_ilosc_farba->setText("0.00 ");
            ui->cena_za_ilosc_guma->setText("0.00 ");
            ui->cena_za_ilosc_magnes->setText("0.00 ");
            ui->cena_za_ilosc_plastik->setText("0.00 ");
            ui->cena_za_ilosc_rzadki_metal->setText("0.00 ");


            sklad.karton += karton;
            sklad.metal += metal;
            sklad.cement += cement;
            sklad.drut += drut;
            sklad.farba += farba;
            sklad.guma += guma;
            sklad.magnes += magnes;
            sklad.plastik += plastik;
            sklad.rzadki_metal += rzadki;
        }
}







////////////////////////////////////////WYWOŁADNIE FUNKCJI SPRZEDAJ PRODUKT MNIEJ/////////////////////////////////////////////////////////////////////


void oknoglowne::on_sprzedaj_mniej_pudlo_clicked(){magazyn.sprzedaj_mniej(ceny.pudlo_sprzedaj,ui->sprzedaj_ilosc_pudlo,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_pas_clicked(){magazyn.sprzedaj_mniej(ceny.pas_sprzedaj,ui->sprzedaj_ilosc_pas,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_beton_clicked(){magazyn.sprzedaj_mniej(ceny.beton_sprzedaj,ui->sprzedaj_ilosc_beton,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_kabel_clicked(){magazyn.sprzedaj_mniej(ceny.kabel_sprzedaj,ui->sprzedaj_ilosc_kabel,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_uklad_clicked(){magazyn.sprzedaj_mniej(ceny.uklad_sprzedaj,ui->sprzedaj_ilosc_uklad,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_koloz_clicked(){magazyn.sprzedaj_mniej(ceny.koloz_sprzedaj,ui->sprzedaj_ilosc_koloz,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_waz_clicked(){magazyn.sprzedaj_mniej(ceny.waz_sprzedaj,ui->sprzedaj_ilosc_waz,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_kolom_clicked(){magazyn.sprzedaj_mniej(ceny.kolom_sprzedaj,ui->sprzedaj_ilosc_kolom,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_silnik_clicked(){magazyn.sprzedaj_mniej(ceny.silnik_sprzedaj,ui->sprzedaj_ilosc_silnik,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_kolop_clicked(){magazyn.sprzedaj_mniej(ceny.kolop_sprzedaj,ui->sprzedaj_ilosc_kolop,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_pompa_clicked(){magazyn.sprzedaj_mniej(ceny.pompa_sprzedaj,ui->sprzedaj_ilosc_pompa,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_krasnal_clicked(){magazyn.sprzedaj_mniej(ceny.krasnal_sprzedaj,ui->sprzedaj_ilosc_krasnal,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_glosniki_clicked(){magazyn.sprzedaj_mniej(ceny.glosniki_sprzedaj,ui->sprzedaj_ilosc_glosniki,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_toster_clicked(){magazyn.sprzedaj_mniej(ceny.toster_sprzedaj,ui->sprzedaj_ilosc_toster,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_ramie_clicked(){magazyn.sprzedaj_mniej(ceny.ramie_sprzedaj,ui->sprzedaj_ilosc_ramie,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_tasma_clicked(){magazyn.sprzedaj_mniej(ceny.tasma_sprzedaj,ui->sprzedaj_ilosc_tasma,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_samoch_clicked(){magazyn.sprzedaj_mniej(ceny.samoch_sprzedaj,ui->sprzedaj_ilosc_samoch,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_pistolet_clicked(){magazyn.sprzedaj_mniej(ceny.pistolet_sprzedaj,ui->sprzedaj_ilosc_pistolet,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_wieza_clicked(){magazyn.sprzedaj_mniej(ceny.wieza_sprzedaj,ui->sprzedaj_ilosc_wieza,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_ukladlo_clicked(){magazyn.sprzedaj_mniej(ceny.ukladlo_sprzedaj,ui->sprzedaj_ilosc_ukladlo,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_widzet_clicked(){magazyn.sprzedaj_mniej(ceny.widzet_sprzedaj,ui->sprzedaj_ilosc_widzet,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_budowniczy_clicked(){magazyn.sprzedaj_mniej(ceny.budowniczy_sprzedaj,ui->sprzedaj_ilosc_budowniczy,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_automatk_clicked(){magazyn.sprzedaj_mniej(ceny.automatk_sprzedaj,ui->sprzedaj_ilosc_automatk,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_mniej_automats_clicked(){magazyn.sprzedaj_mniej(ceny.automats_sprzedaj,ui->sprzedaj_ilosc_automats,ui->msuma_przedmiowtow,ui->msuma_zysk);}




///////////////////////////////////////////////////////WYWOŁADNIE FUNKCJI SPRZEDAJ PRODUKT WIECEJ/////////////////////////////////////////////////////////////////////




void oknoglowne::on_sprzedaj_wiecej_pudlo_clicked(){magazyn.sprzedaj_wiecej(ceny.pudlo_sprzedaj,sklad.pudlo,ui->sprzedaj_ilosc_pudlo,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_pas_clicked(){magazyn.sprzedaj_wiecej(ceny.pas_sprzedaj,sklad.pas,ui->sprzedaj_ilosc_pas,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_beton_clicked(){magazyn.sprzedaj_wiecej(ceny.beton_sprzedaj,sklad.beton,ui->sprzedaj_ilosc_beton,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_kabel_clicked(){magazyn.sprzedaj_wiecej(ceny.kabel_sprzedaj,sklad.kabel,ui->sprzedaj_ilosc_kabel,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_uklad_clicked(){magazyn.sprzedaj_wiecej(ceny.uklad_sprzedaj,sklad.uklad,ui->sprzedaj_ilosc_uklad,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_koloz_clicked(){magazyn.sprzedaj_wiecej(ceny.koloz_sprzedaj,sklad.koloz,ui->sprzedaj_ilosc_koloz,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_waz_clicked(){magazyn.sprzedaj_wiecej(ceny.waz_sprzedaj,sklad.waz,ui->sprzedaj_ilosc_waz,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_kolom_clicked(){magazyn.sprzedaj_wiecej(ceny.kolom_sprzedaj,sklad.kolom,ui->sprzedaj_ilosc_kolom,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_silnik_clicked(){magazyn.sprzedaj_wiecej(ceny.silnik_sprzedaj,sklad.silnik,ui->sprzedaj_ilosc_silnik,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_kolop_clicked(){magazyn.sprzedaj_wiecej(ceny.kolop_sprzedaj,sklad.kolop,ui->sprzedaj_ilosc_kolop,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_pompa_clicked(){magazyn.sprzedaj_wiecej(ceny.pompa_sprzedaj,sklad.pompa,ui->sprzedaj_ilosc_pompa,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_krasnal_clicked(){magazyn.sprzedaj_wiecej(ceny.krasnal_sprzedaj,sklad.krasnal,ui->sprzedaj_ilosc_krasnal,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_glosniki_clicked(){magazyn.sprzedaj_wiecej(ceny.glosniki_sprzedaj,sklad.glosniki,ui->sprzedaj_ilosc_glosniki,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_toster_clicked(){magazyn.sprzedaj_wiecej(ceny.toster_sprzedaj,sklad.toster,ui->sprzedaj_ilosc_toster,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_ramie_clicked(){magazyn.sprzedaj_wiecej(ceny.ramie_sprzedaj,sklad.ramie,ui->sprzedaj_ilosc_ramie,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_tasma_clicked(){magazyn.sprzedaj_wiecej(ceny.tasma_sprzedaj,sklad.tasma,ui->sprzedaj_ilosc_tasma,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_samoch_clicked(){magazyn.sprzedaj_wiecej(ceny.samoch_sprzedaj,sklad.samoch,ui->sprzedaj_ilosc_samoch,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_pistolet_clicked(){magazyn.sprzedaj_wiecej(ceny.pistolet_sprzedaj,sklad.pistolet,ui->sprzedaj_ilosc_pistolet,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_wieza_clicked(){magazyn.sprzedaj_wiecej(ceny.wieza_sprzedaj,sklad.wieza,ui->sprzedaj_ilosc_wieza,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_ukladlo_clicked(){magazyn.sprzedaj_wiecej(ceny.ukladlo_sprzedaj,sklad.ukladlo,ui->sprzedaj_ilosc_ukladlo,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_widzet_clicked(){magazyn.sprzedaj_wiecej(ceny.widzet_sprzedaj,sklad.widzet,ui->sprzedaj_ilosc_widzet,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_budowniczy_clicked(){magazyn.sprzedaj_wiecej(ceny.budowniczy_sprzedaj,sklad.budowniczy,ui->sprzedaj_ilosc_budowniczy,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_automatk_clicked(){magazyn.sprzedaj_wiecej(ceny.automatk_sprzedaj,sklad.automatk,ui->sprzedaj_ilosc_automatk,ui->msuma_przedmiowtow,ui->msuma_zysk);}
void oknoglowne::on_sprzedaj_wiecej_automats_clicked(){magazyn.sprzedaj_wiecej(ceny.automats_sprzedaj,sklad.automats,ui->sprzedaj_ilosc_automats,ui->msuma_przedmiowtow,ui->msuma_zysk);}



/////////////////////////////////////////////WYWOŁADNIE FUNKCJI PRZYCISKU SPRZEDAJ PRODUKTY/////////////////////////////////////////////////////////////////////

void oknoglowne::on_sprzedaj_button_clicked()
{


    sklad.pudlo -= ui->sprzedaj_ilosc_pudlo->text().toInt();
    sklad.pas -= ui->sprzedaj_ilosc_pas->text().toInt();
    sklad.beton -= ui->sprzedaj_ilosc_beton->text().toInt();
    sklad.kabel -= ui->sprzedaj_ilosc_kabel->text().toInt();
    sklad.uklad -= ui->sprzedaj_ilosc_uklad->text().toInt();
    sklad.koloz -= ui->sprzedaj_ilosc_koloz->text().toInt();
    sklad.waz -= ui->sprzedaj_ilosc_waz->text().toInt();
    sklad.kolom -= ui->sprzedaj_ilosc_kolom->text().toInt();
    sklad.silnik -= ui->sprzedaj_ilosc_silnik->text().toInt();
    sklad.kolop -= ui->sprzedaj_ilosc_kolop->text().toInt();
    sklad.pompa -= ui->sprzedaj_ilosc_pompa->text().toInt();
    sklad.krasnal -= ui->sprzedaj_ilosc_krasnal->text().toInt();
    sklad.glosniki -= ui->sprzedaj_ilosc_glosniki->text().toInt();
    sklad.toster -= ui->sprzedaj_ilosc_toster->text().toInt();
    sklad.ramie -= ui->sprzedaj_ilosc_ramie->text().toInt();
    sklad.tasma -= ui->sprzedaj_ilosc_tasma->text().toInt();
    sklad.samoch -= ui->sprzedaj_ilosc_samoch->text().toInt();
    sklad.pistolet -= ui->sprzedaj_ilosc_pistolet->text().toInt();
    sklad.wieza -= ui->sprzedaj_ilosc_wieza->text().toInt();
    sklad.ukladlo -= ui->sprzedaj_ilosc_ukladlo->text().toInt();
    sklad.widzet -= ui->sprzedaj_ilosc_widzet->text().toInt();
    sklad.budowniczy -= ui->sprzedaj_ilosc_budowniczy->text().toInt();
    sklad.automatk -= ui->sprzedaj_ilosc_automatk->text().toInt();
    sklad.automats -= ui->sprzedaj_ilosc_automats->text().toInt();

    wyzeruj_ilosc_magazyn();

    double zysk = ui->msuma_zysk->text().toDouble();
    sklad.fundusze += zysk;
    ui->msuma_zysk->setText("0");
    ui->msuma_przedmiowtow->setText("0");
}

/////////////////////////////////////////////WLACZANIE AUTOMATOW/////////////////////////////////////////////////////////////////////

void oknoglowne::on_autok_button_clicked()
{
    if( ui->autok_button->text() == "Start")
    {
        if(sklad.automatk > 0)
        {
            ui->autok_button->setText("Stop");
            automatk_bool = true;
        }
    }
    else
    {
        ui->autok_button->setText("Start");
            automatk_bool = false;
    }

}
void oknoglowne::on_autos_button_clicked()
{
    if( ui->autos_button->text() == "Start")
    {
        if(sklad.automats > 0)
        {
            ui->autos_button->setText("Stop");
            automats_bool = true;
        }
    }
    else
    {
        ui->autos_button->setText("Start");
            automats_bool = false;
    }
}
void oknoglowne::on_autob_button_clicked()
{
    if( ui->autob_button->text() == "Start")
    {
        if(sklad.budowniczy > 0)
        {
            ui->autob_button->setText("Stop");
            automatb_bool = true;
        }
    }
    else
    {
        ui->autob_button->setText("Start");
            automatb_bool = false;
    }


}

/////////////////////////////////////////////FUNKCJE AUTOMATOW/////////////////////////////////////////////////////////////////////

void oknoglowne::kup_najmniej()
{
    int i = 1, x = sklad.karton;
    if(sklad.cement < x)
    {
        x = sklad.cement;
        i = 2;
    }
    if(sklad.drut < x)
    {
        x = sklad.drut;
        i = 3;
    }
    if(sklad.farba < x)
    {
        x = sklad.farba;
        i = 4;
    }
    if(sklad.guma < x)
    {
        x = sklad.guma;
        i = 5;
    }
    if(sklad.magnes < x)
    {
        x = sklad.magnes;
        i = 6;
    }
    if(sklad.metal < x)
    {
        x = sklad.metal;
        i = 7;
    }
    if(sklad.plastik < x)
    {
        x = sklad.plastik;
        i = 8;
    }

    if(i == 1)
    {
        sklad.karton++;
        sklad.fundusze -= ceny.karton_kup;
    }
    if(i == 2)
    {
        sklad.cement++;
        sklad.fundusze -= ceny.cement_kup;
    }
    if(i == 3)
    {
        sklad.drut++;
        sklad.fundusze -= ceny.drut_kup;
    }
    if(i == 4)
    {
        sklad.farba++;
        sklad.fundusze -= ceny.farba_kup;
    }
    if(i == 5)
    {
        sklad.guma++;
        sklad.fundusze -= ceny.guma_kup;
    }
    if(i == 6)
    {
        sklad.magnes++;
        sklad.fundusze -= ceny.magnes_kup;
    }
    if(i == 7)
    {
        sklad.metal++;
        sklad.fundusze -= ceny.metal_kup;
    }
    if(i == 8)
    {
        sklad.plastik++;
        sklad.fundusze -= ceny.guma_kup;
    }


}
void oknoglowne::automat_sprzedaj()
{
    if(sklad.glosniki > 0)
    {
        sklad.glosniki--;
        sklad.fundusze +=ceny.glosniki_sprzedaj;
         int ilosc = ui->sprzedaj_ilosc_glosniki->text().toInt();
         if(ilosc > 0)
         {
             int suma_ilosc = ui->msuma_przedmiowtow->text().toInt();
             ui->msuma_przedmiowtow->setText(QString::number(suma_ilosc-ilosc));
             double suma = ui->msuma_zysk->text().toDouble();
             suma -=(ilosc*ceny.glosniki_sprzedaj);
             ui->msuma_zysk->setText(QString::number(suma));
         }

        ui->sprzedaj_ilosc_glosniki->setText("0");
    }
    else if(sklad.toster > 0)
    {
        sklad.toster--;
        sklad.fundusze +=ceny.toster_sprzedaj;
        int ilosc = ui->sprzedaj_ilosc_toster->text().toInt();
        if(ilosc > 0)
        {
            int suma_ilosc = ui->msuma_przedmiowtow->text().toInt();
            ui->msuma_przedmiowtow->setText(QString::number(suma_ilosc-ilosc));
            double suma = ui->msuma_zysk->text().toDouble();
            suma -=(ilosc*ceny.toster_sprzedaj);
            ui->msuma_zysk->setText(QString::number(suma));
        }

       ui->sprzedaj_ilosc_toster->setText("0");
    }
    else if(sklad.krasnal > 0)
    {
        sklad.krasnal--;
        sklad.fundusze +=ceny.krasnal_sprzedaj;
        int ilosc = ui->sprzedaj_ilosc_krasnal->text().toInt();
        if(ilosc > 0)
        {
            int suma_ilosc = ui->msuma_przedmiowtow->text().toInt();
            ui->msuma_przedmiowtow->setText(QString::number(suma_ilosc-ilosc));
            double suma = ui->msuma_zysk->text().toDouble();
            suma -=(ilosc*ceny.krasnal_sprzedaj);
            ui->msuma_zysk->setText(QString::number(suma));
        }

       ui->sprzedaj_ilosc_krasnal->setText("0");
    }
    else if(sklad.samoch > 0)
    {
        sklad.samoch--;
        sklad.fundusze +=ceny.samoch_sprzedaj;
        int ilosc = ui->sprzedaj_ilosc_samoch->text().toInt();
        if(ilosc > 0)
        {
            int suma_ilosc = ui->msuma_przedmiowtow->text().toInt();
            ui->msuma_przedmiowtow->setText(QString::number(suma_ilosc-ilosc));
            double suma = ui->msuma_zysk->text().toDouble();
            suma -=(ilosc*ceny.samoch_sprzedaj);
            ui->msuma_zysk->setText(QString::number(suma));
        }

       ui->sprzedaj_ilosc_samoch->setText("0");
    }
    else if(sklad.pistolet > 0)
    {
        sklad.pistolet--;
        sklad.fundusze +=ceny.pistolet_sprzedaj;
        int ilosc = ui->sprzedaj_ilosc_pistolet->text().toInt();
        if(ilosc > 0)
        {
            int suma_ilosc = ui->msuma_przedmiowtow->text().toInt();
            ui->msuma_przedmiowtow->setText(QString::number(suma_ilosc-ilosc));
            double suma = ui->msuma_zysk->text().toDouble();
            suma -=(ilosc*ceny.pistolet_sprzedaj);
            ui->msuma_zysk->setText(QString::number(suma));
        }

       ui->sprzedaj_ilosc_pistolet->setText("0");
    }
    else if(sklad.wieza > 0)
    {
        sklad.wieza--;
        sklad.fundusze +=ceny.wieza_sprzedaj;
        int ilosc = ui->sprzedaj_ilosc_wieza->text().toInt();
        if(ilosc > 0)
        {
            int suma_ilosc = ui->msuma_przedmiowtow->text().toInt();
            ui->msuma_przedmiowtow->setText(QString::number(suma_ilosc-ilosc));
            double suma = ui->msuma_zysk->text().toDouble();
            suma -=(ilosc*ceny.wieza_sprzedaj);
            ui->msuma_zysk->setText(QString::number(suma));
        }

       ui->sprzedaj_ilosc_wieza->setText("0");
    }

}
void oknoglowne::automat_buduj()
{
    int wybor = qrand() % 6;

    if(wybor == 0)
    {
        if(sklad.pudlo < 1)
            if(sklad.karton < 1)
                buduj_wieza();
            else
            buduj_pudlo();
        else
        buduj_glosniki();
    }

    if(wybor ==1)
    {
        if(sklad.pudlo < 1)
            if(sklad.karton < 1)
                buduj_wieza();
            else
            buduj_pudlo();
        else
        buduj_toster();
    }

    if(wybor == 2)
    {
        if(sklad.pudlo < 1)
            if(sklad.karton < 1)
                buduj_wieza();
            else
            buduj_pudlo();
        else
        buduj_krasnal();
    }

    if(wybor == 3)
    {
        if(sklad.kolop < 4)
            buduj_kolop();
        else if(sklad.pudlo < 1)
            if(sklad.karton < 1)
                buduj_wieza();
            else
            buduj_pudlo();
        else
        buduj_samoch();
    }

    if(wybor == 4)
    {
        if(sklad.waz < 4)
            buduj_waz();
        else if(sklad.pudlo < 1)
            if(sklad.karton < 1)
                buduj_wieza();
            else
            buduj_pudlo();
        else
            buduj_pistolet();
    }
    if(wybor == 5)
    {
        if(sklad.kabel < 6)
            buduj_kabel();
        else if(sklad.beton < 8)
            buduj_beton();
    else
        buduj_wieza();
    }

}

/////////////////////////////////////////////FUNKCJE AUTOMATOW/////////////////////////////////////////////////////////////////////


void oknoglowne::automaty_funkcje_timera()
{
    if(automatk_bool)
    {
        if(sklad.fundusze > 10)
        {
            if(sklad.automatk >= 1)
            {
                if(ui->autok->value() == 100)
                {
                    kup_najmniej();
                    ui->autok->setValue(0);
                }
                ui->autok->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 2)
            {
                if(ui->autok_2->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_2->setValue(0);
                }
                ui->autok_2->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 3)
            {
                if(ui->autok_3->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_3->setValue(0);
                }
                ui->autok_3->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 4)
            {
                if(ui->autok_4->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_4->setValue(0);
                }
                ui->autok_4->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 5)
            {
                if(ui->autok_5->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_5->setValue(0);
                }
                ui->autok_5->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 6)
            {
                if(ui->autok_6->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_6->setValue(0);
                }
                ui->autok_6->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 7)
            {
                if(ui->autok_7->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_7->setValue(0);
                }
                ui->autok_7->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 8)
            {
                if(ui->autok_8->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_8->setValue(0);
                }
                ui->autok_8->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 9)
            {
                if(ui->autok_9->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_9->setValue(0);
                }
                ui->autok_9->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 10)
            {
                if(ui->autok_10->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_10->setValue(0);
                }
                ui->autok_10->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 11)
            {
                if(ui->autok_11->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_11->setValue(0);
                }
                ui->autok_11->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 12)
            {
                if(ui->autok_12->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_12->setValue(0);
                }
                ui->autok_12->setValue(ui->autok->value() + 1);
            }
            if(sklad.automatk >= 13)
            {
                if(ui->autok_13->value() == 100)
                {
                    kup_najmniej();
                    ui->autok_13->setValue(0);
                }
                ui->autok_13->setValue(ui->autok->value() + 1);
            }
        }
    }
    if(automats_bool)
    {
        if(sklad.automats >= 1)
        {
                 if(ui->autos->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos->setValue(0);
                 }
                 ui->autos->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 2)
             {
                 if(ui->autos_2->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_2->setValue(0);
                 }
                 ui->autos_2->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 3)
             {
                 if(ui->autos_3->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_3->setValue(0);
                 }
                 ui->autos_3->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 4)
             {
                 if(ui->autos_4->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_4->setValue(0);
                 }
                 ui->autos_4->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 5)
             {
                 if(ui->autos_5->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_5->setValue(0);
                 }
                 ui->autos_5->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 6)
             {
                 if(ui->autos_6->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_6->setValue(0);
                 }
                 ui->autos_6->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 7)
             {
                 if(ui->autos_7->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_7->setValue(0);
                 }
                 ui->autos_7->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 8)
             {
                 if(ui->autos_8->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_8->setValue(0);
                 }
                 ui->autos_8->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 9)
             {
                 if(ui->autos_9->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_9->setValue(0);
                 }
                 ui->autos_9->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 10)
             {
                 if(ui->autos_10->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_10->setValue(0);
                 }
                 ui->autos_10->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 11)
             {
                 if(ui->autos_11->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_11->setValue(0);
                 }
                 ui->autos_11->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 12)
             {
                 if(ui->autos_12->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_12->setValue(0);
                 }
                 ui->autos_12->setValue(ui->autos->value() + 1);
             }
             if(sklad.automats >= 13)
             {
                 if(ui->autos_13->value() == 100)
                 {
                     automat_sprzedaj();
                     ui->autos_13->setValue(0);
                 }
                 ui->autos_13->setValue(ui->autos->value() + 1);
             }





    }
    if(automatb_bool)
    {
        if(sklad.budowniczy >= 1)
                      {
                          if(ui->autob->value() == 100)
                          {
                               automat_buduj();
                               ui->autob->setValue(0);
                          }
                           ui->autob->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 2)
                       {
                           if(ui->autob_2->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_2->setValue(0);
                           }
                           ui->autob_2->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 3)
                       {
                           if(ui->autob_3->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_3->setValue(0);
                           }
                           ui->autob_3->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 4)
                       {
                           if(ui->autob_4->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_4->setValue(0);
                           }
                           ui->autob_4->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 5)
                       {
                           if(ui->autob_5->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_5->setValue(0);
                           }
                           ui->autob_5->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 6)
                       {
                           if(ui->autob_6->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_6->setValue(0);
                           }
                           ui->autob_6->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 7)
                       {
                           if(ui->autob_7->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_7->setValue(0);
                           }
                           ui->autob_7->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 8)
                       {
                           if(ui->autob_8->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_8->setValue(0);
                           }
                           ui->autob_8->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 9)
                       {
                           if(ui->autob_9->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_9->setValue(0);
                           }
                           ui->autob_9->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 10)
                       {
                           if(ui->autob_10->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_10->setValue(0);
                           }
                           ui->autob_10->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 11)
                       {
                           if(ui->autob_11->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_11->setValue(0);
                           }
                           ui->autob_11->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 12)
                       {
                           if(ui->autob_12->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_12->setValue(0);
                           }
                           ui->autob_12->setValue(ui->autob->value() + 1);
                       }
                       if(sklad.budowniczy >= 13)
                       {
                           if(ui->autob_13->value() == 100)
                           {
                               automat_buduj();
                               ui->autob_13->setValue(0);
                           }
                           ui->autob_13->setValue(ui->autob->value() + 1);
                       }
    }



}

void oknoglowne::wyzeruj_ilosc_magazyn()
{
    ui->sprzedaj_ilosc_pas->setText("0");
    ui->sprzedaj_ilosc_beton->setText("0");
    ui->sprzedaj_ilosc_pudlo->setText("0");
    ui->sprzedaj_ilosc_kabel->setText("0");
    ui->sprzedaj_ilosc_uklad->setText("0");
    ui->sprzedaj_ilosc_koloz->setText("0");
    ui->sprzedaj_ilosc_waz->setText("0");
    ui->sprzedaj_ilosc_kolom->setText("0");
    ui->sprzedaj_ilosc_silnik->setText("0");
    ui->sprzedaj_ilosc_kolop->setText("0");
    ui->sprzedaj_ilosc_pompa->setText("0");
    ui->sprzedaj_ilosc_krasnal->setText("0");
    ui->sprzedaj_ilosc_glosniki->setText("0");
    ui->sprzedaj_ilosc_toster->setText("0");
    ui->sprzedaj_ilosc_ramie->setText("0");
    ui->sprzedaj_ilosc_tasma->setText("0");
    ui->sprzedaj_ilosc_samoch->setText("0");
    ui->sprzedaj_ilosc_pistolet->setText("0");
    ui->sprzedaj_ilosc_wieza->setText("0");
    ui->sprzedaj_ilosc_ukladlo->setText("0");
    ui->sprzedaj_ilosc_widzet->setText("0");
    ui->sprzedaj_ilosc_budowniczy->setText("0");
    ui->sprzedaj_ilosc_automatk->setText("0");
    ui->sprzedaj_ilosc_automats->setText("0");
}




void oknoglowne::on_button_zapis_clicked()
{

    FILE * save = fopen( "save.sav", "w" );
    fprintf( save, "%lf, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
             sklad.fundusze,
             sklad.karton,
             sklad.cement,
             sklad.magnes,
             sklad.metal,
             sklad.farba,
             sklad.plastik,
             sklad.rzadki_metal,
             sklad.guma,
             sklad.drut,
             sklad.pas,
             sklad.beton,
             sklad.pudlo,
             sklad.kabel,
             sklad.uklad,
             sklad.koloz,
             sklad.waz,
             sklad.kolom,
             sklad.silnik,
             sklad.kolop,
             sklad.pompa,
             sklad.krasnal,
             sklad.glosniki,
             sklad.toster,
             sklad.ramie,
             sklad.tasma,
             sklad.samoch,
             sklad.pistolet,
             sklad.wieza,
             sklad.ukladlo,
             sklad.widzet,
             sklad.budowniczy,
             sklad.automatk,
             sklad.automats );

    fclose( save );
}

void oknoglowne::on_button_odczyt_clicked()
{
    automats_bool = false;
    automatk_bool = false;
    automatb_bool = false;


    FILE * save = fopen( "save.sav", "r" );
    fscanf( save, "%lf, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
            &sklad.fundusze,
            &sklad.karton,
            &sklad.cement,
            &sklad.magnes,
            &sklad.metal,
            &sklad.farba,
            &sklad.plastik,
            &sklad.rzadki_metal,
            &sklad.guma,
            &sklad.drut,
            &sklad.pas,
            &sklad.beton,
            &sklad.pudlo,
            &sklad.kabel,
            &sklad.uklad,
            &sklad.koloz,
            &sklad.waz,
            &sklad.kolom,
            &sklad.silnik,
            &sklad.kolop,
            &sklad.pompa,
            &sklad.krasnal,
            &sklad.glosniki,
            &sklad.toster,
            &sklad.ramie,
            &sklad.tasma,
            &sklad.samoch,
            &sklad.pistolet,
            &sklad.wieza,
            &sklad.ukladlo,
            &sklad.widzet,
            &sklad.budowniczy,
            &sklad.automatk,
            &sklad.automats );
    fclose( save );



    on_autob_button_clicked();
    on_autok_button_clicked();
    on_autos_button_clicked();
}
