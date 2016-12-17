#ifndef COREPROVIDER_H
#define COREPROVIDER_H

#include <QObject>

#include "moduleprovider.h"

class CoreProvider : public QObject, public ModuleProvider
{
    Q_OBJECT

public:
    explicit CoreProvider(QJSEngine* engine);
    NodeModule* module(QString module);

private:
    QJSEngine* engine;
};

#endif // COREPROVIDER_H
