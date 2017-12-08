#include "dbconnect.h"
#include "ui_dbconnect.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QtDebug>
#include <QSqlQuery>

DbConnect::DbConnect(QWidget *parent):
    QDialog(parent),
    ui(new Ui::DbConnect)
{
    ui->setupUi(this);
    QStringList drivers = QSqlDatabase::drivers();//返回所有可用的数据库驱动的清单
    ui->dbComboBox->addItems(drivers);
    ui->status_Label->setText(tr("状态:"));
}

DbConnect::~DbConnect()
{
    delete ui;
}

void DbConnect::on_submit_clicked()//连接槽函数
{
    if(ui->dbComboBox->currentText().isEmpty())
    {
        ui->status_Label->setText(tr("Please choose a sql driver"));
        ui->dbComboBox->setFocus();
    }
    else if(ui->dbComboBox->currentText() == "QSQLITE")//使用sqlite数据库
    {
        createDB();
        accept();
    }
    else
    {
        QMessageBox::information(this, tr("SQL"), tr("Sorry, only QSQLITE avaliable!"));
    }
}
//创建数据库文件commodity.db并插入了5条记录初始化
void DbConnect::createDB()
{
    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"));
    db.setDatabaseName("commodity.db");
    db.open();
    if(!db.open())
    {
        err = db.lastError();
        qDebug() << err.text();
    }
    else
    {
        ui->status_Label->setText(tr("Create sqlite successfully!"));
    }

    QSqlQuery q;//数据库操作,执行数据库语句
    bool success = q.exec("create table commodity(id int primary key, category varchar(40), name varchar(40), origin varchar(40), count int, price double, quality varchar(40), exp varchar(40))");
    if(success)
    {
        qDebug() << QObject::tr("Create commodity table successfully!");
    }
    q.exec(QObject::tr("insert into commodity values(1,'Food','Water','Hangzhou',10,2.0,'High','12 months')"));
    q.exec(QObject::tr("insert into commodity values(2,'Food','Milk','Hangzhou',20,7.0,'High','7 days')"));
    q.exec(QObject::tr("insert into commodity values(3,'Food','Apple','Hangzhou',10,10.0,'High','1 week')"));
    q.exec(QObject::tr("insert into commodity values(4,'Digital','iPhone','America',50,7000,'High','12 months')"));
    q.exec(QObject::tr("insert into commodity values(5,'Book','C++ Primer','Beijing',100,99.99,'High','1 week')"));
    q.exec(QObject::tr("insert into commodity values(6,'Food','Coffee','Hangzhou',1000,10.0,'High','6 months')"));
    q.exec(QObject::tr("insert into commodity values(7,'Digital','Macbook','America',50,10000,'High','24 months')"));
    q.exec(QObject::tr("insert into commodity values(8,'Book','Thinking in Java','Beijing',500,49.99,'High','1 week')"));
}

void DbConnect::on_cancel_clicked()
{
    close();
}
