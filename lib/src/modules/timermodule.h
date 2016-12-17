#ifndef TIMERMODULE_H
#define TIMERMODULE_H

#include <QObject>
#include <QJSEngine>
#include <QJSValue>
#include <QJSValueList>
#include <QHash>
#include <QTimer>

#include <src/nodeeventloop.h>
#include <src/nodeengine.h>
#include <src/nodemodule.h>

class TimerModule : public QObject, public NodeModule
{
    Q_OBJECT
    Q_INTERFACES(NodeModule)
public:
    explicit TimerModule(QJSEngine *engine);

    Q_INVOKABLE int setInterval(QJSValue callback, int t, QJSValue args);
    Q_INVOKABLE int setTimeout(QJSValue callback, int t, QJSValue args);

    Q_INVOKABLE void clear(int id);

    QJSValue getJSInstance();
    bool isBusy();

private:
    int nextID;
    QJSEngine* engine;
    QHash<int, QTimer*> timers;
    int createTimer(QJSValue callback, QJSValue args);

signals:
    void dispatch(QJSValue target, QJSValueList args);
    void ipcMessage(QJSValue msg);
};

#endif // TIMERMODULE_H
