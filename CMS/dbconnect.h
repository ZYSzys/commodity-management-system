#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DbConnect;
}

class DbConnect: public QDialog
{
    Q_OBJECT
public:
    explicit DbConnect(QWidget *parent = 0);
    ~DbConnect();

    void createDB();

private slots:
    void on_submit_clicked();
    void on_cancel_clicked();

private:
    Ui::DbConnect *ui;
};

#endif // DBCONNECT_H
