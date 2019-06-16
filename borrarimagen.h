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
    QString* crearArray(QString oracion);
    void detectarPlabrasDelete(QString* arrayOracion);
private slots:
    void on_botonBorrar_clicked();

private:
    Ui::borrarImagen *ui;
};

#endif // BORRARIMAGEN_H
