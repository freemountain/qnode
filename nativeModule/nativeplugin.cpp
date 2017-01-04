#include "nativeplugin.h"


NativePlugin::NativePlugin(QObject *parent) :
    QGenericPlugin(parent)
{
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(nativeModule, NativePlugin)
#endif // QT_VERSION < 0x050000
