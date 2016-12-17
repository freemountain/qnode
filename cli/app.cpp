#include "app.h"

#include <QJSEngine>
#include <QDebug>
#include <QObject>
#include <QDir>

#include "src/moduleloader.h"
#include "src/jsvalueutils.h"
#include "src/utils.h"

App::App(int &argc, char *argv[]): QCoreApplication(argc, argv)
{
    this->engine = new NodeEngine(this);

    connect(engine, &NodeEngine::finished, [this](const QJSValue &e) {
        int code = 0;
        if(e.isError()) {
            code = 1;
            qDebug() <<" main:"
                    << e.property("name").toString()
                    << e.property("message").toString()
                    << e.property("stack").toString();
        };
        this->exit(code);
    });

    connect(engine, &NodeEngine::ipcMessage, [this](const QJSValue &msg) {
        qDebug() << "ipcMsg: " << JSValueUtils::stringify(msg);
    });
}

int App::exec() {
    if(this->arguments().size() < 2) {
        qFatal("no entry point");
    }
    QString arg = this->arguments().at(1);
    QString entry = Utils::resolvePath(QDir::currentPath(), arg);
    QString path = Utils::dirname(entry);

    this->engine->start(entry, path);
    return QCoreApplication::exec();
}
