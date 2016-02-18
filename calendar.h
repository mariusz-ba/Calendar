#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>
#include <QWidget>
#include <QListView>
#include <QHBoxLayout>
#include <QList>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>

#include "event.h"
#include "eventdialog.h"

class Calendar : public QWidget
{
    Q_OBJECT
public:
    explicit Calendar(QWidget *parent = 0);
    ~Calendar();

public slots:
    void addEvent();
    void editEvent();
    void removeEvent();

private:
    void initDatabase();

    QString m_dateFormat;
    QSqlDatabase m_db;
    QSqlTableModel* m_sqlTableModel;

    QListView* m_listView;
    QHBoxLayout* m_layout;
};

#endif // CALENDAR_H
