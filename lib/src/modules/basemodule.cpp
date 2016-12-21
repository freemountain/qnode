#include "basemodule.h"

BaseModule::BaseModule(EngineContext *ctx) : QObject(ctx)
{
    this->ctx = ctx;
}

bool BaseModule::isBusy() {
    return false;
}

QJSValue BaseModule::getJSInstance() {
    return this->jsInstance;
}
