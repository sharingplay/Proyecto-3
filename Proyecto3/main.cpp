#include "mainwindow.h"
#include <QApplication>
#include "xml.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XML* prueba= new XML();
//    prueba->writeXML("prueba");
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
