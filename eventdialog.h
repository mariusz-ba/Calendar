#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QCalendarWidget>
#include <QTimeEdit>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include "event.h"

class EventDialog : public QDialog
{
    Q_OBJECT
public:
    explicit EventDialog(QWidget *parent = 0);
    Event getEvent() const;
    void setDefault(const QString& name, const QString& description, const QDate& date, const QTime& time);

protected:
    void accept();

private:
    QLineEdit* m_nameLine;
    QTextEdit* m_descriptionEdit;
    QCalendarWidget* m_calendarWidget;
    QTimeEdit* m_timeEdit;
    QDialogButtonBox* m_buttonBox;

    QFormLayout* formLayout;
    QVBoxLayout* verticalLayout;

    Event return_event;
};

#endif // EVENTDIALOG_H
