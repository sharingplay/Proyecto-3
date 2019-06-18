#ifndef SOCKS_H
#define SOCKS_H
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<iostream>
#include <netinet/in.h>
#include<fstream>
#include<errno.h>
#include <QDebug>
#include <qimage.h>
using namespace std;

class socks
{
public:
    static socks & getInstance(){
        static socks instance;
        return instance;
    }
    socks();
    void enviar_imagen(QImage imagen);
    int send_image(int socket, QImage image);
    int receive_image(int socket);
    void enviar(string mensaje, int puerto, string ip);
    string escuchaEnviaImagen(int puerto, QImage mensaje);
    string escuchaEnvia(int puerto, string mensaje);
};

#endif // SOCKS_H
