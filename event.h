#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QDateTime>

class Event
{
public:
    Event(const QString& name = QString(), const QString& description = QString(), const QDateTime& dateTime = QDateTime());

    void setName(const QString& name);
    void setDescription(const QString& desciption);
    void setDateTime(const QDateTime& date);

    QString name() const;
    QString description() const;
    QDateTime dateTime() const;

    bool operator<(const Event& other) const;

private:
    QString m_name;
    QString m_description;
    QDateTime m_dateTime;
};

#endif // EVENT_H
