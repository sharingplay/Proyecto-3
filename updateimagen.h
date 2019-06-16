#ifndef UPDATEIMAGEN_H
#define UPDATEIMAGEN_H

#include <QDialog>
#include "QDebug"
#include "galerias.h"

namespace Ui {
class updateImagen;
}

class updateImagen : public QDialog
{
    Q_OBJECT

public:
    explicit updateImagen(QWidget *parent = nullptr);
    ~updateImagen();
    //!
    //! \brief crearArray crea un array a partir de un QString ingresado en un line edit para poder identificarlas
    //! \param oracion QString que se le ingresa
    //! \return array de las palabras sin espacios
    //!
    QString* crearArray(QString oracion);
    //!
    //! \brief detectarPlabrasDelete recorre el array revisando si contiene palabras claves que coincidan con la sintaxis de sql para actualizar la metadata de una imagen
    //! \param arrayOracion array con las palabras que se desean identificar
    //!
    void detectarPalabrasUpdate(QString* arrayOracion);


private slots:
    void on_updateButton_clicked();

private:
    Ui::updateImagen *ui;
};

#endif // UPDATEIMAGEN_H
