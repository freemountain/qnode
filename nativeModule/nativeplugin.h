#ifndef NATIVEPLUGIN_H
#define NATIVEPLUGIN_H

#include <QGenericPlugin>

#include "qnode.h"
class NativePlugin : public QObject, public QNodeModule {
  Q_OBJECT
  Q_INTERFACES(QNodeModule)

#if QT_VERSION >= 0x050000
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface" FILE
                        "nativeModule.json")
#endif  // QT_VERSION >= 0x050000

 public:
  NativePlugin(QObject *parent = 0);
};

#endif  // NATIVEPLUGIN_H
