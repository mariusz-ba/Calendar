#include "listdelegate.h"
#include <QPainter>

ListDelegate::ListDelegate()
{
}

ListDelegate::~ListDelegate()
{
}

void ListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);

    QFont headerFont = QApplication::font();
    QFont dateFont = QApplication::font();
    QFont descFont = QApplication::font();

    headerFont.setBold(true);
    headerFont.setPixelSize(16);
    dateFont.setItalic(true);
    QFontMetrics fm(headerFont);
    QFontMetrics fmd(dateFont);


    QString headerText = qvariant_cast<QString>(index.model()->index(index.row(), 1).data());
    QString descText = qvariant_cast<QString>(index.model()->index(index.row(), 2).data());
    QString dateText = qvariant_cast<QString>(index.model()->index(index.row(), 3).data());

    QRect headerRect = option.rect;
    QRect dateRect = option.rect;
    dateRect.setHeight(fmd.height()+2);
    QRect descRect = option.rect;

    headerRect.setTop(headerRect.top()+2);
    headerRect.setLeft(headerRect.left()+2);
    headerRect.setBottom(headerRect.top()+fm.height()+2);

    dateRect.setTop(headerRect.bottom()+1);
    dateRect.setLeft(headerRect.left());
    dateRect.setBottom(dateRect.top()+fmd.height());

    descRect.setTop(dateRect.bottom()+1);
    descRect.setLeft(dateRect.left());

    painter->setFont(headerFont);
    painter->drawText(headerRect, headerText);

    painter->setFont(dateFont);
    painter->drawText(dateRect, dateText);

    painter->setFont(descFont);
    painter->drawText(descRect, descText);

    painter->restore();
}

QSize ListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QFont font = QApplication::font();
    QFontMetrics fm(font);
    return QSize(option.rect.width(), fm.height()+50);
}
