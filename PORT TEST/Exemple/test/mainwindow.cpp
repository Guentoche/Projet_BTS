#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qextserialport.h"
#include <QTimer>
#include <QLineEdit>
#include <QTextEdit>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(CPIN()));
    timer2=new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(CPIN2()));
    timer3=new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(CREG()));
    timer4=new QTimer(this);
    connect(timer4,SIGNAL(timeout()),this,SLOT(CMGF()));
    timer5=new QTimer(this);
    connect(timer5,SIGNAL(timeout()),this,SLOT(CMGS()));
    timer6=new QTimer(this);
    connect(timer6,SIGNAL(timeout()),this,SLOT(envoie()));
    timer7=new QTimer(this);
    connect(timer6,SIGNAL(timeout()),this,SLOT(transmission()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialisation()
{
    port = new QextSerialPort(QLatin1String("/dev/ttyS0"), QextSerialPort::Polling);

    port = new QextSerialPort(QLatin1String("COM13"), QextSerialPort::Polling);

    port->setBaudRate(BAUD115200);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_2);
    port->setTimeout(1000);

    if (port->open(QIODevice::ReadWrite)) {

           qDebug("Connecté");

       } else {

           qDebug("Erreur");
       }


}

void MainWindow::emettre(const QString &message)
{
    if (port == NULL || !port->isOpen())
        {
            qDebug("erreur message non transmit");
        }

    else {
            port->write(message.toLatin1());

        }
}


void MainWindow::recevoir()
{


            int numBytes;

            numBytes = port->bytesAvailable();
            if(numBytes > 1024)
                numBytes = 1024;

            int i = port->read(buff, numBytes);
            if (i != -1)
                buff[i] = '\0';
            else
                buff[0] = '\0';
            msg = QLatin1String(buff);





}


void MainWindow::on_pushButton_clicked()
{

    initialisation();
    ui->pushButton->setVisible(false);

}
void MainWindow::on_pushButton_2_clicked()
{

    transmission();
    timer7->start(300000);

}

void MainWindow::transmission()
{


    timer->start(2000);



}

void MainWindow::CPIN()
{
    timer->stop();
    emettre("AT+CPIN=7518" "\x0D");
    recevoir();
    timer2->start(11000);
    ui->textEdit->setText("Connexion en cours...");

}

void MainWindow::CPIN2()
{
    timer2->stop();
    emettre("AT+CPIN?" "\x0D");
    recevoir();

    if(msg.contains("OK") || x == 1)
    {
        x=1;
        timer3->start(5000);
        ui->textEdit->setText("Code PIN validé");
        qDebug(msg.toLatin1());

    }
    else {
        ui->textEdit->setText("Erreur Code PIN");
        qDebug(msg.toLatin1());

    }

}

void MainWindow::CREG()
{
    timer3->stop();
    emettre("AT+CREG?" "\x0D");
    recevoir();
    if(msg.contains("READY"))
    {
        timer4->start(5000);
        ui->textEdit->setText("Carte SIM validée");
        qDebug(msg.toLatin1());
    }
    else {
        ui->textEdit->setText("Erreur Carte SIM");
        qDebug(msg.toLatin1());
    }
}

void MainWindow::CMGF()
{
    timer4->stop();
    emettre("AT+CMGF=1" "\x0D");
    recevoir();
    if(msg.contains("0,1"))
    {
        timer5->start(5000);
        ui->textEdit->setText("GSM enregistré");
        qDebug(msg.toLatin1());

    }
    else {
        ui->textEdit->setText("Erreur Enregistrement refusé ");
        qDebug(msg.toLatin1());
    }
}

void MainWindow::CMGS()
{
    timer5->stop();
    emettre("AT+CMGS=+33634235939" "\x0D");
    recevoir();
    if(msg.contains("OK"))
    {
        timer6->start(5000);
        ui->textEdit->setText("Passage en mode texte");
        qDebug(msg.toLatin1());
    }
    else
    {
        ui->textEdit->setText("Erreur texte");
        qDebug(msg.toLatin1());
    }

}

void MainWindow::envoie()
{
    timer6->stop();
    recevoir();
    if(msg.contains(">"))
    {
        emettre("94 94" "\x1A");
        ui->textEdit->setText("Sms envoyé !");
        qDebug(msg.toLatin1());
    }
    else
    {
        ui->textEdit->setText("Erreur GMGS message non envoyé !");
        qDebug(msg.toLatin1());
    }

}



