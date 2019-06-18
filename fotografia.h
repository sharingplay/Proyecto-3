#ifndef FOTOGRAFIA_H
#define FOTOGRAFIA_H
#include "iostream"
#include <QFileDialog>
#include "QString"
#include "QDebug"
using namespace std;

class fotografia
{
private:
    QString Nombre,autor,descripcion,ano;
    int tamano;
    QImage imagen;

public:
    fotografia();
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getAutor() const;
    void setAutor(const QString &value);
    QString getDescripcion() const;
    void setDescripcion(const QString &value);
    QString getAno() const;
    void setAno(QString &value);
    QImage getImagen() const;
    void setImagen(QImage value);
    //!
    //! \brief imprimirDatosImagen imprime en consola los datos de la imagen
    //!
    void imprimirDatosImagen();
    int getTamano() const;
    void setTamano(int value);
};

#endif // FOTOGRAFIA_H
