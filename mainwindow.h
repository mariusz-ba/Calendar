#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "calendar.h"
#include "aboutdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void about();

private:
    Calendar* calendar;
    QMenu* menu;
    QAction* m_actionAdd;
    QAction* m_actionEdit;
    QAction* m_actionRemove;
    QAction* m_actionExit;
    QMenu* help_menu;
    QAction* m_actionAbout;
};

#endif // MAINWINDOW_H
