/********************************************************
 *
 * Calendar App
 *
 * Created by Mariusz Baran on 17.02.2016
 * Copyright (c) 2016 Mariusz Baran. All rights reserved
 *
 ********************************************************/

 
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
