#include "busquedaimagen.h"
#include "ui_busquedaimagen.h"
#include "iostream"
using namespace std;

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


void busquedaImagen::detectarPlabras(QString* arrayOracion)
{    
    QString* arrayOriginal = arrayOracion;
    QString arrayPalabras[arrayOriginal[0].toInt()] ;


    for (int i = 0;i< (arrayOriginal[0].toInt());i++) {
        arrayPalabras[i] = arrayOriginal[i+1];
    }

    //*****Select*****
    if(arrayPalabras[0] == "select"){

        /*
         * Modificar que toda la informacion que ingrese el usuario la almacene en los arrays globales
         * Y hacer un boton para cada funcion de buscar, eliminar y actualizar         *
         * */
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
        else if(arrayPalabras[1]=="*") {
             galerias::getInstance().metadataBuscar = "todo";
        }
        else {
            qDebug()<<"El tipo de metadata "<< arrayPalabras[1]<< " no existe";
        }

        //Galeria en la que se desea buscar
        if(arrayPalabras[2] == "from"){
            //Busca la galeria que coincida con el nombre de la ingresada
            QString nombreGaleriaBuscar = arrayPalabras[3];
            for (Node* nodoGaleria = galerias::getInstance().listaGalerias->getFirst();nodoGaleria != nullptr;nodoGaleria = nodoGaleria->getNext()) {
                galeria* galeriaBuscar = (galeria*)nodoGaleria->getData();
                if (galeriaBuscar->getNombre() == nombreGaleriaBuscar){
                    galerias::getInstance().galeriaBuscar = galeriaBuscar;
                }
                else if(nodoGaleria->getNext() == nullptr){
                    qDebug()<<"La galeria con el nombre "<<nombreGaleriaBuscar<<" no existe";
                }
            }
        }

        else{
            qDebug()<<"No se ingreso la palabra from";
        }


        if(arrayPalabras[4] == "where"){
            if(arrayPalabras[5]=="nombre"){
                galerias::getInstance().fotoBuscar->setNombre(arrayPalabras[7]);
            }
            else if(arrayPalabras[5]=="ano"){
                galerias::getInstance().fotoBuscar->setAno(arrayPalabras[7]);
            }
            else if(arrayPalabras[5]=="descripcion"){
                QString descripcion;
                for (int i = 7; i<= arrayOriginal[0].toInt()-1;i++) {
                    descripcion += arrayPalabras[i] + " ";
                }
                qDebug()<<descripcion;
                galerias::getInstance().fotoBuscar->setDescripcion(descripcion);
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
        qDebug()<<"Se quiere buscar --> "<<galerias::getInstance().metadataBuscar <<" de la imagen y en la galeria " <<galerias::getInstance().galeriaBuscar->getNombre();
        galerias::getInstance().fotoBuscar->imprimirDatosImagen();
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
            //Busca la galerlistaCrearia que coincida con el nombre de la ingresada
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

        if (arrayPalabras[2] == "set"){

            if(arrayPalabras[1] == "nombre"){
                galerias::getInstance().metadataActualizar = "nombre";
                galerias::getInstance().fotoActualizar->setNombre(arrayPalabras[3]);
            }
            else if (arrayPalabras[1] == "ano"){
                galerias::getInstance().metadataActualizar = "ano";
                galerias::getInstance().fotoActualizar->setAno(arrayPalabras[3]);
            }
            else if (arrayPalabras[1] == "autor"){
                galerias::getInstance().metadataActualizar = "autor";
                galerias::getInstance().fotoActualizar->setAutor(arrayPalabras[3]);
            }
            else if (arrayPalabras[1] == "descripcion"){
                galerias::getInstance().metadataActualizar = "descripcion";
                galerias::getInstance().fotoActualizar->setDescripcion(arrayPalabras[3]);
            }
            else {
                qDebug()<<"Error, la metadata que desea modificar no existe";
            }

        }
        else {
            qDebug()<<"No se ingreso el comando set para indicar el nuevo valor de la metadata seleccionada";
        }

        if (arrayPalabras[4] == "where"){

        }

    }

    else {
        qDebug()<<"La primera palabra debe ser un comando como select,update o delete ";
    }
    qDebug()<<"Se quiere eliminar --> "<<galerias::getInstance().metadataEliminar <<" de la imagen y en la galeria " <<galerias::getInstance().galeriaEliminar->getNombre();
    galerias::getInstance().fotoEliminar->imprimirDatosImagen();
}

QString* busquedaImagen::crearArray(QString hablada)
{
    QStringList listaSeparada = hablada.split(" ");
    int i = 0;
    int tamano = listaSeparada.count();
    QString *arrayString = new QString[tamano+1];
    arrayString[0] = QString::number(tamano);;
    foreach(QString palabra, listaSeparada){
        arrayString[i+1] = palabra;
        i++;
    }
    return arrayString;
}

void busquedaImagen::on_botonBusqueda_clicked()
{
    QString oracion = ui->searchEdit->text();
    QString *arraySTR = crearArray(oracion);
    detectarPlabras(arraySTR);
    close();



}

