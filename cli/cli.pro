QT += core qml
QT -= gui


CONFIG += c++11

TARGET = cli
CONFIG += console

TEMPLATE = app

SOURCES += main.cpp \
    app.cpp


#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release/ -lqnode
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug/ -lqnode
#else:unix: LIBS += -L$$OUT_PWD/../lib/ -lqnode

#INCLUDEPATH += $$PWD/../lib
#DEPENDPATH += $$PWD/../lib

HEADERS += \
    app.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release/ -lqnode
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug/ -lqnode
else:unix: LIBS += -L$$OUT_PWD/../lib/ -lqnode

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib
