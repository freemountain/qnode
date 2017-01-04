#ifndef UTILMODULE_H
#define UTILMODULE_H

#include <QObject>

#include <src/modules/basemodule.h>
#include <src/nodemodule.h>
#include "qnode.h"
#include "src/engine/enginecontext.h"
class UtilModule : public BaseModule {
  Q_OBJECT
 public:
  explicit UtilModule(QNodeEngineContext* ctx);

  Q_INVOKABLE QString inspect(QJSValue object, int depth = 2);
};

#endif  // UTILMODULE_H
