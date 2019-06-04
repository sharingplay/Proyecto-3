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
    XML();
    string readXML();
    void writeXML(string datos);
    void newGallery(string galeria);
    void update(string cambio, string imagen, string atributo);
    void obtener(string imagen);
    void obtenerVarias(string atributo, string dato);
    void eliminar(string imagen);
};

#endif // XML_H
