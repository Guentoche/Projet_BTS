#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qextserialport.h"
#include <QWidget>

class QLineEdit;
class QTextEdit;
class QextSerialPort;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QextSerialPort *port;
    QLineEdit *message;
    QTextEdit *received_msg;
    char buff[1024];
    QString msg;
    int x;
    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;
    QTimer *timer6;
    QTimer *timer7;


private slots:
    void initialisation();
    void emettre(const QString &trame);
    void recevoir();    
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void CPIN();
    void CPIN2();
    void CREG();
    void CMGF();
    void CMGS();
    void transmission();
    void envoie();

};

#endif // MAINWINDOW_H
