#ifndef LISTDELEGATE_H
#define LISTDELEGATE_H

#include <QObject>
#include <QApplication>
#include <QStyledItemDelegate>

class ListDelegate : public QStyledItemDelegate
{
public:
    ListDelegate();
    virtual ~ListDelegate();

    enum DataRole {HeaderTextRole = Qt::UserRole + 100,
                   DateTextRole = Qt::UserRole + 101,
                   DescriptionTextRole = Qt::UserRole + 102};

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    //QSqlTableModel* m_tableModel;
};

#endif // LISTDELEGATE_H
