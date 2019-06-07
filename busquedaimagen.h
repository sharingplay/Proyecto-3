#ifndef BUSQUEDAIMAGEN_H
#define BUSQUEDAIMAGEN_H

#include <QDialog>
#include "QDebug"

namespace Ui {
class busquedaImagen;
}

class busquedaImagen : public QDialog
{
    Q_OBJECT

public:
    explicit busquedaImagen(QWidget *parent = nullptr);
    ~busquedaImagen();

private slots:
    void on_botonBusqueda_clicked();

private:
    Ui::busquedaImagen *ui;
};

#endif // BUSQUEDAIMAGEN_H
