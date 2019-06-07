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
    void imprimirInfoGalerias();
};

#endif // GALERIAS_H
