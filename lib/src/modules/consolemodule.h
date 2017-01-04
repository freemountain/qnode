#ifndef CONSOLEMODULE_H
#define CONSOLEMODULE_H

#include <QObject>

#include "qnode.h"
#include "src/engine/enginecontext.h"
#include "src/modules/basemodule.h"

class ConsoleModule : public BaseModule {
  Q_OBJECT

 public:
  explicit ConsoleModule(QNodeEngineContext* ctx);

  Q_INVOKABLE void log(QString msg);
  Q_INVOKABLE void error(QString msg);
};

#endif  // CONSOLEMODULE_H
