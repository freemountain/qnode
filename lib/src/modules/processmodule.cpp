#include "processmodule.h"

#include <QDebug>
#include <QJSValueIterator>

#include "src/utils.h"
#include "src/jsvalueutils.h"

ProcessModule::ProcessModule(QJSEngine *engine) : QObject(engine)
{
    this->engine = engine;
}

void ProcessModule::nextTick(QJSValue callback, QJSValue args) {
    QJSValueList argList = JSValueUtils::arrayToList(args);

    emit dispatch(callback, argList);
}

void ProcessModule::send(QJSValue msg) {
    emit ipcMessage(msg);
}

QJSValue ProcessModule::getJSInstance() {
    QString wrapperSrc = Utils::readFile(":/libqnode/js/processWrapper.js");
    return JSValueUtils::wrapModule2(engine, engine->newQObject(this), wrapperSrc);
}

bool ProcessModule::isBusy() {
    return false;
}
