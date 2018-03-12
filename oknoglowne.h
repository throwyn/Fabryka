#ifndef OKNOGLOWNE_H
#define OKNOGLOWNE_H

#include <QMouseEvent>
#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include "c_ceny.h"
#include "c_sklad.h"
#include "c_zakup.h"
#include "my_qlabel.h"
#include "c_produkcja.h"
#include "c_magazyn.h"
//#include "imgclick.h"


namespace Ui {
class oknoglowne;
}

class oknoglowne : public QMainWindow
{
    Q_OBJECT

private:

    C_sklad sklad;
    C_ceny ceny;
    C_produkcja buduj;
    C_zakup zakup;
    c_magazyn magazyn;
    bool automatk_bool = 0;
    bool automats_bool = 0;
    bool automatb_bool = 0;


public:
    explicit oknoglowne(QWidget *parent = 0);
    ~oknoglowne();
signals:
    void clicked();

private slots:
    void on_kup_mniej_karton_clicked();
    void on_kup_wiecej_karton_clicked();
    void on_kup_mniej_cement_clicked();
    void on_kup_wiecej_cement_clicked();
    void on_kup_mniej_drut_clicked();
    void on_kup_wiecej_drut_clicked();
    void on_kup_mniej_farba_clicked();
    void on_kup_wiecej_farba_clicked();
    void on_kup_mniej_guma_clicked();
    void on_kup_wiecej_guma_clicked();
    void on_kup_mniej_magnes_clicked();
    void on_kup_wiecej_magnes_clicked();
    void on_kup_mniej_metal_clicked();
    void on_kup_wiecej_metal_clicked();
    void on_kup_mniej_plastik_clicked();
    void on_kup_wiecej_plastik_clicked();
    void on_kup_mniej_rzadki_metal_clicked();
    void on_kup_wiecej_rzadki_metal_clicked();
    void on_kup_sprzedaj_clicked();

private slots:

    void buduj_pudlo();
    void buduj_kabel();
    void buduj_beton();
    void buduj_pas();
    void buduj_uklad();
    void buduj_koloz();
    void buduj_waz();
    void buduj_kolom();
    void buduj_silnik();
    void buduj_kolop();
    void buduj_pompa();
    void buduj_krasnal();
    void buduj_glosniki();
    void buduj_toster();
    void buduj_ramie();
    void buduj_tasma();
    void buduj_samoch();
    void buduj_pistolet();
    void buduj_wieza();
    void buduj_ukladlo();
    void buduj_widzet();
    void buduj_budowniczy();
    void buduj_automatk();
    void buduj_automats();

    void on_sprzedaj_mniej_pudlo_clicked();

    void on_sprzedaj_wiecej_pudlo_clicked();

    void on_sprzedaj_mniej_kabel_clicked();

    void on_sprzedaj_wiecej_kabel_clicked();

    void on_sprzedaj_mniej_beton_clicked();

    void on_sprzedaj_wiecej_beton_clicked();

    void on_sprzedaj_mniej_pas_clicked();

    void on_sprzedaj_wiecej_pas_clicked();

    void on_sprzedaj_mniej_uklad_clicked();

    void on_sprzedaj_wiecej_uklad_clicked();

    void on_sprzedaj_mniej_koloz_clicked();

    void on_sprzedaj_wiecej_koloz_clicked();

    void on_sprzedaj_mniej_waz_clicked();

    void on_sprzedaj_wiecej_waz_clicked();

    void on_sprzedaj_mniej_kolom_clicked();

    void on_sprzedaj_wiecej_kolom_clicked();

    void on_sprzedaj_mniej_silnik_clicked();

    void on_sprzedaj_wiecej_silnik_clicked();

    void on_sprzedaj_mniej_kolop_clicked();

    void on_sprzedaj_wiecej_kolop_clicked();

    void on_sprzedaj_mniej_pompa_clicked();

    void on_sprzedaj_wiecej_pompa_clicked();

    void on_sprzedaj_mniej_ramie_clicked();

    void on_sprzedaj_wiecej_ramie_clicked();

    void on_sprzedaj_mniej_tasma_clicked();

    void on_sprzedaj_wiecej_tasma_clicked();

    void on_sprzedaj_mniej_ukladlo_clicked();

    void on_sprzedaj_wiecej_ukladlo_clicked();

    void on_sprzedaj_mniej_widzet_clicked();

    void on_sprzedaj_wiecej_widzet_clicked();

    void on_sprzedaj_mniej_glosniki_clicked();

    void on_sprzedaj_wiecej_glosniki_clicked();

    void on_sprzedaj_mniej_toster_clicked();

    void on_sprzedaj_wiecej_toster_clicked();

    void on_sprzedaj_mniej_krasnal_clicked();

    void on_sprzedaj_wiecej_krasnal_clicked();

    void on_sprzedaj_mniej_samoch_clicked();

    void on_sprzedaj_wiecej_samoch_clicked();

    void on_sprzedaj_mniej_pistolet_clicked();

    void on_sprzedaj_wiecej_pistolet_clicked();

    void on_sprzedaj_mniej_wieza_clicked();

    void on_sprzedaj_wiecej_wieza_clicked();

    void on_sprzedaj_mniej_budowniczy_clicked();

    void on_sprzedaj_wiecej_budowniczy_clicked();

    void on_sprzedaj_mniej_automatk_clicked();

    void on_sprzedaj_wiecej_automatk_clicked();

    void on_sprzedaj_mniej_automats_clicked();

    void on_sprzedaj_wiecej_automats_clicked();

    void on_sprzedaj_button_clicked();
    void on_autok_button_clicked();
    void automaty_funkcje_timera();
    void kup_najmniej();
    void automat_sprzedaj();
    void automat_buduj();
    void on_autos_button_clicked();
    void wyzeruj_ilosc_magazyn();
    void on_autob_button_clicked();

    void on_button_zapis_clicked();

    void on_button_odczyt_clicked();

public slots:
    void odswiez();


private:
    Ui::oknoglowne *ui;




};





#endif // OKNOGLOWNE_H
