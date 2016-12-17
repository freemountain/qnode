#ifndef PROCESSMODULE_H
#define PROCESSMODULE_H

#include <QObject>
#include <QJSValue>
#include <QJSEngine>
#include <QJSValueList>


#include <src/nodeeventloop.h>
#include <src/nodemodule.h>

class ProcessModule: public QObject, public NodeModule {
    Q_OBJECT
    Q_INTERFACES(NodeModule)
public:
    explicit ProcessModule(QJSEngine *engine);

    Q_INVOKABLE void nextTick(QJSValue callback, QJSValue args);
    Q_INVOKABLE void send(QJSValue msg);

    QJSValue getJSInstance();
    bool isBusy();

signals:
    void dispatch(QJSValue target, QJSValueList args);
    void ipcMessage(QJSValue msg);

private:
    QJSEngine *engine;
};

#endif // PROCESSMODULE_H
