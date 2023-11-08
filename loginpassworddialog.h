#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class LoginPasswordDialog : public QDialog {
    Q_OBJECT
private:
    QLineEdit* loginLineEdit;
    QLineEdit* passwordLineEdit;
    QLabel* loginLabel;
    QLabel* passwordLabel;

    QPushButton* okButton;
    QPushButton* generateButton;

    QGridLayout* myGridLayout;

public:
    LoginPasswordDialog(/*QWidget* pwgt = 0*/);
    ~LoginPasswordDialog();

    QString getLoginString() const;
    QString getPasswordString () const;
    void setLoginString(const QString& loginStr);
    void setPasswordString(const QString& passwordStr);
};
#endif // INPUTDIALOG_H
