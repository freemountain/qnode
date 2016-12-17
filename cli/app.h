#ifndef APP_H
#define APP_H

#include <QObject>
#include <QCoreApplication>
#include "src/nodeengine.h"

class App : public QCoreApplication
{
    Q_OBJECT
public:
    App(int &argc, char *argv[]);
    int exec();
private:
    NodeEngine* engine;
};

#endif // APP_H
