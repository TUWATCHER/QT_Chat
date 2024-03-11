#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

signals:
    void accepted();
    void rejected();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void databaseConnect();

private:
    Ui::LoginForm *ui;
    QSqlDatabase m_PsqlDb;
    bool m_dbConnected = false;
    QString m_username;
    QString m_password;
};

#endif // LOGINFORM_H
