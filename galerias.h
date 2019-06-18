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
    QString arrayBuscar[5]; //datos de la imagen que se desea buscar
    QString arrayBorrar[5]; //datos de la imagen que se desea borrar
    QString arrayUpdate[5]; //datos de la imagen que se desea actualizar
    QString arrayPrueba[5][6];


    void imprimirInfoGalerias();
    QString* leerArray(string oracion);

};

#endif // GALERIAS_H
