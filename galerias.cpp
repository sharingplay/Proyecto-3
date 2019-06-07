#include "galerias.h"
#include "fotografia.h"

galerias::galerias()
{

}

void galerias::imprimirInfoGalerias()
{
    for (Node* nodoGaleria = this->listaGalerias->getFirst();nodoGaleria!=nullptr;nodoGaleria = nodoGaleria->getNext()) {
        galeria* galeriaTemp = (galeria*)nodoGaleria->getData();
        qDebug()<<"\n**************"<<galeriaTemp->getNombre()<<"**************";
        for (Node* NodoImagenes = galeriaTemp->listaFotos->getFirst();NodoImagenes!=nullptr;NodoImagenes = NodoImagenes->getNext()) {
            fotografia* imagenActual = (fotografia*) NodoImagenes->getData();
            imagenActual->imprimirDatosImagen();
            qDebug()<<"\n...........................";
        }

    }
}

