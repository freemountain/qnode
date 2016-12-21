#ifndef BASEMODULE_H
#define BASEMODULE_H

#include <QObject>

#include <src/nodemodule.h>
#include "src/engine/enginecontext.h"

class BaseModule : public QObject, public NodeModule
{
    Q_OBJECT
    Q_INTERFACES(NodeModule)
public:
    explicit BaseModule(EngineContext* ctx);

    QJSValue getJSInstance();
    bool isBusy();

protected:
    EngineContext* ctx;
    QJSValue jsInstance;

signals:
    void dispatch(QJSValue target, QJSValueList args);
    void ipcMessage(QJSValue msg);
    void stdOutMessage(QString msg);
};

#endif // BASEMODULE_H
