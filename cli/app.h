#ifndef APP_H
#define APP_H

#include "src/engine/nodeengine.h"
#include <QCoreApplication>
#include <QObject>

class App : public QCoreApplication {

  Q_OBJECT
public:
  App(int &argc, char *argv[]);
  int exec();

private:
  NodeEngine *engine;
  QTextStream *out;
};

#endif // APP_H
