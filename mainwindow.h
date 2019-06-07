#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "creategalery.h"
#include "fotografia.h"
#include "ingresometadata.h"
#include "galerias.h"
#include "busquedaimagen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_addButton_clicked();

    void on_searchButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
