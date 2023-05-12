#include "dialog.h"


Dialog::Dialog(QObject *parent)
    : QAbstractTableModel(parent)
{

}

int Dialog::rowCount(const QModelIndex & /*parent*/) const
{
    return ROWS;
}

int Dialog::columnCount(const QModelIndex & /*parent*/) const
{
    return COLS;
}

QVariant Dialog::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole && checkIndex(index))
        return m_gridData[index.row()][index.column()];

    return QVariant();
}

bool Dialog::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole) {
        if (!checkIndex(index))
            return false;
        //save value from editor to member m_gridData
        m_gridData[index.row()][index.column()] = value.toString();
        //for presentation purposes only: build and emit a joined string
        QString result;
        for (int row = 0; row < ROWS; row++) {
            for (int col= 0; col < COLS; col++)
                result += m_gridData[row][col] + ' ';
        }
        emit editCompleted(result);
        return true;
    }
    return false;
}

Qt::ItemFlags Dialog::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

