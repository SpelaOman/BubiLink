/********************************************************************************
** Form generated from reading UI file 'add_campaign.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_CAMPAIGN_H
#define UI_ADD_CAMPAIGN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_campaign
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *txt_campaign_id;
    QLineEdit *txt_campaign_name;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *txt_campaign_description;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_delete;
    QPushButton *btn_save;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *add_campaign)
    {
        if (add_campaign->objectName().isEmpty())
            add_campaign->setObjectName(QString::fromUtf8("add_campaign"));
        add_campaign->resize(627, 505);
        horizontalLayout_2 = new QHBoxLayout(add_campaign);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        txt_campaign_id = new QLineEdit(add_campaign);
        txt_campaign_id->setObjectName(QString::fromUtf8("txt_campaign_id"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txt_campaign_id);

        txt_campaign_name = new QLineEdit(add_campaign);
        txt_campaign_name->setObjectName(QString::fromUtf8("txt_campaign_name"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txt_campaign_name);

        label = new QLabel(add_campaign);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(add_campaign);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(add_campaign);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        txt_campaign_description = new QTextEdit(add_campaign);
        txt_campaign_description->setObjectName(QString::fromUtf8("txt_campaign_description"));

        formLayout->setWidget(3, QFormLayout::FieldRole, txt_campaign_description);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_delete = new QPushButton(add_campaign);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout->addWidget(btn_delete);

        btn_save = new QPushButton(add_campaign);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout->addWidget(btn_save);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(255, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        QWidget::setTabOrder(txt_campaign_id, txt_campaign_name);
        QWidget::setTabOrder(txt_campaign_name, txt_campaign_description);
        QWidget::setTabOrder(txt_campaign_description, btn_save);

        retranslateUi(add_campaign);

        QMetaObject::connectSlotsByName(add_campaign);
    } // setupUi

    void retranslateUi(QWidget *add_campaign)
    {
        add_campaign->setWindowTitle(QApplication::translate("add_campaign", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("add_campaign", "ID", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("add_campaign", "Ime Kampanije", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("add_campaign", "Opis Kampanije", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("add_campaign", "Izbri\305\241i", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("add_campaign", "Vnesi", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class add_campaign: public Ui_add_campaign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_CAMPAIGN_H
