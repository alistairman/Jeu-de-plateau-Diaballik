/********************************************************************************
** Form generated from reading UI file 'formaddplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMADDPLAYER_H
#define UI_FORMADDPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAddPLayer
{
public:
    QLineEdit *inputPlayer1;
    QLineEdit *inputPlayer2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *sendPlayers;

    void setupUi(QWidget *FormAddPLayer)
    {
        if (FormAddPLayer->objectName().isEmpty())
            FormAddPLayer->setObjectName(QString::fromUtf8("FormAddPLayer"));
        FormAddPLayer->resize(400, 300);
        inputPlayer1 = new QLineEdit(FormAddPLayer);
        inputPlayer1->setObjectName(QString::fromUtf8("inputPlayer1"));
        inputPlayer1->setGeometry(QRect(120, 70, 113, 21));
        inputPlayer2 = new QLineEdit(FormAddPLayer);
        inputPlayer2->setObjectName(QString::fromUtf8("inputPlayer2"));
        inputPlayer2->setGeometry(QRect(120, 130, 113, 21));
        label = new QLabel(FormAddPLayer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 58, 16));
        label_2 = new QLabel(FormAddPLayer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 130, 58, 16));
        sendPlayers = new QPushButton(FormAddPLayer);
        sendPlayers->setObjectName(QString::fromUtf8("sendPlayers"));
        sendPlayers->setGeometry(QRect(210, 210, 112, 32));

        retranslateUi(FormAddPLayer);

        QMetaObject::connectSlotsByName(FormAddPLayer);
    } // setupUi

    void retranslateUi(QWidget *FormAddPLayer)
    {
        FormAddPLayer->setWindowTitle(QCoreApplication::translate("FormAddPLayer", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormAddPLayer", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("FormAddPLayer", "TextLabel", nullptr));
        sendPlayers->setText(QCoreApplication::translate("FormAddPLayer", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAddPLayer: public Ui_FormAddPLayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMADDPLAYER_H
