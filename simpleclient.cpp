#include "simpleclient.h"
#include <iostream>
#include <QString>

simpleClient::simpleClient(QObject *parent) : QObject(parent)
{

}

void simpleClient::Connect()
{
    this->socket = new QTcpSocket();

    socket->connectToHost("127.0.0.1", 1111);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected\n";

        socket->waitForBytesWritten(1000);

        socket->waitForReadyRead(3000);

        qDebug() << "Reading: \n" << socket->bytesAvailable();
        qDebug() << socket->readAll();

        std::string user_name;

        do{

            std::getline(std::cin, user_name);
            qDebug() << "YOUR INPUT IS: ";
            std::cout << user_name << "\n\n";

            char usr_arr[1024];
            strncpy(usr_arr, user_name.c_str(), sizeof(usr_arr));
            usr_arr[sizeof(usr_arr) - 1] = 0;

            socket->write(usr_arr);

            socket->waitForBytesWritten(2000);
            socket->flush();

        }while(std::strcmp((const char*)&user_name, "end"));

    }
    else
    {qDebug() << "Not Connected\n";}
}
