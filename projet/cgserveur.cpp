#include "cgserveur.h"

CGSERVEUR::CGSERVEUR()
{

}

void CGSERVEUR::client_connexion( ) {
QTcpSocket *clientConnection = serveur->nextPendingConnection ( );	//  socket de service
connect (clientConnection, SIGNAL (readyRead( )), this, SLOT(client_lecture()));	// connexion du signal "readyRead( )"  indiquant la réception de données en provenance du client  au slot  " client_lecture( )".
Clients.append(clientConnection);

}

QString CGSERVEUR::client_lecture()  {
    QString texte;
    foreach(QTcpSocket *client, Clients)  {

        if (client->bytesAvailable()){
            QByteArray s = client->readAll();  	// boucle de lecture (sur le socket de service) des données reçues
            //ui->textEdit->append(s);
            texte=s;
        }
    }
    return texte;
}

void CGSERVEUR::creation_serveur(){
    serveur=new QTcpServer;
    int a=5000;
    serveur->listen(QHostAddress::Any,a);
    connect (serveur, SIGNAL(newConnection()),this,SLOT(client_connexion()));
}
