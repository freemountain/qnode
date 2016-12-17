#include <QCoreApplication>
#include <QtTest>
#include <QDebug>

#include "jsvalueutilstest.h"
#include "jstests.h"

#ifndef SRCDIR
   #error "SRCDIR not defined"
#endif

int main(int argc, char** argv)
{
   QString srcDir = QString(SRCDIR);
   QCoreApplication a(argc, argv);

   int status = 0;
   auto ASSERT_TEST = [&status, argc, argv](QObject* obj) {
     status |= QTest::qExec(obj, argc, argv);
     delete obj;
   };

   ASSERT_TEST(new JSValueUtilsTest());
   ASSERT_TEST(new JSTest());

   return status;
}

