#ifndef BUSQUEDAIMAGEN_H
#define BUSQUEDAIMAGEN_H

#include <QDialog>
#include "QDebug"
#include "fotografia.h"
#include "galerias.h"

namespace Ui {
class busquedaImagen;
}

class busquedaImagen : public QDialog
{
    Q_OBJECT

public:
    explicit busquedaImagen(QWidget *parent = nullptr);
    ~busquedaImagen();
    //!
    //! \brief crearArray crea un array a partir de un QString ingresado en un line edit para poder identificarlas
    //! \param oracion QString que se le ingresa
    //! \return array de las palabras sin espacios
    //!
    QString* crearArray(QString oracion);
    //!
    //! \brief detectarPlabrasSelect recorre el array revisando si contiene palabras claves que coincidan con la sintaxis de sql para buscar una imagen
    //! \param arrayOracion array con las palabras que se desean identificar
    //!
    void detectarPlabrasSelect(QString* arrayOracion);

private slots:
    void on_botonBusqueda_clicked();

private:
    Ui::busquedaImagen *ui;
};

#endif // BUSQUEDAIMAGEN_H
