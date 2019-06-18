#include "fotografia.h"
#include "iostream"

using namespace std;

QString fotografia::getNombre() const
{
    return Nombre;
}

void fotografia::setNombre(const QString &value)
{
    Nombre = value;
}

QString fotografia::getAutor() const
{
    return autor;
}

void fotografia::setAutor(const QString &value)
{
    autor = value;
}

QString fotografia::getDescripcion() const
{
    return descripcion;
}

void fotografia::setDescripcion(const QString &value)
{
    descripcion = value;
}

QString fotografia::getAno() const
{
    return ano;
}

void fotografia::setAno(QString &value)
{
    ano = value;
}

QImage fotografia::getImagen() const
{
    return imagen;
}

void fotografia::setImagen(QImage value)
{
    imagen = value;
}

void fotografia::imprimirDatosImagen()
{
    qDebug()<<"Tamano "<<this->tamano<<" Bytes";
    qDebug()<<"Nombre "<<this->Nombre;
    qDebug()<<"Autor "<<this->autor;
    qDebug()<<"Ano "<<this->ano;
    qDebug()<<"Descripcion "<<this->descripcion;
    qDebug()<<"Imagen "<<this->imagen;
}

QString fotografia::getTamano() const
{
    return tamano;
}

void fotografia::setTamano(QString value)
{
    tamano = value;
}

QString fotografia::getNombreGaleria() const
{
    return nombreGaleria;
}

void fotografia::setNombreGaleria(const QString &value)
{
    nombreGaleria = value;
}

fotografia::fotografia()
{

}
