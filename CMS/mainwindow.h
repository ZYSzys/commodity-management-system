#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QGroupBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QListWidget>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //explicit MainWindow(QWidget *parent = 0);
    MainWindow(const QString &commodityTable, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void changeComView(QModelIndex index);
    void removeComFromComModel();
    void searchSlot();
    void returnSlot();
    void addNewSlot();
    void addNewToTable();
    void cancelBtnSlot();
    void clearSlot();
    void quitBtnSlot();

private:
    QGroupBox *createComGroup();
    QGroupBox *createDetailGroup();
    QSqlTableModel *comModel;
    QTableView *comView;
    QListWidget *showList;
    QListWidgetItem *item;
    QLineEdit *seLineEdit;
    QLineEdit *idLineEdit;
    QLineEdit *categoryLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *originLineEdit;
    QLineEdit *countLineEdit;
    QLineEdit *priceLineEdit;
    QLineEdit *qualityLineEdit;
};

#endif // MAINWINDOW_H
