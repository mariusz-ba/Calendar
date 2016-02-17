#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    calendar = new Calendar(this);

    this->setCentralWidget(calendar);

    menu = new QMenu(tr("&Menu"));
    m_actionAdd = new QAction(tr("&Add Event"), this);
    m_actionEdit = new QAction(tr("&Edit Event"), this);
    m_actionRemove = new QAction(tr("&Remove Event"), this);
    m_actionExit = new QAction(tr("E&xit"), this);
    menu->addActions({m_actionAdd, m_actionEdit, m_actionRemove, m_actionExit});

    menuBar()->addMenu(menu);

    connect(m_actionAdd, SIGNAL(triggered()), calendar, SLOT(addEvent()));
    connect(m_actionEdit, SIGNAL(triggered()), calendar, SLOT(editEvent()));
    connect(m_actionRemove, SIGNAL(triggered()), calendar, SLOT(removeEvent()));
    connect(m_actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
}
