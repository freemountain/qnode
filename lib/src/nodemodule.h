#ifndef NODEMODULE_H
#define NODEMODULE_H

#include <QObject>
#include <QQueue>
#include <QJSValue>
#include <QJSValueList>

class NodeModule {

    public:
        virtual ~NodeModule(){}
        virtual QJSValue getJSInstance() = 0;
        virtual bool isBusy() = 0;

    //signals:
        virtual void dispatch(QJSValue target, QJSValueList args) =0;
        virtual void ipcMessage(QJSValue msg) =0;
        virtual void stdOutMessage(QString msg) =0;
};

Q_DECLARE_INTERFACE(NodeModule, "NodeModule")


#endif // NODEMODULE_H
