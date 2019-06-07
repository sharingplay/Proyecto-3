#include "ingresometadata.h"
#include "ui_ingresometadata.h"


ingresoMetadata::ingresoMetadata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ingresoMetadata)
{
    ui->setupUi(this);
}

ingresoMetadata::~ingresoMetadata()
{
    delete ui;
}

void ingresoMetadata::on_guardarButton_clicked()
{

   QString nombre = ui->nameEdit->text();
   QString year = ui->yearEdit->text();
   QString descripcion = ui->descripEdit->text();
   QString author = ui->authorEdit->text();
   galerias::getInstance().fotoGlobal->setAno(year);
   galerias::getInstance().fotoGlobal->setNombre(nombre);
   galerias::getInstance().fotoGlobal->setAutor(author);
   galerias::getInstance().fotoGlobal->setDescripcion(descripcion);

   close();
   createGalery ventanaGaleria;
   ventanaGaleria.setModal(true);
   ventanaGaleria.exec();


}
