#include "mainwindow.h"
#include <QApplication>
#include "xml.h"
#include "socks.h"
#include "serializador.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XML* prueba= new XML();
   prueba->writeXML("prueba");
   string nombre;
   string autor;
   string creacion;
   string descripcion;
   string tamano;
   string galeria;
   string foto_b64;
   int id;
   string recibe = socks::getInstance().escuchaEnvia(8080,"");
   serializador::getInstance().deserializarMeta(recibe, &nombre, &autor, &creacion, &descripcion, &tamano, &galeria,&foto_b64,&id);
   if (id == 1){
       if(creacion == "nombre"){
          prueba->buscarNombre(descripcion);
       }
       if(creacion == "autor"){
           prueba->buscarAutor(descripcion);
       }
       if(creacion == "ano"){
           prueba->buscarCreacion(descripcion);
       }
       if(creacion == "descripcion"){
           prueba->buscarDescripcion(descripcion);
       }
       if(creacion == "tamano"){
            prueba->buscarTamano(descripcion);
       }
   }
   if (id ==2){
       prueba->eliminar(nombre);
   }
//    prueba->readXML();
//    prueba->newGallery("prueba");
//    prueba->agregarImagen("prueba","68597","rosa","pablo","1985","15x15","holaaaa");
//    prueba->agregarImagen("prueba","685787","rosa","pablo","1985","15x15","holaaaa");
//    prueba->agregarImagen("prueba","96597","rosa","pablo","1985","15x15","holaaaa");
//    prueba->agregarImagen("prueba","684897","rosa","pablo","1985","15x15","holaaaa");
//    prueba->eliminar("68597");
//    prueba->eliminar("96597");
//    prueba->eliminar("684897");
//    cout<<prueba->buscarDescripcion("holaaaa")<<endl;
//    cout<<"here main"<<endl;
    MainWindow w;
    w.show();
    return a.exec();
}
