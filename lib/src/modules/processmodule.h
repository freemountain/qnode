#ifndef PROCESSMODULE_H
#define PROCESSMODULE_H

#include <QObject>
#include <QJSValue>
#include <QJSEngine>
#include <QJSValueList>

#include <src/modules/basemodule.h>
#include "src/engine/enginecontext.h"

class ProcessModule: public BaseModule {
    Q_OBJECT
public:
    explicit ProcessModule(EngineContext *ctx);

    Q_INVOKABLE void nextTick(QJSValue callback, QJSValue args);
    Q_INVOKABLE void send(QJSValue msg);
};

#endif // PROCESSMODULE_H
