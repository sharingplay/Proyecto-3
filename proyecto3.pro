#-------------------------------------------------
#
# Project created by QtCreator 2019-05-28T21:58:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    creategalery.cpp \
    linkedlist.cpp \
    node.cpp \
    galerias.cpp \
    galeria.cpp \
    ingresometadata.cpp \
    fotografia.cpp \
    busquedaimagen.cpp \
    borrarimagen.cpp \
    updateimagen.cpp \
    seleccionfotos.cpp

HEADERS += \
        mainwindow.h \
    creategalery.h \
    linkedlist.h \
    node.h \
    galerias.h \
    galeria.h \
    fotografia.h \
    ingresometadata.h \
    busquedaimagen.h \
    borrarimagen.h \
    updateimagen.h \
    seleccionfotos.h

FORMS += \
        mainwindow.ui \
    creategalery.ui \
    ingresometadata.ui \
    busquedaimagen.ui \
    borrarimagen.ui \
    updateimagen.ui \
    seleccionfotos.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../imagenes/imagenes.qrc

DISTFILES +=
