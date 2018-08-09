 #include <QCoreApplication>
#include "simpleclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    simpleClient* client = new simpleClient();
    client->Connect();

    return a.exec();
}
