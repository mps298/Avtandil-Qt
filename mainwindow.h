#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCloseEvent>
#include <QMap>
#include <QFile>
#include <QFileDialog>
#include <QDataStream>
#include <QIntValidator>
#include <QClipboard>
#include <QInputDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include <QPair>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QMap<QString, QPair<QString, QString>> myPasswords = QMap<QString, QPair<QString, QString>>();
    int myPin = 0;
    int pinAttemptsLeft = 3;


    QString currentKeyString = QString();
    QString currentLoginString = QString();
    QString currentPasswordString = QString();
    const QString fileNameString = QString("%1/avtandil1956_LP.dat").arg(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    const QString oldFileNameString = QString("%1/avtandil1956.dat").arg(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));

    bool textFilemustBeDeleted = false;
    QString textFileToDelete = QString();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void pinSlot(); // main() checks whether checkPinSlot or createPinSlot must work when the app starts

private slots:
    void on_findPasswordPushButton_clicked();
    void on_createPasswordPushButton_clicked();
    void on_printAllPushButton_clicked();

    void saveDataSlot();
    void openDataSlot();

    QString createNameSlot();

    void checkPinSlot();
    void createPinSlot();
    void wrongPinSlot();

    void createPasswordSlot(const QString &myKey, const QString &myLogin = QString(), const QString &myPassword = QString());
    QString generatePasswordSlot();
    void showPasswordSlot();


    void on_changePinPushButton_clicked();
    void on_deletePasswordPushButton_clicked();

    void oldToNewSlot();

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    virtual void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
