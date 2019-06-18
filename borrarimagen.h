#ifndef BORRARIMAGEN_H
#define BORRARIMAGEN_H

#include <QDialog>
#include "galerias.h"

namespace Ui {
class borrarImagen;
}

class borrarImagen : public QDialog
{
    Q_OBJECT

public:
    explicit borrarImagen(QWidget *parent = nullptr);
    ~borrarImagen();
    //!
    //! \brief crearArray crea un array a partir de un QString ingresado en un line edit para poder identificarlas
    //! \param oracion QString que se le ingresa
    //! \return array de las palabras sin espacios
    //!
    QString* crearArray(QString oracion);
    //!
    //! \brief detectarPlabrasDelete recorre el array revisando si contiene palabras claves que coincidan con la sintaxis de sql para borrar una imagen
    //! \param arrayOracion array con las palabras que se desean identificar
    //!
    void detectarPlabrasDelete(QString* arrayOracion);
private slots:
    void on_botonBorrar_clicked();

private:
    Ui::borrarImagen *ui;
};

#endif // BORRARIMAGEN_H
