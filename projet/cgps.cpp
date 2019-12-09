#include "cgps.h"
#include "termios.h"

CGPS::CGPS()
{
    text="Erreur Connection";
    text1="Port Connecte";
    if((fd=open("/dev/ttyUSB0",O_RDONLY|O_NOCTTY))<0){
        //ui->label->setText(text);
    }
    else{
        //ui->label->setText(text1);
        struct termios tio;
        tcgetattr(fd,&tio);
        tio.c_cflag=B4800|CS8|CLOCAL|CREAD;
        tio.c_oflag=0;
        tio.c_lflag=0;
        tio.c_iflag |=IGNPAR;
        tio.c_lflag&=~(ICANON);
        tio.c_cc[VTIME]=0;
        tio.c_cc[VMIN]=1;
        tcflush(fd,TCIOFLUSH);
        tcsetattr(fd,TCSANOW,&tio);

    }
}
QString CGPS::trame(){
    nb=500;
    int q=read(fd,buffer,nb);
    QString Q=QString::number(q);
   // ui->textBrowser->setText(buffer);

    QString sd;
    for(int i=0;i<500;i++){sd+=buffer[i];}
    std::string text=sd.toUtf8().constData();
    QString pk;
    int pos=text.find("$GPGLL");
    for(int j=pos;j<pos+50;j++){pk+=buffer[j];}
    //ui->textBrowser->setText(pk); // affiche la trame GPGLL

    std::string ok=pk.toUtf8().constData();
    int pos2=ok.find(",");
    QString sk;
    for(int k=pos2;k<pos2+11;k++){sk+=ok[k+1];}
    //ui->textBrowser->setText(sk); // Affichage de la latitude

    int pos3=ok.find("N,");
    QString skt;
    for(int l=pos3;l<pos3+12;l++){skt+=ok[l+2];}
    //ui->textBrowser->setText(skt); // Affichage de la longitude

    int pos4=ok.find("E");
    QString t1;
    for (int m=pos4;m<pos4+10;m++){t1+=ok[m+2];} // Affichage de l'heure

    QString position = sk + "\n" + skt + "\n" + t1;
    return position;
}

QString CGPS::latitude(){
    nb=500;
    int q=read(fd,buffer,nb);
    QString Q=QString::number(q);
   // ui->textBrowser->setText(buffer);

    QString sd;
    for(int i=0;i<500;i++){sd+=buffer[i];}
    std::string text=sd.toUtf8().constData();
    QString pk;
    int pos=text.find("$GPGLL");
    for(int j=pos;j<pos+50;j++){pk+=buffer[j];}
    //ui->textBrowser->setText(pk); // affiche la trame GPGLL

    std::string ok=pk.toUtf8().constData();
    int pos2=ok.find(",");
    QString sk;
    for(int k=pos2;k<pos2+11;k++){sk+=ok[k+1];}
    //ui->textBrowser->setText(sk); // Affichage de la latitude
    return sk;
}

QString CGPS::longitude(){
    nb=500;
    int q=read(fd,buffer,nb);
    QString Q=QString::number(q);
   // ui->textBrowser->setText(buffer);

    QString sd;
    for(int i=0;i<500;i++){sd+=buffer[i];}
    std::string text=sd.toUtf8().constData();
    QString pk;
    int pos=text.find("$GPGLL");
    for(int j=pos;j<pos+50;j++){pk+=buffer[j];}
    //ui->textBrowser->setText(pk); // affiche la trame GPGLL
    std::string ok=pk.toUtf8().constData();
    int pos3=ok.find("N,");
    QString skt;
    for(int l=pos3;l<pos3+12;l++){skt+=ok[l+2];}
    //ui->textBrowser->setText(skt); // Affichage de la longitude
    return skt;
}

QString CGPS::heure(){
    nb=500;
    int q=read(fd,buffer,nb);
    QString Q=QString::number(q);
   // ui->textBrowser->setText(buffer);

    QString sd;
    for(int i=0;i<500;i++){sd+=buffer[i];}
    std::string text=sd.toUtf8().constData();
    QString pk;
    int pos=text.find("$GPGLL");
    for(int j=pos;j<pos+50;j++){pk+=buffer[j];}
    //ui->textBrowser->setText(pk); // affiche la trame GPGLL
    std::string ok=pk.toUtf8().constData();
    int pos4=ok.find("E");
    QString t1;
    for (int m=pos4;m<pos4+10;m++){t1+=ok[m+2];} // Affichage de l'heure
    return t1;
}
