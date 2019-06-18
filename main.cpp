#include "mainwindow.h"
#include <QApplication>
#include "fotografia.h"
#include "raid.h"
#include "xml.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    RAID::getInstance().createDisks();
    XML::getInstance().writeXML("");
    w.show();

    return a.exec();
}
