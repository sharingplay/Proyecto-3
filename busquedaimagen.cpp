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

QString* busquedaImagen::construirArray(QString listaCrear)
{
    QStringList infoSeparada = listaCrear.split(" ");
    QString arrayPalabras[infoSeparada.count()];
    int i = 0;

    foreach(QString palabra, infoSeparada){
        arrayPalabras[i] = palabra;
//        qDebug()<<i;
//        qDebug()<<arrayPalabras[i];
        i++;
    }
    return  arrayPalabras;
}


void busquedaImagen::on_botonBusqueda_clicked()
{
   QString infoImagenBuscar = ui->searchEdit->text();
   QString* arrayPalabras = construirArray(infoImagenBuscar);
   qDebug()<< &arrayPalabras[1];
   //llamar funcion que crea la lista


}

