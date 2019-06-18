#include "mainwindow.h"
#include <QApplication>
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <raid.h>
using namespace std;

int main(int argc, char *argv[]){
    RAID a;
 //a.createDisks();
 //a.write("/home/jose/Desktop/Proyecto-3/image1.png","BobEsponja");
    //system("rm -r geeksforgeeks2");
   //rmdir("geeksforgeeks");

    a.seek("BobEsponja");

    return 0;
}
