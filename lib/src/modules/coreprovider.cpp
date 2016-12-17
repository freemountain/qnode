#include "coreprovider.h"

#include <QJSValue>
#include <QDebug>

#include "timermodule.h"
#include "processmodule.h"
#include "src/utils.h"
#include "src/jsvalueutils.h"

CoreProvider::CoreProvider(QJSEngine* engine) : QObject(engine)
{
    this->engine = engine;
}

NodeModule *CoreProvider::module(QString module) {
    if(module == "process") {
        ProcessModule* proc = new ProcessModule(engine);
        NodeModule *mod = qobject_cast<NodeModule*>(proc);
        return mod;
    }

    if(module == "timers") {
        TimerModule* timer = new TimerModule(engine);
        NodeModule *mod = qobject_cast<NodeModule*>(timer);
        return mod;
    }

    return nullptr;
}
