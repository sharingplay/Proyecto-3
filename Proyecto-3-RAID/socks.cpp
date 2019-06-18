#include "socks.h"
#include "serializador.h"
#include "raid.h"
using namespace std;

socks::socks()
{


}
string socks::escuchaEnviaImagen(int puerto,QString path)
{
    int server_fd, new_socket, valread;
    QImage mensaje;
    mensaje.load(path);
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
    close(server_fd);

    send_image(server_fd, mensaje);

    close(server_fd);
    return message;
}


int socks::send_image(int socket, QImage imagen){

    FILE *picture;
    int size, read_size, stat, packet_index;
    char send_buffer[10240], read_buffer[256];
    packet_index = 1;
    qDebug()<<imagen.save("envio","PNG");
    qDebug()<<imagen.pixel(202,213)<<"RGB";
    picture = fopen("envio", "r");
    printf("Getting Picture Size\n");

    if(picture == NULL) {
        printf("Error Opening Image File"); }

    fseek(picture, 0, SEEK_END);
    size = ftell(picture);
    fseek(picture, 0, SEEK_SET);
    printf("Total Picture size: %i\n",size);

    //Send Picture Size
    printf("Sending Picture Size\n");
    write(socket, (void *)&size, sizeof(int));

    //Send Picture as Byte Array
    printf("Sending Picture as Byte Array\n");

    do { //Read while we get errors that are due to signals.
        stat=read(socket, &read_buffer , 255);
        printf("Bytes read: %i\n",stat);
    } while (stat < 0);

    printf("Received data in socket\n");
    printf("Socket data: %c\n", read_buffer);

    while(!feof(picture)) {
        //while(packet_index = 1){
        //Read from the file into our send buffer
        read_size = fread(send_buffer, 1, sizeof(send_buffer)-1, picture);

        //Send data through our socket
        do{
            stat = write(socket, send_buffer, read_size);
        }while (stat < 0);

        printf("Packet Number: %i\n",packet_index);
        printf("Packet Size Sent: %i\n",read_size);
        printf(" \n");
        printf(" \n");


        packet_index++;

        //Zero out our send buffer
        bzero(send_buffer, sizeof(send_buffer));
    }
}
string socks::recibirImagen(int puerto,string nombre)
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
    close(server_fd);

    receive_image(server_fd, nombre);

    close(server_fd);
    return message;
}
int socks::receive_image(int socket, string nombre)
{ // Start function

    int buffersize = 0, recv_size = 0,size = 0, read_size, write_size, packet_index =1,stat;

    char imagearray[10241],verify = '1';
    FILE *image;

    //Find the size of the image
    do{
        stat = read(socket, &size, sizeof(int));
    }while(stat<0);

    printf("Packet received.\n");
    printf("Packet size: %i\n",stat);
    printf("Image size: %i\n",size);
    printf(" \n");

    char buffer[] = "Got it";

    //Send our verification signal
    do{
        stat = write(socket, &buffer, sizeof(int));
    }while(stat<0);

    printf("Reply sent\n");
    printf(" \n");
    string archivo = "/home/wajo/Documentos/TEC/Datos II/Proyecto 3/Proyecto-3/Proyecto-3-RAID/";
    archivo.append(nombre.c_str());
    archivo.append(".png");
    image = fopen(archivo.c_str(), "w");

    if( image == NULL) {
        printf("Error has occurred. Image file could not be opened\n");
        return -1; }

    //Loop while we himagen->save("envio");ave not received the entire file yet


    int need_exit = 0;
    struct timeval timeout = {10,0};

    fd_set fds;
    int buffer_fd, buffer_out;

    while(recv_size < size) {
        //while(packet_index < 2){

        FD_ZERO(&fds);
        FD_SET(socket,&fds);

        buffer_fd = select(FD_SETSIZE,&fds,NULL,NULL,&timeout);

        if (buffer_fd < 0)
            printf("error: bad file descriptor set.\n");

        if (buffer_fd == 0)
            printf("error: buffer read timeout expired.\n");

        if (buffer_fd > 0)
        {
            do{
                read_size = read(socket,imagearray, 10241);
            }while(read_size <0);

            printf("Packet number received: %i\n",packet_index);
            printf("Packet size: %i\n",read_size);


            //Write the currently read data into our image file
            write_size = fwrite(imagearray,1,read_size, image);
            printf("Written image size: %i\n",write_size);

            if(read_size !=write_size) {
                printf("error in read write\n");    }


            //Increment the total number of bytes read
            recv_size += read_size;
            packet_index++;
            printf("Total received image size: %i\n",recv_size);
            printf(" \n");
            printf(" \n");
        }

    }

    fclose(image);
    RAID::getInstance().write(archivo.c_str(), nombre.c_str());
    printf("Image successfully Received!\n");
    close(socket);
    return 1;
}
string socks::escuchaEnvia(int puerto,string mensaje)
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char hello[mensaje.length()+1];
    strcpy(hello,mensaje.c_str());
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
    int id;
    string nombre;
    serializador::getInstance().deserializarInfo(message,&id,&nombre);
    if (id == 1){
        QString path ="/home/wajo/Documentos/TEC/Datos II/Proyecto 3/Proyecto-3/Proyecto-3-RAID/";
        path.append(path.append(nombre.c_str()));
        path.append(".png");
        send(new_socket , hello , strlen(hello) , 0 );
        return escuchaEnviaImagen(8080,path);
    }
    else if(id ==2){
        send(new_socket , hello , strlen(hello) , 0 );
        return recibirImagen(8080,nombre);
    }
    close(server_fd);
    return message;
}
