#include "utilmodule.h"

UtilModule::UtilModule(EngineContext *ctx) : BaseModule(ctx)
{
    this->jsInstance = this->ctx->wrapModule(this, ":/libqnode/js/utilWrapper.js");
}
