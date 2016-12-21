TEMPLATE = lib

QT += qml
QT -= gui

TARGET = qnode
DEFINES += libqnode

SOURCES += $$PWD/src/jsvalueutils.cpp \
    src/utils.cpp \
    src/engine/moduleloader.cpp \
    src/engine/nodeengine.cpp \
    src/engine/nodeeventloop.cpp \
    src/modules/coreprovider.cpp \
    src/modules/processmodule.cpp \
    src/modules/timermodule.cpp \
    src/modules/consolemodule.cpp \
    src/engine/enginecontext.cpp \
    src/modules/utilmodule.cpp \
    src/modules/basemodule.cpp \
    src/modules/assertmodule.cpp

HEADERS += $$PWD/src/jsvalueutils.h \
    src/utils.h \
    src/nodemodule.h \
    src/moduleprovider.h \
    src/engine/moduleloader.h \
    src/engine/nodeengine.h \
    src/engine/nodeeventloop.h \
    src/modules/coreprovider.h \
    src/modules/processmodule.h \
    src/modules/timermodule.h \
    src/modules/consolemodule.h \
    src/engine/enginecontext.h \
    src/engine/inodeengine.h \
    src/modules/utilmodule.h \
    src/modules/basemodule.h \
    src/modules/assertmodule.h

RESOURCES += libqnode.qrc

DISTFILES += \
    js/processWrapper
