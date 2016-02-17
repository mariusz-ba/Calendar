#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "calendar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Calendar* calendar;
    QMenu* menu;
    QAction* m_actionAdd;
    QAction* m_actionEdit;
    QAction* m_actionRemove;
    QAction* m_actionExit;
};

#endif // MAINWINDOW_H
