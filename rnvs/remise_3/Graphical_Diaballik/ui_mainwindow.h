/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionPlaying_rules;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *Player1;
    QLabel *label;
    QLabel *Player2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *currentPlayer;
    QLabel *label_selected;
    QLabel *label_move;
    QLabel *label_passe;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *move;
    QPushButton *passe;
    QPushButton *cancel;
    QPushButton *endturn;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1679, 700);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionPlaying_rules = new QAction(MainWindow);
        actionPlaying_rules->setObjectName(QString::fromUtf8("actionPlaying_rules"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        Player1 = new QLabel(centralwidget);
        Player1->setObjectName(QString::fromUtf8("Player1"));

        horizontalLayout->addWidget(Player1, 0, Qt::AlignHCenter);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label, 0, Qt::AlignHCenter);

        Player2 = new QLabel(centralwidget);
        Player2->setObjectName(QString::fromUtf8("Player2"));

        horizontalLayout->addWidget(Player2, 0, Qt::AlignHCenter);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setMouseTracking(false);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setAutoScroll(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        currentPlayer = new QLabel(centralwidget);
        currentPlayer->setObjectName(QString::fromUtf8("currentPlayer"));

        horizontalLayout_2->addWidget(currentPlayer);

        label_selected = new QLabel(centralwidget);
        label_selected->setObjectName(QString::fromUtf8("label_selected"));

        horizontalLayout_2->addWidget(label_selected);

        label_move = new QLabel(centralwidget);
        label_move->setObjectName(QString::fromUtf8("label_move"));

        horizontalLayout_2->addWidget(label_move);

        label_passe = new QLabel(centralwidget);
        label_passe->setObjectName(QString::fromUtf8("label_passe"));

        horizontalLayout_2->addWidget(label_passe);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        move = new QPushButton(centralwidget);
        move->setObjectName(QString::fromUtf8("move"));

        horizontalLayout_3->addWidget(move);

        passe = new QPushButton(centralwidget);
        passe->setObjectName(QString::fromUtf8("passe"));

        horizontalLayout_3->addWidget(passe);

        cancel = new QPushButton(centralwidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_3->addWidget(cancel);

        endturn = new QPushButton(centralwidget);
        endturn->setObjectName(QString::fromUtf8("endturn"));

        horizontalLayout_3->addWidget(endturn);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2, 0, Qt::AlignHCenter);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 1);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1679, 17));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(actionPlaying_rules);
        menuMenu->addAction(actionQuitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Diaballik", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionQuitter->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPlaying_rules->setText(QCoreApplication::translate("MainWindow", "Playing rules", nullptr));
#if QT_CONFIG(shortcut)
        actionPlaying_rules->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        Player1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "VS", nullptr));
        Player2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        currentPlayer->setText(QCoreApplication::translate("MainWindow", "CurrentPlayer:", nullptr));
        label_selected->setText(QCoreApplication::translate("MainWindow", "Selected:", nullptr));
        label_move->setText(QCoreApplication::translate("MainWindow", "move:", nullptr));
        label_passe->setText(QCoreApplication::translate("MainWindow", "passe:", nullptr));
        move->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        passe->setText(QCoreApplication::translate("MainWindow", "Throw", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindow", "Cancel selection", nullptr));
        endturn->setText(QCoreApplication::translate("MainWindow", "End Turn", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">How the game works</span></p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">The first player is yellow.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">To make a move, select the player you want to move, and click move. Then press the square where you want to move it and hit the move button again. (Make one move at a time)"
                        "</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">To make a throw, select the player carrying the ball and hit the throw button. Then select the player to throw to and hit the throw button again.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">When you have a selection problem or your data is invalid click on the cancel selection button to reset your selection.</span></p></body></html>", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
