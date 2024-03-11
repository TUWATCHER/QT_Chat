#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginscreen.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

