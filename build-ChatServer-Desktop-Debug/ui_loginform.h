/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *loginLabel;
    QLabel *paswordLabel;
    QLineEdit *passwordEdit;
    QLineEdit *loginEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QLabel *databaseLabel;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QString::fromUtf8("LoginForm"));
        LoginForm->resize(400, 136);
        verticalLayout = new QVBoxLayout(LoginForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        loginLabel = new QLabel(LoginForm);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, loginLabel);

        paswordLabel = new QLabel(LoginForm);
        paswordLabel->setObjectName(QString::fromUtf8("paswordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, paswordLabel);

        passwordEdit = new QLineEdit(LoginForm);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordEdit);

        loginEdit = new QLineEdit(LoginForm);
        loginEdit->setObjectName(QString::fromUtf8("loginEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, loginEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(LoginForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        databaseLabel = new QLabel(LoginForm);
        databaseLabel->setObjectName(QString::fromUtf8("databaseLabel"));

        verticalLayout->addWidget(databaseLabel);

        QWidget::setTabOrder(loginEdit, passwordEdit);

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Chat Server Administrator Login", nullptr));
        loginLabel->setText(QCoreApplication::translate("LoginForm", "Login:", nullptr));
        paswordLabel->setText(QCoreApplication::translate("LoginForm", "Password", nullptr));
        databaseLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
