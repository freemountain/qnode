#include "enginecontext.h"

#include "src/jsvalueutils.h"
#include "src/utils.h"

EngineContext::EngineContext(INodeEngine* nodeEngine, ModuleLoader* loader,
                             QJSEngine* jsEngine)
    : QObject(dynamic_cast<QObject*>(nodeEngine)) {
  this->nodeEngine = nodeEngine;
  this->jsEngine = jsEngine;
  this->loader = loader;
  this->std_out = new QTextStream(&this->out_buffer);
  this->std_err = new QTextStream(&this->err_buffer);
  this->jsCtx = jsEngine->newQObject(this);
}

void EngineContext::writeStandardError(QString data) {
  this->std_err->operator<<(data);
}

void EngineContext::writeStandardOutput(QString data) {
  this->std_out->operator<<(data);
}

void EngineContext::flushStandardError() {
  // engine->e
  emit nodeEngine->readyReadStandardError();
}

void EngineContext::flushStandardOutput() {
  emit nodeEngine->readyReadStandardOutput();
}

QString EngineContext::readAllStandardOutput() {
  return this->std_out->readAll();
}

QString EngineContext::readAllStandardError() {
  return this->std_err->readAll();
}

QJSValue EngineContext::require(QString module) {
  return this->loader->require(module, "").property("exports");
}

QJSValue EngineContext::wrapModule(QObject* module, QString wrapperPath,
                                   QJSValueList args) {
  QString wrapperSrc = Utils::readFile(wrapperPath);
  QJSValue jsMod = jsEngine->newQObject(module);

  // return JSValueUtils::wrapModule2(jsEngine, jsEngine->newQObject(module),
  // wrapperSrc);

  QJSValueList wrapperArgs;
  QJSValue helper =
      JSValueUtils::createFunction(
          jsEngine, Utils::readFile(":/libqnode/js/moduleHelper.js"),
          "#moduleHelper")
          .call();
  QJSValue wrapper =
      JSValueUtils::createFunction(jsEngine, wrapperSrc, "#moduleWrapper");
  wrapperArgs << jsMod << helper << jsCtx
              << JSValueUtils::listToArray(jsEngine, args);

  return wrapper.call(wrapperArgs);
}

QJSEngine* EngineContext::getJsEngine() { return this->jsEngine; }

INodeEngine* EngineContext::getNodeEngine() { return this->nodeEngine; }