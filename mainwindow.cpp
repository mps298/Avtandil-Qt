#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Crypter.h"
#include "loginpassworddialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug()<< "file path = "<<fileNameString;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_findPasswordPushButton_clicked()
{
    if (myPasswords.isEmpty() == false)
    {
        myPasswords.clear();
    }

    openDataSlot();

    QStringList keysList = myPasswords.keys();

    if (keysList.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText(tr("No passwords saved"));
        msgBox.sizeHint();
        msgBox.exec();
        return;
    }

    bool ok;

    QString keySelectedString = QInputDialog::getItem(this, tr("Choose service"), tr("Service:"), keysList, 0, false, &ok);

    if (ok)
    {
        currentKeyString = keySelectedString;

        auto it = myPasswords.find(currentKeyString);

        if (it == myPasswords.end())
        {
            QMessageBox msgBox;
            msgBox.setText(tr("No service found"));
            msgBox.sizeHint();
            msgBox.exec();
            return;
        }

        currentLoginString = it.value().first;
        currentPasswordString = it.value().second;
        showPasswordSlot();
    }
}

void MainWindow::on_createPasswordPushButton_clicked()
{
    currentKeyString = createNameSlot();
    if (currentKeyString!=QString())
    {
        createPasswordSlot(currentKeyString);
    }
}

void MainWindow::on_printAllPushButton_clicked()
{
    if (myPasswords.isEmpty())
    {

        QMessageBox msgBox;
        msgBox.setText(tr("No passwords saved"));
        msgBox.sizeHint();
        msgBox.exec();
        return;
    }
    if (QMessageBox::No == QMessageBox::question(this, tr("Save as a text"),
                                                 tr("Your database will be saved in a text file and therefore may be compromized if anyone else gets access to this file\nAre you sure?"),
                                                 QMessageBox::Yes|QMessageBox::No))
    {
        return;
    }

    QString fileToSaveNameStr = QFileDialog::getSaveFileName(this, tr("Save database to file"), "Avtandil_passwords.txt", "*txt");

    if (fileToSaveNameStr == QString())
    {
        return;
    }

    QFile file(fileToSaveNameStr);
    QTextStream stream(&file);

    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Oops, something's wrong, try again"));
        msgBox.sizeHint();
        msgBox.exec();
        return;
    }

    auto it = myPasswords.begin();
    while (it != myPasswords.end())
    {
        stream << it.key() <<"\n"
               << tr("login/email: ") << it.value().first <<"\n"
               << tr("password: ") <<it.value().second <<"\n\n";
        ++it;
    }

    stream.flush();
    file.close();

    if (QMessageBox::Yes == QMessageBox::question(this, tr("Database saved"),
                                                  tr("Your database is saved as a text file\nDo you want it to be deleted when the application is closed?"),
                                                  QMessageBox::Yes|QMessageBox::No))
    {
        textFileToDelete = fileToSaveNameStr;
        textFilemustBeDeleted = true;
    }
    else
    {
        textFileToDelete = QString();
        textFilemustBeDeleted = false;
    }

}

void MainWindow::saveDataSlot()
{
    qDebug()<<"saveDataSlot works";

    if (QMessageBox::No == QMessageBox::question(this, tr("Save changes"),
                                                 tr("Do you wand to save changes?"),
                                                 QMessageBox::Yes|QMessageBox::No))
    {
        return;
    }

    QFile file(fileNameString);
    if (file.open(QIODevice::WriteOnly))
    {
        QMap<QString, QPair<QString, QString>> dataToSaveMap = QMap<QString, QPair<QString, QString>>();

        auto it = myPasswords.begin();
        while (it!=myPasswords.end())
        {
            dataToSaveMap.insert(Crypter::cryptString(it.key()), QPair<QString, QString>(Crypter::cryptString(it.value().first), Crypter::cryptString(it.value().second)));
            ++it;
        }

        int dataToSavePIN = Crypter::cryptInt(myPin);

        QDataStream out(&file);
        out << (int)dataToSavePIN;
        out << (QMap<QString, QPair<QString, QString>>)dataToSaveMap;

        file.flush();
        file.close();
    }
    else {
        qDebug()<<"No file open to write";
    }
}

void MainWindow::openDataSlot()
{
    qDebug()<<"openDataSlot works";

    QFile file(fileNameString);
    if (file.open(QIODevice::ReadOnly))
    {
        QMap<QString, QPair<QString, QString>> dataToOpenMap = QMap<QString, QPair<QString, QString>>();
        int datatoOpenPIN = 0;
        myPasswords = QMap<QString, QPair<QString, QString>>();
        myPin = 0;


        QDataStream in(&file);
        in >> datatoOpenPIN >> dataToOpenMap;
        qDebug()<<"datatoOpenPIN = "<<datatoOpenPIN;
        qDebug()<<"dataToOpenMap = "<<dataToOpenMap;

        auto it = dataToOpenMap.begin();
        while (it!=dataToOpenMap.end())
        {
            myPasswords.insert(Crypter::decryptString(it.key()), QPair<QString, QString>(Crypter::decryptString(it.value().first), Crypter::decryptString(it.value().second)));
            ++it;
        }

        myPin = Crypter::decryptInt(datatoOpenPIN);

        file.flush();
        file.close();
    }
    else {
        qDebug()<<"No file open to read";
    }
}

QString MainWindow::createNameSlot()
{
    bool ok;
    QString textEnteredString = QString();

    do
    {
        textEnteredString = QInputDialog::getText(this, tr("Name of service"), tr("Enter name of service:"),
                                                  QLineEdit::Normal, "", &ok);
        while (ok && textEnteredString.isEmpty())
        {
            QMessageBox msgBox;
            msgBox.setText(tr("Name of service cannot be empty!"));
            msgBox.sizeHint();
            msgBox.exec();
        }

        if (ok)
        {
            textEnteredString = textEnteredString.toLower();
            textEnteredString = textEnteredString.simplified();
            textEnteredString[0] = textEnteredString[0].toUpper();
        }
        else
        {
            return QString();
        }

        if (myPasswords.find(textEnteredString) != myPasswords.end())
        {

            qDebug()<<"name exists";
            QMessageBox msgBox;
            msgBox.setText(tr("Service") + textEnteredString + tr(" already exists, choose another name"));
            msgBox.sizeHint();
            msgBox.exec();
        }
    }
    while (myPasswords.find(textEnteredString) != myPasswords.end());

    return  textEnteredString;
}

void MainWindow::pinSlot()
{
    if(QFile(fileNameString).exists())
    {
        qDebug()<<fileNameString<<"exists";
        openDataSlot();
        checkPinSlot();
    }
    else
    {
        qDebug()<<fileNameString<<"doesn't exist";
        createPinSlot();
    }

    oldToNewSlot();
}

void MainWindow::checkPinSlot()
{
    qDebug()<<"checkPinSlot works";
    qDebug()<<"pinAttemptsLeft = "<<pinAttemptsLeft;
    qDebug()<<"myPin = "<<myPin;

    if (myPin == 0)
    {
        qDebug()<<"myPin = 0";
        createPinSlot();
    }

    bool ok;

    QString attemptsLeftString = QString();

    if (pinAttemptsLeft < 3)
    {
        attemptsLeftString += tr("\nAttempts left: ") + QString::number(pinAttemptsLeft);
    }

    QString textEnteredString = QInputDialog::getText(this, tr("PIN-code"), tr("Enter your PIN") + attemptsLeftString, QLineEdit::Password, "", &ok);
    if (ok)
    {
        if (textEnteredString.toInt() != myPin)
        {
            pinAttemptsLeft--;

            if (pinAttemptsLeft == 0)
            {
                qDebug()<<"pinAttemptsLeft == 0!!!";
                wrongPinSlot();
            }
            checkPinSlot();
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText(tr("No PIN - no passwords, goodbye!"));
        msgBox.sizeHint();
        msgBox.exec();
        //    abort();
        if (textFilemustBeDeleted || textFileToDelete!=QString())
        {
            QFile::remove(textFileToDelete);
        }

        exit(100500);
    }
    pinAttemptsLeft = 3;
}

void MainWindow::createPinSlot()
{
    qDebug()<<"createPinSlot works";

    bool ok;

    int intEntered = -1;

    do
    {
        intEntered = QInputDialog::getInt(this, tr("PIN-code"), tr("Create a PIN-code:"), 1000, 1000, 9999, 1, &ok);

        if (ok == false)
        {
            pinAttemptsLeft--;
            if (pinAttemptsLeft)
            {
            QMessageBox msgBox;
            msgBox.setText(tr("PIN-code must be created"));
            msgBox.sizeHint();
            msgBox.exec();
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText(tr("Ok, goodbye then..."));
                msgBox.sizeHint();
                msgBox.exec();
                exit(100500);
            }
        }
    }
    while (ok == false);

    myPin = intEntered;

    QMessageBox msgBox;
    msgBox.setText(tr("Your PIN-code is ") + QString::number(myPin) + tr(", don't forget it!"));
    msgBox.sizeHint();
    msgBox.exec();

}

void MainWindow::wrongPinSlot()
{
    QMessageBox msgBox;
    msgBox.setText(tr("Wrong PIN-code, goodbye!"));
    msgBox.sizeHint();
    msgBox.exec();
    //    abort();
    if (textFilemustBeDeleted || textFileToDelete!=QString())
    {
        QFile::remove(textFileToDelete);
    }

    exit(100500);
}

void MainWindow::createPasswordSlot(const QString &myKey, const QString &myLogin, const QString &myPassword)
{
    qDebug()<<"createPasswordslot works!";
    qDebug()<<"myKey = "<<myKey;
    qDebug()<<"myLogin = "<<myLogin;
    qDebug()<<"myPassword = "<<myPassword;

    if (currentKeyString!=myKey)    {
        currentKeyString = myKey;
    }
    if (currentLoginString!=myLogin)    {
        currentLoginString = myLogin;
    }
    if (currentPasswordString!=myPassword)  {
        currentPasswordString = myPassword;
    }

    LoginPasswordDialog loginPasswordInputDialog;
    loginPasswordInputDialog.setWindowTitle(myKey);
    loginPasswordInputDialog.setLoginString(myLogin);
    loginPasswordInputDialog.setPasswordString(myPassword);

    if (loginPasswordInputDialog.exec() == QDialog::Accepted)
    {
        currentLoginString = loginPasswordInputDialog.getLoginString();
        currentPasswordString = loginPasswordInputDialog.getPasswordString();

        auto it = myPasswords.find(currentKeyString);

        if (it != myPasswords.end())
        {
            myPasswords.erase(it);
        }

        myPasswords.insert(currentKeyString, QPair<QString, QString>(currentLoginString, currentPasswordString));
        saveDataSlot();
        showPasswordSlot();
    }
    else /*if (loginPasswordInputDialog.exec() == QDialog::Rejected)*/
    {
        currentLoginString = loginPasswordInputDialog.getLoginString();
        currentPasswordString = generatePasswordSlot();
        loginPasswordInputDialog.setPasswordString(currentPasswordString);
        createPasswordSlot(currentKeyString, currentLoginString, currentPasswordString);

    }
    //    else
    //    {
    //        currentKeyString = QString();
    //        currentPasswordString = QString();
    //        currentPasswordString = QString();
    //        return;
    //    }
}

QString MainWindow::generatePasswordSlot()
{
    QString passwordGeneratedString = QString();
    passwordGeneratedString.append('a' + qrand()%26);
    passwordGeneratedString.append('A' + qrand()%26);
    passwordGeneratedString.append('0' + qrand()%10);
    passwordGeneratedString.append('!' + qrand()%15);

    while (passwordGeneratedString.length() < 15)
    {
        switch (qrand()%5) {
        case 0: case 1: passwordGeneratedString.append('a' + qrand()%26); break;
        case 2: case 3: passwordGeneratedString.append('A' + qrand()%26); break;
        case 4: passwordGeneratedString.append('0' + qrand()%10); break;

        default:
            break;
        }
    }
    qDebug()<<"password before shuffling = "<<passwordGeneratedString;

    std::random_shuffle(passwordGeneratedString.begin(), passwordGeneratedString.end());
    qDebug()<<"password after shuffling = "<<passwordGeneratedString;

    return passwordGeneratedString;
}

void MainWindow::showPasswordSlot()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(currentKeyString);
    QString textString = QString();
    textString += "Login/email: ";
    textString += currentLoginString;
    textString += "\nPassword: ";
    textString += currentPasswordString;
    msgBox.setText(textString);

    QPushButton* okButton = msgBox.addButton(tr("Ok"), QMessageBox::AcceptRole);
    QPushButton* copyPasswordButton = msgBox.addButton(tr("Copy to clipboard"), QMessageBox::ActionRole);
    QPushButton* changePasswordButton = msgBox.addButton(tr("Change login/password"), QMessageBox::ActionRole);
    msgBox.sizeHint();
    msgBox.exec();

    if (msgBox.clickedButton() == changePasswordButton)
    {
        createPasswordSlot(currentKeyString, currentLoginString, currentPasswordString);
    }
    else if (msgBox.clickedButton() == copyPasswordButton)
    {
        QApplication::clipboard()->setText(currentPasswordString);
        currentKeyString = QString();
        currentLoginString = QString();
        currentPasswordString = QString();
    }
    else if (msgBox.clickedButton() == okButton)
    {
        currentKeyString = QString();
        currentLoginString = QString();
        currentPasswordString = QString();
    }
}

void MainWindow::on_changePinPushButton_clicked()
{
    static bool cancelClicked = false;

    qDebug()<<"changePinSlot works";

    if (myPin == 0)
    {
        qDebug()<<"myPin = 0";
        createPinSlot();
    }

    bool ok;

    QString attemptsLeftString = QString();

    if (pinAttemptsLeft < 3)
    {
        attemptsLeftString += tr("\nAttempts left: ") + QString::number(pinAttemptsLeft);
    }

    QString textEnteredString = QInputDialog::getText(this, tr("PIN-code"), tr("Enter your current PIN") + attemptsLeftString, QLineEdit::Password,
                                                      "", &ok);
    qDebug()<<"ok = "<< ok;

    if (ok)
    {
        qDebug()<<"ok pressed";
        if (textEnteredString.toInt() != myPin)
        {
            pinAttemptsLeft--;

            if (pinAttemptsLeft == 0)
            {
                qDebug()<<"pinAttemptsLeft == 0!!!";
                wrongPinSlot();
            }
            on_changePinPushButton_clicked();
        }
    }
    else
    {
        //        pinAttemptsLeft--;

        //        if (pinAttemptsLeft == 0)
        //        {
        //            qDebug()<<"pinAttemptsLeft == 0!!!";
        //            wrongPinSlot();
        //        }
        //        checkPinSlot();
        cancelClicked = true;
        qDebug()<<"cancel pressed";
        pinAttemptsLeft = 3;
        return;
    }

    pinAttemptsLeft = 3;

    if (cancelClicked)  {   return; }

    ok = false;
    int intEntered = QInputDialog::getInt(this, tr("PIN-code"),
                                          tr("Create a new PIN-code:"), 1000, 1000, 9999, 1, &ok);
    if (ok)
    {
        myPin = intEntered;
        saveDataSlot();
    }
}

void MainWindow::on_deletePasswordPushButton_clicked()
{
    QStringList keysList = myPasswords.keys();

    if (keysList.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText(tr("No passwords saved"));
        msgBox.sizeHint();
        msgBox.exec();
        return;
    }

    bool ok;

    QString keySelectedString = QInputDialog::getItem(this, tr("Choose service"), tr("Service:"), keysList, 0, false, &ok);

    if (ok)
    {
        if (QMessageBox::No == QMessageBox::question(this, tr("Delete a password"),
                                                     tr("Your login and password for ") + keySelectedString +
                                                     tr(" will be deleted\nAre you sure?"),
                                                     QMessageBox::Yes|QMessageBox::No))
        {
            return;
        }

        if (myPasswords.find(keySelectedString) == myPasswords.end())
        {
            QMessageBox msgBox;
            msgBox.setText(tr("Oops, deleting failure!"));
            msgBox.sizeHint();
            msgBox.exec();
            return;
        }

        myPasswords.remove(keySelectedString);

        if (myPasswords.find(keySelectedString) == myPasswords.end())
        {
            QMessageBox msgBox;
            msgBox.setText(tr("Deleted successfully!"));
            msgBox.sizeHint();
            msgBox.exec();
            saveDataSlot();
        }
    }

}

void MainWindow::oldToNewSlot()
{
    if (QFile(oldFileNameString).exists())
    {
        if (QMessageBox::No == QMessageBox::question(this, tr("Rewrite the database"),
                                                     tr("Your old database is found\nDo you want to use it?\n"
                                                        "You will be offered to fill a login/email field for each service"),
                                                     QMessageBox::Yes|QMessageBox::No))
        {
            return;
        }

        QFile file(oldFileNameString);
        if (file.open(QIODevice::ReadOnly))
        {
            QMap<QString, QString> oldDataMap = QMap<QString, QString>();
            int oldPin = 0;

            QDataStream in(&file);
            in >> oldPin >> oldDataMap;

            myPasswords.clear();

            auto it = oldDataMap.begin();
            while (it!=oldDataMap.end())
            {
                createPasswordSlot(Crypter::decryptString(it.key()), QString(), Crypter::decryptString(it.value()));
                ++it;
            }

            file.flush();
            file.close();
            qDebug()<<"delete succesfull = "<<QFile::remove(oldFileNameString);

            saveDataSlot();
        }
        else {
            qDebug()<<"No old file open to read";
        }
    }
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();

    if (textFilemustBeDeleted)
    {
        QFile::remove(textFileToDelete);
    }

    saveDataSlot();

    event->accept();
}
