#include "udpsocket.h"

UdpSocket::UdpSocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress("192.168.5.200"), 12345); //Отправление с IP и порта компьютера ; same port when will receive
    if (udpSocket->state() == QAbstractSocket::BoundState){qDebug() << udpSocket->state();}
    else{qDebug() << udpSocket->state();}

    flag = true;
    connect(udpSocket, &QUdpSocket::readyRead, this, &UdpSocket::readDatagramAPD);

}

void UdpSocket::readDatagramAPD()
{
    qDebug() << "sizeDatagram = " << udpSocket->pendingDatagramSize();

    if (flag)
    {
        qDebug() << "Запрос параметров УПС";
        QByteArray data;
        data.resize(2);
        data[0] = 0x21;
        data[1] = 0x01;

        udpSocket->writeDatagram(data, QHostAddress("192.168.5.2"), 12345);
        flag = false;
    }

    while (udpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();

        QByteArray byteArray = datagram.data();
        qDebug() << byteArray;

        if (byteArray.size() == 18)
        {
            datagramAPD = convertTheDatagram(byteArray.begin());
            qDebug() << datagramAPD.start_byte << datagramAPD.end_byte << datagramAPD.channel << datagramAPD.V_42_T400_PDK_T_start;
//            datagramAPD.interaction_algorithm = 0b0110;
//            datagramAPD.PDK = 0b01;
//            datagramAPD.UZO = 0b01;
            //datagramAPD.PDK_pause = 0x55;
            //datagramAPD.manage_of_tangent = 0b01;
            //datagramAPD.plume = 0b01;
            //datagramAPD.V42_N400 = 0b1110;
            //datagramAPD.phasing = 0b00;
            emit sendDatagramAPD(datagramAPD);
        }
    }
}

DatagramAPD UdpSocket::convertTheDatagram(char* begin)
{
    return (*(reinterpret_cast<DatagramAPD*>(begin)));
}
