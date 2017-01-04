#ifndef TIMERMODULE_H
#define TIMERMODULE_H

#include <QHash>
#include <QJSEngine>
#include <QJSValue>
#include <QJSValueList>
#include <QObject>
#include <QTimer>

#include <src/nodemodule.h>
#include "qnode.h"
#include "src/engine/enginecontext.h"
#include "src/modules/basemodule.h"

class TimerModule : public BaseModule {
  Q_OBJECT

 public:
  explicit TimerModule(QNodeEngineContext* ctx);

  Q_INVOKABLE int setInterval(QJSValue callback, int t, QJSValue args);
  Q_INVOKABLE int setTimeout(QJSValue callback, int t, QJSValue args);

  Q_INVOKABLE void clear(int id);

  bool isBusy();

 private:
  int nextID;
  QHash<int, QTimer*> timers;
  int createTimer(QJSValue callback, QJSValue args);
};

#endif  // TIMERMODULE_H
