#ifndef CLIENTDEMO_H
#define CLIENTDEMO_H

#include <QObject>
#include <QTcpSocket>
#include "TextMessage.h"
#include "TxtMsgAssembler.h"
#include "TxMsgHandler.h"

class ClientDemo : public QObject
{
    Q_OBJECT

    QTcpSocket m_client;
    TxtMsgAssembler m_assembler;
    TxMsgHandler* m_handler;
protected slots:
    void onConnected();
    void onDisconnected();
    void onDataReady();
    void onBytesWritten(qint64 bytes);

public:
    ClientDemo(QObject* parent = NULL);
    bool connectTo(QString ip, int port);
    qint64 send(TextMessage& message);
    void setHandler(TxMsgHandler* handler);
    qint64 available();
    bool isValid();
    void close();
};

#endif // CLIENTDEMO_H
