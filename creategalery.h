#ifndef CREATEGALERY_H
#define CREATEGALERY_H

#include <QDialog>
#include "galerias.h"
#include "fotografia.h"


namespace Ui {
class createGalery;
}

class createGalery : public QDialog
{
    Q_OBJECT

public:
    explicit createGalery(QWidget *parent = nullptr);
    ~createGalery();

private slots:
    //!
    //! \brief on_botonCrear_clicked verifica si la galeria que se desea crear no existe, de ser asi la crea y se la asigna a la imagen ingresada
    //!
    void on_botonCrear_clicked();
    //!
    //! \brief on_botonGuardar_clicked asigna la imagen ingresada a una galeria existente
    //!
    void on_botonGuardar_clicked();

private:
    Ui::createGalery *ui;
};

#endif // CREATEGALERY_H
