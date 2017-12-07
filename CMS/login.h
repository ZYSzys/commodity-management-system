#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
    class Login;
}

class Login : public QDialog {
    Q_OBJECT
public:
    Login(QWidget *parent = 0);
    ~Login();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Login *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // LOGIN_H
