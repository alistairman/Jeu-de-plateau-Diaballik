/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionPlaying_rules;
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
    QPushButton *endturn;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1679, 700);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionPlaying_rules = new QAction(MainWindow);
        actionPlaying_rules->setObjectName(QStringLiteral("actionPlaying_rules"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Player1 = new QLabel(centralwidget);
        Player1->setObjectName(QStringLiteral("Player1"));
        Player1->setGeometry(QRect(370, 10, 58, 16));
        Player2 = new QLabel(centralwidget);
        Player2->setObjectName(QStringLiteral("Player2"));
        Player2->setGeometry(QRect(700, 10, 58, 16));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(30, 50, 1052, 424));
        tableWidget->setMouseTracking(false);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setAutoScroll(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(550, 10, 21, 16));
        currentPlayer = new QLabel(centralwidget);
        currentPlayer->setObjectName(QStringLiteral("currentPlayer"));
        currentPlayer->setGeometry(QRect(30, 490, 251, 16));
        move = new QPushButton(centralwidget);
        move->setObjectName(QStringLiteral("move"));
        move->setGeometry(QRect(40, 540, 112, 32));
        label_move = new QLabel(centralwidget);
        label_move->setObjectName(QStringLiteral("label_move"));
        label_move->setGeometry(QRect(480, 490, 271, 16));
        label_passe = new QLabel(centralwidget);
        label_passe->setObjectName(QStringLiteral("label_passe"));
        label_passe->setGeometry(QRect(760, 490, 281, 20));
        label_selected = new QLabel(centralwidget);
        label_selected->setObjectName(QStringLiteral("label_selected"));
        label_selected->setGeometry(QRect(310, 490, 161, 16));
        passe = new QPushButton(centralwidget);
        passe->setObjectName(QStringLiteral("passe"));
        passe->setGeometry(QRect(40, 600, 112, 32));
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(230, 560, 131, 32));
        endturn = new QPushButton(centralwidget);
        endturn->setObjectName(QStringLiteral("endturn"));
        endturn->setGeometry(QRect(450, 560, 131, 32));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(1130, 160, 461, 311));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1240, 100, 271, 61));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1679, 17));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Diaballik", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        actionPlaying_rules->setText(QApplication::translate("MainWindow", "Playing rules", Q_NULLPTR));
        actionPlaying_rules->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", Q_NULLPTR));
        Player1->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        Player2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "VS", Q_NULLPTR));
        currentPlayer->setText(QApplication::translate("MainWindow", "CurrentPlayer:", Q_NULLPTR));
        move->setText(QApplication::translate("MainWindow", "Move", Q_NULLPTR));
        label_move->setText(QApplication::translate("MainWindow", "move:", Q_NULLPTR));
        label_passe->setText(QApplication::translate("MainWindow", "passe:", Q_NULLPTR));
        label_selected->setText(QApplication::translate("MainWindow", "Selected:", Q_NULLPTR));
        passe->setText(QApplication::translate("MainWindow", "Throw", Q_NULLPTR));
        cancel->setText(QApplication::translate("MainWindow", "Cancel selection", Q_NULLPTR));
        endturn->setText(QApplication::translate("MainWindow", "End Turn", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">When you have a selection problem or your data is invalid click on the cancel selection button to reset your selection.</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">How the game works</span></p></body></html>", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
