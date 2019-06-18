#include "galeria.h"



int galeria::getCantidadFotos() const
{
    return cantidadFotos;
}

void galeria::agregarImagen(fotografia* foto){
    this->listaFotos->Add(foto);
    this->cantidadFotos++;
}

void galeria::eliminarImagen(Node *foto)
{
    for(Node* eliminar = this->listaFotos->getFirst();eliminar != nullptr; eliminar = eliminar->getNext()){
        if(eliminar == foto){
            this->listaFotos->remove(eliminar);
        }
        else{
            qDebug()<<"No se encontro la imagen que se desea eliminar";
        }
    }
}

QString galeria::getNombre() const
{
    return nombre;
}

void galeria::setNombre(const QString &value)
{
    nombre = value;
}

galeria::galeria()
{
    
}
