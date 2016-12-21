#include <QCoreApplication>
#include <QJSEngine>
#include <QDebug>
#include <QObject>

#include "app.h"
#include "src/engine/enginecontext.h"

int main(int argc, char *argv[])
{

    App* a = new App(argc, argv);
    a->exec();

}
