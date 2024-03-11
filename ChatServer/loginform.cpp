#include "loginform.h"
#include "ui_loginform.h"
#include <QTimer>
#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    auto timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &LoginForm::databaseConnect);
    timer->start(10);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_buttonBox_accepted()
{
    QString query = "select login, password from chatdb.admins where login = \'" +
            ui->loginEdit->text() + "\'";

    QSqlQuery runQuery(query, m_PsqlDb);
    //emit accepted();

        while (runQuery.next())
        {
            m_username = runQuery.value(0).toString();
            m_password = runQuery.value(1).toString();
        }

       if (ui->loginEdit->text() == m_username
               && ui->passwordEdit->text() == m_password)
       {
           runQuery.clear();
           m_PsqlDb.close();
           emit accepted();
       }
       else
       {
           runQuery.clear();
           QMessageBox::critical(this, "Error", "Wrong username or password!");
       }
}


void LoginForm::on_buttonBox_rejected()
{
    emit rejected();
}

void LoginForm::databaseConnect()
{
    if (m_dbConnected)
    {
        ui->databaseLabel->setText("<font color='green'>Database Connected</font>");
        return;
    }
    ui->databaseLabel->setText("<font color='red'>Database Not Connected</font>");
    m_PsqlDb = QSqlDatabase::addDatabase("QPSQL");
    m_PsqlDb.setHostName("127.0.0.1");
    m_PsqlDb.setPort(5432);
    m_PsqlDb.setDatabaseName("template1");
    m_PsqlDb.setUserName("postgres");
    m_dbConnected = m_PsqlDb.open();

}

