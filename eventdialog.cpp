#include "eventdialog.h"

EventDialog::EventDialog(QWidget *parent) : QDialog(parent)
{    
    m_nameLine = new QLineEdit();
    m_descriptionEdit = new QTextEdit();
    m_timeEdit = new QTimeEdit();
    m_calendarWidget = new QCalendarWidget();
    m_buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    formLayout = new QFormLayout();
    formLayout->addRow(tr("Event name:"), m_nameLine);
    formLayout->addRow(tr("Event description:"), m_descriptionEdit);
    formLayout->addRow(tr("Time:"), m_timeEdit);

    verticalLayout = new QVBoxLayout();
    verticalLayout->addLayout(formLayout);
    verticalLayout->addWidget(m_calendarWidget);
    verticalLayout->addWidget(m_buttonBox);

    this->setLayout(verticalLayout);

    connect(m_buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(m_buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void EventDialog::accept()
{
    return_event.setName(m_nameLine->text());
    return_event.setDescription(m_descriptionEdit->toPlainText());
    return_event.setDateTime(QDateTime(m_calendarWidget->selectedDate(), m_timeEdit->time()));
    QDialog::accept();
}

Event EventDialog::getEvent() const
{
    return return_event;
}

void EventDialog::setDefault(const QString &name, const QString &description, const QDate &date, const QTime &time)
{
    m_nameLine->setText(name);
    m_descriptionEdit->setText(description);
    m_calendarWidget->setSelectedDate(date);
    m_timeEdit->setTime(time);
}
