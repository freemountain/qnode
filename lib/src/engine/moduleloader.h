#ifndef MODULELOADER_H
#define MODULELOADER_H

#include <QJSEngine>
#include <QJSValue>
#include <QList>
#include <QObject>

#include "src/engine/nodeeventloop.h"
#include "src/moduleprovider.h"

class ModuleLoader : public QObject {
  Q_OBJECT
 public:
  explicit ModuleLoader(QJSEngine* engine);

  Q_INVOKABLE QJSValue require(QString module, QString path);
  Q_PROPERTY(QJSValue cache READ getCacheProp)

  QJSValue getCacheProp();
  QJSValue getJSValue();
  void addModuleProvider(ModuleProvider* provider);

 signals:
  void loadedNativeModule(NodeModule* module);

 public slots:
 private:
  QJSEngine* engine;
  QJSValue moduleCache;
  QJSValue jsLoader;
  QList<ModuleProvider*> provider;

  bool inCache(QString key);
  QJSValue getCache(QString key);
  void addCache(QString key, QJSValue module);

  QJSValue loadCoreModule(QString path);
  QJSValue returnModule(QJSValue val, QString path);

  QJSValue loadAsFile(QString path);
  QJSValue loadAsDirectory(QString path);

  QJSValue loadJSONFile(QString path);

  QJSValue loadNodeModules(QString module, QString start);
  QStringList nodeModulesPaths(QString start);
};

#endif  // MODULELOADER_H
