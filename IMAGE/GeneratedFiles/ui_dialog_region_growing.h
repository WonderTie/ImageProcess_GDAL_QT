/********************************************************************************
** Form generated from reading UI file 'dialog_region_growing.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_REGION_GROWING_H
#define UI_DIALOG_REGION_GROWING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_region_growing
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_auto;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *spinBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *spinBox_2;
    QFrame *line;
    QWidget *tab_peo;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *spinBox_3;
    QFrame *line_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Dialog_region_growing)
    {
        if (Dialog_region_growing->objectName().isEmpty())
            Dialog_region_growing->setObjectName(QStringLiteral("Dialog_region_growing"));
        Dialog_region_growing->resize(429, 260);
        gridLayout = new QGridLayout(Dialog_region_growing);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(Dialog_region_growing);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_auto = new QWidget();
        tab_auto->setObjectName(QStringLiteral("tab_auto"));
        horizontalLayoutWidget = new QWidget(tab_auto);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 130, 381, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMouseTracking(true);

        horizontalLayout->addWidget(checkBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBox_2 = new QCheckBox(horizontalLayoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout->addWidget(checkBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        checkBox_3 = new QCheckBox(horizontalLayoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout->addWidget(checkBox_3);

        pushButton = new QPushButton(tab_auto);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 170, 93, 28));
        pushButton_2 = new QPushButton(tab_auto);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 170, 93, 28));
        horizontalLayoutWidget_2 = new QWidget(tab_auto);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 20, 381, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        spinBox = new QSpinBox(horizontalLayoutWidget_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(255);
        spinBox->setValue(30);

        horizontalLayout_2->addWidget(spinBox);

        horizontalLayoutWidget_3 = new QWidget(tab_auto);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 90, 381, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        spinBox_2 = new QSpinBox(horizontalLayoutWidget_3);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(1000);
        spinBox_2->setValue(40);

        horizontalLayout_3->addWidget(spinBox_2);

        line = new QFrame(tab_auto);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 60, 401, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab_auto, QString());
        tab_peo = new QWidget();
        tab_peo->setObjectName(QStringLiteral("tab_peo"));
        horizontalLayoutWidget_4 = new QWidget(tab_peo);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 20, 381, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        spinBox_3 = new QSpinBox(horizontalLayoutWidget_4);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(255);
        spinBox_3->setValue(30);

        horizontalLayout_4->addWidget(spinBox_3);

        line_2 = new QFrame(tab_peo);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 60, 401, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushButton_3 = new QPushButton(tab_peo);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 170, 93, 28));
        pushButton_4 = new QPushButton(tab_peo);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(190, 170, 93, 28));
        tabWidget->addTab(tab_peo, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Dialog_region_growing);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog_region_growing);
    } // setupUi

    void retranslateUi(QDialog *Dialog_region_growing)
    {
        Dialog_region_growing->setWindowTitle(QApplication::translate("Dialog_region_growing", "\345\237\272\344\272\216\347\201\260\345\272\246\345\267\256\345\274\202\347\232\204\345\214\272\345\237\237\347\224\237\351\225\277", nullptr));
        checkBox->setText(QApplication::translate("Dialog_region_growing", "\351\273\230\350\256\244", nullptr));
        checkBox_2->setText(QApplication::translate("Dialog_region_growing", "\345\220\210\345\271\266", nullptr));
        checkBox_3->setText(QApplication::translate("Dialog_region_growing", "\345\210\240\351\231\244", nullptr));
        pushButton->setText(QApplication::translate("Dialog_region_growing", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog_region_growing", "\345\217\226\346\266\210", nullptr));
        label->setText(QApplication::translate("Dialog_region_growing", "\347\201\260\345\272\246\345\267\256\345\274\202\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Dialog_region_growing", "\346\234\200\345\260\217\350\201\232\347\261\273\345\215\225\345\205\203\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_auto), QApplication::translate("Dialog_region_growing", "\350\207\252\345\212\250\345\214\272\345\237\237\347\224\237\351\225\277", nullptr));
        label_3->setText(QApplication::translate("Dialog_region_growing", "\347\201\260\345\272\246\345\267\256\345\274\202\357\274\232", nullptr));
        pushButton_3->setText(QApplication::translate("Dialog_region_growing", "\345\217\226\346\266\210", nullptr));
        pushButton_4->setText(QApplication::translate("Dialog_region_growing", "\347\241\256\350\256\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_peo), QApplication::translate("Dialog_region_growing", "\344\272\244\344\272\222\345\214\272\345\237\237\347\224\237\351\225\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_region_growing: public Ui_Dialog_region_growing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_REGION_GROWING_H
