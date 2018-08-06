#include "simpleclient.h"

simpleClient::simpleClient(QObject *parent) : QObject(parent)
{

}

void simpleClient::Connect()
{
    this->socket = new QTcpSocket();

    socket->connectToHost("127.0.0.1", 1235);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected\n";

        socket->write("hello server\r\n\r\n\r\n");
        socket->waitForBytesWritten(1000);

        socket->waitForReadyRead(3000);

        qDebug() << "Reading: \n" << socket->bytesAvailable();

        qDebug() << socket->readAll();

        socket->close();
    }
    else
    {qDebug() << "Not Connected\n";}

}
