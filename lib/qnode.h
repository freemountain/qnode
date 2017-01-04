#ifndef QNODE_H
#define QNODE_H

#include <QJSValue>
#include <QObject>
#include <QTextStream>

class QNodeEngine {
 public:
  virtual ~QNodeEngine() {}
  virtual QString readAllStandardOutput() = 0;
  virtual QString readAllStandardError() = 0;

  // signals:
  virtual void readyReadStandardOutput() = 0;
  virtual void readyReadStandardError() = 0;
  virtual void finished(QJSValue error, bool failed) = 0;
  virtual void ipcMessage(QJSValue msg) = 0;

 public slots:
  virtual void start(QString entry, QString cwd) = 0;
};

Q_DECLARE_INTERFACE(QNodeEngine, "QNodeEngine")

class QNodeEngineContext {
 public:
  virtual ~QNodeEngineContext() {}

  QTextStream* getOutStream();
  QTextStream* getErrorStream();

  Q_INVOKABLE QJSValue require(QString module);
  QJSValue wrapModule(QObject* module, QString wrapperPath,
                      QJSValueList args = QJSValueList());

  QString readAllStandardOutput();
  QString readAllStandardError();

  QJSEngine* getJsEngine();
  QNodeEngine* getNodeEngine();

 public slots:
  void writeStandardOutput(QString data);
  void writeStandardError(QString data);
  void flushStandardOutput();
  void flushStandardError();
};

Q_DECLARE_INTERFACE(QNodeEngineContext, "QNodeEngineContext")

class QNodeModule {
 public:
  virtual ~QNodeModule() {}
  virtual QJSValue getJSInstance() = 0;
  virtual bool isBusy() = 0;

  // signals:
  virtual void dispatch(const QJSValue& target, const QJSValueList& args) = 0;
  virtual void ipcMessage(QJSValue msg) = 0;
  virtual void stdOutMessage(QString msg) = 0;
};

Q_DECLARE_INTERFACE(QNodeModule, "QNodeModule")

class QNodeModuleProvider {
 public:
  virtual ~QNodeModuleProvider() {}

  virtual QNodeModule* module(QString module) = 0;
};

Q_DECLARE_INTERFACE(QNodeModuleProvider, "QNodeModuleProvider")

#endif  // QNODE_H
