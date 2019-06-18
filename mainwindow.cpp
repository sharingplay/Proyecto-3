#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{

    QString imagen = QFileDialog::getOpenFileName(this,tr ("Seleccione la imagen"),"","All files (*.*)");
    if(QString::compare(imagen, QString()) != 0){
        QImage image;
        QImage imagenNueva;
        bool valid = image.load(imagen);
        qDebug()<<imagen;
        if(valid){
            image = image.scaledToWidth(ui->label_imagen->width(), Qt::SmoothTransformation);
            ui->label_imagen->setPixmap(QPixmap::fromImage(image));

            galerias::getInstance().fotoGlobal->setTamano(image.sizeInBytes());
            galerias::getInstance().fotoGlobal->setImagen(image);
            image = imagenNueva;
            //llama al ingreso de metadata
            ingresoMetadata ventanaMetadata;
            ventanaMetadata.setModal(true);
            ventanaMetadata.exec();
            galerias::getInstance().fotoGlobal->imprimirDatosImagen();
            galerias::getInstance().fotoGlobal = new fotografia();
        }
        else {
            qDebug()<<"Error al cargar la imagen";
        }
    }
}

void MainWindow::on_searchButton_clicked()
{

    busquedaImagen ventanaBusqueda;
    ventanaBusqueda.setModal(true);
    ventanaBusqueda.exec();
    galerias::getInstance().arrayBuscar[4] = 1;
}

void MainWindow::on_updateButton_clicked()
{
    updateImagen ventanaUpdate;
    ventanaUpdate.setModal(true);
    ventanaUpdate.exec();
    galerias::getInstance().arrayUpdate[4] = 3;
}

void MainWindow::on_deleteButton_clicked()
{
    borrarImagen ventanaBorrar;
    ventanaBorrar.setModal(true);
    ventanaBorrar.exec();
    galerias::getInstance().arrayBorrar[4] = 2;
}

void MainWindow::on_infoButton_clicked()
{
    string palabraPrueba;
    palabraPrueba = "asd134s1341,paisaje,PAISAJES,Jesus,1999,paisaje con lago.";//base64,nombre,autor,ano,tamano,descripcion
    QString* prueba = galerias::getInstance().leerArray(palabraPrueba);
    for (int i = 0 ; i < 6;i++) {
        qDebug()<<prueba[i];

    }

    //    for (int i = 0; i < prueba->size();i++) {
    //        qDebug()<< prueba[i];
    //    }
    //    seleccionFotos ventanaTabla;
    //    ventanaTabla.setModal(true);
    //    ventanaTabla.exec();
}



