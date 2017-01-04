#ifndef COREPROVIDER_H
#define COREPROVIDER_H

#include <QObject>

#include "qnode.h"
#include "src/engine/enginecontext.h"
#include "src/moduleprovider.h"
class CoreProvider : public QObject, public QNodeModuleProvider {
  Q_OBJECT
  Q_INTERFACES(QNodeModuleProvider)

 public:
  explicit CoreProvider(QNodeEngineContext* ctx);
  QNodeModule* module(QString module);

 private:
  QNodeEngineContext* ctx;
};

#endif  // COREPROVIDER_H
