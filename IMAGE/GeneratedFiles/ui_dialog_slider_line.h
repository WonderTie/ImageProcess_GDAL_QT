/********************************************************************************
** Form generated from reading UI file 'dialog_slider_line.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SLIDER_LINE_H
#define UI_DIALOG_SLIDER_LINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_slider_line
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *label_3;
    QSlider *horizontalSlider_2;
    QLabel *label_4;

    void setupUi(QDialog *Dialog_slider_line)
    {
        if (Dialog_slider_line->objectName().isEmpty())
            Dialog_slider_line->setObjectName(QStringLiteral("Dialog_slider_line"));
        Dialog_slider_line->resize(431, 70);
        horizontalLayoutWidget = new QWidget(Dialog_slider_line);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 40, 411, 22));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(horizontalLayoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setSingleStep(5);
        horizontalSlider->setValue(127);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalLayoutWidget_2 = new QWidget(Dialog_slider_line);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 411, 22));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSlider_2 = new QSlider(horizontalLayoutWidget_2);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setSingleStep(5);
        horizontalSlider_2->setValue(127);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_2);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);


        retranslateUi(Dialog_slider_line);

        QMetaObject::connectSlotsByName(Dialog_slider_line);
    } // setupUi

    void retranslateUi(QDialog *Dialog_slider_line)
    {
        Dialog_slider_line->setWindowTitle(QApplication::translate("Dialog_slider_line", "\347\272\277\346\200\247\345\233\276\345\203\217\345\242\236\345\274\272", nullptr));
        label_5->setText(QApplication::translate("Dialog_slider_line", "\344\270\212\345\200\274\357\274\232", nullptr));
        label->setText(QApplication::translate("Dialog_slider_line", "0", nullptr));
        label_2->setText(QApplication::translate("Dialog_slider_line", "255", nullptr));
        label_6->setText(QApplication::translate("Dialog_slider_line", "\344\270\213\345\200\274\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Dialog_slider_line", "0", nullptr));
        label_4->setText(QApplication::translate("Dialog_slider_line", "255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_slider_line: public Ui_Dialog_slider_line {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SLIDER_LINE_H
