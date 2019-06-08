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

void busquedaImagen::construirArray(QString listaCrear)
{
    //Contruye el array para buscar palabras
    QStringList infoSeparada = listaCrear.split(" ");
    QString arrayPalabras[infoSeparada.count()];
    int i = 0;

    foreach(QString palabra, infoSeparada){
        arrayPalabras[i] = palabra;
        qDebug()<<i;
        qDebug()<<arrayPalabras[i];
        i++;
    }
    //*****Select*****
    if(arrayPalabras[0] == "select"){

        if(arrayPalabras[1] == "nombre"){
            galerias::getInstance().metadataBuscar = "nombre";
        }
        else if(arrayPalabras[1]=="autor"){
            galerias::getInstance().metadataBuscar = "autor";
        }
        else if(arrayPalabras[1]=="descripcion"){
            galerias::getInstance().metadataBuscar = "descripcion";
        }
        else if(arrayPalabras[1]=="ano"){
            galerias::getInstance().metadataBuscar = "ano";
        }
        else {
            qDebug()<<"El tipo de metadata que desea ver no existe";
        }

        //Galeria en la que se desea buscar
        if(arrayPalabras[2]== "from"){
            //Busca la galeria que coincida con el nombre de la ingresada
            QString nombreGaleriaBuscar = arrayPalabras[3];
            for (Node* nodoGaleria = galerias::getInstance().listaGalerias->getFirst();nodoGaleria != nullptr;nodoGaleria = nodoGaleria->getNext()) {
                galeria* galeriaBuscar = (galeria*)nodoGaleria->getData();
                if (galeriaBuscar->getNombre() == nombreGaleriaBuscar){
                    galerias::getInstance().galeriaBuscar = galeriaBuscar;
                }
            }
        }

        if(arrayPalabras[4] == "where"){
            if(arrayPalabras[5]=="nombre"){
                galerias::getInstance().fotoBuscar->setNombre(arrayPalabras[7]);
            }
            else if(arrayPalabras[5]=="ano"){
                galerias::getInstance().fotoBuscar->setAno(arrayPalabras[7]);
            }
            else if(arrayPalabras[5]=="descripcion"){
                galerias::getInstance().fotoBuscar->setDescripcion(arrayPalabras[7]);
            }
            else if(arrayPalabras[5]=="autor"){
                galerias::getInstance().fotoBuscar->setAutor(arrayPalabras[7]);
            }
            else {
                qDebug()<<"No se especifico que metadata se quiere buscar";
            }
        }

        else {
            qDebug()<<"No se especifico con el comando where que metadata se desea buscar";
        }
    }

    //*****Delete*****
    else if (arrayPalabras[0] == "delete") {

        if(arrayPalabras[1] == "nombre"){
            galerias::getInstance().metadataEliminar = "nombre";
        }
        else if(arrayPalabras[1]=="autor"){
            galerias::getInstance().metadataEliminar = "autor";
        }
        else if(arrayPalabras[1]=="descripcion"){
            galerias::getInstance().metadataEliminar = "descripcion";
        }
        else if(arrayPalabras[1]=="ano"){
            galerias::getInstance().metadataEliminar = "ano";
        }
        else {
            qDebug()<<"El tipo de metadata que desea ver no existe";
        }

        //Galeria de la que se desea borrar metadata especifica
        if(arrayPalabras[2]== "from"){
            //Busca la galeria que coincida con el nombre de la ingresada
            QString nombreGaleriaEliminar = arrayPalabras[3];
            for (Node* nodoGaleria = galerias::getInstance().listaGalerias->getFirst();nodoGaleria != nullptr;nodoGaleria = nodoGaleria->getNext()) {
                galeria* galeriaBorrar = (galeria*)nodoGaleria->getData();
                if (galeriaBorrar->getNombre() == nombreGaleriaEliminar){
                    galerias::getInstance().galeriaEliminar = galeriaBorrar;
                }
            }
        }

        if(arrayPalabras[4] == "where"){
            if(arrayPalabras[5]=="nombre"){
                galerias::getInstance().fotoEliminar->setNombre(arrayPalabras[7]);
            }
            else if(arrayPalabras[5]=="ano"){
                galerias::getInstance().fotoEliminar->setAno(arrayPalabras[7]);
            }
            else if(arrayPalabras[5]=="descripcion"){
                galerias::getInstance().fotoEliminar->setDescripcion(arrayPalabras[7]);
            }
            else if(arrayPalabras[5]=="autor"){
                galerias::getInstance().fotoEliminar->setAutor(arrayPalabras[7]);
            }
            else {
                qDebug()<<"No se especifico que metadata se quiere eliminar";
            }
        }

        else {
            qDebug()<<"No se especifico con el comando where que metadata se desea borrar";
        }
    }
    //*****Update*****
    else if (arrayPalabras[0] == "update") {

    }

    else {
        qDebug()<<"La primera palabra debe ser un comando como select,update o delete ";
    }
}

QString* busquedaImagen::crearArrayPalabras(QString oracion)
{
    QStringList infoSeparada = oracion.split(" ");
    int i = 0;
    QString* resultado = (QString*)malloc(infoSeparada.count() * sizeof(int));

    foreach(QString palabra, infoSeparada){
        resultado[i] = palabra;
        qDebug()<<i;
        qDebug()<<resultado[i];
        i++;
    }
    return resultado;
}

void busquedaImagen::on_botonBusqueda_clicked()
{
    QString infoImagenBuscar = ui->searchEdit->text();
    crearArrayPalabras(infoImagenBuscar);
}

