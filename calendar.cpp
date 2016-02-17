#include "calendar.h"
#include <QDebug>

Calendar::Calendar(QWidget *parent) : QWidget(parent)
{
    m_listWidget = new QListWidget(this);
    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_listWidget);
    this->setLayout(m_layout);
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
            m_eventList.push_back(tmpEvent);
            qDebug() << "Pushed";
        }

        updateListWidget();
    }
}

void Calendar::editEvent()
{

    int index = m_listWidget->currentIndex().row();
    if(index < 0 || index >= m_eventList.size())
        return;

    Event tmpEvent = m_eventList.at(index);

    EventDialog dialog(this);
    dialog.setModal(true);
    dialog.setDefault(tmpEvent.name(), tmpEvent.description(), tmpEvent.dateTime().date(), tmpEvent.dateTime().time());

    if(dialog.exec() == QDialog::Accepted)
    {
        tmpEvent = dialog.getEvent();

        if((!tmpEvent.name().isEmpty()) && (!tmpEvent.description().isEmpty()))
        {
            m_eventList.removeAt(index);
            m_eventList.push_back(tmpEvent);
        }

        updateListWidget();
    }
}

void Calendar::removeEvent()
{
    int index = m_listWidget->currentIndex().row();
    if(index < 0 || index >= m_eventList.size())
        return;

    m_eventList.removeAt(index);

    updateListWidget();
}

void Calendar::updateListWidget()
{
    m_listWidget->clear();
    qSort(m_eventList);
    foreach(Event e, m_eventList)
    {
        m_listWidget->addItem(e.name() + "\n" + e.dateTime().date().toString("dd-MM-yyyy") + " Godz: " + e.dateTime().time().toString("h:mm:ss") + "\n" + e.description());
    }
    qDebug() << "List contains " << m_listWidget->count() << " elements";
}
