#ifndef DIALOG_H
#define DIALOG_H

#include <QAbstractTableModel>
#include <QString>

const int COLS= 3;
const int ROWS= 2;

class Dialog : public QAbstractTableModel
{
    Q_OBJECT
public:
    Dialog(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QString m_gridData[ROWS][COLS];

signals:
    void editCompleted(const QString &);

};

#endif // DIALOG_H
