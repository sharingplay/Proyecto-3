#ifndef SOCKS_H
#define SOCKS_H
#include <qimage.h>
#include <string.h>
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
};

#endif // SOCKS_H
