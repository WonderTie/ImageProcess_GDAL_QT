/********************************************************************************
** Form generated from reading UI file 'IMAGE.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_H
#define UI_IMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IMAGEClass
{
public:
    QAction *actionOpen;
    QAction *actionGRAY;
    QAction *actionLaplace;
    QAction *actionImage_linear_enhancement;
    QAction *actionRegion_growing;
    QAction *actionGuassian;
    QAction *actionsave;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QSpacerItem *verticalSpacer;
    QTableView *tableView;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *imagex;
    QLabel *imagey;
    QLabel *label;
    QLabel *prox;
    QLabel *proy;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *menuCalculate;
    QMenu *menuLaplace;
    QMenu *menuImage_enhancement;
    QMenu *menuSegmentation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IMAGEClass)
    {
        if (IMAGEClass->objectName().isEmpty())
            IMAGEClass->setObjectName(QStringLiteral("IMAGEClass"));
        IMAGEClass->resize(1209, 814);
        actionOpen = new QAction(IMAGEClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionGRAY = new QAction(IMAGEClass);
        actionGRAY->setObjectName(QStringLiteral("actionGRAY"));
        actionLaplace = new QAction(IMAGEClass);
        actionLaplace->setObjectName(QStringLiteral("actionLaplace"));
        actionImage_linear_enhancement = new QAction(IMAGEClass);
        actionImage_linear_enhancement->setObjectName(QStringLiteral("actionImage_linear_enhancement"));
        actionRegion_growing = new QAction(IMAGEClass);
        actionRegion_growing->setObjectName(QStringLiteral("actionRegion_growing"));
        actionGuassian = new QAction(IMAGEClass);
        actionGuassian->setObjectName(QStringLiteral("actionGuassian"));
        actionsave = new QAction(IMAGEClass);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        centralWidget = new QWidget(IMAGEClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);

        verticalLayout->addWidget(treeView);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        verticalLayout->setStretch(0, 20);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 40);

        horizontalLayout->addLayout(verticalLayout);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        imagex = new QLabel(centralWidget);
        imagex->setObjectName(QStringLiteral("imagex"));

        horizontalLayout_2->addWidget(imagex);

        imagey = new QLabel(centralWidget);
        imagey->setObjectName(QStringLiteral("imagey"));

        horizontalLayout_2->addWidget(imagey);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        prox = new QLabel(centralWidget);
        prox->setObjectName(QStringLiteral("prox"));

        horizontalLayout_2->addWidget(prox);

        proy = new QLabel(centralWidget);
        proy->setObjectName(QStringLiteral("proy"));

        horizontalLayout_2->addWidget(proy);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        IMAGEClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IMAGEClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1209, 18));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuCalculate = new QMenu(menuBar);
        menuCalculate->setObjectName(QStringLiteral("menuCalculate"));
        menuLaplace = new QMenu(menuBar);
        menuLaplace->setObjectName(QStringLiteral("menuLaplace"));
        menuImage_enhancement = new QMenu(menuBar);
        menuImage_enhancement->setObjectName(QStringLiteral("menuImage_enhancement"));
        menuSegmentation = new QMenu(menuBar);
        menuSegmentation->setObjectName(QStringLiteral("menuSegmentation"));
        IMAGEClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IMAGEClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        IMAGEClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(IMAGEClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IMAGEClass->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(menuCalculate->menuAction());
        menuBar->addAction(menuLaplace->menuAction());
        menuBar->addAction(menuImage_enhancement->menuAction());
        menuBar->addAction(menuSegmentation->menuAction());
        menuOpen->addAction(actionOpen);
        menuOpen->addAction(actionsave);
        menuCalculate->addAction(actionGRAY);
        menuLaplace->addAction(actionLaplace);
        menuLaplace->addAction(actionGuassian);
        menuImage_enhancement->addAction(actionImage_linear_enhancement);
        menuSegmentation->addAction(actionRegion_growing);

        retranslateUi(IMAGEClass);

        QMetaObject::connectSlotsByName(IMAGEClass);
    } // setupUi

    void retranslateUi(QMainWindow *IMAGEClass)
    {
        IMAGEClass->setWindowTitle(QApplication::translate("IMAGEClass", "IMAGE", nullptr));
        actionOpen->setText(QApplication::translate("IMAGEClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        actionGRAY->setText(QApplication::translate("IMAGEClass", "RGB2GRAY", nullptr));
        actionLaplace->setText(QApplication::translate("IMAGEClass", "\346\213\211\346\231\256\346\213\211\346\226\257\351\224\220", nullptr));
        actionImage_linear_enhancement->setText(QApplication::translate("IMAGEClass", "\345\233\276\345\203\217\347\272\277\346\200\247\345\242\236\351\225\277", nullptr));
        actionRegion_growing->setText(QApplication::translate("IMAGEClass", "\345\214\272\345\237\237\347\224\237\351\225\277", nullptr));
        actionGuassian->setText(QApplication::translate("IMAGEClass", "\351\253\230\346\226\257\345\271\263\346\273\221", nullptr));
        actionsave->setText(QApplication::translate("IMAGEClass", "\345\217\246\345\255\230\344\270\272", nullptr));
        imagex->setText(QApplication::translate("IMAGEClass", "0", nullptr));
        imagey->setText(QApplication::translate("IMAGEClass", "0", nullptr));
        label->setText(QApplication::translate("IMAGEClass", "   :   ", nullptr));
        prox->setText(QApplication::translate("IMAGEClass", "0", nullptr));
        proy->setText(QApplication::translate("IMAGEClass", "0", nullptr));
        menuOpen->setTitle(QApplication::translate("IMAGEClass", "\346\226\207\344\273\266", nullptr));
        menuCalculate->setTitle(QApplication::translate("IMAGEClass", "\345\233\276\345\203\217\344\272\214\345\200\274\345\214\226", nullptr));
        menuLaplace->setTitle(QApplication::translate("IMAGEClass", "\345\233\276\345\203\217\346\273\244\346\263\242", nullptr));
        menuImage_enhancement->setTitle(QApplication::translate("IMAGEClass", "\345\233\276\345\203\217\345\242\236\351\225\277", nullptr));
        menuSegmentation->setTitle(QApplication::translate("IMAGEClass", "\345\233\276\345\203\217\345\210\206\345\211\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IMAGEClass: public Ui_IMAGEClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_H
