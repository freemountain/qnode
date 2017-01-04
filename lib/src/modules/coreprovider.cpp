#include "coreprovider.h"

#include <QDebug>
#include <QJSValue>

#include "consolemodule.h"
#include "fsmodule.h"
#include "processmodule.h"
#include "timermodule.h"
#include "utilmodule.h"

#include "src/jsvalueutils.h"
#include "src/utils.h"

CoreProvider::CoreProvider(EngineContext* ctx) : QObject(ctx) {
  this->ctx = ctx;
}

NodeModule* CoreProvider::module(QString module) {
  if (module == "process") {
    ProcessModule* proc = new ProcessModule(ctx);
    NodeModule* mod = qobject_cast<NodeModule*>(proc);
    return mod;
  }

  if (module == "timers") {
    TimerModule* timer = new TimerModule(ctx);
    NodeModule* mod = qobject_cast<NodeModule*>(timer);
    return mod;
  }

  if (module == "console") {
    ConsoleModule* console = new ConsoleModule(ctx);
    NodeModule* mod = qobject_cast<NodeModule*>(console);
    return mod;
  }

  if (module == "util") {
    UtilModule* util = new UtilModule(ctx);
    NodeModule* mod = qobject_cast<NodeModule*>(util);
    return mod;
  }

  if (module == "fs") {
    FsModule* fs = new FsModule(ctx);
    NodeModule* mod = qobject_cast<NodeModule*>(fs);
    return mod;
  }

  if (module == "assert") {
    QJSValue jsMod = this->ctx->require(":/libqnode/js/assertModule.js");
    return BaseModule::fromJSValue(ctx, jsMod);
  }

  return nullptr;
}
