#ifndef CGSERVEUR_H
#define CGSERVEUR_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QMainWindow>
class CGSERVEUR : public QObject
{
    Q_OBJECT
public:
    CGSERVEUR();


public slots:
    void client_connexion();
    QString client_lecture();
    void creation_serveur();
private:
    QTcpServer *serveur;
    QList<QTcpSocket *> Clients;

};

#endif // CGSERVEUR_H
