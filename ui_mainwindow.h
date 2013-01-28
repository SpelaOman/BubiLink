/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTvori_novo;
    QAction *actionUrejaj_obstoje_e;
    QAction *actionIzhod;
    QAction *actionVir_Source;
    QAction *actionMedij_Medium;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *profile_id;
    QLineEdit *campaign_id;
    QComboBox *campaign_name;
    QPushButton *new_campaign;
    QPushButton *new_profile;
    QLabel *label;
    QComboBox *profile_name;
    QPushButton *btn_add_link;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *tbl_links;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(779, 545);
        actionTvori_novo = new QAction(MainWindow);
        actionTvori_novo->setObjectName(QString::fromUtf8("actionTvori_novo"));
        actionUrejaj_obstoje_e = new QAction(MainWindow);
        actionUrejaj_obstoje_e->setObjectName(QString::fromUtf8("actionUrejaj_obstoje_e"));
        actionIzhod = new QAction(MainWindow);
        actionIzhod->setObjectName(QString::fromUtf8("actionIzhod"));
        actionVir_Source = new QAction(MainWindow);
        actionVir_Source->setObjectName(QString::fromUtf8("actionVir_Source"));
        actionMedij_Medium = new QAction(MainWindow);
        actionMedij_Medium->setObjectName(QString::fromUtf8("actionMedij_Medium"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        profile_id = new QLineEdit(centralWidget);
        profile_id->setObjectName(QString::fromUtf8("profile_id"));

        gridLayout->addWidget(profile_id, 0, 1, 1, 1);

        campaign_id = new QLineEdit(centralWidget);
        campaign_id->setObjectName(QString::fromUtf8("campaign_id"));

        gridLayout->addWidget(campaign_id, 1, 1, 1, 1);

        campaign_name = new QComboBox(centralWidget);
        campaign_name->setObjectName(QString::fromUtf8("campaign_name"));
        campaign_name->setMinimumSize(QSize(200, 25));
        campaign_name->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(campaign_name, 1, 2, 1, 1);

        new_campaign = new QPushButton(centralWidget);
        new_campaign->setObjectName(QString::fromUtf8("new_campaign"));

        gridLayout->addWidget(new_campaign, 1, 3, 1, 1);

        new_profile = new QPushButton(centralWidget);
        new_profile->setObjectName(QString::fromUtf8("new_profile"));

        gridLayout->addWidget(new_profile, 0, 3, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        profile_name = new QComboBox(centralWidget);
        profile_name->setObjectName(QString::fromUtf8("profile_name"));
        profile_name->setMinimumSize(QSize(200, 25));
        profile_name->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(profile_name, 0, 2, 1, 1);

        btn_add_link = new QPushButton(centralWidget);
        btn_add_link->setObjectName(QString::fromUtf8("btn_add_link"));

        gridLayout->addWidget(btn_add_link, 1, 4, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 501, 398));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        tbl_links = new QTableWidget(centralWidget);
        tbl_links->setObjectName(QString::fromUtf8("tbl_links"));
        tbl_links->setMinimumSize(QSize(250, 0));
        tbl_links->setMaximumSize(QSize(250, 16777215));
        tbl_links->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl_links->setAlternatingRowColors(true);
        tbl_links->setSelectionMode(QAbstractItemView::SingleSelection);
        tbl_links->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbl_links->setSortingEnabled(true);

        horizontalLayout_2->addWidget(tbl_links);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 779, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(profile_id, profile_name);
        QWidget::setTabOrder(profile_name, new_profile);
        QWidget::setTabOrder(new_profile, campaign_id);
        QWidget::setTabOrder(campaign_id, campaign_name);
        QWidget::setTabOrder(campaign_name, new_campaign);
        QWidget::setTabOrder(new_campaign, scrollArea);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionTvori_novo->setText(QApplication::translate("MainWindow", "Tvori novo", 0, QApplication::UnicodeUTF8));
        actionUrejaj_obstoje_e->setText(QApplication::translate("MainWindow", "Urejaj obstoje\304\215e", 0, QApplication::UnicodeUTF8));
        actionIzhod->setText(QApplication::translate("MainWindow", "Izhod", 0, QApplication::UnicodeUTF8));
        actionVir_Source->setText(QApplication::translate("MainWindow", "Vir (Source)", 0, QApplication::UnicodeUTF8));
        actionMedij_Medium->setText(QApplication::translate("MainWindow", "Medij (Medium)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Kampanija", 0, QApplication::UnicodeUTF8));
        new_campaign->setText(QApplication::translate("MainWindow", "Nova Kampanija", 0, QApplication::UnicodeUTF8));
        new_profile->setText(QApplication::translate("MainWindow", "Nov Profil", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Profil", 0, QApplication::UnicodeUTF8));
        btn_add_link->setText(QApplication::translate("MainWindow", "Dodaj Novo Povezavo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
