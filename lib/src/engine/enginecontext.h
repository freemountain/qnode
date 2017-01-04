#ifndef ENGINECONTEXT_H
#define ENGINECONTEXT_H

#include <QObject>
#include <QTextStream>

#include "qnode.h"
#include "src/engine/inodeengine.h"
#include "src/engine/moduleloader.h"

//#include "nodeengine.h"

// class NodeEngine;

class EngineContext : public QObject, public QNodeEngineContext {
  Q_OBJECT
  Q_INTERFACES(QNodeEngineContext)

 public:
  explicit EngineContext(QNodeEngine* nodeEngine, ModuleLoader* loader,
                         QJSEngine* jsEngine);

  QTextStream* getOutStream();
  QTextStream* getErrorStream();

  Q_INVOKABLE QJSValue require(QString module);
  QJSValue wrapModule(QObject* module, QString wrapperPath,
                      QJSValueList args = QJSValueList());

  QString readAllStandardOutput();
  QString readAllStandardError();

  QJSEngine* getJsEngine();
  QNodeEngine* getNodeEngine();

 private:
  QTextStream* std_out;
  QTextStream* std_err;
  QNodeEngine* nodeEngine;
  QJSEngine* jsEngine;
  ModuleLoader* loader;
  QJSValue jsCtx;

  QString out_buffer;
  QString err_buffer;

 public slots:
  void writeStandardOutput(QString data);
  void writeStandardError(QString data);
  void flushStandardOutput();
  void flushStandardError();
};

#endif  // ENGINECONTEXT_H
