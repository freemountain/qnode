#include "consolemodule.h"

ConsoleModule::ConsoleModule(EngineContext* ctx) : BaseModule(ctx)
{
    this->jsInstance = this->ctx->wrapModule(this, ":/libqnode/js/consoleWrapper.js");
}

void ConsoleModule::log(QString msg) {
    this->ctx->writeStandardOutput(msg.append("\n"));
    this->ctx->flushStandardOutput();
}
