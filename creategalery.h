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
    void on_botonCrear_clicked();

    void on_botonGuardar_clicked();

private:
    Ui::createGalery *ui;
};

#endif // CREATEGALERY_H
