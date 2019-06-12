#include "xml.h"


XML::XML()
{

}
string XML::readXML(){
//    auto filename = QFileDialog::getSaveFileName(nullptr,"Abrir Datos",QDir::rootPath(),"XML file (*.xml)");
//    if(filename.isEmpty()){
//        return "";
//    }
//    QFile file(filename);
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        QMessageBox::critical(nullptr,"Error",file.errorString());
//        return "";
//    }
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        auto id= ix.attribute("id");
        auto base64= ix.firstChild().toElement().attribute("base64");
        auto nombre= ix.firstChild().toElement().attribute("nombre");
        auto Autor= ix.firstChild().toElement().attribute("Autor");
        auto Creacion= ix.firstChild().toElement().attribute("Creacion");
        auto Tamano= ix.firstChild().toElement().attribute("Tamano");
        auto Descripcion= ix.firstChild().toElement().attribute("Descripcion");
        //imprimir
        std::cout << "base64  = " << base64.toStdString().c_str() << std::endl;
        std::cout << "Nombre  = " << nombre.toStdString().c_str() << std::endl;
        std::cout << "Autor  = " << Autor.toStdString().c_str() << std::endl;
        std::cout << "Creacion  = " << Creacion.toStdString().c_str() << std::endl;
        std::cout << "Tamano  = " << Tamano.toStdString().c_str() << std::endl;
        std::cout << "Descp  = " << Descripcion.toStdString().c_str() << std::endl;
        ix=ix.nextSibling().toElement();
    }
}
void XML::newGallery(string galeria){

    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto Galeria= doc.createElement("Galeria");
    Galeria.setAttribute("nombre", "personaje");
    root.appendChild(Galeria);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
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
    Imagen.setAttribute("base64", "/doc/nose");
    Imagen.setAttribute("nombre", "Pablo");
    Imagen.setAttribute("Autor", "Julian");
    Imagen.setAttribute("Creacion", "1989");
    Imagen.setAttribute("Tamano", "15x5");
    Imagen.setAttribute("Descripcion", "MarioIdiota");
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
