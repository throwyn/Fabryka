#include "c_produkcja.h"
#include <QObject>
#include <QProgressBar>


C_produkcja::C_produkcja()
{

}

void C_produkcja::Buduj_pudlo(C_sklad* sklad, QProgressBar* proggress_pudlo, QLabel* s1_pudlo)
{
    if(sklad->karton>=1)
    {
        proggress_pudlo->setValue(proggress_pudlo->value() + 1);
        sklad->karton--;
        QString text = "karton x" + QString::number(4-proggress_pudlo->value());
        s1_pudlo->setText(text);
        if(proggress_pudlo->value() == 4)
        {
            s1_pudlo->setText("karton x4");
            sklad->pudlo++;
            proggress_pudlo->setValue(0);
        }
    }
    else
    {
        s1_pudlo->setVisible(true);
        s1_pudlo->setStyleSheet("QLabel{color:red}");
    }

}
void C_produkcja::buduj_kabel(C_sklad* sklad, QLabel* s1_kabel)
{
    if(sklad->metal>=1)
    {
        sklad->kabel++;
        sklad->metal--;
    }
    else
    {
        s1_kabel->setVisible(true);
        s1_kabel->setStyleSheet("QLabel{color:red}");
    }
}
void C_produkcja::buduj_beton(C_sklad* sklad,QProgressBar* proggress_beton,QLabel* s1_beton,QLabel* s2_beton)
{

    if(proggress_beton->value() < 2)
    {
        if(sklad->cement>=1)
           {
               proggress_beton->setValue(proggress_beton->value() + 1);
               sklad->cement--;
               s1_beton->setText("cement x" + QString::number(2 - proggress_beton->value()));
           }
           else
           {
               s1_beton->setVisible(true);
               s1_beton->setStyleSheet("QLabel{color:red}");
           }
    }
    else if(proggress_beton->value() >= 2 && proggress_beton->value() < 4)
    {
        if(sklad->metal>=1)
           {
               proggress_beton->setValue(proggress_beton->value() + 1);
               sklad->metal--;
               s2_beton->setText("metal x" + QString::number(4 - proggress_beton->value()));
               if(proggress_beton->value() == 4)
               {
                   s1_beton->setText("cement x2");
                   s2_beton->setText("metal x2");
                   sklad->beton++;
                   proggress_beton->setValue(0);
               }
           }
           else
           {
               s2_beton->setVisible(true);
               s2_beton->setStyleSheet("QLabel{color:red}");
           }
    }

}
void C_produkcja::buduj_pas(C_sklad* sklad,QProgressBar* proggress_pas,QLabel* s1_pas)
{
    if(sklad->guma>=1)
    {
        proggress_pas->setValue(proggress_pas->value() + 1);
        sklad->guma--;
        QString text = "guma x" + QString::number(2 - proggress_pas->value());
        s1_pas->setText(text);
        if(proggress_pas->value() == 2)
        {
            s1_pas->setText("guma x2");
            sklad->pas++;
            proggress_pas->setValue(0);
        }
    }
    else
    {
        s1_pas->setVisible(true);
        s1_pas->setStyleSheet("QLabel{color:red}");
    }
}
void C_produkcja::buduj_uklad(C_sklad* sklad,QProgressBar* proggress_uklad,QLabel* s1_uklad,QLabel* s2_uklad)
{
    if(proggress_uklad->value() < 2)
    {
        if(sklad->plastik>=1)
           {
               proggress_uklad->setValue(proggress_uklad->value() + 1);
               sklad->plastik--;
               s1_uklad->setText("plastik x" + QString::number(2 - proggress_uklad->value()));
           }
           else
           {
               s1_uklad->setVisible(true);
               s1_uklad->setStyleSheet("QLabel{color:red}");
           }
    }
    else if(proggress_uklad->value() >= 2 && proggress_uklad->value() < 3)
    {
        if(sklad->drut>=1)
           {
               proggress_uklad->setValue(proggress_uklad->value() + 1);
               sklad->drut--;
               s2_uklad->setText("drut x" + QString::number(3 - proggress_uklad->value()));
               if(proggress_uklad->value() == 3)
               {
                   s1_uklad->setText("plastik x2");
                   s2_uklad->setText("drut x1");
                   sklad->uklad++;
                   proggress_uklad->setValue(0);
               }
           }
           else
           {
               s2_uklad->setVisible(true);
               s2_uklad->setStyleSheet("QLabel{color:red}");
           }
    }
}
void C_produkcja::buduj_koloz(C_sklad* sklad,QProgressBar* proggress_koloz,QLabel* s1_koloz)
{

    if(sklad->metal>=1)
    {
        proggress_koloz->setValue(proggress_koloz->value() + 1);
        sklad->metal--;
        QString text = "metal x" + QString::number(2 - proggress_koloz->value());
        s1_koloz->setText(text);
        if(proggress_koloz->value() == 2)
        {
            s1_koloz->setText("metal x2");
            sklad->koloz++;
            proggress_koloz->setValue(0);
        }
    }
    else
    {
        s1_koloz->setVisible(true);
        s1_koloz->setStyleSheet("QLabel{color:red}");
    }



}
void C_produkcja::buduj_waz(C_sklad* sklad,QProgressBar* proggress_waz,QLabel* s1_waz)
{
    if(sklad->guma>=1)
    {
        proggress_waz->setValue(proggress_waz->value() + 1);
        sklad->guma--;
        QString text = "guma x" + QString::number(2 - proggress_waz->value());
        s1_waz->setText(text);
        if(proggress_waz->value() == 2)
        {
            s1_waz->setText("guma x2");
            sklad->waz++;
            proggress_waz->setValue(0);
        }
    }
    else
    {
        s1_waz->setVisible(true);
        s1_waz->setStyleSheet("QLabel{color:red}");
    }
}
void C_produkcja::buduj_kolom(C_sklad* sklad,QProgressBar* proggress_kolom,QLabel* s1_kolom)
{

    if(sklad->metal>=1)
    {
        proggress_kolom->setValue(proggress_kolom->value() + 1);
        sklad->metal--;
        QString text = "metal x" + QString::number(2 - proggress_kolom->value());
        s1_kolom->setText(text);
        if(proggress_kolom->value() == 2)
        {
            s1_kolom->setText("metal x2");
            sklad->kolom++;
            proggress_kolom->setValue(0);
        }
    }
    else
    {
        s1_kolom->setVisible(true);
        s1_kolom->setStyleSheet("QLabel{color:red}");
    }



}
void C_produkcja::buduj_silnik(C_sklad* sklad,QProgressBar* proggress_silnik,QLabel* s1_silnik,QLabel* s2_silnik,QLabel* s3_silnik)
{
    if(proggress_silnik->value() < 2)
    {
        if(sklad->magnes>=1)
           {
               proggress_silnik->setValue(proggress_silnik->value() + 1);
               sklad->magnes--;
               s1_silnik->setText("magnes x" + QString::number(2 - proggress_silnik->value()));
           }
           else
           {
               s1_silnik->setVisible(true);
               s1_silnik->setStyleSheet("QLabel{color:red}");
           }
    }
    else if(proggress_silnik->value() >= 2 && proggress_silnik->value() < 3)
    {
        if(sklad->metal>=1)
           {
               proggress_silnik->setValue(proggress_silnik->value() + 1);
               sklad->metal--;
               s2_silnik->setText("metal x" + QString::number(3 - proggress_silnik->value()));

           }
           else
           {
               s2_silnik->setVisible(true);
               s2_silnik->setStyleSheet("QLabel{color:red}");
           }
    }
    else if(proggress_silnik->value() >= 3 && proggress_silnik->value() < 5)
    {
        if(sklad->drut>=1)
           {
               proggress_silnik->setValue(proggress_silnik->value() + 1);
               sklad->drut--;
               s3_silnik->setText("drut x" + QString::number(5 - proggress_silnik->value()));
               if(proggress_silnik->value() == 5)
               {
                   s1_silnik->setText("magnes x2");
                   s2_silnik->setText("metal x1");
           s3_silnik->setText("drut x2");
                   sklad->silnik++;
                   proggress_silnik->setValue(0);
               }
           }
           else
           {
               s3_silnik->setVisible(true);
               s3_silnik->setStyleSheet("QLabel{color:red}");
           }
    }
}
void C_produkcja::buduj_kolop(C_sklad* sklad,QProgressBar* proggress_kolop,QLabel* s1_kolop)
{

    if(sklad->plastik>=1)
    {
        proggress_kolop->setValue(proggress_kolop->value() + 1);
        sklad->plastik--;
        QString text = "plastik x" + QString::number(2 - proggress_kolop->value());
        s1_kolop->setText(text);
        if(proggress_kolop->value() == 2)
        {
            s1_kolop->setText("plastik x2");
            sklad->kolop++;
            proggress_kolop->setValue(0);
        }
    }
    else
    {
        s1_kolop->setVisible(true);
        s1_kolop->setStyleSheet("QLabel{color:red}");
    }



}
void C_produkcja::buduj_pompa(C_sklad* sklad,QProgressBar* proggress_pompa,QLabel* s1_pompa,QLabel* s2_pompa,QLabel* s3_pompa)
{
    if(proggress_pompa->value() < 2)
       {
           if(sklad->metal>=1)
              {
                  proggress_pompa->setValue(proggress_pompa->value() + 1);
                  sklad->metal--;
                  s1_pompa->setText("metal x" + QString::number(2 - proggress_pompa->value()));
              }
              else
              {
                  s1_pompa->setVisible(true);
                  s1_pompa->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_pompa->value() >= 2 && proggress_pompa->value() < 3)
       {
           if(sklad->plastik>=1)
              {
                  proggress_pompa->setValue(proggress_pompa->value() + 1);
                  sklad->plastik--;
                  s2_pompa->setText("plastik x" + QString::number(3 - proggress_pompa->value()));

              }
              else
              {
                  s2_pompa->setVisible(true);
                  s2_pompa->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_pompa->value() >= 3 && proggress_pompa->value() < 4)
       {
           if(sklad->guma>=1)
              {
                  proggress_pompa->setValue(proggress_pompa->value() + 1);
                  sklad->guma--;
                  s3_pompa->setText("guma x" + QString::number(4 - proggress_pompa->value()));
                  if(proggress_pompa->value() == 4)
                  {
                      s1_pompa->setText("metal x2");
                      s2_pompa->setText("plastik x1");
              s3_pompa->setText("guma x1");
                      sklad->pompa++;
                      proggress_pompa->setValue(0);
                  }
              }
              else
              {
                  s3_pompa->setVisible(true);
                  s3_pompa->setStyleSheet("QLabel{color:red}");
              }
       }
}
void C_produkcja::buduj_krasnal(C_sklad* sklad,QProgressBar* proggress_krasnal,QLabel* s1_krasnal,QLabel* s2_krasnal,QLabel* s3_krasnal)
{
    if(proggress_krasnal->value() < 1)
       {
           if(sklad->cement>=1)
              {
                  proggress_krasnal->setValue(proggress_krasnal->value() + 1);
                  sklad->cement--;
                  s1_krasnal->setText("cement x" + QString::number(1 - proggress_krasnal->value()));
              }
              else
              {
                  s1_krasnal->setVisible(true);
                  s1_krasnal->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_krasnal->value() >= 1 && proggress_krasnal->value() < 2)
       {
           if(sklad->farba>=1)
              {
                  proggress_krasnal->setValue(proggress_krasnal->value() + 1);
                  sklad->farba--;
                  s2_krasnal->setText("farba x" + QString::number(2 - proggress_krasnal->value()));

              }
              else
              {
                  s2_krasnal->setVisible(true);
                  s2_krasnal->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_krasnal->value() >= 2 && proggress_krasnal->value() < 3)
       {
           if(sklad->pudlo>=1)
              {
                  proggress_krasnal->setValue(proggress_krasnal->value() + 1);
                  sklad->pudlo--;
                  s3_krasnal->setText("pudło x" + QString::number(3 - proggress_krasnal->value()));
                  if(proggress_krasnal->value() == 3)
                  {
                      s1_krasnal->setText("cement x1");
                      s2_krasnal->setText("farba x1");
              s3_krasnal->setText("pudło x1");
                      sklad->krasnal++;
                      proggress_krasnal->setValue(0);
                  }
              }
              else
              {
                  s3_krasnal->setVisible(true);
                  s3_krasnal->setStyleSheet("QLabel{color:red}");
              }
       }
}
void C_produkcja::buduj_glosniki(C_sklad* sklad,QProgressBar* proggress_glosniki,QLabel* s1_glosniki,QLabel* s2_glosniki,QLabel* s3_glosniki,QLabel* s4_glosniki)
{
    if(proggress_glosniki->value() < 2)
       {
           if(sklad->magnes>=1)
              {
                  proggress_glosniki->setValue(proggress_glosniki->value() + 1);
                  sklad->magnes--;
                  s1_glosniki->setText("magnes x" + QString::number(2 - proggress_glosniki->value()));
              }
              else
              {
                  s1_glosniki->setVisible(true);
                  s1_glosniki->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_glosniki->value() >= 2 && proggress_glosniki->value() < 4)
       {
           if(sklad->plastik>=1)
              {
                  proggress_glosniki->setValue(proggress_glosniki->value() + 1);
                  sklad->plastik--;
                  s2_glosniki->setText("plastik x" + QString::number(4 - proggress_glosniki->value()));
}
              else
              {
                  s2_glosniki->setVisible(true);
                  s2_glosniki->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_glosniki->value() >= 4 && proggress_glosniki->value() < 5)
       {
           if(sklad->drut>=1)
              {
                  proggress_glosniki->setValue(proggress_glosniki->value() + 1);
                  sklad->drut--;
                  s3_glosniki->setText("drut x" + QString::number(5 - proggress_glosniki->value()));
              }
              else
              {
                  s3_glosniki->setVisible(true);
                  s3_glosniki->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_glosniki->value() >= 5 && proggress_glosniki->value() < 6)
       {
           if(sklad->pudlo>=1)
              {
                  proggress_glosniki->setValue(proggress_glosniki->value() + 1);
                  sklad->pudlo--;
                  s3_glosniki->setText("pudlo x" + QString::number(5 - proggress_glosniki->value()));
                  if(proggress_glosniki->value() == 6)
                  {
                      s1_glosniki->setText("magnes x2");
                      s2_glosniki->setText("plastik x2");
                      s3_glosniki->setText("drut x1");
                      sklad->glosniki++;
                      proggress_glosniki->setValue(0);
                  }
              }
              else
              {
                  s4_glosniki->setVisible(true);
                  s4_glosniki->setStyleSheet("QLabel{color:red}");
              }
       }
}
void C_produkcja::buduj_toster(C_sklad* sklad,QProgressBar* proggress_toster,QLabel* s1_toster,QLabel* s2_toster,QLabel* s3_toster)
{
    if(proggress_toster->value() < 2)
       {
           if(sklad->metal>=1)
              {
                  proggress_toster->setValue(proggress_toster->value() + 1);
                  sklad->metal--;
                  s1_toster->setText("metal x" + QString::number(2 - proggress_toster->value()));
              }
              else
              {
                  s1_toster->setVisible(true);
                  s1_toster->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_toster->value() >= 2 && proggress_toster->value() < 4)
       {
           if(sklad->drut>=1)
              {
                  proggress_toster->setValue(proggress_toster->value() + 1);
                  sklad->drut--;
                  s2_toster->setText("drut x" + QString::number(4 - proggress_toster->value()));

              }
              else
              {
                  s2_toster->setVisible(true);
                  s2_toster->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_toster->value() >= 4 && proggress_toster->value() < 5)
       {
           if(sklad->pudlo>=1)
              {
                  proggress_toster->setValue(proggress_toster->value() + 1);
                  sklad->pudlo--;
                  s3_toster->setText("pudlo x" + QString::number(5 - proggress_toster->value()));
                  if(proggress_toster->value() == 5)
                  {
                      s1_toster->setText("metal x2");
                      s2_toster->setText("drut x2");
              s3_toster->setText("pudło x1");
                      sklad->toster++;
                      proggress_toster->setValue(0);
                  }
              }
              else
              {
                  s3_toster->setVisible(true);
                  s3_toster->setStyleSheet("QLabel{color:red}");
              }
       }
}
void C_produkcja::buduj_ramie(C_sklad* sklad,QProgressBar* proggress_ramie,QLabel* s1_ramie,QLabel* s2_ramie,QLabel* s3_ramie)
{
    if(proggress_ramie->value() < 2)
       {
           if(sklad->metal>=1)
              {
                  proggress_ramie->setValue(proggress_ramie->value() + 1);
                  sklad->metal--;
                  s1_ramie->setText("metal x" + QString::number(2 - proggress_ramie->value()));
              }
              else
              {
                  s1_ramie->setVisible(true);
                  s1_ramie->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_ramie->value() >= 2 && proggress_ramie->value() < 3)
       {
           if(sklad->uklad>=1)
              {
                  proggress_ramie->setValue(proggress_ramie->value() + 1);
                  sklad->uklad--;
                  s2_ramie->setText("układ x" + QString::number(3 - proggress_ramie->value()));

              }
              else
              {
                  s2_ramie->setVisible(true);
                  s2_ramie->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_ramie->value() >= 3 && proggress_ramie->value() < 5)
       {
           if(sklad->silnik>=1)
              {
                  proggress_ramie->setValue(proggress_ramie->value() + 1);
                  sklad->silnik--;
                  s3_ramie->setText("silnik x" + QString::number(5 - proggress_ramie->value()));
                  if(proggress_ramie->value() == 5)
                  {
                      s1_ramie->setText("metal x2");
                      s2_ramie->setText("układ x1");
              s3_ramie->setText("silnik x2");
                      sklad->ramie++;
                      proggress_ramie->setValue(0);
                  }
              }
              else
              {
                  s3_ramie->setVisible(true);
                  s3_ramie->setStyleSheet("QLabel{color:red}");
              }
       }
}
void C_produkcja::buduj_tasma(C_sklad* sklad,QProgressBar* proggress_tasma,QLabel* s1_tasma,QLabel* s2_tasma,QLabel* s3_tasma,QLabel* s4_tasma)
{
    if(proggress_tasma->value() < 4)
       {
           if(sklad->pas>=1)
              {
                  proggress_tasma->setValue(proggress_tasma->value() + 1);
                  sklad->pas--;
                  s1_tasma->setText("pas x" + QString::number(4 - proggress_tasma->value()));
              }
              else
              {
                  s1_tasma->setVisible(true);
                  s1_tasma->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_tasma->value() >= 4 && proggress_tasma->value() < 5)
       {
           if(sklad->silnik>=1)
              {
                  proggress_tasma->setValue(proggress_tasma->value() + 1);
                  sklad->silnik--;
                  s2_tasma->setText("silnik x" + QString::number(5 - proggress_tasma->value()));

              }
              else
              {
                  s2_tasma->setVisible(true);
                  s2_tasma->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_tasma->value() >= 5 && proggress_tasma->value() < 7)
       {
           if(sklad->koloz>=1)
              {
                  proggress_tasma->setValue(proggress_tasma->value() + 1);
                  sklad->koloz--;
                  s3_tasma->setText("koło zębate x" + QString::number(7 - proggress_tasma->value()));
              }
              else
              {
                  s3_tasma->setVisible(true);
                  s3_tasma->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_tasma->value() >= 7 && proggress_tasma->value() < 15)
       {
           if(sklad->kolom>=1)
              {
                  proggress_tasma->setValue(proggress_tasma->value() + 1);
                  sklad->kolom--;
                  s4_tasma->setText("metalowe kółka x" + QString::number(15 - proggress_tasma->value()));
                  if(proggress_tasma->value() == 15)
                  {
                      s1_tasma->setText("pas x1");
                      s2_tasma->setText("silnik x6");
                  s3_tasma->setText("koło zębate x2");
                      sklad->tasma++;
                      proggress_tasma->setValue(0);
                  }
              }
              else
              {
                  s4_tasma->setVisible(true);
                  s4_tasma->setStyleSheet("QLabel{color:red}");
              }
       }
}
void C_produkcja::buduj_samoch(C_sklad* sklad,QProgressBar* proggress_samoch,QLabel* s1_samoch,QLabel* s2_samoch,QLabel* s3_samoch,QLabel* s4_samoch,QLabel* s5_samoch)
{
    if(proggress_samoch->value() < 1)
          {
              if(sklad->metal>=1)
                 {
                     proggress_samoch->setValue(proggress_samoch->value() + 1);
                     sklad->metal--;
                     s1_samoch->setText("metal x" + QString::number(1 - proggress_samoch->value()));
                 }
                 else
                 {
                     s1_samoch->setVisible(true);
                     s1_samoch->setStyleSheet("QLabel{color:red}");
                 }
          }
          else if(proggress_samoch->value() >= 1 && proggress_samoch->value() < 2)
          {
              if(sklad->farba>=1)
                 {
                     proggress_samoch->setValue(proggress_samoch->value() + 1);
                     sklad->farba--;
                     s2_samoch->setText("farba x" + QString::number(2 - proggress_samoch->value()));

                 }
                 else
                 {
                     s2_samoch->setVisible(true);
                     s2_samoch->setStyleSheet("QLabel{color:red}");
                 }
          }
          else if(proggress_samoch->value() >= 2 && proggress_samoch->value() < 5)
          {
              if(sklad->plastik>=1)
                 {
                     proggress_samoch->setValue(proggress_samoch->value() + 1);
                     sklad->plastik--;
                     s3_samoch->setText("plastik x" + QString::number(5 - proggress_samoch->value()));
                 }
                 else
                 {
                     s3_samoch->setVisible(true);
                     s3_samoch->setStyleSheet("QLabel{color:red}");
                 }
          }
         else if(proggress_samoch->value() >= 5 && proggress_samoch->value() < 9)
             {
                 if(sklad->kolop>=1)
                    {
                        proggress_samoch->setValue(proggress_samoch->value() + 1);
                        sklad->kolop--;
                        s4_samoch->setText("plastikowe kółka x" + QString::number(9 - proggress_samoch->value()));

                    }
                    else
                    {
                        s4_samoch->setVisible(true);
                        s4_samoch->setStyleSheet("QLabel{color:red}");
                    }
             }
          else if(proggress_samoch->value() >= 9 && proggress_samoch->value() < 10)
          {
              if(sklad->pudlo>=1)
                 {
                     proggress_samoch->setValue(proggress_samoch->value() + 1);
                     sklad->pudlo--;
                     s5_samoch->setText("pudło x" + QString::number(10 - proggress_samoch->value()));
                     if(proggress_samoch->value() == 10)
                     {
                         s1_samoch->setText("metal x1");
                         s2_samoch->setText("farba x1");
                         s3_samoch->setText("plastik x3");
                         s4_samoch->setText("plastikowe kółka x4");
                         s5_samoch->setText("pudło x1");

                         sklad->samoch++;
                         proggress_samoch->setValue(0);
                     }
                 }
                 else
                 {
                     s5_samoch->setVisible(true);
                     s5_samoch->setStyleSheet("QLabel{color:red}");
                 }
          }
}
void C_produkcja::buduj_pistolet(C_sklad* sklad,QProgressBar* proggress_pistolet,QLabel* s1_pistolet,QLabel* s2_pistolet,QLabel* s3_pistolet,QLabel* s4_pistolet)
{
    if(proggress_pistolet->value() < 1)
       {
           if(sklad->farba>=1)
              {
                  proggress_pistolet->setValue(proggress_pistolet->value() + 1);
                  sklad->farba--;
                  s1_pistolet->setText("farba x" + QString::number(1 - proggress_pistolet->value()));
              }
              else
              {
                  s1_pistolet->setVisible(true);
                  s1_pistolet->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_pistolet->value() >= 1 && proggress_pistolet->value() < 7)
       {
           if(sklad->plastik>=1)
              {
                  proggress_pistolet->setValue(proggress_pistolet->value() + 1);
                  sklad->plastik--;
                  s2_pistolet->setText("plastik x" + QString::number(7 - proggress_pistolet->value()));

              }
              else
              {
                  s2_pistolet->setVisible(true);
                  s2_pistolet->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_pistolet->value() >= 7 && proggress_pistolet->value() < 9)
       {
           if(sklad->waz>=1)
              {
                  proggress_pistolet->setValue(proggress_pistolet->value() + 1);
                  sklad->waz--;
                  s3_pistolet->setText("wąż gumowy x" + QString::number(9 - proggress_pistolet->value()));
              }
              else
              {
                  s3_pistolet->setVisible(true);
                  s3_pistolet->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_pistolet->value() >= 9 && proggress_pistolet->value() < 10)
       {
           if(sklad->pudlo>=1)
              {
                  proggress_pistolet->setValue(proggress_pistolet->value() + 1);
                  sklad->pudlo--;
                  s4_pistolet->setText("pudło x" + QString::number(10 - proggress_pistolet->value()));
                  if(proggress_pistolet->value() == 10)
                  {
                      s1_pistolet->setText("farba x1");
                      s2_pistolet->setText("plastik x6");
                      s3_pistolet->setText("wąż gumowy x2");
                      s4_pistolet->setText("pudło x1");
                      sklad->pistolet++;
                      proggress_pistolet->setValue(0);
                  }
              }
              else
              {
                  s4_pistolet->setVisible(true);
                  s4_pistolet->setStyleSheet("QLabel{color:red}");
              }
       }
}
void C_produkcja::buduj_wieza(C_sklad* sklad,QProgressBar* proggress_wieza,QLabel* s1_wieza,QLabel* s2_wieza,QLabel* s3_wieza)
{
    if(proggress_wieza->value() < 12)
         {
             if(sklad->metal>=1)
                {
                    proggress_wieza->setValue(proggress_wieza->value() + 1);
                    sklad->metal--;
                    s1_wieza->setText("metal x" + QString::number(12 - proggress_wieza->value()));
                }
                else
                {
                    s1_wieza->setVisible(true);
                    s1_wieza->setStyleSheet("QLabel{color:red}");
                }
         }
         else if(proggress_wieza->value() >= 12 && proggress_wieza->value() < 18)
         {
             if(sklad->kabel>=1)
                {
                    proggress_wieza->setValue(proggress_wieza->value() + 1);
                    sklad->kabel--;
                    s2_wieza->setText("kabel x" + QString::number(18 - proggress_wieza->value()));

                }
                else
                {
                    s2_wieza->setVisible(true);
                    s2_wieza->setStyleSheet("QLabel{color:red}");
                }
         }
         else if(proggress_wieza->value() >= 18 && proggress_wieza->value() < 26)
         {
             if(sklad->beton>=1)
                {
                    proggress_wieza->setValue(proggress_wieza->value() + 1);
                    sklad->beton--;
                    s3_wieza->setText("beton x" + QString::number(26 - proggress_wieza->value()));
                    if(proggress_wieza->value() == 26)
                    {
                        s1_wieza->setText("metal x12");
                        s2_wieza->setText("kabel x6");
                s3_wieza->setText("beton x8");
                        sklad->wieza++;
                        proggress_wieza->setValue(0);
                    }
                }
                else
                {
                    s3_wieza->setVisible(true);
                    s3_wieza->setStyleSheet("QLabel{color:red}");
                }
         }
}
void C_produkcja::buduj_ukladlo(C_sklad* sklad,QProgressBar* proggress_ukladlo,QLabel* s1_ukladlo,QLabel* s2_ukladlo)
{
    if(proggress_ukladlo->value() < 5)
      {
          if(sklad->drut>=1)
             {
                 proggress_ukladlo->setValue(proggress_ukladlo->value() + 1);
                 sklad->drut--;
                 s1_ukladlo->setText("drut x" + QString::number(5 - proggress_ukladlo->value()));
             }
             else
             {
                 s1_ukladlo->setVisible(true);
                 s1_ukladlo->setStyleSheet("QLabel{color:red}");
             }
      }
      else if(proggress_ukladlo->value() >= 5 && proggress_ukladlo->value() < 9)
      {
          if(sklad->uklad>=1)
             {
                 proggress_ukladlo->setValue(proggress_ukladlo->value() + 1);
                 sklad->uklad--;
                 s2_ukladlo->setText("układ x" + QString::number(9 - proggress_ukladlo->value()));
                 if(proggress_ukladlo->value() == 9)
                 {
                     s1_ukladlo->setText("drut x5");
                     s2_ukladlo->setText("układ x4");
                     sklad->ukladlo++;
                     proggress_ukladlo->setValue(0);
                 }
             }
             else
             {
                 s2_ukladlo->setVisible(true);
                 s2_ukladlo->setStyleSheet("QLabel{color:red}");
             }
      }
}
void C_produkcja::buduj_widzet(C_sklad* sklad,QProgressBar* proggress_widzet,QLabel* s1_widzet,QLabel* s2_widzet,QLabel* s3_widzet,QLabel* s4_widzet,QLabel* s5_widzet)
{
    if(proggress_widzet->value() < 1)
       {
           if(sklad->metal>=1)
              {
                  proggress_widzet->setValue(proggress_widzet->value() + 1);
                  sklad->metal--;
                  s1_widzet->setText("metal x" + QString::number(1 - proggress_widzet->value()));
              }
              else
              {
                  s1_widzet->setVisible(true);
                  s1_widzet->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_widzet->value() >= 1 && proggress_widzet->value() < 3)
       {
           if(sklad->plastik>=1)
              {
                  proggress_widzet->setValue(proggress_widzet->value() + 1);
                  sklad->plastik--;
                  s2_widzet->setText("plastik x" + QString::number(3 - proggress_widzet->value()));

              }
              else
              {
                  s2_widzet->setVisible(true);
                  s2_widzet->setStyleSheet("QLabel{color:red}");
              }
       }
       else if(proggress_widzet->value() >= 3 && proggress_widzet->value() < 5)
       {
           if(sklad->drut>=1)
              {
                  proggress_widzet->setValue(proggress_widzet->value() + 1);
                  sklad->drut--;
                  s3_widzet->setText("drut x" + QString::number(5 - proggress_widzet->value()));
              }
              else
              {
                  s3_widzet->setVisible(true);
                  s3_widzet->setStyleSheet("QLabel{color:red}");
              }
       }
      else if(proggress_widzet->value() >= 5 && proggress_widzet->value() < 7)
          {
              if(sklad->uklad>=1)
                 {
                     proggress_widzet->setValue(proggress_widzet->value() + 1);
                     sklad->uklad--;
                     s4_widzet->setText("układ x" + QString::number(7 - proggress_widzet->value()));

                 }
                 else
                 {
                     s4_widzet->setVisible(true);
                     s4_widzet->setStyleSheet("QLabel{color:red}");
                 }
          }
       else if(proggress_widzet->value() >= 7 && proggress_widzet->value() < 9)
       {
           if(sklad->ukladlo>=1)
              {
                  proggress_widzet->setValue(proggress_widzet->value() + 1);
                  sklad->ukladlo--;
                  s5_widzet->setText("układ logiczny x" + QString::number(9 - proggress_widzet->value()));
                  if(proggress_widzet->value() == 9)
                  {
                      s1_widzet->setText("metal x1");
                      s2_widzet->setText("plastik x2");
                  s3_widzet->setText("drut x2");
                  s4_widzet->setText("układ x2");
                  s5_widzet->setText("układ logiczny x2");

                      sklad->widzet++;
                      proggress_widzet->setValue(0);
                  }
              }
              else
              {
                  s5_widzet->setVisible(true);
                  s5_widzet->setStyleSheet("QLabel{color:red}");
              }
       }
}
void C_produkcja::buduj_budowniczy(C_sklad* sklad,QProgressBar* proggress_budowniczy,QLabel* s1_budowniczy,QLabel* s2_budowniczy,QLabel* s3_budowniczy,QLabel* s4_budowniczy,QLabel* s5_budowniczy)
{
    if(proggress_budowniczy->value() < 2)
          {
              if(sklad->silnik>=1)
                 {
                     proggress_budowniczy->setValue(proggress_budowniczy->value() + 1);
                     sklad->silnik--;
                     s1_budowniczy->setText("silnik x" + QString::number(2 - proggress_budowniczy->value()));
                 }
                 else
                 {
                     s1_budowniczy->setVisible(true);
                     s1_budowniczy->setStyleSheet("QLabel{color:red}");
                 }
          }
          else if(proggress_budowniczy->value() >= 2 && proggress_budowniczy->value() < 5)
          {
              if(sklad->ramie>=1)
                 {
                     proggress_budowniczy->setValue(proggress_budowniczy->value() + 1);
                     sklad->ramie--;
                     s2_budowniczy->setText("ramie x" + QString::number(5 - proggress_budowniczy->value()));

                 }
                 else
                 {
                     s2_budowniczy->setVisible(true);
                     s2_budowniczy->setStyleSheet("QLabel{color:red}");
                 }
          }
          else if(proggress_budowniczy->value() >= 5 && proggress_budowniczy->value() < 7)
          {
              if(sklad->widzet>=1)
                 {
                     proggress_budowniczy->setValue(proggress_budowniczy->value() + 1);
                     sklad->widzet--;
                     s3_budowniczy->setText("widżet x" + QString::number(7 - proggress_budowniczy->value()));
                 }
                 else
                 {
                     s3_budowniczy->setVisible(true);
                     s3_budowniczy->setStyleSheet("QLabel{color:red}");
                 }
          }
         else if(proggress_budowniczy->value() >= 7 && proggress_budowniczy->value() < 8)
             {
                 if(sklad->tasma>=1)
                    {
                        proggress_budowniczy->setValue(proggress_budowniczy->value() + 1);
                        sklad->tasma--;
                        s4_budowniczy->setText("taśma produkcyjna x" + QString::number(8 - proggress_budowniczy->value()));

                    }
                    else
                    {
                        s4_budowniczy->setVisible(true);
                        s4_budowniczy->setStyleSheet("QLabel{color:red}");
                    }
             }
          else if(proggress_budowniczy->value() >= 8 && proggress_budowniczy->value() < 9)
          {
              if(sklad->pompa>=1)
                 {
                     proggress_budowniczy->setValue(proggress_budowniczy->value() + 1);
                     sklad->pompa--;
                     s5_budowniczy->setText("pompa x" + QString::number(9 - proggress_budowniczy->value()));
                     if(proggress_budowniczy->value() == 9)
                     {
                         s1_budowniczy->setText("silnik x2");
                         s2_budowniczy->setText("ramie x3");
                     s3_budowniczy->setText("widżet x2");
                     s4_budowniczy->setText("taśma produkcyjna x1");
                     s5_budowniczy->setText("pompa x1");

                         sklad->budowniczy++;
                         proggress_budowniczy->setValue(0);
                     }
                 }
                 else
                 {
                     s5_budowniczy->setVisible(true);
                     s5_budowniczy->setStyleSheet("QLabel{color:red}");
                 }
          }
}
void C_produkcja::buduj_automatk(C_sklad* sklad,QProgressBar* proggress_automatk,QLabel* s1_automatk,QLabel* s2_automatk,QLabel* s3_automatk,QLabel* s4_automatk,QLabel* s5_automatk)
{
    if(proggress_automatk->value() < 1)
          {
              if(sklad->farba>=1)
                 {
                     proggress_automatk->setValue(proggress_automatk->value() + 1);
                     sklad->farba--;
                     s1_automatk->setText("farba x" + QString::number(1 - proggress_automatk->value()));
                 }
                 else
                 {
                     s1_automatk->setVisible(true);
                     s1_automatk->setStyleSheet("QLabel{color:red}");
                 }
          }
          else if(proggress_automatk->value() >= 1 && proggress_automatk->value() < 7)
          {
              if(sklad->drut>=1)
                 {
                     proggress_automatk->setValue(proggress_automatk->value() + 1);
                     sklad->drut--;
                     s2_automatk->setText("drut x" + QString::number(7 - proggress_automatk->value()));

                 }
                 else
                 {
                     s2_automatk->setVisible(true);
                     s2_automatk->setStyleSheet("QLabel{color:red}");
                 }
          }
          else if(proggress_automatk->value() >= 7 && proggress_automatk->value() < 11)
          {
              if(sklad->uklad>=1)
                 {
                     proggress_automatk->setValue(proggress_automatk->value() + 1);
                     sklad->uklad--;
                     s3_automatk->setText("układ x" + QString::number(11 - proggress_automatk->value()));
                 }
                 else
                 {
                     s3_automatk->setVisible(true);
                     s3_automatk->setStyleSheet("QLabel{color:red}");
                 }
          }
         else if(proggress_automatk->value() >= 11 && proggress_automatk->value() < 12)
             {
                 if(sklad->ukladlo>=1)
                    {
                        proggress_automatk->setValue(proggress_automatk->value() + 1);
                        sklad->ukladlo--;
                        s4_automatk->setText("układ logiczny x" + QString::number(12 - proggress_automatk->value()));

                    }
                    else
                    {
                        s4_automatk->setVisible(true);
                        s4_automatk->setStyleSheet("QLabel{color:red}");
                    }
             }
          else if(proggress_automatk->value() >= 12 && proggress_automatk->value() < 13)
          {
              if(sklad->widzet>=1)
                 {
                     proggress_automatk->setValue(proggress_automatk->value() + 1);
                     sklad->widzet--;
                     s5_automatk->setText("widżet x" + QString::number(13 - proggress_automatk->value()));
                     if(proggress_automatk->value() == 13)
                     {
                         s1_automatk->setText("farba x1");
                         s2_automatk->setText("drut x6");
                     s3_automatk->setText("układ x4");
                     s4_automatk->setText("układ logiczny x1");
                     s5_automatk->setText("widżet x1");

                         sklad->automatk++;
                         proggress_automatk->setValue(0);
                     }
                 }
                 else
                 {
                     s5_automatk->setVisible(true);
                     s5_automatk->setStyleSheet("QLabel{color:red}");
                 }
          }
}
void C_produkcja::buduj_automats(C_sklad* sklad,QProgressBar* proggress_automats,QLabel* s1_automats,QLabel* s2_automats,QLabel* s3_automats,QLabel* s4_automats,QLabel* s5_automats)
{
    if(proggress_automats->value() < 1)
          {
              if(sklad->farba>=1)
                 {
                     proggress_automats->setValue(proggress_automats->value() + 1);
                     sklad->farba--;
                     s1_automats->setText("farba x" + QString::number(1 - proggress_automats->value()));
                 }
                 else
                 {
                     s1_automats->setVisible(true);
                     s1_automats->setStyleSheet("QLabel{color:red}");
                 }
          }
          else if(proggress_automats->value() >= 1 && proggress_automats->value() < 7)
          {
              if(sklad->drut>=1)
                 {
                     proggress_automats->setValue(proggress_automats->value() + 1);
                     sklad->drut--;
                     s2_automats->setText("drut x" + QString::number(7 - proggress_automats->value()));

                 }
                 else
                 {
                     s2_automats->setVisible(true);
                     s2_automats->setStyleSheet("QLabel{color:red}");
                 }
          }
          else if(proggress_automats->value() >= 7 && proggress_automats->value() < 11)
          {
              if(sklad->uklad>=1)
                 {
                     proggress_automats->setValue(proggress_automats->value() + 1);
                     sklad->uklad--;
                     s3_automats->setText("układ x" + QString::number(11 - proggress_automats->value()));
                 }
                 else
                 {
                     s3_automats->setVisible(true);
                     s3_automats->setStyleSheet("QLabel{color:red}");
                 }
          }
         else if(proggress_automats->value() >= 11 && proggress_automats->value() < 12)
             {
                 if(sklad->ukladlo>=1)
                    {
                        proggress_automats->setValue(proggress_automats->value() + 1);
                        sklad->ukladlo--;
                        s4_automats->setText("układ logiczny x" + QString::number(12 - proggress_automats->value()));

                    }
                    else
                    {
                        s4_automats->setVisible(true);
                        s4_automats->setStyleSheet("QLabel{color:red}");
                    }
             }
          else if(proggress_automats->value() >= 12 && proggress_automats->value() < 13)
          {
              if(sklad->widzet>=1)
                 {
                     proggress_automats->setValue(proggress_automats->value() + 1);
                     sklad->widzet--;
                     s5_automats->setText("widżet x" + QString::number(13 - proggress_automats->value()));
                     if(proggress_automats->value() == 13)
                     {
                         s1_automats->setText("farba x1");
                         s2_automats->setText("drut x6");
                     s3_automats->setText("układ x4");
                     s4_automats->setText("układ logiczny x1");
                     s5_automats->setText("widżet x1");

                         sklad->automats++;
                         proggress_automats->setValue(0);
                     }
                 }
                 else
                 {
                     s5_automats->setVisible(true);
                     s5_automats->setStyleSheet("QLabel{color:red}");
                 }
          }
}

