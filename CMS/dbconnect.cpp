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
    QStringList drivers = QSqlDatabase::drivers();
    ui->dbComboBox->addItems(drivers);
    ui->status_Label->setText(tr("Connecting to database"));
}

DbConnect::~DbConnect()
{
    delete ui;
}

void DbConnect::on_submit_clicked()
{
    if(ui->dbComboBox->currentText().isEmpty())
    {
        ui->status_Label->setText(tr("Please choose a sql driver"));
        ui->dbComboBox->setFocus();
    }
    else if(ui->dbComboBox->currentText() == "QSQLITE")
    {
        createDB();
        accept();
    }
    else
    {
        QMessageBox::information(this, tr("SQL"), tr("Sorry, only QSQLITE avaliable!"));
    }
}

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

    QSqlQuery q;
    bool success = q.exec("create table commodity(id int primary key, category varchar(40), name varchar(40), origin varchar(40), count int, price double, quality varchar(40))");
    if(success)
    {
        qDebug() << QObject::tr("Create commodity table successfully!");
    }
    q.exec(QObject::tr("insert into commodity values(1,'Food','Water','Hangzhou',10,2.0,'High')"));
    q.exec(QObject::tr("insert into commodity values(2,'Food','Milk','Hangzhou',10,7.0,'High')"));
    q.exec(QObject::tr("insert into commodity values(3,'Food','Apple','Hangzhou',10,10.0,'High')"));
}

void DbConnect::on_cancel_clicked()
{
    close();
}
