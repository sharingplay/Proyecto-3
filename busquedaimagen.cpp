#include "busquedaimagen.h"
#include "ui_busquedaimagen.h"

busquedaImagen::busquedaImagen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::busquedaImagen)
{
    ui->setupUi(this);
}

busquedaImagen::~busquedaImagen()
{
    delete ui;
}

void busquedaImagen::on_botonBusqueda_clicked()
{
   QString infoImagenBuscar = ui->searchEdit->text();
   infoImagenBuscar.split(" ");
   qDebug()<<infoImagenBuscar;
}
