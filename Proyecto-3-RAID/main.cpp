#include "mainwindow.h"
#include <QApplication>
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <raid.h>
#include "socks.h"
using namespace std;

int main(int argc, char *argv[]){
    RAID a;
    a.createDisks();
    while (true){
        socks::getInstance().escuchaEnvia(8080,"");
    }

    //a.write("/home/wajo/Documentos/TEC/Datos II/Proyecto 3/Proyecto-3/Proyecto-3-RAID/image1.png","BobEsponja");


    return 0;
}
