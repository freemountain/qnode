#ifndef BASEMODULE_H
#define BASEMODULE_H

#include <QObject>

#include <src/nodemodule.h>
#include "src/engine/enginecontext.h"

class BaseModule : public QObject, public NodeModule {
  Q_OBJECT
  Q_INTERFACES(NodeModule)
 public:
  static BaseModule* fromJSValue(EngineContext* ctx, QJSValue value);
  explicit BaseModule(EngineContext* ctx);

  QJSValue getJSInstance();
  bool isBusy();

 protected:
  EngineContext* ctx;
  QJSValue jsInstance;

 signals:
  void dispatch(const QJSValue& target, const QJSValueList& args);
  void ipcMessage(QJSValue msg);
  void stdOutMessage(QString msg);
};

#endif  // BASEMODULE_H
