#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget* parent): QDialog(parent)
{
    m_imageLabel = new QLabel(this);
    m_headerLabel = new QLabel(tr("Calendar 1.0 (opensource)"), this);
    m_descriptionLabel = new QLabel(tr("Based on Qt 5.5.1 (MSVC 2013, 32 bit)\nThis is a simple calendar app connected to the SQLite database."), this);

    m_closeButton = new QPushButton(tr("Close"), this);
    connect(m_closeButton, SIGNAL(clicked()), this, SLOT(accept()));

    m_vboxLayout = new QVBoxLayout();
    m_vboxLayout->addWidget(m_headerLabel);
    m_vboxLayout->addWidget(m_descriptionLabel);

    m_hboxLayout = new QHBoxLayout();
    m_hboxLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    m_hboxLayout->addWidget(m_closeButton);

    m_vboxLayout->addLayout(m_hboxLayout);

    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->addWidget(m_imageLabel);
    m_mainLayout->addLayout(m_vboxLayout);

    QFont font = m_headerLabel->font();
    font.setBold(true);
    font.setPixelSize(16);
    m_headerLabel->setFont(font);

    QPixmap pixmap(":/img/Calendar.png");
    m_imageLabel->setMinimumSize(96,96);
    m_imageLabel->setPixmap(pixmap.scaled(QSize(m_imageLabel->width(), m_imageLabel->height()), Qt::KeepAspectRatio));
}

AboutDialog::~AboutDialog()
{
}
