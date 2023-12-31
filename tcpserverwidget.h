#ifndef TCPSERVERWIDGET_H
#define TCPSERVERWIDGET_H

#include "tcpserver.h"
#include <QWidget>

namespace Ui {
class TcpServerWidget;
}

class TcpServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServerWidget(QWidget *parent = nullptr);
    ~TcpServerWidget();

private slots:
    void appendReceivedData(QString client, QByteArray data);
    void updateConnectionList(QVector<QString> list);
    void updateServerState(TcpServer::ServerState state);
    void newClientConnectedIn(QString client);
    void clientDisconnected(QString client);
    void serverErrorHandler(QString error);

    void on_actionPushButton_clicked();

    void on_clearConversationPushButton_clicked();

    void on_clearSendPushButton_clicked();

    void on_clientListComboBox_activated(int index);

    void on_sendPushButton_clicked();

    void on_disconnectPushButton_clicked();

    // pause or resume accepting new connections
    void on_pausePushButton_clicked();

private:
    bool paused;
    QString curConnection;
    QVector<QString> connectionList;
    TcpServer tcpServer;
    TcpServer::ServerState serverState;
    Ui::TcpServerWidget *ui;
};

#endif // TCPSERVERWIDGET_H
