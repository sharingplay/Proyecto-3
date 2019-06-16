#include "updateimagen.h"
#include "ui_updateimagen.h"


updateImagen::updateImagen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateImagen)
{
    ui->setupUi(this);
}

updateImagen::~updateImagen()
{
    delete ui;
}

QString *updateImagen::crearArray(QString oracion)
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

void updateImagen::detectarPalabrasUpdate(QString *arrayOracion)
{
    QString* arrayOriginal = arrayOracion;
    QString arrayPalabras[arrayOriginal[0].toInt()] ;


    for (int i = 0;i< (arrayOriginal[0].toInt());i++) {
        arrayPalabras[i] = arrayOriginal[i+1];
    }

    //*****Update*****
    if (arrayPalabras[0] == "update") {

        if (arrayPalabras[2] == "set"){

            if(arrayPalabras[1] == "nombre"){
                galerias::getInstance().arrayUpdate[0] = "nombre";
                galerias::getInstance().arrayUpdate[1] = arrayPalabras[3];
            }
            else if (arrayPalabras[1] == "ano"){
                galerias::getInstance().arrayUpdate[0] = "ano";
                galerias::getInstance().arrayUpdate[1] = arrayPalabras[3];
            }
            else if (arrayPalabras[1] == "autor"){
                galerias::getInstance().arrayUpdate[0] = "autor";
                galerias::getInstance().arrayUpdate[1] = arrayPalabras[3];
            }
            else if (arrayPalabras[1] == "descripcion"){
                galerias::getInstance().arrayUpdate[0] = "descripcion";

                QString descripcion = "";
                int i = 3;
                while (arrayPalabras[i] != "where") {
                    descripcion = descripcion + arrayPalabras[i] + " ";
                    i++;
                }
                galerias::getInstance().arrayUpdate[1] = descripcion;

                if (arrayPalabras[i] == "where"){
                    galerias::getInstance().arrayUpdate[2] = arrayPalabras[i+1];
                    galerias::getInstance().arrayUpdate[3] = arrayPalabras[i+3];
                }
                else {
                    qDebug()<<"no se ingreso la palabra where";
                }
            }
            else {
                qDebug()<<"Error, la metadata que desea modificar no existe";
            }

        }
        else {
            qDebug()<<"No se ingreso el comando set para indicar el nuevo valor de la metadata seleccionada";
        }

        if (arrayPalabras[4] == "where"){
            galerias::getInstance().arrayUpdate[2] = arrayPalabras[5];
            galerias::getInstance().arrayUpdate[3] = arrayPalabras[7];
        }

    }
    else{
        qDebug()<<"No se ingreso la palabra update";
    }
    cout<<"Dato actualizar -->"<<galerias::getInstance().arrayUpdate[0].toStdString()<<endl;
    cout<<" valor nuevo -->"<<galerias::getInstance().arrayUpdate[1].toStdString()<<endl;
    cout<<" Dato comparar -->"<<galerias::getInstance().arrayUpdate[2].toStdString()<<endl;
    cout<<" valor dato -->"<<galerias::getInstance().arrayUpdate[3].toStdString()<<endl;
}

void updateImagen::on_updateButton_clicked()
{
    QString oracion = ui->updateEdit->text();
    QString *arraySTR = crearArray(oracion);
    detectarPalabrasUpdate(arraySTR);
    close();
}
