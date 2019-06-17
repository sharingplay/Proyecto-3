#ifndef SELECCIONFOTOS_H
#define SELECCIONFOTOS_H

#include <QDialog>
#include "galerias.h"

namespace Ui {
class seleccionFotos;
}

class seleccionFotos : public QDialog
{
    Q_OBJECT

public:
    explicit seleccionFotos(QWidget *parent = nullptr);
    ~seleccionFotos();

private slots:
    void on_verButton_clicked();

private:
    Ui::seleccionFotos *ui;
    enum Columna{

        NOMBRE,ANO,AUTOR,TAMANO,DESCRIPCION,BOTON
    };
};

#endif // SELECCIONFOTOS_H
