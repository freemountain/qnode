#ifndef MODULEPROVIDER_H
#define MODULEPROVIDER_H

#include <QObject>
#include <QJSEngine>
#include <QJSValue>
#include <QStringList>

#include <src/nodeeventloop.h>
#include <src/nodemodule.h>

class ModuleProvider {
    public:
        virtual NodeModule* module(QString module) = 0;
};

#endif // MODULEPROVIDER_H
