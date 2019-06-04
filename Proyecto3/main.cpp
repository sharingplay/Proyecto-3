#include "mainwindow.h"
#include <QApplication>
#include "xml.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XML* prueba= new XML();
    //prueba->readXML();
    prueba->writeXML("prueba");
    cout<<"here main"<<endl;
    MainWindow w;
    w.show();
    return a.exec();
}
