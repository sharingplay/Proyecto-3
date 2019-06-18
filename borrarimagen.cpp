#include "borrarimagen.h"
#include "ui_borrarimagen.h"

borrarImagen::borrarImagen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::borrarImagen)
{
    ui->setupUi(this);
}

borrarImagen::~borrarImagen()
{
    delete ui;
}

QString *borrarImagen::crearArray(QString oracion)
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

void borrarImagen::detectarPlabrasDelete(QString *arrayOracion)
{
    QString* arrayOriginal = arrayOracion;
    QString arrayPalabras[arrayOriginal[0].toInt()] ;


    for (int i = 0;i< (arrayOriginal[0].toInt());i++) {
        arrayPalabras[i] = arrayOriginal[i+1];
    }
    //*****Delete*****
    if (arrayPalabras[0] == "delete") {


        if(arrayPalabras[1] == "nombre"){
            galerias::getInstance().arrayBorrar[0] = "nombre";
        }
        else if(arrayPalabras[1]=="autor"){
            galerias::getInstance().arrayBorrar[0] = "autor";
        }
        else if(arrayPalabras[1]=="descripcion"){
            galerias::getInstance().arrayBorrar[0] = "descripcion";
        }
        else if(arrayPalabras[1]=="ano"){
            galerias::getInstance().arrayBorrar[0] = "ano";
        }
        else if (arrayPalabras[1] == "tamano") {
            galerias::getInstance().arrayBorrar[0] = "tamano";
        }
        else if(arrayPalabras[1]=="*") {
            galerias::getInstance().arrayBorrar[0] = "todo";
        }
        else {
            qDebug()<<"El tipo de metadata "<< arrayPalabras[1]<< " no existe";
        }

        //Galeria de la que se desea borrar metadata
        if(arrayPalabras[2]== "from"){
            if(arrayPalabras[2] == "from"){
                galerias::getInstance().arrayBorrar[1] = arrayPalabras[3];
            }
        }
        else{
            qDebug()<<"No se ingreso la palabra from";
        }

        if(arrayPalabras[4] == "where"){
            if(arrayPalabras[5]=="nombre"){
                galerias::getInstance().arrayBorrar[2] = "nombre";
                galerias::getInstance().arrayBorrar[3] = arrayPalabras[7];
            }
            else if(arrayPalabras[5]=="ano"){
                galerias::getInstance().arrayBorrar[2] = "ano";
                galerias::getInstance().arrayBorrar[3] = arrayPalabras[7];
            }
            else if(arrayPalabras[5]=="autor"){
                galerias::getInstance().arrayBorrar[2] = "autor";
                galerias::getInstance().arrayBorrar[3] = arrayPalabras[7];
            }
            else if(arrayPalabras[5]=="tamano"){
                galerias::getInstance().arrayBorrar[2] = "tamano";
                galerias::getInstance().arrayBorrar[3] = arrayPalabras[7];
            }
            else if(arrayPalabras[5]=="descripcion"){
                galerias::getInstance().arrayBorrar[2] = "descripcion";
                QString descripcion;
                for (int i = 7; i<= arrayOriginal[0].toInt()-1;i++) {
                    descripcion += arrayPalabras[i] + " ";
                }
                galerias::getInstance().arrayBorrar[3] = descripcion;
            }
            else {
                qDebug()<<"No se especifico que metadata se quiere eliminar";
            }
        }

        else {
            qDebug()<<"No se especifico con el comando where que metadata se desea borrar";
        }
        cout<<"Dato buscar -->"<<galerias::getInstance().arrayBorrar[0].toStdString()<<endl;
        cout<<" Galeria -->"<<galerias::getInstance().arrayBorrar[1].toStdString()<<endl;
        cout<<" Dato comparar -->"<<galerias::getInstance().arrayBorrar[2].toStdString()<<endl;
        cout<<" valor dato -->"<<galerias::getInstance().arrayBorrar[3].toStdString()<<endl;
    }
}

void borrarImagen::on_botonBorrar_clicked()
{
    QString oracion = ui->borrarEdit->text();
    QString *arraySTR = crearArray(oracion);
    detectarPlabrasDelete(arraySTR);
    close();

}
