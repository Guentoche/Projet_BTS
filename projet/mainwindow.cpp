#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->label_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->textBrowser->setVisible(false);
    ui->textBrowser_2->setVisible(false);
    ui->textBrowser_3->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->pushButton_4->setVisible(false);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton_2->isVisible()){
        ui->label_4->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_5->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->textBrowser->setVisible(false);
        ui->textBrowser_2->setVisible(false);
        ui->textBrowser_3->setVisible(false);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
    }
    else{
        ui->pushButton_3->setVisible(true);
        ui->pushButton_5->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->textBrowser->setVisible(true);
        ui->textBrowser_2->setVisible(true);
        ui->textBrowser_3->setVisible(true);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_3->setVisible(true);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString fnatic=gps.latitude();
    QString vitality=gps.longitude();
    QString misfits=gps.heure();
    ui->textBrowser->setText(fnatic);
    ui->textBrowser_3->setText(vitality);
    ui->textBrowser_2->setText(misfits);

}

void MainWindow::on_pushButton_4_clicked()
{
    //serv->creation_serveur();

    serveur=new QTcpServer;
    int a=5000;
    serveur->listen(QHostAddress::Any,a);
    connect (serveur, SIGNAL(newConnection()),this,SLOT(client_connexion()));


}
QString MainWindow::client_lecture()  {

    /*QString valeur = serv->lecture();
    ui->textEdit->setText(valeur);*/
QString texte;
    foreach(QTcpSocket *client, Clients){
        if (client->bytesAvailable()){
            y=client->readAll();
            ui->textEdit->append(y);
            texte=y;
        }
    }
    return texte;
}

void MainWindow::client_connexion(){
    //serv->client_connexion();

    QTcpSocket *clientConnection =serveur->nextPendingConnection();
    connect (clientConnection,SIGNAL(readyRead()),this,SLOT(client_lecture()));
    Clients.append(clientConnection);


}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_4->isVisible()){
        ui->pushButton_4->setVisible(false);
        ui->label_4->setVisible(false);
        ui->textEdit->setVisible(false);
    }
    else{
        ui->label_4->setVisible(true);
        ui->pushButton_4->setVisible(true);
        ui->textEdit->setVisible(true);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString a ="";//client_lecture();
    QString b ="";
    piface.carte(a,b);
    bool c =piface.carte(a,b);

    if (c){piface.cable();}
    }
