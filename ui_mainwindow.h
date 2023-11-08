/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *findPasswordPushButton;
    QPushButton *createPasswordPushButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *printAllPushButton;
    QPushButton *changePinPushButton;
    QPushButton *deletePasswordPushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(477, 167);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        findPasswordPushButton = new QPushButton(centralwidget);
        findPasswordPushButton->setObjectName(QString::fromUtf8("findPasswordPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(findPasswordPushButton->sizePolicy().hasHeightForWidth());
        findPasswordPushButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(findPasswordPushButton);

        createPasswordPushButton = new QPushButton(centralwidget);
        createPasswordPushButton->setObjectName(QString::fromUtf8("createPasswordPushButton"));
        sizePolicy.setHeightForWidth(createPasswordPushButton->sizePolicy().hasHeightForWidth());
        createPasswordPushButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(createPasswordPushButton);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        printAllPushButton = new QPushButton(centralwidget);
        printAllPushButton->setObjectName(QString::fromUtf8("printAllPushButton"));
        sizePolicy.setHeightForWidth(printAllPushButton->sizePolicy().hasHeightForWidth());
        printAllPushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(printAllPushButton);

        changePinPushButton = new QPushButton(centralwidget);
        changePinPushButton->setObjectName(QString::fromUtf8("changePinPushButton"));
        sizePolicy.setHeightForWidth(changePinPushButton->sizePolicy().hasHeightForWidth());
        changePinPushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(changePinPushButton);

        deletePasswordPushButton = new QPushButton(centralwidget);
        deletePasswordPushButton->setObjectName(QString::fromUtf8("deletePasswordPushButton"));
        sizePolicy.setHeightForWidth(deletePasswordPushButton->sizePolicy().hasHeightForWidth());
        deletePasswordPushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(deletePasswordPushButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Avtandil1956", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Choose action:", nullptr));
        findPasswordPushButton->setText(QCoreApplication::translate("MainWindow", "Find a password", nullptr));
        createPasswordPushButton->setText(QCoreApplication::translate("MainWindow", "Create a password", nullptr));
        printAllPushButton->setText(QCoreApplication::translate("MainWindow", "Save passwords as a text", nullptr));
        changePinPushButton->setText(QCoreApplication::translate("MainWindow", "Change PIN", nullptr));
        deletePasswordPushButton->setText(QCoreApplication::translate("MainWindow", "Delete a password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
