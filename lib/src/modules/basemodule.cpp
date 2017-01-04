#include "basemodule.h"

BaseModule::BaseModule(EngineContext* ctx) : QObject(ctx) { this->ctx = ctx; }

BaseModule* BaseModule::fromJSValue(EngineContext* ctx, QJSValue value) {
  BaseModule* mod = new BaseModule(ctx);
  mod->jsInstance = value;

  return mod;
}

bool BaseModule::isBusy() { return false; }

QJSValue BaseModule::getJSInstance() { return this->jsInstance; }
