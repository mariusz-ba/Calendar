#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <QSettings>

#include "calendar.h"
#include "aboutdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);

private slots:
    void loadSettings();
    void saveSettings();

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
