#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   static MainWindow* createServer();

private slots:
   void on_actionExit_triggered();
   void databaseConnect();
   void getUsers();
   MainWindow* on_actionLog_Out_triggered();

   void on_usersUpdateButton_clicked();

   void on_applyButton_clicked();

   void on_deleteUser_clicked();

   void on_messageUpdateButton_clicked();

   void on_deleteMessageButton_clicked();

   void on_messageApplyButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_PsqlDb;
    bool m_dbconnected = false;
    QSqlRelationalTableModel* m_userModel;
    QSqlRelationalTableModel* m_messageModel;
};
#endif // MAINWINDOW_H
