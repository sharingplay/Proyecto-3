#ifndef GALERIA_H
#define GALERIA_H
#include "iostream"
#include "linkedlist.h"
#include "fotografia.h"
#include "QString"
using namespace std;


class galeria
{
private:
    QString nombre;
    int cantidadFotos = 0;
public:
    galeria();
    LinkedList* listaFotos = new LinkedList();
    int getCantidadFotos() const;
    void agregarImagen(fotografia* foto);
    void eliminarImagen(Node* foto);
    QString getNombre() const;
    void setNombre(const QString &value);
};

#endif // GALERIA_H
