#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udp = new UdpSocket();
    timer = new QTimer(this);

    if (udp->udpSocket->state() == QAbstractSocket::BoundState){ui->statusbar->showMessage(tr("Сокет привязан"));}
    else{ui->statusbar->showMessage(tr("Сокет не привязан"));}

    connect(udp, &UdpSocket::sendDatagramAPD, this, &MainWindow::getDatagramAPD);
    connect(this, &MainWindow::changeTab, ui->tabWidget, &QTabWidget::setCurrentIndex);
    connect(timer, &QTimer::timeout, this, &MainWindow::currentSituation);
    timer->start(500);
}

void MainWindow::Channel(char data)
{
    switch (data)
    {
    case CHANNEL_C1_TCH_LVC:
        ui->lineEdit->setText(QString("С1-ТЧ|ЛВС"));
        ui->radioButton->setChecked(true);
        break;
    case CHANNEL_C1_FL_LVC:
        ui->lineEdit->setText(QString("С1-ФЛ|ЛВС"));
        ui->radioButton_2->setChecked(true);
        break;
    case CHANNEL_C1_TCH_C1_FL:
        ui->lineEdit->setText(QString("С1-ТЧ|С1-ФЛ"));
        ui->radioButton_3->setChecked(true);
        break;
    }
}

void MainWindow::InteractionAlgorithm(char data)
{
    switch (data)
    {
    case INTERACTION_ALGORITHM_ODK_PDK:
        ui->lineEdit_2->setText(QString("Симплекс ОДК/ПДК"));
        ui->radioButton_4->setChecked(true);
        break;
    case INTERACTION_ALGORITHM_DUPLEX_2:
        ui->lineEdit_2->setText(QString("Дуплекс 2"));
        ui->radioButton_5->setChecked(true);
        break;
    case INTERACTION_ALGORITHM_5C55_ARAGVA:
        ui->lineEdit_2->setText(QString("5Ц55 Арагва"));
        ui->radioButton_6->setChecked(true);
        break;
    case INTERACTION_ALGORITHM_V42:
        ui->lineEdit_2->setText(QString("V42"));
        ui->radioButton_62->setChecked(true);
        break;
    }
}

void MainWindow::Plume(char data)
{
    switch (data)
    {
    case PLUME_ON:
        ui->lineEdit_3->setText(QString("ВКЛ."));
        ui->comboBox_8->setCurrentIndex(0);
        break;
    case PLUME_OFF:
        ui->lineEdit_3->setText(QString("ВЫКЛ."));
        ui->comboBox_8->setCurrentIndex(1);
        break;
    }
}

void MainWindow::PDK(char data)
{
    switch (data)
    {
    case PDK_ODK:
        ui->lineEdit_4->setText(QString("ОДК"));
        ui->radioButton_7->setChecked(true);
        break;
    case PDK_PDK:
        ui->lineEdit_4->setText(QString("ПДК"));
        ui->radioButton_8->setChecked(true);
        break;
    }
}

void MainWindow::UZO(char data)
{
    switch (data)
    {
    case UZO_ODK1_PDK1:
        if(ui->lineEdit_4->text() == QString("ПДК")){ui->lineEdit_5->setText(QString("ПДК1"));}
        else{ui->lineEdit_5->setText(QString("ОДК1"));}
        break;
    case UZO_ODK2_PDK2:
        if(ui->lineEdit_4->text() == QString("ПДК")){ui->lineEdit_5->setText(QString("ПДК2"));}
        else{ui->lineEdit_5->setText(QString("ОДК2"));}
        break;
    }
}

void MainWindow::Tangent(char data)
{
    switch (data)
    {
    case TANGENT_ON:
        ui->lineEdit_6->setText(QString("Сам. упр."));
        break;
    case TANGENT_OFF:
        ui->lineEdit_6->setText(QString("Авт. упр."));
        break;
    }
}

void MainWindow::Phasing(char data)
{
    switch (data)
    {
    case PHASING_ONE:
        ui->lineEdit_7->setText(QString("Однократный"));
        break;
    case PHASING_PERIOD:
        ui->lineEdit_7->setText(QString("Периодический"));
        break;
    }
}

void MainWindow::SpeedAndTypeOfModulationС1TCH(char data)
{
    switch (data)
    {
    case SPEED_AND_TYPE_OF_MODULATION_С1_TCH_1:
        ui->lineEdit_8->setText(QString("9600 V29"));
        break;
    case SPEED_AND_TYPE_OF_MODULATION_С1_TCH_2:
        ui->lineEdit_8->setText(QString("7200 V29"));
        break;
    case SPEED_AND_TYPE_OF_MODULATION_С1_TCH_3:
        ui->lineEdit_8->setText(QString("4800 V29"));
        break;
    case SPEED_AND_TYPE_OF_MODULATION_С1_TCH_4:
        ui->lineEdit_8->setText(QString("4800 V27"));
        break;
    case SPEED_AND_TYPE_OF_MODULATION_С1_TCH_5:
        ui->lineEdit_8->setText(QString("2400 V26"));
        break;
    case SPEED_AND_TYPE_OF_MODULATION_С1_TCH_6:
        ui->lineEdit_8->setText(QString("1200 V26"));
        break;
    case SPEED_AND_TYPE_OF_MODULATION_С1_TCH_7:
        ui->lineEdit_8->setText(QString("1200 V23"));
        break;
    case SPEED_AND_TYPE_OF_MODULATION_С1_TCH_8:
        ui->lineEdit_8->setText(QString("600 V23"));
        break;
    }
}

void MainWindow::TransmissionLevelC1TCH(char data)
{
    switch (data)
    {
    case TRANSMISSION_LEVEL_C1_TCH_1:
        ui->lineEdit_9->setText(QString("+4 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_2:
        ui->lineEdit_9->setText(QString("+2 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_3:
        ui->lineEdit_9->setText(QString("0 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_4:
        ui->lineEdit_9->setText(QString("-2 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_5:
        ui->lineEdit_9->setText(QString("-4 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_6:
        ui->lineEdit_9->setText(QString("-6 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_7:
        ui->lineEdit_9->setText(QString("-8 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_8:
        ui->lineEdit_9->setText(QString("-10 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_9:
        ui->lineEdit_9->setText(QString("-12 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_10:
        ui->lineEdit_9->setText(QString("-14 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_11:
        ui->lineEdit_9->setText(QString("-16 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_12:
        ui->lineEdit_9->setText(QString("-18 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_13:
        ui->lineEdit_9->setText(QString("-20 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_14:
        ui->lineEdit_9->setText(QString("-22 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_15:
        ui->lineEdit_9->setText(QString("-24 дБ"));
        break;
    case TRANSMISSION_LEVEL_C1_TCH_16:
        ui->lineEdit_9->setText(QString("-26 дБ"));
        break;
    }
}

void MainWindow::ModuleV26(char data)
{
    switch (data)
    {
    case MODULE_V26_A:
        ui->lineEdit_10->setText(QString("Альтернатива А"));
        break;
    case MODULE_V26_B:
        ui->lineEdit_10->setText(QString("Альтернатива В"));
        break;
    }
}

void MainWindow::FrequenceV29(char data)
{
    switch (data)
    {
    case FREQUENCE_V29_1800:
        ui->lineEdit_11->setText(QString("1800 Гц"));
        break;
    case FREQUENCE_V29_1700:
        ui->lineEdit_11->setText(QString("1700 Гц"));
        break;
    }
}

void MainWindow::Scrambler(char data)
{
    switch (data)
    {
    case SCRAMBLER_ON:
        ui->lineEdit_12->setText(QString("ВКЛ."));
        break;
    case SCRAMBLER_OFF:
        ui->lineEdit_12->setText(QString("ВЫКЛ."));
        break;
    }
}

void MainWindow::AdaptationCorrector(char data)
{
    switch (data)
    {
    case ADAPTATION_CORRECTOR_ON:
        ui->lineEdit_13->setText(QString("ВКЛ."));
        break;
    case ADAPTATION_CORRECTOR_OFF:
        ui->lineEdit_13->setText(QString("ВЫКЛ."));
        break;
    }
}

void MainWindow::CableCorrectorOnTransmission(char data)
{
    switch (data)
    {
    case CABLE_CORRECTOR_ON_TRANSMISSION_ON:
        ui->lineEdit_14->setText(QString("ВКЛ."));
        break;
    case CABLE_CORRECTOR_ON_TRANSMISSION_OFF:
        ui->lineEdit_14->setText(QString("ВЫКЛ."));
        break;
    }
}

void MainWindow::CableCorrectorAtReception(char data)
{
    switch (data)
    {
    case CABLE_CORRECTOR_AT_RECEPTION_ON:
        ui->lineEdit_15->setText(QString("ВКЛ."));
        break;
    case CABLE_CORRECTOR_AT_RECEPTION_OFF:
        ui->lineEdit_15->setText(QString("ВЫКЛ."));
        break;
    }
}

void MainWindow::SpeedC1Fl(char data)
{
    switch (data)
    {
    case SPEED_C1_FL_1:
        ui->lineEdit_16->setText(QString("9600"));
        break;
    case SPEED_C1_FL_2:
        ui->lineEdit_16->setText(QString("4800"));
        break;
    case SPEED_C1_FL_3:
        ui->lineEdit_16->setText(QString("2400"));
        break;
    case SPEED_C1_FL_4:
        ui->lineEdit_16->setText(QString("1200"));
        break;
    case SPEED_C1_FL_5:
        ui->lineEdit_16->setText(QString("600"));
        break;
    case SPEED_C1_FL_6:
        ui->lineEdit_16->setText(QString("19200"));
        break;
    case SPEED_C1_FL_7:
        ui->lineEdit_16->setText(QString("16000"));
        break;
    case SPEED_C1_FL_8:
        ui->lineEdit_16->setText(QString("32000"));
        break;
    case SPEED_C1_FL_9:
        ui->lineEdit_16->setText(QString("48000"));
        break;
    default:
        ui->lineEdit_16->setText(QString("9600"));
        break;
    }
}

void MainWindow::ManageOfTangent(char data)
{
    switch (data)
    {
    case MANAGE_OF_TANGENT_ON:
        ui->lineEdit_17->setText(QString("ВКЛ."));
        break;
    case MANAGE_OF_TANGENT_OFF:
        ui->lineEdit_17->setText(QString("ВЫКЛ."));
        break;
    }
}

void MainWindow::V42N400(char data)
{
    switch (data)
    {
    case V42_N400_0:
        ui->lineEdit_18->setText(QString("0 перезапросов"));
        break;
    case V42_N400_1:
        ui->lineEdit_18->setText(QString("1 перезапрос"));
        break;
    case V42_N400_2:
        ui->lineEdit_18->setText(QString("2 перезапроса"));
        break;
    case V42_N400_3:
        ui->lineEdit_18->setText(QString("3 перезапроса"));
        break;
    case V42_N400_4:
        ui->lineEdit_18->setText(QString("4 перезапроса"));
        break;
    case V42_N400_5:
        ui->lineEdit_18->setText(QString("5 перезапросов"));
        break;
    case V42_N400_6:
        ui->lineEdit_18->setText(QString("6 перезапросов"));
        break;
    case V42_N400_7:
        ui->lineEdit_18->setText(QString("7 перезапросов"));
        break;
    case V42_N400_8:
        ui->lineEdit_18->setText(QString("8 перезапросов"));
        break;
    case V42_N400_9:
        ui->lineEdit_18->setText(QString("9 перезапросов"));
        break;
    case V42_N400_10:
        ui->lineEdit_18->setText(QString("10 перезапросов"));
        break;
    case V42_N400_11:
        ui->lineEdit_18->setText(QString("11 перезапросов"));
        break;
    case V42_N400_12:
        ui->lineEdit_18->setText(QString("12 перезапросов"));
        break;
    case V42_N400_13:
        ui->lineEdit_18->setText(QString("13 перезапросов"));
        break;
    case V42_N400_14:
        ui->lineEdit_18->setText(QString("14 перезапросов"));
        break;
    case V42_N400_15:
        ui->lineEdit_18->setText(QString("15 перезапросов"));
        break;
    }
}

void MainWindow::BlockLength(char data)
{
    switch (data)
    {
    case BLOCK_LENGTH_1:
        ui->lineEdit_19->setText(QString("6"));
        ui->lineEdit_20->setText(QString("48/65"));
        break;
    case BLOCK_LENGTH_2:
        ui->lineEdit_19->setText(QString("12"));
        ui->lineEdit_20->setText(QString("96/116"));
        break;
    case BLOCK_LENGTH_3:
        ui->lineEdit_19->setText(QString("18"));
        ui->lineEdit_20->setText(QString("144/165"));
        break;
    }
}

void MainWindow::NubmersOfRequeries(char data)
{
    switch (data)
    {
    case NUBMERS_OF_REQUERIES_1:
        ui->lineEdit_21->setText(QString("0"));
        break;
    case NUBMERS_OF_REQUERIES_2:
        ui->lineEdit_21->setText(QString("1"));
        break;
    case NUBMERS_OF_REQUERIES_3:
        ui->lineEdit_21->setText(QString("3"));
        break;
    case NUBMERS_OF_REQUERIES_4:
        ui->lineEdit_21->setText(QString("не ограничено"));
        break;
    }
}

void MainWindow::DephasingCriterion(char data)
{
    switch (data)
    {
    case DEPHASING_CRITERION_1:
        ui->lineEdit_22->setText(QString("4 запроса"));
        break;
    case DEPHASING_CRITERION_2:
        ui->lineEdit_22->setText(QString("10 запросов"));
        break;
    case DEPHASING_CRITERION_3:
        ui->lineEdit_22->setText(QString("25 запросов"));
        break;
    case DEPHASING_CRITERION_4:
        ui->lineEdit_22->setText(QString("45 запросов"));
        break;
    case DEPHASING_CRITERION_5:
        ui->lineEdit_22->setText(QString("85 запросов"));
        break;
    case DEPHASING_CRITERION_6:
        ui->lineEdit_22->setText(QString("120 запросов"));
        break;
    case DEPHASING_CRITERION_7:
        ui->lineEdit_22->setText(QString("2 сек"));
        break;
    case DEPHASING_CRITERION_8:
        ui->lineEdit_22->setText(QString("10 сек"));
        break;
    }
}

void MainWindow::BlockDepth(char data)
{
    switch (data)
    {
    case BLOCK_DEPTH_1:
        ui->lineEdit_23->setText(QString("4"));
        break;
    case BLOCK_DEPTH_2:
        ui->lineEdit_23->setText(QString("6"));
        break;
    case BLOCK_DEPTH_3:
        ui->lineEdit_23->setText(QString("11"));
        break;
    case BLOCK_DEPTH_4:
        ui->lineEdit_23->setText(QString("4"));
        break;
    }
}

void MainWindow::Format5C55(char data)
{
    switch (data)
    {
    case FORMAT_5C55_1:
        ui->lineEdit_24->setText(QString("17 байт"));
        break;
    case FORMAT_5C55_2:
        ui->lineEdit_24->setText(QString("18 байт"));
        break;
    }
}

void MainWindow::InvTransfer(char data)
{
    switch (data)
    {
    case INV_TRANSFER_1:
        if (ui->lineEdit_24->text() == QString("17 байт"))
        {
            ui->lineEdit_25->setText(QString("Данные от ООД поступают в канал без инверсии"));
        }
        else
        {
            ui->lineEdit_25->setText(QString("Данные от ООД перед передачей в канал инвертируются"));
        }
        break;
    case INV_TRANSFER_2:
        if (ui->lineEdit_24->text() == QString("17 байт"))
        {
            ui->lineEdit_25->setText(QString("Данные от ООД перед передачей в канал инвертируются"));
        }
        else
        {
            ui->lineEdit_25->setText(QString("Данные от ООД поступают в канал без инверсии"));
        }
        break;
    }
}

void MainWindow::InvReception(char data)
{
    switch (data)
    {
    case INV_RECEPTION_1:
        if (ui->lineEdit_24->text() == QString("17 байт"))
        {
            ui->lineEdit_26->setText(QString("Данные к ООД поступают из канала без инверсии"));
        }
        else
        {
            ui->lineEdit_26->setText(QString("Данные из канала перед отправкой к ООД инвертируются"));
        }
        break;
    case INV_RECEPTION_2:
        if (ui->lineEdit_24->text() == QString("17 байт"))
        {
            ui->lineEdit_26->setText(QString("Данные из канала перед отправкой к ООД инвертируются"));
        }
        else
        {
            ui->lineEdit_26->setText(QString("Данные к ООД поступают из канала без инверсии"));
        }
        break;
    }
}

void MainWindow::ResponseModeV42(char data)
{
    switch (data)
    {
    case RESPONSE_MODE_V42_1:
        ui->lineEdit_27->setText(QString("Инициатор"));
        break;
    case RESPONSE_MODE_V42_2:
        ui->lineEdit_27->setText(QString("Ответчик"));
        break;
    }
}

void MainWindow::PDKPause(char data)
{
    switch (data)
    {
    case PDK_PAUSE:
        ui->lineEdit_28->setText(QString("Точки"));
        break;
    }
}

void MainWindow::AddDataODK2PDK2(char data)
{
    switch (data)
    {
    case ADD_DATA_ODK2_PDK2:
        ui->lineEdit_29->setText(QString("0x00"));
        break;
    }
}

void MainWindow::V42T400PDKTStart(char data)
{
    switch (data)
    {
    case V_42_T400_PDK_T_START:
        if (ui->lineEdit_2->text() == QString("V42"))
        {
            ui->lineEdit_30->setText(QString("2 секунды"));
        }
        else if ((ui->lineEdit_5->text() == QString("ПДК1") || ui->lineEdit_5->text() == QString("ПДК2")) && ui->lineEdit_17->text() == QString("ВКЛ."))
        {
            ui->lineEdit_30->setText(QString("20 мс"));
        }
        else
        {
            ui->lineEdit_30->clear();
        }
        break;
    }
}

void MainWindow::V42T400PDKTStop(char data)
{
    switch (data)
    {
    case V_42_T400_PDK_T_STOP:
        if (ui->lineEdit_2->text() == QString("V42"))
        {
            ui->lineEdit_31->setText(QString("5 секунд"));
        }
        else if ((ui->lineEdit_5->text() == QString("ПДК1") || ui->lineEdit_5->text() == QString("ПДК2")) && ui->lineEdit_17->text() == QString("ВКЛ."))
        {
            ui->lineEdit_31->setText(QString("30 мс"));
        }
        else
        {
            ui->lineEdit_31->clear();
        }
        break;
    }
}

void MainWindow::LoanAmountV42(char data)
{
    switch (data)
    {
    case LOAN_AMOUNT_V42:
        ui->lineEdit_32->setText(QString("15"));
        break;
    }
}

void MainWindow::MaxLengthKadrV42(char data)
{
    switch (data)
    {
    case MAX_LENGTH_KADR_V42:
        ui->lineEdit_33->setText(QString("256"));
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    udp->udpSocket->close();
    qDebug() << udp->udpSocket->state();
}

void MainWindow::getDatagramAPD(DatagramAPD datagramAPD)
{
    datagramAPDMain = datagramAPD;

    Channel(datagramAPD.channel);
    InteractionAlgorithm(datagramAPD.interaction_algorithm);
    Plume(datagramAPD.plume);
    if (ui->lineEdit_2->text() == QString("Симплекс ОДК/ПДК"))
    {
        // проверка симплекс
        PDK(datagramAPD.PDK); // 4
        UZO(datagramAPD.UZO); // 5
    }
    else
    {
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
    }
    if (ui->lineEdit_5->text() == QString("ПДК1") || ui->lineEdit_5->text() == QString("ПДК2"))
    {
        // проверка пдк1 и пдк2
        ManageOfTangent(datagramAPD.manage_of_tangent); // 17
        if (ui->lineEdit_17->text() == QString("ВКЛ."))
        {
            // проверка включена ли тангента
            Tangent(datagramAPD.tangent); // 6
        }
        else
        {
            ui->lineEdit_6->clear();
        }
        Phasing(datagramAPD.phasing); // 7
        PDKPause(datagramAPD.PDK_pause);// 28
    }
    else
    {
        ui->lineEdit_17->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_28->clear();
    }
    if (ui->lineEdit->text() == QString("С1-ТЧ|ЛВС") || ui->lineEdit->text() == QString("С1-ТЧ|С1-ФЛ"))
    {
        // проверка канала С1-ТЧ
        SpeedAndTypeOfModulationС1TCH(datagramAPD.speed_and_type_of_modulation_С1_TCH); //8
        TransmissionLevelC1TCH(datagramAPD.transmission_level_C1_TCH); //9
        if (ui->lineEdit_8->text() == QString("2400 V26") || ui->lineEdit_8->text() == QString("1200 V26"))
        {
            // проверка скорости
            ModuleV26(datagramAPD.module_V26);//10
        }
        else
        {
            ui->lineEdit_10->clear();
        }
        if (ui->lineEdit_8->text() == QString("9600 V29") || ui->lineEdit_8->text() == QString("7200 V29") || ui->lineEdit_8->text() == QString("4800 V29"))
        {
            // проверка скорости
            FrequenceV29(datagramAPD.frequence_V29);//11
            AdaptationCorrector(datagramAPD.adaptation_corrector);//13
        }
        else
        {
            ui->lineEdit_11->setText(QString("1800 Гц"));
        }
        CableCorrectorOnTransmission(datagramAPD.cable_corrector_on_transmission); //14
        CableCorrectorAtReception(datagramAPD.cable_corrector_at_reception);//15
    }
    else
    {
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_11->clear();
        ui->lineEdit_13->clear();
        ui->lineEdit_14->clear();
        ui->lineEdit_15->clear();
    }
    Scrambler(datagramAPD.scrambler);
    if (ui->lineEdit->text() == QString("С1-ФЛ|ЛВС"))
    {
        // проверка канала С1-ФЛ
        SpeedC1Fl(datagramAPD.speed_C1_FL);//16
    }
    else
    {
        ui->lineEdit_16->clear();
    }
    if (ui->lineEdit_2->text() == QString("V42"))
    {
        // проверка V42
        V42N400(datagramAPD.V42_N400);//18
        ResponseModeV42(datagramAPD.response_mode_V42);//27
        LoanAmountV42(datagramAPD.loan_amount_V42);//32
        MaxLengthKadrV42(datagramAPD.max_length_kadr_V42);//33
    }
    else
    {
        ui->lineEdit_18->clear();
        ui->lineEdit_27->clear();
        ui->lineEdit_32->clear();
        ui->lineEdit_33->clear();
    }
    if (ui->lineEdit_2->text() == QString("Симплекс ОДК/ПДК") || ui->lineEdit_2->text() == QString("Дуплекс 2"))
    {
        // проверка алгоритма взаимодействия Симплекс ОДК/ПДК или Дуплекс 2
        BlockLength(datagramAPD.block_length); //19 и 20
    }
    else
    {
        ui->lineEdit_19->clear();
        ui->lineEdit_20->clear();
    }
    if (ui->lineEdit_2->text() == QString("Дуплекс 2"))
    {
        // проверка алгоритма взаимодействия Дуплекс 2
        NubmersOfRequeries(datagramAPD.nubmers_of_requeries);//21
        DephasingCriterion(datagramAPD.dephasing_criterion);//22
        BlockDepth(datagramAPD.block_depth);//23
    }
    else
    {
        ui->lineEdit_21->clear();
        ui->lineEdit_22->clear();
        ui->lineEdit_23->clear();
    }
    if (ui->lineEdit_2->text() == QString("5Ц55 Арагва"))
    {
        // проверка 5Ц55 Арагва
        Format5C55(datagramAPD.format_5C55);//24
        InvTransfer(datagramAPD.inv_transfer);//25
        InvReception(datagramAPD.inv_reception);//26
    }
    else
    {
        ui->lineEdit_24->clear();
        ui->lineEdit_25->clear();
        ui->lineEdit_26->clear();
    }
    if (ui->lineEdit_5->text() == QString("ПДК2") || ui->lineEdit_5->text() == QString("ОДК2"))
    {
        AddDataODK2PDK2(datagramAPD.add_data_ODK2_PDK2);//29
    }
    else
    {
        ui->lineEdit_29->clear();
    }
    V42T400PDKTStart(datagramAPD.V_42_T400_PDK_T_start);
    V42T400PDKTStop(datagramAPD.V_42_T400_PDK_T_stop);
}

void MainWindow::currentSituation()
{
    //c1t4
    if (ui->radioButton->isChecked() || ui->radioButton_3->isChecked())
    {
        ui->groupBox_9->setVisible(true);
    }
    else
    {
        ui->groupBox_9->setVisible(false);
    }
    ///simpleks
    if (ui->radioButton_4->isChecked())
    {
        ui->groupBox_10->setVisible(true);
    }
    else
    {
        ui->groupBox_10->setVisible(false);
    }
    ///dupleks
    if (ui->radioButton_5->isChecked())
    {
        ui->groupBox_11->setVisible(true);
    }
    else
    {
        ui->groupBox_11->setVisible(false);
    }
}

void MainWindow::on_pushButton_clicked()
{
    datagramAPDMain.kod_byte = 0x02;
    datagramAPDMain.PDK_pause = 0x55;
    // channel
    //С1-ТЧ
    if (ui->radioButton->isChecked())
    {
        datagramAPDMain.channel = CHANNEL_C1_TCH_LVC;
        if (ui->comboBox->currentText() == QString("9600 V29")){datagramAPDMain.speed_and_type_of_modulation_С1_TCH = SPEED_AND_TYPE_OF_MODULATION_С1_TCH_1;}
        else if (ui->comboBox->currentText() == QString("7200 V29")){datagramAPDMain.speed_and_type_of_modulation_С1_TCH = SPEED_AND_TYPE_OF_MODULATION_С1_TCH_2;}
        else if (ui->comboBox->currentText() == QString("4800 V29")){datagramAPDMain.speed_and_type_of_modulation_С1_TCH = SPEED_AND_TYPE_OF_MODULATION_С1_TCH_3;}
        else if (ui->comboBox->currentText() == QString("4800 V27")){datagramAPDMain.speed_and_type_of_modulation_С1_TCH = SPEED_AND_TYPE_OF_MODULATION_С1_TCH_4;}
        else if (ui->comboBox->currentText() == QString("2400 V26")){datagramAPDMain.speed_and_type_of_modulation_С1_TCH = SPEED_AND_TYPE_OF_MODULATION_С1_TCH_5;}
        else if (ui->comboBox->currentText() == QString("1200 V26")){datagramAPDMain.speed_and_type_of_modulation_С1_TCH = SPEED_AND_TYPE_OF_MODULATION_С1_TCH_6;}
        else if (ui->comboBox->currentText() == QString("1200 V23")){datagramAPDMain.speed_and_type_of_modulation_С1_TCH = SPEED_AND_TYPE_OF_MODULATION_С1_TCH_7;}
        else {datagramAPDMain.speed_and_type_of_modulation_С1_TCH = SPEED_AND_TYPE_OF_MODULATION_С1_TCH_8;}
    }
    if (ui->radioButton_2->isChecked()){datagramAPDMain.channel = CHANNEL_C1_FL_LVC;}
    if (ui->radioButton_3->isChecked()){datagramAPDMain.channel = CHANNEL_C1_TCH_C1_FL;}
    // interaction_algorithm
    if (ui->radioButton_4->isChecked())
    {
        datagramAPDMain.interaction_algorithm = INTERACTION_ALGORITHM_ODK_PDK;
        if (ui->radioButton_7->isChecked()) //ODK
        {
            datagramAPDMain.PDK = PDK_ODK;
            if (ui->radioButton_9->isChecked())// ODK1/PDK1
            {
                datagramAPDMain.UZO = UZO_ODK1_PDK1;
            }
            else
            {
                datagramAPDMain.UZO = UZO_ODK2_PDK2;
            }
        }
        else
        {
            datagramAPDMain.PDK = PDK_PDK;
            if (ui->radioButton_9->isChecked())
            {
                datagramAPDMain.UZO = UZO_ODK1_PDK1;
            }
            else
            {
                datagramAPDMain.UZO = UZO_ODK2_PDK2;
            }
        }
    }
    if (ui->radioButton_5->isChecked()){datagramAPDMain.interaction_algorithm = INTERACTION_ALGORITHM_DUPLEX_2;}
    if (ui->radioButton_6->isChecked()){datagramAPDMain.interaction_algorithm = INTERACTION_ALGORITHM_5C55_ARAGVA;}
    if (ui->radioButton_62->isChecked()){datagramAPDMain.interaction_algorithm = INTERACTION_ALGORITHM_V42;}
    // plume
    if (ui->comboBox_8->currentText() == QString("ВКЛ.")){datagramAPDMain.plume = PLUME_ON;}
    else {datagramAPDMain.plume = PLUME_OFF;}
    // PDK







    ////////////////////////////////////////////////////////////////////
    QByteArray byteArray(reinterpret_cast<char*>(&datagramAPDMain), 18);
    qDebug() << "Отправка датаграммы  " << byteArray.toHex(' ');
    udp->udpSocket->writeDatagram(byteArray, QHostAddress("192.168.5.2"), 12345);

    emit changeTab(0);



//    DatagramAPD datagramAPD;
//    std::memset(&datagramAPD, 0, sizeof(datagramAPD));
//    datagramAPD.start_byte = START_BYTE;
//    datagramAPD.kod_byte = 0x02;
//    datagramAPD.channel = 0b00;
//    datagramAPD.plume = 0b0;
//    datagramAPD.interaction_algorithm = 0x7;
//    datagramAPD.end_byte = 0x05;
//    QByteArray byteArray(reinterpret_cast<char*>(&datagramAPD), 18);
//    qDebug() << "Отправка датаграммы  " << byteArray.toHex(' ');
//    //udp->printDatagramAPD(datagramAPD);
////    char tmp[] = {0x21,0x02,0x1c,0x00,0x00,0x62,0x00,0x04,0x00,0x018,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05};
//    udp->udpSocket->writeDatagram(byteArray, QHostAddress("192.168.5.2"), 12345);
}


void MainWindow::on_radioButton_clicked()
{
//    datagramAPDMain.kod_byte = 0x02;
//    datagramAPDMain.channel = CHANNEL_C1_TCH_LVC;
//    QByteArray byteArray(reinterpret_cast<char*>(&datagramAPDMain), 18);
//    qDebug() << "Отправка датаграммы  " << byteArray.toHex(' ');
//    udp->udpSocket->writeDatagram(byteArray, QHostAddress("192.168.5.2"), 12345);
}

void MainWindow::on_radioButton_2_clicked()
{
//    datagramAPDMain.kod_byte = 0x02;
//    datagramAPDMain.channel = CHANNEL_C1_FL_LVC;
//    QByteArray byteArray(reinterpret_cast<char*>(&datagramAPDMain), 18);
//    qDebug() << "Отправка датаграммы  " << byteArray.toHex(' ');
//    udp->udpSocket->writeDatagram(byteArray, QHostAddress("192.168.5.2"), 12345);
}

