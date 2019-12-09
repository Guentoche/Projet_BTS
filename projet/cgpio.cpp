#include "cgpio.h"
#include "piface.h"

CGPIO::CGPIO()
{
}
bool CGPIO::carte(QString b, QString c){
    pfio_init();
    QString malik= b;
    QString wesley= c;
    if (malik == wesley){
        pfio_digital_write(1,1);
        return true;
    }
    else {
        pfio_digital_write(3,1);
        return false;
    }
}

void CGPIO::cable(){
     pfio_init();
     pfio_digital_write(1,1);
     while(1){
        int num = pfio_read_input();
        if (num==4){
            pfio_digital_write(5,1);
        }
        if (num==2){
            pfio_digital_write(5,0);
        }
        if (num==1){break;}
    }
}
