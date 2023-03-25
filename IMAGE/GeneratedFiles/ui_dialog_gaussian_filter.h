/********************************************************************************
** Form generated from reading UI file 'dialog_gaussian_filter.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_GAUSSIAN_FILTER_H
#define UI_DIALOG_GAUSSIAN_FILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Gaussian_Filter
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog_Gaussian_Filter)
    {
        if (Dialog_Gaussian_Filter->objectName().isEmpty())
            Dialog_Gaussian_Filter->setObjectName(QStringLiteral("Dialog_Gaussian_Filter"));
        Dialog_Gaussian_Filter->resize(727, 561);
        gridLayout = new QGridLayout(Dialog_Gaussian_Filter);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Dialog_Gaussian_Filter);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(Dialog_Gaussian_Filter);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(3);
        spinBox->setSingleStep(2);

        horizontalLayout_2->addWidget(spinBox);

        label = new QLabel(Dialog_Gaussian_Filter);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(Dialog_Gaussian_Filter);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximum(10);
        doubleSpinBox->setSingleStep(0.1);
        doubleSpinBox->setValue(1.6);

        horizontalLayout_2->addWidget(doubleSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(Dialog_Gaussian_Filter);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(Dialog_Gaussian_Filter);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Dialog_Gaussian_Filter);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Dialog_Gaussian_Filter);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Dialog_Gaussian_Filter);

        QMetaObject::connectSlotsByName(Dialog_Gaussian_Filter);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Gaussian_Filter)
    {
        Dialog_Gaussian_Filter->setWindowTitle(QApplication::translate("Dialog_Gaussian_Filter", "\351\253\230\346\226\257\346\273\244\346\263\242", nullptr));
        label_2->setText(QApplication::translate("Dialog_Gaussian_Filter", "\347\252\227\345\217\243\345\244\247\345\260\217\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBox->setToolTip(QApplication::translate("Dialog_Gaussian_Filter", "<html><head/><body><p>\347\252\227\345\217\243\345\244\247\345\260\217\345\217\252\350\203\275\346\230\257\345\245\207\346\225\260</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Dialog_Gaussian_Filter", "Sigma:", nullptr));
        pushButton_3->setText(QApplication::translate("Dialog_Gaussian_Filter", "\347\224\237\346\210\220\346\235\203\351\207\215\347\237\251\351\230\265", nullptr));
        pushButton->setText(QApplication::translate("Dialog_Gaussian_Filter", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog_Gaussian_Filter", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Gaussian_Filter: public Ui_Dialog_Gaussian_Filter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_GAUSSIAN_FILTER_H
