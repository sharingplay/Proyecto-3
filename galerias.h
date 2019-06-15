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
    LinkedList *listaGalerias = new LinkedList();
    fotografia* fotoGlobal = new fotografia();
    QString arrayBuscar[4];
    QString arrayBorrar[4];
    QString arrayUpdate[4];

    galeria* galeriaBuscar = new galeria();
    galeria* galeriaEliminar = new galeria();
    QString metadataBuscar = "";
    QString metadataEliminar = "";
    QString metadataActualizar = "";
    void imprimirInfoGalerias();
};

#endif // GALERIAS_H
