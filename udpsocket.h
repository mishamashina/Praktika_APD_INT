#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "QUdpSocket"
#include "QDebug"
#include <QNetworkDatagram>
#include "datagram.cpp"

class UdpSocket: public QUdpSocket
{
    Q_OBJECT
public:
    UdpSocket();
    void readDatagramAPD();
    DatagramAPD convertTheDatagram(char* begin);
    DatagramAPD datagramAPD;
    QUdpSocket* udpSocket;
    QBitArray* bitArray;
    bool flag;

public slots:
    //void writeDatagramAPD();

signals:
    void sendDatagramAPD(DatagramAPD datagramAPD);

};

#endif // UDPSOCKET_H
