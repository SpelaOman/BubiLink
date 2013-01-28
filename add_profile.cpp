#include "add_profile.h"
#include "ui_add_profile.h"
#include "global.h"
#include "mainwindow.h"

#include <QtSql>
#include <QMessageBox>

add_profile::add_profile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_profile)
{
    ui->setupUi(this);

    // hide ID field
    ui->label_4->setHidden(true);
    ui->txt_profile_id->setHidden(true);

}

add_profile::~add_profile()
{
    delete ui;
}

void add_profile::on_btn_save_clicked() {

    // check if we have a profile name set, otherwise sent warning and abort
    if ( ui->txt_profile_name->text() !="" ) {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "create-new-profile");
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
                sql_check.prepare("SELECT * FROM profile WHERE user LIKE '" + vApp->id_user() + "' AND profile_name LIKE '" + ui->txt_profile_name->text() + "'"
                                  " AND id NOT LIKE '" + ui->txt_profile_id->text() + "'");
                sql_check.exec();
                if ( !sql_check.next() ) { // the profile name is unique
                    QSqlQuery sql_insert(base);
                    if ( ui->txt_profile_id->text() == "" ) { // insert new profile
                        sql_insert.prepare("INSERT INTO profile (user, profile_name, site_name, site_url) VALUES (?, ?, ?, ?)");
                    }
                    else { // update current profile
                        sql_insert.prepare("UPDATE profile SET user = ?, profile_name = ?, site_name= ?, site_url = ? "
                                           "WHERE id LIKE '" + ui->txt_profile_id->text() + "'");
                    }
                    sql_insert.bindValue(0, vApp->id_user());
                    sql_insert.bindValue(1, ui->txt_profile_name->text());
                    sql_insert.bindValue(2, ui->txt_page_title->text());
                    sql_insert.bindValue(3, ui->txt_page_url->text());
                    sql_insert.exec();

                    // change global profile
                    QSqlQuery sql_get_id(base);
                    sql_get_id.prepare("SELECT * FROM profile WHERE user LIKE '" + vApp->id_user() + "' AND profile_name LIKE '" + ui->txt_profile_name->text() + "'");
                    sql_get_id.exec();
                    if ( sql_get_id.next() ) { // the profile was succesfully saved
                        QMessageBox msgbox;
                        msgbox.setText("Profile je bil uspesno shranjen!");
                        msgbox.exec();

                        vApp->set_id_profile(sql_get_id.value(sql_get_id.record().indexOf("id")).toString());

                        // send signal to the main window to refresh profile combo box
                        send("refresh-profiles");
                    }
                    else { // there was an error while saving the profile
                        QMessageBox msgbox;
                        msgbox.setText("Pri shranjevanju profila je prislo do napake!");
                        msgbox.exec();
                    }
                }
                else { // there already is profile with this name
                    QMessageBox msgbox;
                    msgbox.setText("Profil s tem imenom ze obstaja! Prosim, spremenite ga!");
                    msgbox.exec();
                }
            }
            base.close();
        }
        QSqlDatabase::removeDatabase("create-new-profile");
    }
    else { // the profile name field is empty
        QMessageBox msgbox;
        msgbox.setText("Prosim vnesite ime profila!");
        msgbox.exec();
    }

}

void add_profile::fill_fields() {

    // this function fills all the fields of the profile

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
            sql_fill.prepare("SELECT * FROM profile WHERE user LIKE '" + vApp->id_user() + "' AND id LIKE '" + ui->txt_profile_id->text() + "'");
            sql_fill.exec();
            if ( sql_fill.next() ) {
                ui->txt_page_title->setText(sql_fill.value(sql_fill.record().indexOf("site_name")).toString());
                ui->txt_page_url->setText(sql_fill.value(sql_fill.record().indexOf("site_url")).toString());
                ui->txt_profile_name->setText(sql_fill.value(sql_fill.record().indexOf("profile_name")).toString());
            }
        }
        base.close();
    }
    QSqlDatabase::removeDatabase("fill-fields");

}

void add_profile::on_btn_delete_clicked() {

    // check if we have a profile name set, otherwise sent warning and abort
    if ( ui->txt_profile_id->text() !="" ) {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "delete-profile");
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

                // delete selected profile
                QSqlQuery sql_delete(base);
                sql_delete.prepare("DELETE FROM sources WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + ui->txt_profile_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                sql_delete.prepare("DELETE FROM medium WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + ui->txt_profile_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                sql_delete.prepare("DELETE FROM data WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + ui->txt_profile_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                sql_delete.prepare("DELETE FROM campaign WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + ui->txt_profile_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                sql_delete.prepare("DELETE FROM profile WHERE user LIKE '" + vApp->id_user() + "' AND id LIKE '" + ui->txt_profile_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                // set global profile id to null
                vApp->set_id_profile("");

                // clear form fields
                ui->txt_page_title->setText("");
                ui->txt_page_url->setText("");
                ui->txt_profile_id->setText("");
                ui->txt_profile_name->setText("");

                // display message
                QMessageBox msgbox;
                msgbox.setText("Profil je bil uspesno izbrisan!");
                msgbox.exec();

                // send signal to the main window to refresh profile combo box
                send("refresh-profiles");
            }
            base.close();
        }
        QSqlDatabase::removeDatabase("delete-profile");
    }

}

void add_profile::recieve(QString state) {

    // this function receives the signal send from main window and act acordingly

    if ( state == "0" ) { // we input a new profile
        ui->btn_save->setText("Vnesi");
        ui->txt_page_title->setText("");
        ui->txt_page_url->setText("");
        ui->txt_profile_id->setText("");
        ui->txt_profile_name->setText("");
    }
    else { // we have to fill the old profile and make it possible to change it
        ui->btn_save->setText("Spremeni");
        ui->txt_profile_id->setText(state);
        fill_fields();
    }

}
