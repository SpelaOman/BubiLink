/********************************************************************************
** Form generated from reading UI file 'add_profile.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_PROFILE_H
#define UI_ADD_PROFILE_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_profile
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *txt_profile_name;
    QLineEdit *txt_page_title;
    QLineEdit *txt_page_url;
    QLabel *label_4;
    QLineEdit *txt_profile_id;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_delete;
    QPushButton *btn_save;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *add_profile)
    {
        if (add_profile->objectName().isEmpty())
            add_profile->setObjectName(QString::fromUtf8("add_profile"));
        add_profile->resize(511, 399);
        horizontalLayout = new QHBoxLayout(add_profile);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(add_profile);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(add_profile);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label = new QLabel(add_profile);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        txt_profile_name = new QLineEdit(add_profile);
        txt_profile_name->setObjectName(QString::fromUtf8("txt_profile_name"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txt_profile_name);

        txt_page_title = new QLineEdit(add_profile);
        txt_page_title->setObjectName(QString::fromUtf8("txt_page_title"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txt_page_title);

        txt_page_url = new QLineEdit(add_profile);
        txt_page_url->setObjectName(QString::fromUtf8("txt_page_url"));
        txt_page_url->setMinimumSize(QSize(350, 0));

        formLayout->setWidget(3, QFormLayout::FieldRole, txt_page_url);

        label_4 = new QLabel(add_profile);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        txt_profile_id = new QLineEdit(add_profile);
        txt_profile_id->setObjectName(QString::fromUtf8("txt_profile_id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txt_profile_id);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_delete = new QPushButton(add_profile);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_2->addWidget(btn_delete);

        btn_save = new QPushButton(add_profile);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_2->addWidget(btn_save);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        QWidget::setTabOrder(txt_profile_id, txt_profile_name);
        QWidget::setTabOrder(txt_profile_name, txt_page_title);
        QWidget::setTabOrder(txt_page_title, txt_page_url);
        QWidget::setTabOrder(txt_page_url, btn_save);

        retranslateUi(add_profile);

        QMetaObject::connectSlotsByName(add_profile);
    } // setupUi

    void retranslateUi(QWidget *add_profile)
    {
        add_profile->setWindowTitle(QApplication::translate("add_profile", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("add_profile", "URL Spletne Strani", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("add_profile", "Ime Spletne Strani", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("add_profile", "Ime Profila", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("add_profile", "ID", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("add_profile", "Izbri\305\241i", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("add_profile", "Vnesi", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class add_profile: public Ui_add_profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_PROFILE_H
