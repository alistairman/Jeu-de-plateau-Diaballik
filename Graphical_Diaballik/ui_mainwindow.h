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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1679, 700);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionPlaying_rules = new QAction(MainWindow);
        actionPlaying_rules->setObjectName(QStringLiteral("actionPlaying_rules"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        Player1 = new QLabel(centralwidget);
        Player1->setObjectName(QStringLiteral("Player1"));

        horizontalLayout->addWidget(Player1, 0, Qt::AlignHCenter);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label, 0, Qt::AlignHCenter);

        Player2 = new QLabel(centralwidget);
        Player2->setObjectName(QStringLiteral("Player2"));

        horizontalLayout->addWidget(Player2, 0, Qt::AlignHCenter);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setMouseTracking(false);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setAutoScroll(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        currentPlayer = new QLabel(centralwidget);
        currentPlayer->setObjectName(QStringLiteral("currentPlayer"));

        horizontalLayout_2->addWidget(currentPlayer);

        label_selected = new QLabel(centralwidget);
        label_selected->setObjectName(QStringLiteral("label_selected"));

        horizontalLayout_2->addWidget(label_selected);

        label_move = new QLabel(centralwidget);
        label_move->setObjectName(QStringLiteral("label_move"));

        horizontalLayout_2->addWidget(label_move);

        label_passe = new QLabel(centralwidget);
        label_passe->setObjectName(QStringLiteral("label_passe"));

        horizontalLayout_2->addWidget(label_passe);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        move = new QPushButton(centralwidget);
        move->setObjectName(QStringLiteral("move"));

        horizontalLayout_3->addWidget(move);

        passe = new QPushButton(centralwidget);
        passe->setObjectName(QStringLiteral("passe"));

        horizontalLayout_3->addWidget(passe);

        cancel = new QPushButton(centralwidget);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_3->addWidget(cancel);

        endturn = new QPushButton(centralwidget);
        endturn->setObjectName(QStringLiteral("endturn"));

        horizontalLayout_3->addWidget(endturn);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2, 0, Qt::AlignHCenter);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 1);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

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
        label->setText(QApplication::translate("MainWindow", "VS", Q_NULLPTR));
        Player2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        currentPlayer->setText(QApplication::translate("MainWindow", "CurrentPlayer:", Q_NULLPTR));
        label_selected->setText(QApplication::translate("MainWindow", "Selected:", Q_NULLPTR));
        label_move->setText(QApplication::translate("MainWindow", "move:", Q_NULLPTR));
        label_passe->setText(QApplication::translate("MainWindow", "passe:", Q_NULLPTR));
        move->setText(QApplication::translate("MainWindow", "Move", Q_NULLPTR));
        passe->setText(QApplication::translate("MainWindow", "Throw", Q_NULLPTR));
        cancel->setText(QApplication::translate("MainWindow", "Cancel selection", Q_NULLPTR));
        endturn->setText(QApplication::translate("MainWindow", "End Turn", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; text-decoration: underline;\">How the game works</span></p></body></html>", Q_NULLPTR));
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
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
