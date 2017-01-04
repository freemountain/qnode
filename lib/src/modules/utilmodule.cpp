#include "utilmodule.h"

#include "src/jsvalueutils.h"

UtilModule::UtilModule(EngineContext* ctx) : BaseModule(ctx) {
  this->jsInstance =
      this->ctx->wrapModule(this, ":/libqnode/js/utilWrapper.js");
}

QString UtilModule::inspect(QJSValue object, int depth) {
  return JSValueUtils::stringify(object);
}
