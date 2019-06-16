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
    QString* crearArray(QString oracion);
    void detectarPalabrasUpdate(QString* arrayOracion);


private slots:
    void on_updateButton_clicked();

private:
    Ui::updateImagen *ui;
};

#endif // UPDATEIMAGEN_H
