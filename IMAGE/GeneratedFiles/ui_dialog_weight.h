/********************************************************************************
** Form generated from reading UI file 'dialog_weight.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_WEIGHT_H
#define UI_DIALOG_WEIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_weight
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog_weight)
    {
        if (Dialog_weight->objectName().isEmpty())
            Dialog_weight->setObjectName(QStringLiteral("Dialog_weight"));
        Dialog_weight->resize(449, 359);
        gridLayout = new QGridLayout(Dialog_weight);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(Dialog_weight);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Dialog_weight);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Dialog_weight);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Dialog_weight);

        QMetaObject::connectSlotsByName(Dialog_weight);
    } // setupUi

    void retranslateUi(QDialog *Dialog_weight)
    {
        Dialog_weight->setWindowTitle(QApplication::translate("Dialog_weight", "\346\235\203\351\207\215\347\237\251\351\230\265", nullptr));
        pushButton->setText(QApplication::translate("Dialog_weight", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog_weight", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_weight: public Ui_Dialog_weight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_WEIGHT_H
