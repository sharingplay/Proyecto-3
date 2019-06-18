#include "creategalery.h"
#include "ui_creategalery.h"
#include "serializador.h"
#include "socks.h"
#include "xml.h"
#include "raid.h"
using namespace std;

createGalery::createGalery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createGalery)
{
    ui->setupUi(this);
}

createGalery::~createGalery()
{
    delete ui;
}

void createGalery::on_botonCrear_clicked()
{
    bool flag = true;

    galeria* nuevaGaleria = new galeria();
    QString nombreGaleria = ui->nombreGaleriaEdit->text();
    nuevaGaleria->setNombre(nombreGaleria);

    if (galerias::getInstance().listaGalerias->getFirst() != nullptr){
        for (Node* galeriaAux = galerias::getInstance().listaGalerias->getFirst();galeriaAux!=nullptr;galeriaAux = galeriaAux->getNext()) {
            galeria* galeriaTemp = (galeria*)galeriaAux->getData();
            if(nuevaGaleria->getNombre() == galeriaTemp->getNombre()){
                qDebug()<<"Ya existe una galeria con ese nombre";
                flag = false;
                delete (nuevaGaleria);
            }
        }

        if(flag == true){
            fotografia* fotoAgregar = new fotografia();
            fotoAgregar = galerias::getInstance().fotoGlobal;
            nuevaGaleria->agregarImagen(fotoAgregar);
            fotoAgregar->setNombreGaleria(nombreGaleria);
            galerias::getInstance().fotoGlobal = fotoAgregar;
            XML::getInstance().agregarImagen(fotoAgregar->getNombreGaleria().toStdString(),fotoAgregar->getNombre().toStdString(),fotoAgregar->getNombre().toStdString(),fotoAgregar->getAutor().toStdString(),fotoAgregar->getAno().toStdString(),fotoAgregar->getTamano().toStdString(),fotoAgregar->getDescripcion().toStdString());
            fotoAgregar->getImagen().save(fotoAgregar->getNombre(),"PNG");
            string str = fotoAgregar->getNombre().toStdString();
            RAID::getInstance().write(str.c_str(),str.c_str());
            qDebug()<<"Se creo la galeria "<<nombreGaleria<<" y se agrego la foto"<<fotoAgregar->getNombre();
            close();
        }
    }

    else{
        fotografia* fotoAgregar = new fotografia();
        fotoAgregar = galerias::getInstance().fotoGlobal;
        nuevaGaleria->agregarImagen(fotoAgregar);
        fotoAgregar->setNombreGaleria(nombreGaleria);
        galerias::getInstance().fotoGlobal = fotoAgregar;
        XML::getInstance().agregarImagen(fotoAgregar->getNombreGaleria().toStdString(),fotoAgregar->getNombre().toStdString(),fotoAgregar->getNombre().toStdString(),fotoAgregar->getAutor().toStdString(),fotoAgregar->getAno().toStdString(),fotoAgregar->getTamano().toStdString(),fotoAgregar->getDescripcion().toStdString());
        fotoAgregar->getImagen().save(fotoAgregar->getNombre(),"PNG");
        string str = fotoAgregar->getNombre().toStdString();
        RAID::getInstance().write(str.c_str(),str.c_str());
        qDebug()<<"Se creo la galeria "<<nombreGaleria<<" ya que no existia ninguna"<<" y se agrego la foto"<<fotoAgregar->getNombre();
        galerias::getInstance().listaGalerias->Add(nuevaGaleria);

        close();


    }
}

void createGalery::on_botonGuardar_clicked()
{
    bool flag = false;
    QString nombreGaleria = ui->nombreGaleriaEdit->text();

    if (galerias::getInstance().listaGalerias->getFirst() == nullptr){
        qDebug()<<"No existen galerias donde guardar, primero hay que crear una";
    }
    else{
        for (Node* galeriaAux = galerias::getInstance().listaGalerias->getFirst();galeriaAux!=nullptr;galeriaAux = galeriaAux->getNext()) {
            galeria* galeriaTemp = (galeria*)galeriaAux->getData();
            if(galeriaTemp->getNombre() == nombreGaleria){
                flag = true;
                fotografia* fotoAgregar = new fotografia();
                fotoAgregar = galerias::getInstance().fotoGlobal;
                fotoAgregar->setNombreGaleria(galeriaTemp->getNombre());
                galerias::getInstance().fotoGlobal = fotoAgregar;
                qDebug()<<"Se guardo la imagen "<<fotoAgregar->getNombre()<<" en la galeria "<<galeriaTemp->getNombre();
                galeriaTemp->agregarImagen(fotoAgregar);
                close();
            }
        }
        if (flag == false){
        qDebug()<<"No se encontro la galeria ingresada";
        }
    }
}
