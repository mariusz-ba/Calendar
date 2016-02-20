#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    loadSettings();
    this->setWindowIcon(QIcon(":/img/Calendar.png"));
    calendar = new Calendar(this);

    this->setCentralWidget(calendar);

    menu = new QMenu(tr("&Menu"));
    m_actionAdd = new QAction(tr("&Add Event"), this);
    m_actionEdit = new QAction(tr("&Edit Event"), this);
    m_actionRemove = new QAction(tr("&Remove Event"), this);
    m_actionExit = new QAction(tr("E&xit"), this);
    menu->addActions({m_actionAdd, m_actionEdit, m_actionRemove});
    menu->addSeparator();
    menu->addActions({m_actionExit});

    help_menu = new QMenu(tr("&Help"));
    m_actionAbout = new QAction(tr("A&bout"), this);
    help_menu->addActions({m_actionAbout});

    menuBar()->addMenu(menu);
    menuBar()->addMenu(help_menu);

    connect(m_actionAdd, SIGNAL(triggered()), calendar, SLOT(addEvent()));
    connect(m_actionEdit, SIGNAL(triggered()), calendar, SLOT(editEvent()));
    connect(m_actionRemove, SIGNAL(triggered()), calendar, SLOT(removeEvent()));
    connect(m_actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(m_actionAbout, SIGNAL(triggered()), this, SLOT(about()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    saveSettings();
    event->accept();
}

void MainWindow::about()
{
    AboutDialog dl(this);

    dl.setFixedSize(dl.sizeHint());
    dl.setModal(true);
    dl.exec();
}

void MainWindow::loadSettings()
{
    QSettings settings("mariusz-ba", "Calendar");
    QSize size = qvariant_cast<QSize>(settings.value("size", QSize(300, 400)));
    QPoint position = qvariant_cast<QPoint>(settings.value("pos", QPoint(0, 0)));
    resize(size);
    move(position);
}

void MainWindow::saveSettings()
{
    QSettings settings("mariusz-ba", "Calendar");
    settings.setValue("size", size());
    settings.setValue("pos", pos());

}
