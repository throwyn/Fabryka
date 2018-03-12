#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T12:42:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fabryka
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        oknoglowne.cpp \
    c_zakup.cpp \
    c_ceny.cpp \
    c_sklad.cpp \
    my_qlabel.cpp \
    c_produkcja.cpp \
    c_magazyn.cpp

HEADERS  += oknoglowne.h \
    c_zakup.h \
    c_ceny.h \
    c_sklad.h \
    my_qlabel.h \
    c_produkcja.h \
    c_magazyn.h

FORMS    += oknoglowne.ui

DISTFILES += \
    Resources/automatk.bmp \
    Resources/automats.bmp \
    Resources/beton.bmp \
    Resources/budowniczy.bmp \
    Resources/cement.bmp \
    Resources/drut.bmp \
    Resources/farba.bmp \
    Resources/glosniki.bmp \
    Resources/guma.bmp \
    Resources/kabel.bmp \
    Resources/karton.bmp \
    Resources/kolko.bmp \
    Resources/kolko_m.bmp \
    Resources/kolko_p.bmp \
    Resources/krasnal.bmp \
    Resources/magnez.bmp \
    Resources/metal.bmp \
    Resources/pas.bmp \
    Resources/pistolet.bmp \
    Resources/plastik.bmp \
    Resources/pompa.bmp \
    Resources/pudlo.bmp \
    Resources/ramie.bmp \
    Resources/rzadki_metal.bmp \
    Resources/samochodzik.bmp \
    Resources/silnik.bmp \
    Resources/tasma.bmp \
    Resources/toster.bmp \
    Resources/uklad.bmp \
    Resources/ukladlo.bmp \
    Resources/v.bmp \
    Resources/waz.bmp \
    Resources/widżet.bmp \
    Resources/wieza.bmp \
    Resources/x.bmp \
    Resources/zebatka.bmp

RESOURCES += \
    Resources/res.qrc
