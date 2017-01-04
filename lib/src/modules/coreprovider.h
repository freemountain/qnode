#ifndef COREPROVIDER_H
#define COREPROVIDER_H

#include <QObject>

#include "src/engine/enginecontext.h"
#include "src/moduleprovider.h"

class CoreProvider : public QObject, public ModuleProvider {
  Q_OBJECT

 public:
  explicit CoreProvider(EngineContext* ctx);
  NodeModule* module(QString module);

 private:
  EngineContext* ctx;
};

#endif  // COREPROVIDER_H
