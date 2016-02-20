#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class AboutDialog : public QDialog
{
    Q_OBJECT
public:
    AboutDialog(QWidget* parent = 0);
    ~AboutDialog();

private:
    QLabel* m_imageLabel;
    QLabel* m_headerLabel;
    QLabel* m_descriptionLabel;
    QPushButton* m_closeButton;
    QHBoxLayout* m_hboxLayout;
    QVBoxLayout* m_vboxLayout;
    QHBoxLayout* m_mainLayout;
};

#endif // ABOUTDIALOG_H
