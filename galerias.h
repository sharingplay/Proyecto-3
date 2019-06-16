#ifndef GALERIAS_H
#define GALERIAS_H
#include "linkedlist.h"
#include "galeria.h"

class galerias
{
public:
    static galerias& getInstance(){
                  static galerias instance;
                  return instance;
   }
    galerias();
    LinkedList *listaGalerias = new LinkedList(); //lista de todas las galerias
    fotografia* fotoGlobal = new fotografia(); //fotografia que se maneja en la main window
    QString arrayBuscar[4]; //datos de la imagen que se desea buscar
    QString arrayBorrar[4]; //datos de la imagen que se desea borrar
    QString arrayUpdate[4]; //datos de la imagen que se desea actualizar

    void imprimirInfoGalerias();
};

#endif // GALERIAS_H
