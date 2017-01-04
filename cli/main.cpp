#include <QCoreApplication>
#include <QDebug>
#include <QJSEngine>
#include <QObject>
#include <QTextCodec>

#include "app.h"
#include "src/engine/enginecontext.h"

int main(int argc, char* argv[]) {
  App* a = new App(argc, argv);

  a->exec();
}
