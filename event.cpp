#include "event.h"

Event::Event(const QString& name, const QString& description, const QDateTime& dateTime)
    :m_name(name), m_description(description), m_dateTime(dateTime)
{
}

void Event::setName(const QString& name)
{
    m_name = name;
}

void Event::setDescription(const QString& desciption)
{
    m_description = desciption;
}

void Event::setDateTime(const QDateTime& dateTime)
{
    m_dateTime = dateTime;
}

QString Event::name() const
{
    return m_name;
}

QString Event::description() const
{
    return m_description;
}

QDateTime Event::dateTime() const
{
    return m_dateTime;
}

bool Event::operator <(const Event& other) const
{
    return (m_dateTime < other.dateTime());
}

