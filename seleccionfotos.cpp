#include "seleccionfotos.h"
#include "ui_seleccionfotos.h"

seleccionFotos::seleccionFotos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seleccionFotos)
{
    ui->setupUi(this);
    QStringList titulos;
    titulos << "Nombre"<<"Ano"<<"Autor"<<"Tamano"<<"Descripcion"<<"Imagen";
    setWindowTitle("Tabla fotos");
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    galerias::getInstance().arrayPrueba[0][0] = "Campo";galerias::getInstance().arrayPrueba[0][1] = "123";galerias::getInstance().arrayPrueba[0][2] = "mario";galerias::getInstance().arrayPrueba[0][3] = "1000";galerias::getInstance().arrayPrueba[0][4] = "casa en el campo";
    galerias::getInstance().arrayPrueba[1][0] = "CharlieAlvarado";galerias::getInstance().arrayPrueba[1][1] = "12345";galerias::getInstance().arrayPrueba[1][2] = "carlos";galerias::getInstance().arrayPrueba[1][3] = "2000";galerias::getInstance().arrayPrueba[1][4] = "presidente costa rica";
    galerias::getInstance().arrayPrueba[2][0] = "Toruno";galerias::getInstance().arrayPrueba[2][1] = "1098";galerias::getInstance().arrayPrueba[2][2] = "juan";galerias::getInstance().arrayPrueba[2][3] = "3000";galerias::getInstance().arrayPrueba[2][4] = "personaje tico";
}

seleccionFotos::~seleccionFotos()
{
    delete ui;
}

void seleccionFotos::on_verButton_clicked()
{

    for(int i = 0; i <= 2; i++){
    QPushButton* botonImagen = new QPushButton("ver imagen",ui->tableWidget);
    botonImagen->setIconSize(QSize(50,45));
    botonImagen->setVisible(true);
    botonImagen->setObjectName(QString("%1").arg(ui->tableWidget->rowCount()));
    connect(botonImagen, SIGNAL(clicked()),this,SLOT(clickBotonTabla()));



    int fila = ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(fila,NOMBRE,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][0]));
    ui->tableWidget->setItem(fila,ANO,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][1]));
    ui->tableWidget->setItem(fila,AUTOR,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][2]));
    ui->tableWidget->setItem(fila,TAMANO,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][3]));
    ui->tableWidget->setItem(fila,DESCRIPCION,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][4]));
    ui->tableWidget->setCellWidget(i,BOTON,botonImagen);

    }
//    for(int i = 0; i <= 2; i++){
//    QPushButton* botonImagen = new QPushButton();
//    botonImagen->setParent(ui->tableWidget);
//    botonImagen->setIconSize(QSize(50,45));
//    botonImagen->setText("ver");
//    botonImagen->setVisible(true);

//    int fila = ui->tableWidget->rowCount();

//    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
//    ui->tableWidget->setItem(fila,NOMBRE,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][0]));
//    ui->tableWidget->setItem(fila,ANO,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][1]));
//    ui->tableWidget->setItem(fila,AUTOR,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][2]));
//    ui->tableWidget->setItem(fila,TAMANO,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][3]));
//    ui->tableWidget->setItem(fila,DESCRIPCION,new QTableWidgetItem(galerias::getInstance().arrayPrueba[i][4]));
//    ui->tableWidget->setCellWidget(i,BOTON,botonImagen);

    //    }
}

void seleccionFotos::clickBotonTabla()
{
    QString imagen = ui->tableWidget->item(1,0)->text();
    qDebug()<<"click" << imagen;
}
