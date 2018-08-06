#ifndef SIMPLECLIENT_H
#define SIMPLECLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class simpleClient : public QObject
{
    Q_OBJECT
public:
    explicit simpleClient(QObject *parent = nullptr);
    void Connect();
signals:

public slots:

private:
    QTcpSocket* socket;

};

#endif // SIMPLECLIENT_H
