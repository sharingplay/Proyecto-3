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


void busquedaImagen::detectarPlabrasSelect(QString* arrayOracion)
{    
    QString* arrayOriginal = arrayOracion;
    QString arrayPalabras[arrayOriginal[0].toInt()] ;


    for (int i = 0;i< (arrayOriginal[0].toInt());i++) {
        arrayPalabras[i] = arrayOriginal[i+1];
    }

    //*****Select*****
    if(arrayPalabras[0] == "select"){

        if(arrayPalabras[1] == "nombre"){
            galerias::getInstance().arrayBuscar[0] = "nombre";
        }
        else if(arrayPalabras[1]=="autor"){
            galerias::getInstance().arrayBuscar[0] = "autor";
        }
        else if(arrayPalabras[1]=="descripcion"){
            galerias::getInstance().arrayBuscar[0] = "descripcion";
        }
        else if(arrayPalabras[1]=="ano"){
            galerias::getInstance().arrayBuscar[0] = "ano";
        }
        else if(arrayPalabras[1]=="*") {
             galerias::getInstance().arrayBuscar[0] = "todo";
        }
        else {
            qDebug()<<"El tipo de metadata "<< arrayPalabras[1]<< " no existe";
        }

        //Galeria en la que se desea buscar
        if(arrayPalabras[2] == "from"){
            galerias::getInstance().arrayBuscar[1] = arrayPalabras[3];
        }

        else{
            qDebug()<<"No se ingreso la palabra from";
        }

        if(arrayPalabras[4] == "where"){
            if(arrayPalabras[5]=="nombre"){
                galerias::getInstance().arrayBuscar[2] = "nombre";
                galerias::getInstance().arrayBuscar[3] = arrayPalabras[7];
            }
            else if(arrayPalabras[5]=="ano"){
                galerias::getInstance().arrayBuscar[2] = "ano";
                galerias::getInstance().arrayBuscar[3] = arrayPalabras[7];
            }
            else if(arrayPalabras[5]=="autor"){
                galerias::getInstance().arrayBuscar[2] = "autor";
                galerias::getInstance().arrayBuscar[3] = arrayPalabras[7];
            }
            else if(arrayPalabras[5]=="descripcion"){
                galerias::getInstance().arrayBuscar[2] = "descripcion";
                QString descripcion;
                for (int i = 7; i<= arrayOriginal[0].toInt()-1;i++) {
                    descripcion += arrayPalabras[i] + " ";
                }
               galerias::getInstance().arrayBuscar[3] = descripcion;
            }
            else {
                qDebug()<<"No se especifico que metadata se quiere buscar";
            }
        }

        else {
            qDebug()<<"No se especifico con el comando where que metadata se desea buscar";
        }
            cout<<"Dato buscar -->"<<galerias::getInstance().arrayBuscar[0].toStdString()<<endl;
            cout<<" Galeria -->"<<galerias::getInstance().arrayBuscar[1].toStdString()<<endl;
            cout<<" Dato comparar -->"<<galerias::getInstance().arrayBuscar[2].toStdString()<<endl;
            cout<<" valor dato -->"<<galerias::getInstance().arrayBuscar[3].toStdString()<<endl;
    }

}

QString* busquedaImagen::crearArray(QString oracion)
{
    QStringList listaSeparada = oracion.split(" ");
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
    detectarPlabrasSelect(arraySTR);
    close();



}

