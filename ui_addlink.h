/********************************************************************************
** Form generated from reading UI file 'addlink.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLINK_H
#define UI_ADDLINK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddLink
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout_3;
    QLabel *label;
    QLineEdit *txt_campaign_name;
    QLabel *label_5;
    QLineEdit *txt_original_url;
    QLabel *label_10;
    QLineEdit *txt_link_name;
    QLineEdit *txt_base_url;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *txt_link_id;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *txt_content;
    QLineEdit *txt_medium;
    QLineEdit *txt_source;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLineEdit *txt_short_computer;
    QLineEdit *txt_comp_try;
    QLabel *label_9;
    QLabel *label_8;
    QLineEdit *txt_short_human;
    QLabel *label_11;
    QLineEdit *txt_url_preffix;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPlainTextEdit *txt_explanation;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout_4;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *txt_new_url;
    QLineEdit *txt_short_url;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_delete;
    QPushButton *btn_create;
    QPushButton *btn_save;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AddLink)
    {
        if (AddLink->objectName().isEmpty())
            AddLink->setObjectName(QString::fromUtf8("AddLink"));
        AddLink->resize(602, 653);
        verticalLayout_4 = new QVBoxLayout(AddLink);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(AddLink);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout_3 = new QFormLayout(groupBox);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label);

        txt_campaign_name = new QLineEdit(groupBox);
        txt_campaign_name->setObjectName(QString::fromUtf8("txt_campaign_name"));
        txt_campaign_name->setEnabled(false);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, txt_campaign_name);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_5);

        txt_original_url = new QLineEdit(groupBox);
        txt_original_url->setObjectName(QString::fromUtf8("txt_original_url"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, txt_original_url);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_10);

        txt_link_name = new QLineEdit(groupBox);
        txt_link_name->setObjectName(QString::fromUtf8("txt_link_name"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, txt_link_name);

        txt_base_url = new QLineEdit(groupBox);
        txt_base_url->setObjectName(QString::fromUtf8("txt_base_url"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, txt_base_url);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_13);

        txt_link_id = new QLineEdit(groupBox);
        txt_link_id->setObjectName(QString::fromUtf8("txt_link_id"));
        txt_link_id->setEnabled(false);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, txt_link_id);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_2 = new QGroupBox(AddLink);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        txt_content = new QLineEdit(groupBox_2);
        txt_content->setObjectName(QString::fromUtf8("txt_content"));

        gridLayout->addWidget(txt_content, 2, 1, 1, 1);

        txt_medium = new QLineEdit(groupBox_2);
        txt_medium->setObjectName(QString::fromUtf8("txt_medium"));

        gridLayout->addWidget(txt_medium, 0, 1, 1, 1);

        txt_source = new QLineEdit(groupBox_2);
        txt_source->setObjectName(QString::fromUtf8("txt_source"));

        gridLayout->addWidget(txt_source, 1, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(AddLink);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txt_short_computer = new QLineEdit(groupBox_3);
        txt_short_computer->setObjectName(QString::fromUtf8("txt_short_computer"));
        txt_short_computer->setEnabled(false);

        gridLayout_2->addWidget(txt_short_computer, 1, 1, 1, 1);

        txt_comp_try = new QLineEdit(groupBox_3);
        txt_comp_try->setObjectName(QString::fromUtf8("txt_comp_try"));
        txt_comp_try->setEnabled(false);

        gridLayout_2->addWidget(txt_comp_try, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        txt_short_human = new QLineEdit(groupBox_3);
        txt_short_human->setObjectName(QString::fromUtf8("txt_short_human"));

        gridLayout_2->addWidget(txt_short_human, 3, 1, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        txt_url_preffix = new QLineEdit(groupBox_3);
        txt_url_preffix->setObjectName(QString::fromUtf8("txt_url_preffix"));

        gridLayout_2->addWidget(txt_url_preffix, 0, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        txt_explanation = new QPlainTextEdit(AddLink);
        txt_explanation->setObjectName(QString::fromUtf8("txt_explanation"));
        txt_explanation->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txt_explanation->sizePolicy().hasHeightForWidth());
        txt_explanation->setSizePolicy(sizePolicy);
        txt_explanation->setMinimumSize(QSize(200, 200));
        txt_explanation->setMaximumSize(QSize(200, 200));

        verticalLayout->addWidget(txt_explanation);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        groupBox_4 = new QGroupBox(AddLink);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        formLayout_4 = new QFormLayout(groupBox_4);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_7);

        txt_new_url = new QLineEdit(groupBox_4);
        txt_new_url->setObjectName(QString::fromUtf8("txt_new_url"));
        txt_new_url->setEnabled(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, txt_new_url);

        txt_short_url = new QLineEdit(groupBox_4);
        txt_short_url->setObjectName(QString::fromUtf8("txt_short_url"));
        txt_short_url->setEnabled(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, txt_short_url);


        verticalLayout_2->addWidget(groupBox_4);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_delete = new QPushButton(AddLink);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout->addWidget(btn_delete);

        btn_create = new QPushButton(AddLink);
        btn_create->setObjectName(QString::fromUtf8("btn_create"));

        horizontalLayout->addWidget(btn_create);

        btn_save = new QPushButton(AddLink);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout->addWidget(btn_save);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        QWidget::setTabOrder(txt_campaign_name, txt_link_name);
        QWidget::setTabOrder(txt_link_name, txt_original_url);
        QWidget::setTabOrder(txt_original_url, txt_base_url);
        QWidget::setTabOrder(txt_base_url, txt_medium);
        QWidget::setTabOrder(txt_medium, txt_source);
        QWidget::setTabOrder(txt_source, txt_content);
        QWidget::setTabOrder(txt_content, txt_url_preffix);
        QWidget::setTabOrder(txt_url_preffix, txt_short_computer);
        QWidget::setTabOrder(txt_short_computer, txt_comp_try);
        QWidget::setTabOrder(txt_comp_try, txt_short_human);
        QWidget::setTabOrder(txt_short_human, txt_new_url);
        QWidget::setTabOrder(txt_new_url, txt_short_url);
        QWidget::setTabOrder(txt_short_url, btn_create);
        QWidget::setTabOrder(btn_create, btn_save);
        QWidget::setTabOrder(btn_save, txt_explanation);

        retranslateUi(AddLink);

        QMetaObject::connectSlotsByName(AddLink);
    } // setupUi

    void retranslateUi(QWidget *AddLink)
    {
        AddLink->setWindowTitle(QApplication::translate("AddLink", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AddLink", "Osnovni podatki", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddLink", "Ime kampanije", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddLink", "Prvotni URL \304\215lanka", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("AddLink", "Ime povezave", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("AddLink", "Osnovni URL", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("AddLink", "ID", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("AddLink", "Podatki o kampaniji", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddLink", "Vir", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddLink", "Medij", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddLink", "Vsebina", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("AddLink", "Okraj\305\241ave", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("AddLink", "Okraj\305\241ava ro\304\215na", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AddLink", "Okraj\305\241ava ra\304\215unalni\305\241ka", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("AddLink", "Predpona", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("AddLink", "Povezave", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AddLink", "Novi URL \304\215lanka", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AddLink", "Skraj\305\241an URL \304\215lanka", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("AddLink", "Izbri\305\241i", 0, QApplication::UnicodeUTF8));
        btn_create->setText(QApplication::translate("AddLink", "Tvori", 0, QApplication::UnicodeUTF8));
        btn_save->setText(QApplication::translate("AddLink", "Shrani", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddLink: public Ui_AddLink {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLINK_H
