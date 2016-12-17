#include "nodeengine.h"

#include "jsvalueutils.h"
#include "utils.h"

#include <QDebug>

NodeEngine::NodeEngine(QObject *parent) : QObject(parent)
{

    this->engine = new QJSEngine(this);
    this->engine->installExtensions(QJSEngine::ConsoleExtension);
    this->engine->evaluate(Utils::readFile(":/libqnode/js/prelude.js"), "@prelude");
    this->loop = new NodeEventLoop(this);
    this->coreProvider = new CoreProvider(engine);

    this->loader = new ModuleLoader(this->engine);
    this->loader->addModuleProvider(this->coreProvider);
    this->engine->globalObject().setProperty("_loader", this->loader->getJSValue());

    connect(this->loader, &ModuleLoader::loadedNativeModule, this->loop, &NodeEventLoop::addNativeModule);

    connect(this->loop, &NodeEventLoop::finished, [=](const QJSValue &e) {
        if(e.isError()) {
            qDebug() << "enginge error";
        }
        emit finished(e);
    });

    connect(this->loop, &NodeEventLoop::ipcMessage, this, &NodeEngine::ipcMessage);
}

void NodeEngine::start(QString entry, QString path) {
    QString src = QString("function main() {"
                          "var result = _loader.require('%1', '%2');"
                          "if(result instanceof Error) throw result;"
                          "if(result === undefined || result === null) throw new Error('Could not find %1');"
                          "}").arg(entry, path);

    QJSValue entrypoint = JSValueUtils::createFunction(this->engine, src, entry);

    if(entrypoint.isError()) {
        emit finished(entrypoint);
        return;
    }

    this->loop->postEvent(entrypoint, QJSValueList());
    this->loop->start();
}

QJSValue NodeEngine::parseJson(QString json) {
    QJSValue parser = JSValueUtils::createFunction(this->engine, "function(json) {"
                                               "    return JSON.parse(json);"
                                               "}", "@parseJson");
    return parser.call(QJSValueList() << json);
}

QJSEngine* NodeEngine::getEngine() {
    return this->engine;
}
