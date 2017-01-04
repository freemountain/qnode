#ifndef NODEENGINE_H
#define NODEENGINE_H

#include <QJSEngine>
#include <QJSValue>
#include <QObject>

#include "src/engine/enginecontext.h"
#include "src/engine/inodeengine.h"
#include "src/engine/moduleloader.h"
#include "src/engine/nodeeventloop.h"
#include "src/modules/coreprovider.h"

class NodeEngine : public QObject, public INodeEngine {
  Q_OBJECT
  Q_INTERFACES(INodeEngine)
 public:
  explicit NodeEngine(QObject* parent = 0);
  QJSValue require(QString js);
  QJSValue parseJson(QString json);
  QJSEngine* getEngine();

  QString readAllStandardOutput();
  QString readAllStandardError();

 private:
  QJSEngine* engine;
  ModuleLoader* loader;
  NodeEventLoop* loop;
  EngineContext* ctx;
  QTextStream* out;
  CoreProvider* coreProvider;

 signals:
  void readyReadStandardOutput();
  void readyReadStandardError();
  void finished(QJSValue error, bool failed);
  void ipcMessage(QJSValue msg);

 public slots:
  void start(QString entry, QString path);
};

#endif  // NODEENGINE_H
