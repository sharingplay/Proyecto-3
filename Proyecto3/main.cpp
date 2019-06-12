#include "mainwindow.h"
#include <QApplication>
#include "xml.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XML* prueba= new XML();
    prueba->writeXML("prueba");
    prueba->readXML();
    prueba->newGallery("prueba");
    cout<<"here main"<<endl;
    MainWindow w;
    w.show();
    return a.exec();
}
