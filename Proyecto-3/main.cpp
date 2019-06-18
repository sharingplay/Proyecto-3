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
    a.write("../image.jpg","1");
    //system("rm -r geeksforgeeks2");
   //rmdir("geeksforgeeks");

    return 0;
}
