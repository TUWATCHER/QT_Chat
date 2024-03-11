#include "loginscreen.h"
#include "ui_loginscreen.h"

LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    connect(ui->loginForm, &LoginForm::accepted, this, &LoginScreen::OnLoggedIn);
    connect(ui->loginForm, &LoginForm::rejected, this, &LoginScreen::OnRejectRequested);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::OnLoggedIn()
{
    accept();
}

void LoginScreen::OnRejectRequested()
{
    reject();
}
