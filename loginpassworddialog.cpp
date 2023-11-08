#include "loginpassworddialog.h"


LoginPasswordDialog::LoginPasswordDialog(/*QWidget* pwgt*/)
    : QDialog(/*pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint*/)
{
    loginLineEdit = new QLineEdit;
    passwordLineEdit  = new QLineEdit;

    loginLabel    = new QLabel("&Login: ");
    passwordLabel     = new QLabel("&Password: ");

    loginLabel->setBuddy(loginLineEdit);
    passwordLabel->setBuddy(passwordLineEdit);

    okButton     = new QPushButton("&Ok");
    generateButton = new QPushButton("&Generate password");


    connect(okButton, SIGNAL(clicked()), SLOT(accept()));
    connect(generateButton, SIGNAL(clicked()), SLOT(reject()));

    //Layout setup
    myGridLayout = new QGridLayout;
    myGridLayout->addWidget(loginLabel, 0, 0);
    myGridLayout->addWidget(passwordLabel, 1, 0);
    myGridLayout->addWidget(loginLineEdit, 0, 1);
    myGridLayout->addWidget(passwordLineEdit, 1, 1);
    myGridLayout->addWidget(okButton, 2,0);
    myGridLayout->addWidget(generateButton, 2, 1);
    setLayout(myGridLayout);

    setWindowFlags(Qt::Window
        | Qt::WindowMinimizeButtonHint
        | Qt::WindowMaximizeButtonHint
        | Qt::CustomizeWindowHint);

}

LoginPasswordDialog::~LoginPasswordDialog()
{
    if (myGridLayout) {   delete myGridLayout; myGridLayout = nullptr;    }

    if (loginLineEdit)  {   delete loginLineEdit; loginLineEdit = nullptr;    }
    if (passwordLineEdit)   {   delete passwordLineEdit; passwordLineEdit = nullptr;  }
    if (loginLabel)  {   delete loginLabel; loginLabel = nullptr;    }
    if (passwordLabel)   {   delete passwordLabel; passwordLabel = nullptr;    }
    if (okButton)   {   delete okButton; okButton = nullptr;    }
    if (generateButton) {   delete generateButton; generateButton = nullptr;    }
}

QString LoginPasswordDialog::getLoginString() const
{
    return loginLineEdit->text();
}

QString LoginPasswordDialog::getPasswordString() const
{
    return passwordLineEdit->text ();
}

void LoginPasswordDialog::setLoginString(const QString &loginStr)
{
    loginLineEdit->setText(loginStr);
}

void LoginPasswordDialog::setPasswordString(const QString &passwordStr)
{
    passwordLineEdit->setText(passwordStr);
}
