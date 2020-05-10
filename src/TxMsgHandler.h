#ifndef TXMSGHANDLER_H
#define TXMSGHANDLER_H

#include <QTcpSocket>
#include "TextMessage.h"

class TxMsgHandler
{

public:
    virtual void handle(QTcpSocket&,TextMessage&) = 0;
};

#endif // TXMSGHANDLER_H
