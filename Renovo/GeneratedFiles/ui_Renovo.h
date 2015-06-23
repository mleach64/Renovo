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
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_CheckoutUI
{
public:

    void setupUi(QDialog *CheckoutUI)
    {
        if (CheckoutUI->objectName().isEmpty())
            CheckoutUI->setObjectName(QStringLiteral("CheckoutUI"));
        CheckoutUI->resize(400, 300);

        retranslateUi(CheckoutUI);

        QMetaObject::connectSlotsByName(CheckoutUI);
    } // setupUi

    void retranslateUi(QDialog *CheckoutUI)
    {
        CheckoutUI->setWindowTitle(QApplication::translate("CheckoutUI", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class CheckoutUI: public Ui_CheckoutUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENOVO_H
