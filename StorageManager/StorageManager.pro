#-------------------------------------------------
#
# Project created by QtCreator 2011-08-12T16:16:16
#
#-------------------------------------------------

QT       += core
QT       += core gui


TARGET = StorageManager
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Block.cpp \
    Data.cpp \
    mapabits.cpp \
    Metadata.cpp \
    Registro.cpp \
    SMException.cpp \
    StorageManager.cpp \
    SystemBlock.cpp \
    Template.cpp \
    Varchar.cpp \
    MetadataContinuo.cpp \
    InfoMD.cpp \
    InfoMDC.cpp \
    InfoCMD.cpp \
    InfoReg.cpp \
    InfoV.cpp \
    InfoD.cpp \
    mainwindow.cpp

HEADERS += \
    Block.h \
    Data.h \
    mapabits.h \
    Metadata.h \
    SMException.h \
    StorageManager.h \
    SystemBlock.h \
    Template.h \
    Varchar.h \
    MetadataContinuo.h \
    InfoMD.h \
    InfoMDC.h \
    InfoCMD.h \
    Registro.h \
    InfoReg.h \
    InfoV.h \
    InfoD.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
