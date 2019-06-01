#include "raidisk.h"
#include "mainwindow.h"
#include <QApplication>
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

RAIDisk::RAIDisk(int disks){
   if (disks<3){
        cout << "Insufficient amount of disks" << endl;
   }
   else{
       for(int i=0; i<disks; i++){
           string diskname = "Disk Number"+to_string(i);
           const char* setter = diskname.c_str();
           if (mkdir(setter, 0777) == -1)
                cerr << "Error :  " << strerror(errno) << endl;
            else
                cout << "Directory created";

        }
    }
   return;
}
