#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QListWidget>
#include <QMenu>

#include "QLoginDialog.h"
#include "ClientDemo.h"
#include "TxMsgHandler.h"

class MainWin : public QWidget,public TxMsgHandler
{
    Q_OBJECT

    typedef void (MainWin::*MSGHandler)(QTcpSocket&,TextMessage&);

    QVBoxLayout vMainLayout;
    QGroupBox msgGrpBx;
    QGroupBox inputGrpBx;
    QListWidget listWidget;
    QPlainTextEdit msgEditor;
    QLineEdit inputEdit;
    QPushButton logInOutBtn;
    QPushButton sendBtn;
    QLabel statusLbl;
    QLoginDialog loginDlg;
    QMenu listWidgetMenu;
    QString level;

    ClientDemo m_client;

    QMap<QString,MSGHandler> m_handlerMap;

    void initMember();
    void initMsgGrpBx();
    void initInputGrpBx();
    void initListWidgetMenu();
    void connectSlots();

    void setCtrlEnabled(bool enabled);
    QString getCheckedUserId();

    void CONN_Handler(QTcpSocket&,TextMessage&);
    void DSCN_Handler(QTcpSocket&,TextMessage&);
    void LIOK_Handler(QTcpSocket&,TextMessage&);
    void LIER_Handler(QTcpSocket&,TextMessage&);
    void MSGA_Handler(QTcpSocket&,TextMessage&);
    void USER_Handler(QTcpSocket&,TextMessage&);
    void CTRL_Handler(QTcpSocket&,TextMessage&);
protected:
    bool eventFilter(QObject*, QEvent*);
private slots:
    void onSendBtnClicked();
    void onLogInOutBtnClicked();
    void listWidgetMenuClicked();
    void listWidgetContextMenu(const QPoint&);
public:
    MainWin(QWidget *parent = 0);
    void handle(QTcpSocket& obj,TextMessage& message);
    ~MainWin();
};

#endif // MAINWIN_H
