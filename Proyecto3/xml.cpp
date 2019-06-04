#include "xml.h"


XML::XML()
{

}
string XML::readXML(){
    auto filename = QFileDialog::getSaveFileName(nullptr,"Abrir Datos",QDir::rootPath(),"XML file (*.xml)");
    if(filename.isEmpty()){
        return "";
    }
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return "";
    }
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        auto id= ix.attribute("id");
        auto nombre= ix.firstChild().toElement().text();
        auto edad= ix.firstChild().nextSibling().toElement().text();
        auto salario= ix.firstChild().nextSibling().nextSibling().toElement().text();
        //imprimir
        ix=ix.nextSibling().toElement();
    }
}
void XML::newGallery(string galeria){

    QDomDocument doc;
    auto root=doc.createElement("sistema");
    auto Galeria= doc.createElement(QString::fromStdString(galeria));
    Galeria.setAttribute("nombre", "familia");
    root.appendChild(Galeria);
    QFile file("BaseDatos.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return;
    }
    QTextStream xout(&file);
    xout<<doc.toString();
    file.flush();
    file.close();
    return;
}
void XML::writeXML(string datos){
    QDomDocument doc;
    auto root=doc.createElement("sistema");
    doc.appendChild(root);
    auto Galeria= doc.createElement("Galeria");
    Galeria.setAttribute("nombre", "familia");
    root.appendChild(Galeria);
    auto Imagen= doc.createElement("imagen");
    Imagen.setAttribute("dir", "/doc/nose");
    auto eNombre= doc.createElement("nombre");
    auto eAutor= doc.createElement("Autor");
    auto eAnoCreacion= doc.createElement("Creacion");
    auto eTamano= doc.createElement("Tamano");
    auto eDescripcion= doc.createElement("Descripcion");
    eNombre.appendChild(doc.createElement("Graduacion"));
    eAutor.appendChild(doc.createElement("Mariana"));
    eAnoCreacion.appendChild(doc.createElement("2017"));
    eTamano.appendChild(doc.createElement("16x16"));
    eDescripcion.appendChild(doc.createElement("baile de graduacion"));
    Imagen.appendChild(eNombre);
    Imagen.appendChild(eAutor);
    Imagen.appendChild(eAnoCreacion);
    Imagen.appendChild(eTamano);
    Imagen.appendChild(eDescripcion);
    Galeria.appendChild(Imagen);
    QFile file("BaseDatos.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return;
    }
    QTextStream xout(&file);
    xout<<doc.toString();
    file.flush();
    file.close();
    return;
}
