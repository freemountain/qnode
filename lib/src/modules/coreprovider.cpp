#include "coreprovider.h"

#include <QJSValue>
#include <QDebug>

#include "timermodule.h"
#include "processmodule.h"
#include "consolemodule.h"
#include "utilmodule.h"

#include "src/utils.h"
#include "src/jsvalueutils.h"

CoreProvider::CoreProvider(EngineContext* ctx) : QObject(ctx)
{
    this->ctx = ctx;
}

NodeModule *CoreProvider::module(QString module) {
    if(module == "process") {
        ProcessModule* proc = new ProcessModule(ctx);
        NodeModule *mod = qobject_cast<NodeModule*>(proc);
        return mod;
    }

    if(module == "timers") {
        TimerModule* timer = new TimerModule(ctx);
        NodeModule *mod = qobject_cast<NodeModule*>(timer);
        return mod;
    }

    if(module == "console") {
        ConsoleModule* console = new ConsoleModule(ctx);
        NodeModule *mod = qobject_cast<NodeModule*>(console);
        return mod;
    }

    if(module == "util") {
        UtilModule* util = new UtilModule(ctx);
        NodeModule *mod = qobject_cast<NodeModule*>(util);
        return mod;
    }

    if(module == "assert") {
        QJSValue mod = JSValueUtils::loadModule(this->ctx->getJsEngine(), this->jsLoader, path + ".js");

    }

    return nullptr;
}
