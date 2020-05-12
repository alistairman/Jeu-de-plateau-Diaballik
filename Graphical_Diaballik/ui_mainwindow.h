/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QLabel *Player1;
    QLabel *Player2;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *currentPlayer;
    QPushButton *move;
    QLabel *label_move;
    QLabel *label_passe;
    QLabel *label_selected;
    QPushButton *passe;
    QPushButton *cancel;
    QMenuBar *menubar;
    QMenu *menuml;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Player1 = new QLabel(centralwidget);
        Player1->setObjectName(QString::fromUtf8("Player1"));
        Player1->setGeometry(QRect(210, 20, 58, 16));
        Player2 = new QLabel(centralwidget);
        Player2->setObjectName(QString::fromUtf8("Player2"));
        Player2->setGeometry(QRect(530, 20, 58, 16));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 60, 711, 231));
        tableWidget->setMouseTracking(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 20, 21, 16));
        currentPlayer = new QLabel(centralwidget);
        currentPlayer->setObjectName(QString::fromUtf8("currentPlayer"));
        currentPlayer->setGeometry(QRect(40, 310, 251, 16));
        move = new QPushButton(centralwidget);
        move->setObjectName(QString::fromUtf8("move"));
        move->setGeometry(QRect(30, 350, 112, 32));
        label_move = new QLabel(centralwidget);
        label_move->setObjectName(QString::fromUtf8("label_move"));
        label_move->setGeometry(QRect(340, 310, 58, 16));
        label_passe = new QLabel(centralwidget);
        label_passe->setObjectName(QString::fromUtf8("label_passe"));
        label_passe->setGeometry(QRect(340, 430, 58, 16));
        label_selected = new QLabel(centralwidget);
        label_selected->setObjectName(QString::fromUtf8("label_selected"));
        label_selected->setGeometry(QRect(590, 310, 58, 16));
        passe = new QPushButton(centralwidget);
        passe->setObjectName(QString::fromUtf8("passe"));
        passe->setGeometry(QRect(30, 400, 112, 32));
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(30, 450, 112, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuml = new QMenu(menubar);
        menuml->setObjectName(QString::fromUtf8("menuml"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuml->menuAction());
        menuml->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        Player1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Player2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "VS", nullptr));
        currentPlayer->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        move->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_move->setText(QCoreApplication::translate("MainWindow", "move:", nullptr));
        label_passe->setText(QCoreApplication::translate("MainWindow", "passe:", nullptr));
        label_selected->setText(QCoreApplication::translate("MainWindow", "Selected:", nullptr));
        passe->setText(QCoreApplication::translate("MainWindow", "Passe", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        menuml->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
