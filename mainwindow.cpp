#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addlink.h"
#include "add_profile.h"
#include "add_campaign.h"
#include "global.h"

#include <QtSql>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create database
    create_database();

    // set active user
    vApp->set_id_user("1");

    // hide
    ui->profile_id->setHidden(true);
    // hide all the campaign fields until the profile is not selected
    ui->label_2->setHidden(true);
    ui->campaign_id->setHidden(true);
    ui->campaign_name->setHidden(true);
    ui->new_campaign->setHidden(true);
    ui->btn_add_link->setHidden(true);

    // fill the profile combo box
    fill_profiles();

    // set active profile
    ui->profile_name->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Actions
void MainWindow::on_profile_id_textChanged() {

    if ( ui->profile_id->text() != "" ) {
        // change the global profile
        vApp->set_id_profile(ui->profile_id->text());
        vApp->set_id_campaign("");

        // set campaign forms to visible and refresh campaign combo box
        ui->label_2->setHidden(false);
        ui->campaign_name->setHidden(false);
        ui->new_campaign->setHidden(false);

        // fill campaign combo box
        fill_campaigns();

        // call the widget
        add_profile *widget = new add_profile;
        ui->scrollArea->setWidget(widget);
        setWindowTitle("Posodobitev obstojecega profila");
        QObject::connect(this, SIGNAL(send(QString)),
                     widget , SLOT(recieve(QString)));
        send(ui->profile_id->text()); // id of currently selected profile
        this->disconnect();

        // receive signal to refresh profile combo box
        QObject::connect(widget, SIGNAL(send(QString)),
                   this , SLOT(recieve(QString)));
    }
    else { // clear the widget placeholder
        on_new_profile_clicked();
        // hide all the campaign fields until the profile is not selected
        ui->label_2->setHidden(true);
        ui->campaign_name->setHidden(true);
        ui->new_campaign->setHidden(true);
        ui->btn_add_link->setHidden(true);
        ui->campaign_name->clear();
        vApp->set_id_campaign("");
        vApp->set_id_profile("");
        fill_links();
    }

}

void MainWindow::on_profile_name_currentIndexChanged() {

    if ( ui->profile_name->currentIndex() != 0 ) {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "get-profile-id");
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

                // fill profile combo box
                QSqlQuery sql_fill(base);
                sql_fill.prepare("SELECT * FROM profile WHERE user LIKE '" + vApp->id_user() + "' AND profile_name LIKE '" + ui->profile_name->currentText() + "'");
                sql_fill.exec();
                if ( sql_fill.next() ) {
                    ui->profile_id->setText(sql_fill.value(sql_fill.record().indexOf("id")).toString());
                }
                else { // if the profile for some reason does not exist, clear the ID field
                    ui->profile_id->setText("");
                }
            }
            base.close();
        }
        QSqlDatabase::removeDatabase("get-profile-id");
    }
    else { // clear the ID field
        ui->profile_id->setText("");
    }
}

void MainWindow::on_campaign_id_textChanged() {

    if ( ui->campaign_id->text() != "" ) {
        // change the global profile
        vApp->set_id_campaign(ui->campaign_id->text());
        fill_links();
        ui->btn_add_link->setHidden(false);

        // call the widget
        add_campaign *widget = new add_campaign;
        ui->scrollArea->setWidget(widget);
        setWindowTitle("Posodobitev obstojece kampanije");
        QObject::connect(this, SIGNAL(send(QString)),
                     widget , SLOT(recieve(QString)));
        send(ui->campaign_id->text()); // id of currently selected profile
        this->disconnect();

        // receive signal to refresh profile combo box
        QObject::connect(widget, SIGNAL(send(QString)),
                   this , SLOT(recieve(QString)));
    }
    else { // clear the widget placeholder
        vApp->set_id_campaign("");
        on_new_campaign_clicked();
        fill_links();
        ui->btn_add_link->setHidden(true);
    }

}

void MainWindow::on_campaign_name_currentIndexChanged() {

    if ( ui->campaign_name->currentIndex() != 0 ) {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "get-campaign-id");
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

                // fill profile combo box
                QSqlQuery sql_fill(base);
                sql_fill.prepare("SELECT * FROM campaign WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() +
                                 "' AND campaign_name LIKE '" + ui->campaign_name->currentText() + "'");
                sql_fill.exec();
                if ( sql_fill.next() ) {
                    ui->campaign_id->setText(sql_fill.value(sql_fill.record().indexOf("id")).toString());
                }
                else { // if the profile for some reason does not exist, clear the ID field
                    ui->campaign_id->setText("");
                }
            }
            base.close();
        }
        QSqlDatabase::removeDatabase("get-campaign-id");
    }
    else { // clear the ID field
        ui->campaign_id->setText("");
    }
}

void MainWindow::on_tbl_links_doubleClicked() {

    // call the widget
    AddLink *widget = new AddLink;
    ui->scrollArea->setWidget(widget);
    setWindowTitle("Vnos nove povezave");
    QObject::connect(this, SIGNAL(send(QString)),
                    widget , SLOT(recieve(QString)));
    send(ui->tbl_links->selectedItems().takeAt(0)->text()); // id of currently selected profile
    this->disconnect();

    // receive signal to refresh profile combo box
    QObject::connect(widget, SIGNAL(send(QString)),
                    this , SLOT(recieve(QString)));

}

// Buttons
void MainWindow::on_new_profile_clicked() {

    ui->profile_name->setCurrentIndex(0);
    add_profile *widget = new add_profile;
    ui->scrollArea->setWidget(widget);
    setWindowTitle("Vnos novega profila");
    QObject::connect(this, SIGNAL(send(QString)),
                 widget , SLOT(recieve(QString)));
    send("0"); // 0 == new
    this->disconnect();

    // receive signal to refresh profile combo box
    QObject::connect(widget, SIGNAL(send(QString)),
               this , SLOT(recieve(QString)));

}

void MainWindow::on_new_campaign_clicked() {

    ui->campaign_name->setCurrentIndex(0);
    add_campaign *widget = new add_campaign;
    ui->scrollArea->setWidget(widget);
    setWindowTitle("Vnos nove Kampanije");
    QObject::connect(this, SIGNAL(send(QString)),
                 widget , SLOT(recieve(QString)));
    send("0"); // 0 == new
    this->disconnect();

    // receive signal to refresh profile combo box
    QObject::connect(widget, SIGNAL(send(QString)),
               this , SLOT(recieve(QString)));

}

void MainWindow::on_btn_add_link_clicked() {

    if ( vApp->id_user() != "" && vApp->id_profile() != "" && vApp->id_campaign() != "" ) {
        // change the global profile
        vApp->set_id_campaign(ui->campaign_id->text());
        fill_links();

        // call the widget
        AddLink *widget = new AddLink;
        ui->scrollArea->setWidget(widget);
        setWindowTitle("Vnos nove povezave");
        QObject::connect(this, SIGNAL(send(QString)),
                            widget , SLOT(recieve(QString)));
        send("0"); // id of currently selected profile
        this->disconnect();

        // receive signal to refresh profile combo box
        QObject::connect(widget, SIGNAL(send(QString)),
                        this , SLOT(recieve(QString)));
    }
    else if ( vApp->id_user() == "" ) {
        QMessageBox msgbox;
        msgbox.setText("Uporabnisko ime ni nastavljeno!");
        msgbox.exec();
    }
    else if ( vApp->id_profile() == "" ) {
        QMessageBox msgbox;
        msgbox.setText("Profil strani ni nastavljen!");
        msgbox.exec();
    }
    else if ( vApp->id_campaign() == "" ) {
        QMessageBox msgbox;
        msgbox.setText("Kampanija ni nastavljena!");
        msgbox.exec();
    }
    else {
        QMessageBox msgbox;
        msgbox.setText("Prislo je do napake! Postopek se bo prekinil!");
        msgbox.exec();
    }

}

// Functions
void MainWindow::create_database() {

    QString app_path = QApplication::applicationDirPath();
    QString dbase_path = app_path + "/base.bz";

    {
        QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "create-new-tables");
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

            QSqlQuery sql_create_table(base);

            // create table for campaign sources
            sql_create_table.prepare(
                                    "CREATE TABLE IF NOT EXISTS sources ("
                                    "id INTEGER PRIMARY KEY, "
                                    "user TEXT, "
                                    "profile TEXT, "
                                    "campaign TEXT, "
                                    "source_name TEXT)"
                                    );
            sql_create_table.exec();
            sql_create_table.clear();

            // create table for campaign medium
            sql_create_table.prepare(
                                    "CREATE TABLE IF NOT EXISTS medium ("
                                    "id INTEGER PRIMARY KEY, "
                                    "user TEXT, "
                                    "profile TEXT, "
                                    "campaign TEXT, "
                                    "medium_name TEXT)"
                                    );
            sql_create_table.exec();
            sql_create_table.clear();

            // create table for page profile
            sql_create_table.prepare(
                                    "CREATE TABLE IF NOT EXISTS profile ("
                                    "id INTEGER PRIMARY KEY, "
                                    "user TEXT, "
                                    "profile_name TEXT, "
                                    "site_name TEXT, "
                                    "site_url TEXT)"
                                    );
            sql_create_table.exec();
            sql_create_table.clear();

            // create table for page profile
            sql_create_table.prepare(
                                    "CREATE TABLE IF NOT EXISTS campaign ("
                                    "id INTEGER PRIMARY KEY, "
                                    "user TEXT, "
                                    "profile TEXT, "
                                    "campaign_name TEXT, "
                                    "campaign_description TEXT)"
                                    );
            sql_create_table.exec();
            sql_create_table.clear();

            // create table for page profile
            sql_create_table.prepare(
                                    "CREATE TABLE IF NOT EXISTS data ("
                                    "id INTEGER PRIMARY KEY, "
                                    "user TEXT, "
                                    "profile TEXT, "
                                    "campaign TEXT, "
                                    "campaign_name TEXT, "
                                    "link_name TEXT, "
                                    "page_url TEXT, "
                                    "base_url TEXT, "
                                    "source TEXT, "
                                    "medium TEXT, "
                                    "content TEXT, "
                                    "preffix TEXT, "
                                    "comp_short TEXT, "
                                    "human_short TEXT, "
                                    "new_url TEXT, "
                                    "short_url TEXT)"
                                    );
            sql_create_table.exec();
            sql_create_table.clear();

        }
        base.close();
    }
    QSqlDatabase::removeDatabase("create-new-tables");
}

void MainWindow::fill_profiles() {

    ui->profile_name->clear();
    ui->profile_name->addItem("");

    QString app_path = QApplication::applicationDirPath();
    QString dbase_path = app_path + "/base.bz";

    {
        QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "fill-profiles");
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

            // fill profile combo box
            QSqlQuery sql_fill(base);
            sql_fill.prepare("SELECT * FROM profile WHERE user LIKE '" + vApp->id_user() + "'");
            sql_fill.exec();
            while ( sql_fill.next() ) {
                ui->profile_name->addItem(sql_fill.value(sql_fill.record().indexOf("profile_name")).toString());
            }
            sql_fill.clear();

            QSqlQuery sql_select(base);
            sql_select.prepare("SELECT * FROM profile WHERE user LIKE '" + vApp->id_user() + "' AND id LIKE '" + vApp->id_profile() + "'");
            sql_select.exec();
            if ( sql_select.next() ) {
                ui->profile_name->setCurrentIndex(ui->profile_name->findText(sql_select.value(sql_select.record().indexOf("profile_name")).toString()));
            }
        }
        base.close();
    }
    QSqlDatabase::removeDatabase("fill-profiles");

}

void MainWindow::fill_campaigns() {

    ui->campaign_name->clear();
    ui->campaign_name->addItem("");

    QString app_path = QApplication::applicationDirPath();
    QString dbase_path = app_path + "/base.bz";

    {
        QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "fill-campaign");
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

            // fill profile combo box
            QSqlQuery sql_fill(base);
            sql_fill.prepare("SELECT * FROM campaign WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "'");
            sql_fill.exec();
            while ( sql_fill.next() ) {
                ui->campaign_name->addItem(sql_fill.value(sql_fill.record().indexOf("campaign_name")).toString());
            }
            sql_fill.clear();

            QSqlQuery sql_select(base);
            sql_select.prepare("SELECT * FROM campaign WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND id LIKE '" + vApp->id_campaign() + "'");
            sql_select.exec();
            if ( sql_select.next() ) {
                ui->campaign_name->setCurrentIndex(ui->campaign_name->findText(sql_select.value(sql_select.record().indexOf("campaign_name")).toString()));
            }
        }
        base.close();
    }
    QSqlDatabase::removeDatabase("fill-campaign");

}

void MainWindow::fill_links() {

    QString app_path = QApplication::applicationDirPath();
    QString dbase_path = app_path + "/base.bz";

    {
        QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "fill-links");
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

            // clear the table
            ui->tbl_links->clear();

            for ( int i = 0; i <= 2; i++ ) {
                ui->tbl_links->removeColumn(0);
            }

            QSqlQuery sql_clear(base);
            sql_clear.prepare("SELECT * FROM data WHERE user LIKE '" + vApp->id_user() + "'");
            sql_clear.exec();
            while ( sql_clear.next() ) {
                ui->tbl_links->removeRow(0);
            }
            // in case we just deleted one row on will be left behind ...
            ui->tbl_links->removeRow(0);

            // start structuring new table
            ui->tbl_links->insertColumn(0);
            ui->tbl_links->insertColumn(1);

            QTableWidgetItem *naslov0 = new QTableWidgetItem;
            QTableWidgetItem *naslov1 = new QTableWidgetItem;

            naslov0->setText("ID");
            naslov1->setText("Ime povezave");

            ui->tbl_links->setHorizontalHeaderItem(0, naslov0);
            ui->tbl_links->setHorizontalHeaderItem(1, naslov1);

            ui->tbl_links->setColumnWidth(0, 35); // first column is with ID, so it can be short
            ui->tbl_links->setColumnWidth(1, 300);

            QSqlQuery sql_fill(base);
            sql_fill.prepare("SELECT * FROM data WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND campaign LIKE '" + vApp->id_campaign() + "'");
            sql_fill.exec();

            int row = 0;
            while (sql_fill.next()) {
                ui->tbl_links->insertRow(row);
                ui->tbl_links->setRowHeight(row, 20);

                int col = 0;
                int i = 0;
                QString polja[2] = {"id", "link_name"};
                while (col <= 1) {
                    QTableWidgetItem *celica = new QTableWidgetItem;
                    celica->setText(sql_fill.value(sql_fill.record().indexOf(polja[i])).toString());
                    ui->tbl_links->setItem(row, col, celica);
                    col++;
                    i++;
                }
                row++;
            }
        }
        base.close();
    }
    QSqlDatabase::removeDatabase("fill-links");

}

void MainWindow::recieve(QString state) {

    if ( state == "refresh-profiles" ) {
        // refresh the combo box
        fill_profiles();
    }
    else if ( state == "refresh-campaign" ) {
        // refresh the combo box
        fill_campaigns();
    }
    else if ( state == "refresh-links" ) {
        fill_links();
    }

}

// Global actions
void MainWindow::global_id_user_changed() {

}

void MainWindow::global_id_profile_changed() {

}

void MainWindow::global_id_campaign_changed() {

}
