#include "socks.h"
#include "socks.h"
#include "xml.h"
#include "serializador.h"
socks::socks()
{

}
string socks::escuchaEnvia(int puerto,string mensaje)
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( puerto );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read( new_socket , buffer, 1024);
    string message = buffer;
    string nombre;
    string autor;
    string creacion;
    string descripcion;
    string tamano;
    string galeria;
    string foto_b64;
    int id;
    string recibe = socks::getInstance().escuchaEnvia(8080,"");
    serializador::getInstance().deserializarMeta(recibe, &nombre, &autor, &creacion, &descripcion, &tamano, &galeria,&foto_b64,&id);
    if (id == 1){
        if(creacion == "nombre"){
          mensaje = XML::getInstance().buscarNombre(descripcion);
        }
        if(creacion == "autor"){
            mensaje =XML::getInstance().buscarAutor(descripcion);
        }
        if(creacion == "ano"){
            mensaje = XML::getInstance().buscarCreacion(descripcion);
        }
        if(creacion == "descripcion"){
            mensaje = XML::getInstance().buscarDescripcion(descripcion);
        }
        if(creacion == "tamano"){
            mensaje = XML::getInstance().buscarTamano(descripcion);
        }
    }
    if (id ==2){
        XML::getInstance().eliminar(nombre);
    }
    if(id==3){
        XML::getInstance().update(autor,nombre,creacion,descripcion);
    }
    if(id ==4){
        XML::getInstance().agregarImagen(galeria,foto_b64,nombre,autor,creacion,tamano,descripcion);
    }
    mensaje = serializador::getInstance().serializarMetadata(mensaje);
    char hello[mensaje.length()+1];
    strcpy(hello,mensaje.c_str());
    send(new_socket , hello , strlen(hello) , 0 );
    close(server_fd);
    return message;
}

