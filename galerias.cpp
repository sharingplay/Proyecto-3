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

QString* galerias::leerArray(string oracionString)
{
    QString oracion = QString::fromStdString(oracionString);

    QStringList listaSeparada = oracion.split(",");
    int i = 0;
    int tamano = listaSeparada.count();
    QString *arrayQString = new QString[tamano];
    foreach(QString palabra, listaSeparada){
        arrayQString[i] = palabra;
        i++;
    }

    return arrayQString;
}
