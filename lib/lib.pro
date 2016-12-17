TEMPLATE = lib

QT += qml
QT -= gui

TARGET = qnode
DEFINES += libqnode

SOURCES += $$PWD/src/jsvalueutils.cpp \
    src/moduleloader.cpp \
    src/utils.cpp \
    src/nodeengine.cpp \
    src/modules/coreprovider.cpp \
    src/nodeeventloop.cpp \
    src/modules/processmodule.cpp \
    src/modules/timermodule.cpp

HEADERS += $$PWD/src/jsvalueutils.h \
    src/moduleloader.h \
    src/utils.h \
    src/nodeengine.h \
    src/modules/moduleprovider.h \
    src/modules/coreprovider.h \
    src/nodeeventloop.h \
    src/modules/processmodule.h \
    src/modules/timermodule.h \
    src/nodemodule.h

RESOURCES += libqnode.qrc

DISTFILES += \
    js/processWrapper

