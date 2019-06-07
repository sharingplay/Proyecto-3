#ifndef INGRESOMETADATA_H
#define INGRESOMETADATA_H

#include <QDialog>
#include "QDebug"
#include "fotografia.h"
#include "creategalery.h"

namespace Ui {
class ingresoMetadata;
}

class ingresoMetadata : public QDialog
{

    Q_OBJECT

public:
    explicit ingresoMetadata(QWidget *parent = nullptr);
    ~ingresoMetadata();
    static fotografia* fotoNueva;

private slots:

    void on_guardarButton_clicked();

private:
    Ui::ingresoMetadata *ui;

};

#endif // INGRESOMETADATA_H
