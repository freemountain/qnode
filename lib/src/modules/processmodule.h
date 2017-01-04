#ifndef PROCESSMODULE_H
#define PROCESSMODULE_H

#include <QJSEngine>
#include <QJSValue>
#include <QJSValueList>
#include <QObject>

#include <src/modules/basemodule.h>
#include "src/engine/enginecontext.h"

class ProcessModule : public BaseModule {
  Q_OBJECT
 public:
  explicit ProcessModule(EngineContext* ctx);

  Q_INVOKABLE void nextTick(QJSValue callback, QJSValue args);
  Q_INVOKABLE void send(QJSValue msg);
};

#endif  // PROCESSMODULE_H
