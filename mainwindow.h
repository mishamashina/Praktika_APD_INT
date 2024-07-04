#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "udpsocket.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    UdpSocket *udp;
    DatagramAPD datagramAPDMain;

    void Channel(char data);
    void InteractionAlgorithm(char data);
    void Plume(char data);
    void PDK(char data);
    void UZO(char data);
    void Tangent(char data);
    void Phasing(char data);
    void SpeedAndTypeOfModulationС1TCH(char data);
    void TransmissionLevelC1TCH(char data);
    void ModuleV26(char data);
    void FrequenceV29(char data);
    void Scrambler(char data);
    void AdaptationCorrector(char data);
    void CableCorrectorOnTransmission(char data);
    void CableCorrectorAtReception(char data);
    void SpeedC1Fl(char data);
    void ManageOfTangent(char data);
    void V42N400(char data);
    void BlockLength(char data);
    void NubmersOfRequeries(char data);
    void DephasingCriterion(char data);
    void BlockDepth(char data);
    void Format5C55(char data);
    void InvTransfer(char data);
    void InvReception(char data);
    void ResponseModeV42(char data);
    void PDKPause(char data);
    void AddDataODK2PDK2(char data);
    void V42T400PDKTStart(char data);
    void V42T400PDKTStop(char data);
    void LoanAmountV42(char data);
    void MaxLengthKadrV42(char data);

    ~MainWindow();

private slots:
    void getDatagramAPD(DatagramAPD datagramAPD);

    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

signals:
    void changeTab(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
