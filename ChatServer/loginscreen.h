#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>


namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();


public slots:
    void OnLoggedIn();
    void OnRejectRequested();
private:
    Ui::LoginScreen *ui;

};

#endif // LOGINSCREEN_H
