#include <QCoreApplication>
#include <QJSEngine>
#include <QDebug>
#include <QObject>

#include "src/moduleloader.h"
#include "src/jsvalueutils.h"
#include "src/nodeengine.h"
#include "src/utils.h"
#include "app.h"

int main(int argc, char *argv[])
{
    App* a = new App(argc, argv);
    a->exec();
}
