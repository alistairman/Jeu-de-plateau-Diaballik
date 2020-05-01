/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_addDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *namePlayer1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *namePlayer2;

    void setupUi(QDialog *addDialog)
    {
        if (addDialog->objectName().isEmpty())
            addDialog->setObjectName(QString::fromUtf8("addDialog"));
        addDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(addDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        namePlayer1 = new QLineEdit(addDialog);
        namePlayer1->setObjectName(QString::fromUtf8("namePlayer1"));
        namePlayer1->setGeometry(QRect(140, 80, 113, 21));
        label = new QLabel(addDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 58, 16));
        label_2 = new QLabel(addDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 20, 221, 16));
        label_3 = new QLabel(addDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 160, 58, 16));
        namePlayer2 = new QLineEdit(addDialog);
        namePlayer2->setObjectName(QString::fromUtf8("namePlayer2"));
        namePlayer2->setGeometry(QRect(140, 160, 113, 21));

        retranslateUi(addDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), addDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(addDialog);
    } // setupUi

    void retranslateUi(QDialog *addDialog)
    {
        addDialog->setWindowTitle(QCoreApplication::translate("addDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addDialog", "Player 1", nullptr));
        label_2->setText(QCoreApplication::translate("addDialog", "Veuillez entrer les noms des joueurs", nullptr));
        label_3->setText(QCoreApplication::translate("addDialog", "Player 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addDialog: public Ui_addDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
