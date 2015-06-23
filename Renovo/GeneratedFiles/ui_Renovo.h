/********************************************************************************
** Form generated from reading UI file 'Renovo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENOVO_H
#define UI_RENOVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CheckoutUI
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *Total_Button;
    QTextEdit *textEdit;
    QPushButton *Clear_Button;

    void setupUi(QDialog *CheckoutUI)
    {
        if (CheckoutUI->objectName().isEmpty())
            CheckoutUI->setObjectName(QStringLiteral("CheckoutUI"));
        CheckoutUI->resize(477, 316);
        verticalLayout = new QVBoxLayout(CheckoutUI);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(CheckoutUI);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        Total_Button = new QPushButton(CheckoutUI);
        Total_Button->setObjectName(QStringLiteral("Total_Button"));

        horizontalLayout->addWidget(Total_Button);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(CheckoutUI);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        Clear_Button = new QPushButton(CheckoutUI);
        Clear_Button->setObjectName(QStringLiteral("Clear_Button"));

        verticalLayout->addWidget(Clear_Button);


        retranslateUi(CheckoutUI);

        QMetaObject::connectSlotsByName(CheckoutUI);
    } // setupUi

    void retranslateUi(QDialog *CheckoutUI)
    {
        CheckoutUI->setWindowTitle(QApplication::translate("CheckoutUI", "Dialog", 0));
        Total_Button->setText(QApplication::translate("CheckoutUI", "Total", 0));
        Clear_Button->setText(QApplication::translate("CheckoutUI", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class CheckoutUI: public Ui_CheckoutUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENOVO_H
