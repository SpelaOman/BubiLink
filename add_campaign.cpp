#include "add_campaign.h"
#include "ui_add_campaign.h"
#include "global.h"
#include "mainwindow.h"

#include <QtSql>
#include <QMessageBox>

add_campaign::add_campaign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_campaign)
{
    ui->setupUi(this);

    // hide ID fields
    ui->label->setHidden(true);
    ui->txt_campaign_id->setHidden(true);

}

add_campaign::~add_campaign()
{
    delete ui;
}


void add_campaign::on_btn_save_clicked() {

    // check if we have a campaign name set, otherwise sent warning and abort
    if ( ui->txt_campaign_name->text() !="" ) {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "create-new-campaign");
            base.setDatabaseName(dbase_path);
            base.open();
            if(base.isOpen() != true){
                QMessageBox msgbox;
                msgbox.setText("There was a problem with the database");
                msgbox.setInformativeText("Due to unknown reason there was a problem with opening the database.\nThe problem accured during initial opening of the database.");
                msgbox.exec();
            }
            else {
                // the database is open

                // scroll through profiles to determinate if this is really new profile or not
                QSqlQuery sql_check(base);
                sql_check.prepare("SELECT * FROM campaign WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "'"
                                  " AND campaign_name LIKE '" + ui->txt_campaign_name->text() + "' AND id NOT LIKE '" + ui->txt_campaign_id->text() + "'");
                sql_check.exec();
                if ( !sql_check.next() ) { // the campaign name is unique
                    QSqlQuery sql_insert(base);
                    if ( ui->txt_campaign_id->text() == "" ) { // insert new campaign
                        sql_insert.prepare("INSERT INTO campaign (user, profile, campaign_name, campaign_description) VALUES (?, ?, ?, ?)");
                    }
                    else { // update current campaign
                        sql_insert.prepare("UPDATE campaign SET user = ?, profile = ?, campaign_name = ?, campaign_description = ? "
                                           "WHERE id LIKE '" + ui->txt_campaign_id->text() + "'");
                    }
                    sql_insert.bindValue(0, vApp->id_user());
                    sql_insert.bindValue(1, vApp->id_profile());
                    sql_insert.bindValue(2, ui->txt_campaign_name->text());
                    sql_insert.bindValue(3, ui->txt_campaign_description->toPlainText());
                    sql_insert.exec();

                    // change global campaign
                    QSqlQuery sql_get_id(base);
                    sql_get_id.prepare("SELECT * FROM campaign WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "'"
                                       " AND campaign_name LIKE '" + ui->txt_campaign_name->text() + "'");
                    sql_get_id.exec();
                    if ( sql_get_id.next() ) { // the campaign was succesfully saved
                        QMessageBox msgbox;
                        msgbox.setText("Kampanija je bila uspesno shranjen!");
                        msgbox.exec();

                        vApp->set_id_campaign(sql_get_id.value(sql_get_id.record().indexOf("id")).toString());

                        // send signal to the main window to refresh campaign combo box
                        send("refresh-campaign");
                    }
                    else { // there was an error while saving the campaign
                        QMessageBox msgbox;
                        msgbox.setText("Pri shranjevanju kampanije je prislo do napake!");
                        msgbox.exec();
                    }
                }
                else { // there already is campaign with this name
                    QMessageBox msgbox;
                    msgbox.setText("Kampanija s tem imenom ze obstaja! Prosim, spremenite ga!");
                    msgbox.exec();
                }
            }
            base.close();
        }
        QSqlDatabase::removeDatabase("create-new-campaign");
    }
    else { // the profile name field is empty
        QMessageBox msgbox;
        msgbox.setText("Prosim vnesite ime kampanije!");
        msgbox.exec();
    }

}

void add_campaign::on_btn_delete_clicked() {

    // check if we have a campaign name set, otherwise sent warning and abort
    if ( ui->txt_campaign_id->text() !="" ) {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "delete-campaign");
            base.setDatabaseName(dbase_path);
            base.open();
            if(base.isOpen() != true){
                QMessageBox msgbox;
                msgbox.setText("There was a problem with the database");
                msgbox.setInformativeText("Due to unknown reason there was a problem with opening the database.\nThe problem accured during initial opening of the database.");
                msgbox.exec();
            }
            else {
                // the database is open

                // delete campaign
                QSqlQuery sql_delete(base);
                sql_delete.prepare("DELETE FROM sources WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND campaign LIKE '" + ui->txt_campaign_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                sql_delete.prepare("DELETE FROM medium WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND campaign LIKE '" + ui->txt_campaign_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                sql_delete.prepare("DELETE FROM data WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND campaign LIKE '" + ui->txt_campaign_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                sql_delete.prepare("DELETE FROM campaign WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND id LIKE '" + ui->txt_campaign_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                // set global campaign id to null
                vApp->set_id_campaign("");

                // set form fields to empty
                ui->txt_campaign_description->clear();
                ui->txt_campaign_id->setText("");
                ui->txt_campaign_name->setText("");

                // display message
                QMessageBox msgbox;
                msgbox.setText("Kampanija je bila uspesno izbrisana!");
                msgbox.exec();

                // send signal to the main window to refresh campaign combo box
                send("refresh-campaign");
            }
            base.close();
        }
        QSqlDatabase::removeDatabase("delete-campaign");
    }

}

void add_campaign::fill_fields() {

    // this function fills all the fields of the campaign

    QString app_path = QApplication::applicationDirPath();
    QString dbase_path = app_path + "/base.bz";

    {
        QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "fill-fields");
        base.setDatabaseName(dbase_path);
        base.open();
        if(base.isOpen() != true){
            QMessageBox msgbox;
            msgbox.setText("There was a problem with the database");
            msgbox.setInformativeText("Due to unknown reason there was a problem with opening the database.\nThe problem accured during initial opening of the database.");
            msgbox.exec();
        }
        else {
            // the database is open
            QSqlQuery sql_fill(base);
            sql_fill.prepare("SELECT * FROM campaign WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND id LIKE '" + ui->txt_campaign_id->text() + "'");
            sql_fill.exec();
            if ( sql_fill.next() ) {
                ui->txt_campaign_name->setText(sql_fill.value(sql_fill.record().indexOf("campaign_name")).toString());
                ui->txt_campaign_description->setText(sql_fill.value(sql_fill.record().indexOf("campaign_description")).toString());
            }
        }
        base.close();
    }
    QSqlDatabase::removeDatabase("fill-fields");

}

void add_campaign::recieve(QString state) {

    // this function receives the signal send from main window and act acordingly

    if ( state == "0" ) { // we input a new profile
        ui->btn_save->setText("Vnesi");
        ui->txt_campaign_name->setText("");
        ui->txt_campaign_description->clear();
        ui->txt_campaign_id->setText("");
    }
    else { // we have to fill the old profile and make it possible to change it
        ui->btn_save->setText("Spremeni");
        ui->txt_campaign_id->setText(state);
        fill_fields();
    }

}
