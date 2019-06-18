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
    //!
    //! \brief listaFotos lista de fotos que estan en esta galeria
    //!
    LinkedList* listaFotos = new LinkedList();
    int getCantidadFotos() const;
    //!
    //! \brief agregarImagen agrega una imagen a la galeria
    //! \param foto fotografia que se desea agregar
    //!
    void agregarImagen(fotografia* foto);
    //!
    //! \brief eliminarImagen elimina una imagen de la galeria
    //! \param foto fotografia que se desea eliminar de la galeria
    //!
    void eliminarImagen(Node* foto);
    QString getNombre() const;
    void setNombre(const QString &value);
};

#endif // GALERIA_H
