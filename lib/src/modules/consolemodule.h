#ifndef CONSOLEMODULE_H
#define CONSOLEMODULE_H

#include <QObject>

#include "src/engine/enginecontext.h"
#include "src/modules/basemodule.h"

class ConsoleModule : public BaseModule
{
    Q_OBJECT

public:
    explicit ConsoleModule(EngineContext* ctx);

    Q_INVOKABLE void log(QString msg);
};

#endif // CONSOLEMODULE_H
