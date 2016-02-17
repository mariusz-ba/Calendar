#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QHBoxLayout>
#include <QList>
#include "event.h"
#include "eventdialog.h"

class Calendar : public QWidget
{
    Q_OBJECT
public:
    explicit Calendar(QWidget *parent = 0);

public slots:
    void addEvent();
    void editEvent();
    void removeEvent();

private:
    QListWidget* m_listWidget;
    QHBoxLayout* m_layout;
    QList<Event> m_eventList;

    void updateListWidget();
};

#endif // CALENDAR_H
