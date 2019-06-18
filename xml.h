#ifndef XML_H
#define XML_H
#include <iostream>
using namespace std;
#include <QtXml>
#include<QtDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>


class XML
{
public:
    static XML & getInstance(){
        static XML instance;
        return instance;
    }
    XML();
    string readXML();//listo
    void writeXML(string datos);//listo
    void newGallery(string galeria);//listo
    /*
     * cambio lo que desea escribir
     * caracteristica lo que desea cambiar autor, tamano
     * nombre el atributo a buscar
     * lugar si es nombre, autor, tamano
     *
     * */
    void update(string cambio, string caracteristica ,string lugar, string atributo);
    string obtenerImagen(string base64);//listo
    string buscarNombre(string nombre);//listo
    string buscarAutor(string autor);//listo
    string buscarCreacion(string creacion);//listo
    string buscarTamano(string tamano);//listo
    string buscarDescripcion(string descripcion);//listo
    void obtenerVarias(string atributo, string dato);
    void eliminar(string base64);//listo
    void agregarImagen(string carpeta, string base64, string nombre, string autor, string creacion, string tamano, string descripcion);//listo

};

#endif // XML_H
