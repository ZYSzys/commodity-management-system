#include "login.h"
#include "ui_login.h"

#include <QMessageBox>
#include <QTextCodec>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Login::on_pushButton_clicked()
{
  if(this->ui->txtname->text().trimmed()== tr("admin") &&
     this->ui->txtpwd->text().trimmed()==tr("admin"))
  {
      accept();
  }
  else
  {
      //QTextCodec::setCodecForTr( QTextCodec::codecForName("GBK") );
      QMessageBox::warning(this,tr("警告"),tr("用户名或密码错误!"),QMessageBox::Yes);
      this->ui->txtname->clear();
      this->ui->txtpwd->clear();
      this->ui->txtname->setFocus();
  }
}

void Login::on_pushButton_2_clicked()
{
    this->close();
}
