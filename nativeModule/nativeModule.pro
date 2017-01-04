#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T23:33:49
#
#-------------------------------------------------

QT       += core gui

TARGET = $$qtLibraryTarget(nativeModule)
TEMPLATE = lib
CONFIG += plugin

DESTDIR = $$[QT_INSTALL_PLUGINS]/generic

SOURCES += nativeplugin.cpp

HEADERS += nativeplugin.h
DISTFILES += nativeModule.json

unix {
    #target.path = /usr/lib
    #INSTALLS += target
}

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib
