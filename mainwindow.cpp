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

}

void MainWindow::on_updateButton_clicked()
{
    updateImagen ventanaUpdate;
    ventanaUpdate.setModal(true);
    ventanaUpdate.exec();
}

void MainWindow::on_deleteButton_clicked()
{
    borrarImagen ventanaBorrar;
    ventanaBorrar.setModal(true);
    ventanaBorrar.exec();
}

void MainWindow::on_infoButton_clicked()
{
     galerias::getInstance().imprimirInfoGalerias();
}


