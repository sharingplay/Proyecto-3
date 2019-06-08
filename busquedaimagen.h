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
    void detectarPalabras();
    void construirArray(QString listaCrear);
    QString* crearArrayPalabras(QString oracion);


private slots:
    void on_botonBusqueda_clicked();

private:
    Ui::busquedaImagen *ui;
};

#endif // BUSQUEDAIMAGEN_H
