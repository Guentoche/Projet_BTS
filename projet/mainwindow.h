#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cgps.h"
#include "cgserveur.h"
#include "piface.h"
#include "cgpio.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CGPS gps;
    CGSERVEUR *serv;
    CGPIO piface;


public slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void client_connexion();
    QString client_lecture();
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *serveur;
    QList<QTcpSocket *> Clients;
    QByteArray y;
    QTcpSocket soc;

};
#endif // MAINWINDOW_H
