#include "xml.h"


XML::XML()
{

}
string XML::readXML(){
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
        auto Autor= ix.firstChild().toElement().attribute("autor");
        auto Creacion= ix.firstChild().toElement().attribute("creacion");
        auto Tamano= ix.firstChild().toElement().attribute("tamano");
        auto Descripcion= ix.firstChild().toElement().attribute("descripcion");
        //imprimir
        std::cout << "base64  = " << base64.toStdString().c_str() << std::endl;
        std::cout << "Nombre  = " << nombre.toStdString().c_str() << std::endl;
        std::cout << "Autor  = " << Autor.toStdString().c_str() << std::endl;
        std::cout << "Creacion  = " << Creacion.toStdString().c_str() << std::endl;
        std::cout << "Tamano  = " << Tamano.toStdString().c_str() << std::endl;
        std::cout << "Descp  = " << Descripcion.toStdString().c_str() << std::endl;
        ix=ix.nextSibling().toElement();
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return "";
    }
    QTextStream xout(&file);
    xout<<doc.toString();
    file.flush();
    file.close();
    return "";
}
void XML::newGallery(string galeria){

    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto Galeria= doc.createElement("Galeria");
    Galeria.setAttribute("nombre", QString::fromStdString(galeria));
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
void XML::eliminar(string base64){
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        auto child= ix.firstChild();
        while(!child.isNull()){
            string base64Guardada= child.toElement().attribute("base64").toStdString().c_str();
            if(base64Guardada==base64){
                ix.removeChild(child);// verificar que elimine
            }
            std::cout << "base64 = " << base64Guardada << std::endl;
            child=child.nextSibling().toElement();
        }
        ix=ix.nextSibling().toElement();
    }

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
void update(string cambio, string caracteristica,string lugar, string atributo){
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    if(lugar=="base64"){
        while(!ix.isNull()){
            auto child= ix.firstChild();
            while(!child.isNull()){
                string base64Guardada= child.toElement().attribute("base64").toStdString().c_str();
                if(base64Guardada==atributo){
                    //actualizar
                    std::cout << "actualizada" << base64Guardada << std::endl;
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
                child=child.nextSibling().toElement();
            }
            ix=ix.nextSibling().toElement();
        }
    }
    else if (lugar=="nombre") {
        while(!ix.isNull()){
            auto child= ix.firstChild();
            while(!child.isNull()){
                string nombre= child.toElement().attribute("nombre").toStdString().c_str();
                if(nombre==atributo){
                    //actualizar
                    std::cout << "actualizada" << nombre << std::endl;
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
                child=child.nextSibling().toElement();
            }
            ix=ix.nextSibling().toElement();
        }
    }
    else if (lugar=="autor") {
        while(!ix.isNull()){
            auto child= ix.firstChild();
            while(!child.isNull()){
                string autor= child.toElement().attribute("autor").toStdString().c_str();
                if(autor==atributo){
                    //actualizar
                    std::cout << "actualizada" << autor << std::endl;
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
                child=child.nextSibling().toElement();
            }
            ix=ix.nextSibling().toElement();
        }
    }
    else if (lugar=="creacion") {
        while(!ix.isNull()){
            auto child= ix.firstChild();
            while(!child.isNull()){
                string creacion= child.toElement().attribute("creacion").toStdString().c_str();
                if(creacion==atributo){
                    //actualizar
                    std::cout << "actualizada" << creacion << std::endl;
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
                child=child.nextSibling().toElement();
            }
            ix=ix.nextSibling().toElement();
        }
    }
    else if (lugar=="tamano") {
        while(!ix.isNull()){
            auto child= ix.firstChild();
            while(!child.isNull()){
                string tamano= child.toElement().attribute("tamano").toStdString().c_str();
                if(tamano==atributo){
                    //actualizar
                    std::cout << "actualizada" << tamano << std::endl;
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
                child=child.nextSibling().toElement();
            }
            ix=ix.nextSibling().toElement();
        }
    }
    else if (lugar=="descripcion") {
        while(!ix.isNull()){
            auto child= ix.firstChild();
            while(!child.isNull()){
                string descripcion= child.toElement().attribute("descripcion").toStdString().c_str();
                if(descripcion==atributo){
                    //actualizar
                    std::cout << "actualizada" << descripcion << std::endl;
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
                child=child.nextSibling().toElement();
            }
            ix=ix.nextSibling().toElement();
        }
    }
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
void XML::agregarImagen(string carpeta, string base64, string nombre, string autor, string creacion, string tamano, string descripcion){
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        string id= ix.attribute("nombre").toStdString().c_str();
        if(id==carpeta){
            auto Imagen= doc.createElement("imagen");
            //agregar strings
            Imagen.setAttribute("base64", QString::fromStdString(base64));
            Imagen.setAttribute("nombre", QString::fromStdString(nombre));
            Imagen.setAttribute("autor", QString::fromStdString(autor));
            Imagen.setAttribute("creacion", QString::fromStdString(creacion));
            Imagen.setAttribute("tamano", QString::fromStdString(tamano));
            Imagen.setAttribute("descripcion", QString::fromStdString(descripcion));
            ix.appendChild(Imagen);
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
        ix=ix.nextSibling().toElement();
    }
    auto Galeria= doc.createElement("Galeria");
    Galeria.setAttribute("nombre", QString::fromStdString(carpeta));
    root.appendChild(Galeria);
    auto Imagen= doc.createElement("imagen");
    //agregar strings
    Imagen.setAttribute("base64", QString::fromStdString(base64));
    Imagen.setAttribute("nombre", QString::fromStdString(nombre));
    Imagen.setAttribute("autor", QString::fromStdString(autor));
    Imagen.setAttribute("creacion", QString::fromStdString(creacion));
    Imagen.setAttribute("tamano", QString::fromStdString(tamano));
    Imagen.setAttribute("descripcion", QString::fromStdString(descripcion));
    Galeria.appendChild(Imagen);
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
string XML::obtenerImagen(string base64){
    string datos= "";
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        auto child= ix.firstChild();
        while(!child.isNull()){
            string base64Guardada= child.toElement().attribute("base64").toStdString().c_str();
            if(base64Guardada==base64){
                string nombre= child.toElement().attribute("nombre").toStdString().c_str();
                string Autor= child.toElement().attribute("autor").toStdString().c_str();
                string Creacion= child.toElement().attribute("creacion").toStdString().c_str();
                string Tamano= child.toElement().attribute("tamano").toStdString().c_str();
                string Descripcion= child.toElement().attribute("descripcion").toStdString().c_str();
                datos= datos+ base64+ ","+ nombre+ ","+Autor+ ","+Creacion+ ","+Tamano+ ","+Descripcion+ ".";
            }
            std::cout << "base64 = " << base64Guardada << std::endl;
            child=child.nextSibling().toElement();
        }
        ix=ix.nextSibling().toElement();
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return"";
    }
    QTextStream xout(&file);
    xout<<doc.toString();
    file.flush();
    file.close();
    return datos;
}
string XML::buscarNombre(string nombre){
    string datos= "";
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        auto child= ix.firstChild();
        while(!child.isNull()){
            string nombreGuardado= child.toElement().attribute("nombre").toStdString().c_str();
            if(nombreGuardado==nombre){
                string base64= child.toElement().attribute("base64").toStdString().c_str();
                string Autor= child.toElement().attribute("autor").toStdString().c_str();
                string Creacion= child.toElement().attribute("creacion").toStdString().c_str();
                string Tamano= child.toElement().attribute("tamano").toStdString().c_str();
                string Descripcion= child.toElement().attribute("descripcion").toStdString().c_str();
                datos= datos+ base64+ ","+ nombre+ ","+Autor+ ","+Creacion+ ","+Tamano+ ","+Descripcion+ ".";
            }
            std::cout << "nombre  = " << nombreGuardado << std::endl;
            child=child.nextSibling().toElement();
        }
        ix=ix.nextSibling().toElement();

    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return "";
    }
    QTextStream xout(&file);
    xout<<doc.toString();
    file.flush();
    file.close();
    return datos;
}
string XML::buscarAutor(string autor){
    string datos= "";
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        auto child= ix.firstChild();
        while(!child.isNull()){
            string autorGuardado= child.toElement().attribute("autor").toStdString().c_str();
            if(autorGuardado==autor){
                string base64= child.toElement().attribute("base64").toStdString().c_str();
                string nombre= child.toElement().attribute("nombre").toStdString().c_str();
                string Creacion= child.toElement().attribute("creacion").toStdString().c_str();
                string Tamano= child.toElement().attribute("tamano").toStdString().c_str();
                string Descripcion= child.toElement().attribute("descripcion").toStdString().c_str();
                datos= datos+ base64+ ","+ nombre+ ","+autor+ ","+Creacion+ ","+Tamano+ ","+Descripcion+ ".";
            }
            std::cout << "autor  = " << autorGuardado << std::endl;
            child=child.nextSibling().toElement();
        }
        ix=ix.nextSibling().toElement();
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return "";
    }
    QTextStream xout(&file);
    xout<<doc.toString();
    file.flush();
    file.close();
    return datos;
}
string XML::buscarCreacion(string creacion){
    string datos= "";
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        auto child= ix.firstChild();
        while(!child.isNull()){
            string creacionGuardado= child.toElement().attribute("creacion").toStdString().c_str();
            if(creacionGuardado==creacion){
                string base64= child.toElement().attribute("base64").toStdString().c_str();
                string nombre= child.toElement().attribute("nombre").toStdString().c_str();
                string Autor= child.toElement().attribute("autor").toStdString().c_str();
                string Tamano= child.toElement().attribute("tamano").toStdString().c_str();
                string Descripcion= child.toElement().attribute("descripcion").toStdString().c_str();
                datos= datos+ base64+ ","+ nombre+ ","+Autor+ ","+creacion+ ","+Tamano+ ","+Descripcion+ ".";
            }
            std::cout << "creacion  = " << creacionGuardado << std::endl;
            child=child.nextSibling().toElement();
        }
        ix=ix.nextSibling().toElement();
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return "";
    }
    QTextStream xout(&file);
    xout<<doc.toString();
    file.flush();
    file.close();
    return datos;
}
string XML::buscarTamano(string tamano){
    string datos= "";
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        auto child= ix.firstChild();
        while(!child.isNull()){
            string tamanoGuardado= child.toElement().attribute("tamano").toStdString().c_str();
            if(tamanoGuardado==tamano){
                string base64= child.toElement().attribute("base64").toStdString().c_str();
                string nombre= child.toElement().attribute("nombre").toStdString().c_str();
                string Autor= child.toElement().attribute("autor").toStdString().c_str();
                string Creacion= child.toElement().attribute("creacion").toStdString().c_str();
                string Descripcion= child.toElement().attribute("descripcion").toStdString().c_str();
                datos= datos+ base64+ ","+ nombre+ ","+Autor+ ","+Creacion+ ","+tamano+ ","+Descripcion+ ".";
            }
            std::cout << "base64  = " << tamanoGuardado << std::endl;
            child=child.nextSibling().toElement();
        }
        ix=ix.nextSibling().toElement();
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return "";
    }
    QTextStream xout(&file);
    xout<<doc.toString();
    file.flush();
    file.close();
    return datos;
}
string XML::buscarDescripcion(string descripcion){
    string datos= "";
    QFile file("BaseDatos.xml");
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root= doc.firstChild().toElement();
    auto ix= root.firstChild().toElement();
    while(!ix.isNull()){
        auto child= ix.firstChild();
        while(!child.isNull()){
            string descripcionGuardado= child.toElement().attribute("descripcion").toStdString().c_str();
            if(descripcionGuardado==descripcion){
                string base64= child.toElement().attribute("base64").toStdString().c_str();
                string nombre= child.toElement().attribute("nombre").toStdString().c_str();
                string autor= child.toElement().attribute("autor").toStdString().c_str();
                string creacion= child.toElement().attribute("creacion").toStdString().c_str();
                string tamano= child.toElement().attribute("tamano").toStdString().c_str();
                datos= datos+ base64+ ","+ nombre+ ","+autor+ ","+creacion+ ","+tamano+ ","+descripcion+ ".";
            }
            std::cout << "descripcion  = " << descripcionGuardado << std::endl;
            child=child.nextSibling().toElement();
        }
        ix=ix.nextSibling().toElement();
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(nullptr,"Error",file.errorString());
        return "";
    }
    QTextStream xout(&file);
    xout<<doc.toString();
    file.flush();
    file.close();
    return datos;
}
