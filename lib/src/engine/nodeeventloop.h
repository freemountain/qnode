#ifndef NODEEVENTLOOP_H
#define NODEEVENTLOOP_H

#include <QObject>
#include <QQueue>
#include <QJSValue>
#include <QJSValueList>

#include "src/nodemodule.h"

class NodeEvent {
    public:
        explicit NodeEvent(QJSValue target, QJSValueList arguments) {
            this->target = target;
            this->arguments = arguments;
        }
        QJSValue target;
        QJSValueList arguments;
};

class NodeEventLoop : public QObject
{
    Q_OBJECT
public:
    explicit NodeEventLoop(QObject *parent = 0);
    int getQueueSize();
    bool isRunning();
    bool modulesBusy();

private:
    QList<NodeModule*> modules;
    QQueue<NodeEvent> queue;
    bool running;
    bool idle;

signals:
    void finished(QJSValue error);
    void ipcMessage(QJSValue msg);
    void _tick(int n);

private slots:
    void _onTick(int n);

public slots:
    void addNativeModule(NodeModule* module);
    void postEvent(QJSValue target, QJSValueList arguments);
    void start();

};

#endif // NODEEVENTLOOP_H
