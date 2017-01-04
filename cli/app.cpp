#include "app.h"

#include <QDebug>
#include <QDir>
#include <QJSEngine>
#include <QJSValueIterator>
#include <QObject>

#include "qnode.h"
#include "src/engine/moduleloader.h"
#include "src/jsvalueutils.h"
#include "src/utils.h"

App::App(int& argc, char* argv[])
    : QCoreApplication(argc, argv)

{
  this->out = new QTextStream(stdout);
  this->err = new QTextStream(stderr);

  this->engine = new NodeEngine(this);

  connect(engine, &NodeEngine::finished,
          [this](const QJSValue& e, const bool& failed) {
            int code = 0;
            QStringList stackLines = e.property("stack").toString().split("\n");

            if (failed) {
              code = 1;
              this->err->operator<<(e.property("name").toString() + ": " +
                                    e.property("message").toString() + "\n");

              for (int i = 0; i < stackLines.size(); i++)
                this->err->operator<<("  " + stackLines.at(i) + "\n");
            };

            this->out->flush();
            this->err->flush();

            this->exit(code);
          });

  connect(engine, &NodeEngine::ipcMessage, [this](const QJSValue& msg) {
    qDebug() << "ipcMsg: " << JSValueUtils::stringify(msg);
  });

  connect(engine, &NodeEngine::readyReadStandardOutput, [this]() {
    this->out->operator<<(this->engine->readAllStandardOutput());
    this->out->flush();
  });

  connect(engine, &NodeEngine::readyReadStandardError, [this]() {
    this->err->operator<<(this->engine->readAllStandardError());
    this->err->flush();
  });
}

int App::exec() {
  if (this->arguments().size() < 2) {
    qFatal("no entry point");
  }
  QString arg = this->arguments().at(1);
  QString entry = Utils::resolvePath(QDir::currentPath(), arg);
  QString path = Utils::dirname(entry);

  this->engine->start(entry, path);
  return QCoreApplication::exec();
}
