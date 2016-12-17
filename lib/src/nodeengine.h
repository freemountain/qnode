#ifndef NODEENGINE_H
#define NODEENGINE_H

#include <QObject>
#include <QJSEngine>
#include <QJSValue>

#include "src/moduleloader.h"
#include "src/nodeeventloop.h"
#include "modules/coreprovider.h"

class NodeEngine : public QObject
{
    Q_OBJECT

public:
    explicit NodeEngine(QObject *parent = 0);
    QJSValue require(QString js);
    QJSValue parseJson(QString json);
    QJSEngine* getEngine();

private:
    QJSEngine* engine;
    ModuleLoader* loader;
    NodeEventLoop* loop;
    CoreProvider* coreProvider;

signals:
    void finished(QJSValue error);
    void ipcMessage(QJSValue msg);

public slots:
    void start(QString entry, QString path);
};

#endif // NODEENGINE_H
