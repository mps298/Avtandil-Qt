#ifndef SHOWPASSWORDDIALOG_H
#define SHOWPASSWORDDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class ShowPasswordDialog : public QDialog
{
private:
    QLabel* loginLabel;
    QLabel* passwordLabel;

    QLabel* currentLoginLabel;
    QLabel* currentPasswordLabel;

    QPushButton* copyLoginButton;
    QPushButton* copyPasswordButton;

    QPushButton* okButton;
    QPushButton* generateButton;

    QGridLayout* myGridLayout;

public:
    ShowPasswordDialog();


};

#endif // SHOWPASSWORDDIALOG_H
