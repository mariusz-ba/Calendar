#include "calendar.h"
#include <QDebug>

Calendar::Calendar(QWidget *parent) : QWidget(parent), m_dateFormat("yyyy-MM-dd HH:mm:ss")
{
    initDatabase();
    m_listView = new QListView(this);
    m_listView->setModel(m_sqlTableModel);
    m_listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_listDelegate = new ListDelegate();
    m_listView->setItemDelegate(m_listDelegate);

    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_listView);

    connect(m_listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(editEventIndex(QModelIndex)));

    this->setLayout(m_layout);
}

Calendar::~Calendar()
{
    if(m_db.isOpen())
        m_db.close();
}

void Calendar::initDatabase()
{
    QFile dbFile("data.db");
    if(dbFile.exists())
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName("data.db");
        m_db.open();
        qDebug() << "Database oppened.";
    }
    else
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName("data.db");
        m_db.open();
        QSqlQuery createTable(m_db);
        createTable.exec("CREATE TABLE events(empty_place TEXT NULL, name TEXT NULL, description TEXT NULL, date_time DATETIME)");
        qDebug() << "Database created.";
    }

    m_sqlTableModel = new QSqlTableModel(this, m_db);
    m_sqlTableModel->setTable("events");
    m_sqlTableModel->setSort(3, Qt::AscendingOrder);
    m_sqlTableModel->select();
}

void Calendar::addEvent()
{
    EventDialog dialog(this);
    dialog.setModal(true);

    if(dialog.exec() == QDialog::Accepted)
    {
        Event tmpEvent = dialog.getEvent();
        qDebug() << tmpEvent.name();

        if((!tmpEvent.name().isEmpty()) || (!tmpEvent.description().isEmpty()))
        {
            QSqlQueryModel check;
            check.setQuery("SELECT * FROM events WHERE date_time='" + tmpEvent.dateTime().toString(m_dateFormat) + "'", m_db);
            if(check.rowCount() == 0)
            {
                QSqlQuery insertion(m_db);
                insertion.prepare("INSERT INTO events(name, description, date_time) VALUES"
                                  "(?,?,?)");
                insertion.addBindValue(tmpEvent.name());
                insertion.addBindValue(tmpEvent.description());
                insertion.addBindValue(tmpEvent.dateTime().toString(m_dateFormat));
                insertion.exec();
                qDebug() << "Pushed";
                m_sqlTableModel->select();
            }
            else
            {
                //Item with this date already exists
                QMessageBox::warning(this, tr("Calendar"), tr("Item with this date and time already exists."));
            }
        }
    }
}

void Calendar::editEventIndex(QModelIndex)
{
    editEvent();
}

void Calendar::editEvent()
{
    int row = m_listView->currentIndex().row();
    if(row < 0 || row >= m_sqlTableModel->rowCount())
        return;

    Event tmpEvent;
    tmpEvent.setName(m_sqlTableModel->index(row, 1).data().toString());
    tmpEvent.setDescription(m_sqlTableModel->index(row, 2).data().toString());
    tmpEvent.setDateTime(QDateTime::fromString(m_sqlTableModel->index(row, 3).data().toString(), m_dateFormat));

    EventDialog dialog(this);
    dialog.setModal(true);
    dialog.setDefault(tmpEvent.name(), tmpEvent.description(), tmpEvent.dateTime().date(), tmpEvent.dateTime().time());

    QString tempDate = tmpEvent.dateTime().toString(m_dateFormat);

    if(dialog.exec() == QDialog::Accepted)
    {
        tmpEvent = dialog.getEvent();

        if((!tmpEvent.name().isEmpty()) && (!tmpEvent.description().isEmpty()))
        {
            QSqlQuery update_query(m_db);
            update_query.prepare("UPDATE events SET "
                                 "name=?, description=?, date_time=?"
                                 "WHERE date_time=?");
            update_query.addBindValue(tmpEvent.name());
            update_query.addBindValue(tmpEvent.description());
            update_query.addBindValue(tmpEvent.dateTime().toString(m_dateFormat));
            update_query.addBindValue(tempDate);
            update_query.exec();
            qDebug() << "Edited";
            m_sqlTableModel->select();
        }
    }
}

void Calendar::removeEvent()
{
    int row = m_listView->currentIndex().row();
    if(row < 0 || row >= m_sqlTableModel->rowCount())
        return;

    QString date = m_sqlTableModel->index(row, 3).data().toString();

    QSqlQuery remove_query(m_db);
    remove_query.prepare("DELETE FROM events WHERE date_time=?");
    remove_query.addBindValue(date);
    remove_query.exec();
    qDebug() << "Removed";
    m_sqlTableModel->select();
}
