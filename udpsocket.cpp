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
    //qDebug() << "Размер полученной датаграммы =" << udpSocket->pendingDatagramSize();

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

        if (byteArray.size() == 18)
        {
            qDebug() << "Полученная датаграмма" << byteArray.toHex(' ');

            datagramAPD = convertTheDatagram(byteArray.begin());

            printDatagramAPD(datagramAPD);

//            datagramAPD.interaction_algorithm = 0b0110;
//            datagramAPD.PDK = 0b01;
//            datagramAPD.UZO = 0b01;
//            datagramAPD.PDK_pause = 0x55;
//            datagramAPD.manage_of_tangent = 0b01;
            //datagramAPD.plume = 0b01;
            //datagramAPD.V42_N400 = 0b1110;
            //datagramAPD.phasing = 0b00;
            emit sendDatagramAPD(datagramAPD);
        }
    }
}

void UdpSocket::printDatagramAPD(DatagramAPD datagramAPD)
{
    qDebug() << "----------------------------------------------------------------";
    qDebug() << "Разбивка датаграммы по битам:";
    qDebug() << Qt::hex << Qt::showbase << "start_byte:" <<datagramAPD.start_byte;
    qDebug() << Qt::hex << Qt::showbase << "kod_byte:" <<datagramAPD.kod_byte;
    qDebug() << Qt::hex << Qt::showbase << "channel:" <<datagramAPD.channel;
    qDebug() << Qt::hex << Qt::showbase << "interaction_algorithm:" <<datagramAPD.interaction_algorithm;
    qDebug() << Qt::hex << Qt::showbase << "plume:" <<datagramAPD.plume;
    qDebug() << Qt::hex << Qt::showbase << "PDK:" <<datagramAPD.PDK;
    qDebug() << Qt::hex << Qt::showbase << "UZO:" <<datagramAPD.UZO;
    qDebug() << Qt::hex << Qt::showbase << "tangent:" <<datagramAPD.tangent;
    qDebug() << Qt::hex << Qt::showbase << "phasing:" <<datagramAPD.phasing;
    qDebug() << Qt::hex << Qt::showbase << "speed_and_type_of_modulation_С1_TCH:" <<datagramAPD.speed_and_type_of_modulation_С1_TCH;
    qDebug() << Qt::hex << Qt::showbase << "transmission_level_C1_TCH:" <<datagramAPD.transmission_level_C1_TCH;
    qDebug() << Qt::hex << Qt::showbase << "module_V26:" <<datagramAPD.module_V26;
    qDebug() << Qt::hex << Qt::showbase << "frequence_V29:" <<datagramAPD.frequence_V29;
    qDebug() << Qt::hex << Qt::showbase << "scrambler:" <<datagramAPD.scrambler;
    qDebug() << Qt::hex << Qt::showbase << "adaptation_corrector:" <<datagramAPD.adaptation_corrector;
    qDebug() << Qt::hex << Qt::showbase << "cable_corrector_on_transmission:" <<datagramAPD.cable_corrector_on_transmission;
    qDebug() << Qt::hex << Qt::showbase << "cable_corrector_at_reception:" <<datagramAPD.cable_corrector_at_reception;
    qDebug() << Qt::hex << Qt::showbase << "speed_C1_FL:" <<datagramAPD.speed_C1_FL;
    qDebug() << Qt::hex << Qt::showbase << "manage_of_tangent:" <<datagramAPD.manage_of_tangent;
    qDebug() << Qt::hex << Qt::showbase << "V42_N400:" <<datagramAPD.V42_N400;
    qDebug() << Qt::hex << Qt::showbase << "block_length:" <<datagramAPD.block_length;
    qDebug() << Qt::hex << Qt::showbase << "nubmers_of_requeries:" <<datagramAPD.nubmers_of_requeries;
    qDebug() << Qt::hex << Qt::showbase << "dephasing_criterion:" <<datagramAPD.dephasing_criterion;
    qDebug() << Qt::hex << Qt::showbase << "block_depth:" <<datagramAPD.block_depth;
    qDebug() << Qt::hex << Qt::showbase << "format_5C55:" <<datagramAPD.format_5C55;
    qDebug() << Qt::hex << Qt::showbase << "inv_transfer:" <<datagramAPD.inv_transfer;
    qDebug() << Qt::hex << Qt::showbase << "inv_reception:" <<datagramAPD.inv_reception;
    qDebug() << Qt::hex << Qt::showbase << "response_mode_V42:" <<datagramAPD.response_mode_V42;
    qDebug() << Qt::hex << Qt::showbase << "PDK_pause:" <<datagramAPD.PDK_pause;
    qDebug() << Qt::hex << Qt::showbase << "add_data_ODK2_PDK2:" <<datagramAPD.add_data_ODK2_PDK2;
    qDebug() << Qt::hex << Qt::showbase << "V_42_T400_PDK_T_start:" <<datagramAPD.V_42_T400_PDK_T_start;
    qDebug() << Qt::hex << Qt::showbase << "V_42_T400_PDK_T_stop:" <<datagramAPD.V_42_T400_PDK_T_stop;
    qDebug() << Qt::hex << Qt::showbase << "loan_amount_V42:" <<datagramAPD.loan_amount_V42;
    qDebug() << Qt::hex << Qt::showbase << "max_length_kadr_V42:" <<datagramAPD.max_length_kadr_V42;
    qDebug() << Qt::hex << Qt::showbase << "end_byte:" <<datagramAPD.end_byte;
    qDebug() << "----------------------------------------------------------------";
}

DatagramAPD UdpSocket::convertTheDatagram(char* begin)
{
    return (*(reinterpret_cast<DatagramAPD*>(begin)));
}
