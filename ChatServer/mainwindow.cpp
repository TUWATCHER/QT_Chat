#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginscreen.h"
#include <QDialog>
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::databaseConnect);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow *MainWindow::createServer()
{
   LoginScreen login;

   auto result = login.exec();
   if (result == QDialog::Rejected)
   {
       return nullptr;
   }
   auto mainWindow = new MainWindow();
   mainWindow->setAttribute(Qt::WA_DeleteOnClose);

   return mainWindow;
}


void MainWindow::on_actionExit_triggered()
{
    m_PsqlDb.commit();
    m_PsqlDb.close();
    this->close();
}

void MainWindow::databaseConnect()
{
    if (m_dbconnected)
    {
        ui->dataBaseConnectionLabel->setText
                ("<font color='green'>Database Connected</font>");
        return;
    }
    ui->dataBaseConnectionLabel->setText
            ("<font color='red'>Database Not Connected</font>");
    m_PsqlDb = QSqlDatabase::addDatabase("QPSQL");
    m_PsqlDb.setHostName("127.0.0.1");
    m_PsqlDb.setPort(5432);
    m_PsqlDb.setDatabaseName("template1");
    m_PsqlDb.setUserName("postgres");
    m_dbconnected = m_PsqlDb.open();
}

void MainWindow::getUsers()
{
    m_userModel = new QSqlRelationalTableModel(this, m_PsqlDb);
    m_userModel->setTable("chatdb.usertb");
    m_userModel->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);
    m_userModel->select();
    m_userModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    m_userModel->setHeaderData(1, Qt::Horizontal, tr("USERNAME"));
    m_userModel->setHeaderData(3, Qt::Horizontal, tr("ENABLED"));
    m_userModel->setHeaderData(4, Qt::Horizontal, tr("BANNED"));

    ui->usersTableView->setModel(m_userModel);
    ui->usersTableView->hideColumn(2);
    ui->usersTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->usersTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->usersTableView->horizontalHeader()->setStretchLastSection(true);
    ui->usersTableView->show();

    ui->usersUpdateButton->setText("Reset");

}


MainWindow* MainWindow::on_actionLog_Out_triggered()
{
    LoginScreen login;
    this->close();
    auto result = login.exec();
    if (result == QDialog::Rejected)
    {
        return nullptr;
    }
    auto mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose);

    return mainWindow;
}


void MainWindow::on_usersUpdateButton_clicked()
{
    getUsers();
}


void MainWindow::on_applyButton_clicked()
{
    m_userModel->submitAll();
    m_PsqlDb.commit();
}


void MainWindow::on_deleteUser_clicked()
{
    QModelIndexList selectedRows = ui->usersTableView->
            selectionModel()->selectedRows();
    if(!selectedRows.isEmpty())
    {
        int rowToDelete = selectedRows.first().row();
        m_userModel->removeRow(rowToDelete);
    }

}


void MainWindow::on_messageUpdateButton_clicked()
{
    m_messageModel = new QSqlRelationalTableModel(this, m_PsqlDb);
    m_messageModel->setTable("chatdb.messagetb");
    m_messageModel->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);
    m_messageModel->select();
    m_messageModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    m_messageModel->setHeaderData(1, Qt::Horizontal, tr("FROM"));
    m_messageModel->setHeaderData(3, Qt::Horizontal, tr("TO"));
    m_messageModel->setHeaderData(4, Qt::Horizontal, tr("TEXT"));

    ui->messagesTableView->setModel(m_messageModel);
    ui->messagesTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->messagesTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->messagesTableView->horizontalHeader()->setStretchLastSection(true);
    ui->messagesTableView->show();

    ui->messageUpdateButton->setText("Reset");
}


void MainWindow::on_deleteMessageButton_clicked()
{
    QModelIndexList selectedRows = ui->messagesTableView->
            selectionModel()->selectedRows();
    if(!selectedRows.isEmpty())
    {
        int rowToDelete = selectedRows.first().row();
        m_messageModel->removeRow(rowToDelete);
    }
}


void MainWindow::on_messageApplyButton_clicked()
{
    m_messageModel->submitAll();
    m_PsqlDb.commit();
}

