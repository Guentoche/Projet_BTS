#ifndef CGPS_H
#define CGPS_H
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "errno.h"
#include "QString"

class CGPS
{
private:
    char buffer [1000];
    int nb;
    int fd;
    QString text;
    QString text1;
public:
    CGPS();
    QString trame();
    QString latitude();
    QString longitude();
    QString heure();
};

#endif // CGPS_H
