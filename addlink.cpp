#include "addlink.h"
#include "ui_addlink.h"
#include "global.h"

#include <QCompleter>
#include <QtSql>
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>

AddLink::AddLink(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddLink)
{
    ui->setupUi(this);

    // hide fields
    ui->label_13->setHidden(true);
    ui->txt_link_id->setHidden(true);
    ui->txt_comp_try->setHidden(true);
    ui->txt_explanation->setHidden(true);

    // Introduce completers
    introduce_completers();

    // Color must fill fields
    ui->txt_original_url->setStyleSheet("QLineEdit{background: #DF6561;}");
    ui->txt_medium->setStyleSheet("QLineEdit{background: #DF6561;}");
    ui->txt_source->setStyleSheet("QLineEdit{background: #DF6561;}");
    ui->txt_content->setStyleSheet("QLineEdit{background: #DF6561;}");

}

AddLink::~AddLink()
{
    delete ui;
}

void AddLink::on_btn_save_clicked() {

    save();

}

void AddLink::on_btn_create_clicked() {

    create_url();

}

void AddLink::on_btn_delete_clicked() {

    if ( ui->txt_link_id->text() != "" ) {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "delete-data");
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

                QSqlQuery sql_delete(base);
                sql_delete.prepare("DELETE FROM data WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() +
                                   "' AND campaign LIKE '" + vApp->id_campaign() + "' AND id LIKE '" + ui->txt_link_id->text() + "'");
                sql_delete.exec();
                sql_delete.clear();

                fill_fields();

            }
            base.close();
        }
        QSqlDatabase::removeDatabase("delete-data");

        // reload the completers
        introduce_completers();

        // fill and empty fields
        fill_fields();

        // send signal to the main window to refresh links table
        send("refresh-links");
    }

}

void AddLink::on_txt_original_url_textChanged() {

    if ( ui->txt_original_url->text() != "" ) {
        ui->txt_original_url->setStyleSheet("");
    }
    else {
        ui->txt_original_url->setStyleSheet("QLineEdit{background: #DF6561;}");
    }

}

void AddLink::on_txt_medium_textChanged() {

    if ( ui->txt_medium->text() != "" ) {
        ui->txt_medium->setStyleSheet("");
    }
    else {
        ui->txt_medium->setStyleSheet("QLineEdit{background: #DF6561;}");
    }

}

void AddLink::on_txt_source_textChanged() {

    if ( ui->txt_source->text() != "" ) {
        ui->txt_source->setStyleSheet("");
    }
    else {
        ui->txt_source->setStyleSheet("QLineEdit{background: #DF6561;}");
    }

}

void AddLink::on_txt_content_textChanged() {

    if ( ui->txt_content->text() != "" ) {
        ui->txt_content->setStyleSheet("");
    }
    else {
        ui->txt_content->setStyleSheet("QLineEdit{background: #DF6561;}");
    }

}

void AddLink::fill_fields() {

    // empty all fields
    ui->txt_link_id->setText("");
    ui->txt_original_url->setText("");
    ui->txt_source->setText("");
    ui->txt_medium->setText("");
    ui->txt_content->setText("");
    ui->txt_short_computer->setText("");
    ui->txt_short_human->setText("");
    ui->txt_new_url->setText("");
    ui->txt_short_url->setText("");
    ui->txt_link_name->setText("");
    ui->txt_campaign_name->setText("");
    ui->txt_base_url->setText("");
    ui->txt_url_preffix->setText("");

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
            sql_fill.prepare("SELECT * FROM campaign WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND id LIKE '" + vApp->id_campaign() + "'");
            sql_fill.exec();
            if ( sql_fill.next() ) {
                ui->txt_campaign_name->setText(sql_fill.value(sql_fill.record().indexOf("campaign_name")).toString());
                ui->txt_link_name->setText(sql_fill.value(sql_fill.record().indexOf("campaign_name")).toString());
                QSqlQuery sql_profile(base);
                sql_profile.prepare("SELECT * FROM profile WHERE user LIKE '" + vApp->id_user() + "' AND id LIKE '" + vApp->id_profile() + "'");
                sql_profile.exec();
                if ( sql_profile.next() ) {
                    ui->txt_base_url->setText(sql_profile.value(sql_profile.record().indexOf("site_url")).toString());
                }
            }
        }
        base.close();
    }
    QSqlDatabase::removeDatabase("fill-fields");

    // create unique short string that can be used for url rewrite
    ui->txt_short_computer->setText("");
    randomizator(1);

}

void AddLink::introduce_completers() {

    QStringList list_sources;
    QStringList list_medium;

    QString app_path = QApplication::applicationDirPath();
    QString dbase_path = app_path + "/base.bz";

    {
        QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "select-completers");
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

            QSqlQuery sql_select(base);
            sql_select.prepare("SELECT * FROM sources WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND campaign LIKE '" + vApp->id_campaign() + "'");
            sql_select.exec();
            while ( sql_select.next() ) {
                list_sources.append(sql_select.value(sql_select.record().indexOf("source_name")).toString());
            }
            sql_select.clear();

            sql_select.prepare("SELECT * FROM medium WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND campaign LIKE '" + vApp->id_campaign() + "'");
            sql_select.exec();
            while ( sql_select.next() ) {
                list_medium.append(sql_select.value(sql_select.record().indexOf("medium_name")).toString());
            }
            sql_select.clear();

        }
        base.close();
    }
    QSqlDatabase::removeDatabase("select-completers");

    QCompleter *completer_sources = new QCompleter(list_sources, this);
    completer_sources->setCaseSensitivity(Qt::CaseInsensitive);
    ui->txt_source->setCompleter(completer_sources);

    QCompleter *completer_medium = new QCompleter(list_medium, this);
    completer_medium->setCaseSensitivity(Qt::CaseInsensitive);
    ui->txt_medium->setCompleter(completer_medium);

}

void AddLink::save_source() {

    if ( ui->txt_source->text() != "" ) {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "save-source");
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

                QSqlQuery sql_find(base);
                sql_find.prepare("SELECT * FROM sources WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() +
                                 "' AND campaign LIKE '" + vApp->id_campaign() + "' AND source_name LIKE '" + ui->txt_source->text() + "'");
                sql_find.exec();
                if ( !sql_find.next() ) {
                    QSqlQuery sql_insert(base);
                    sql_insert.prepare("INSERT INTO sources (user, profile, campaign, source_name) VALUES (?, ?, ?, ?)");
                    sql_insert.bindValue(0, vApp->id_user());
                    sql_insert.bindValue(1, vApp->id_profile());
                    sql_insert.bindValue(2, vApp->id_campaign());
                    sql_insert.bindValue(3, ui->txt_source->text());
                    sql_insert.exec();
                }
            }
            base.close();
        }
        QSqlDatabase::removeDatabase("save-source");
    }
    else { // There is no source, so non will be saved
        QMessageBox msgbox;
        msgbox.setText("Vir je prazen! Prosim, navedite vir!");
        msgbox.exec();
    }

}

void AddLink::save_medium() {

    if ( ui->txt_medium->text() != "" ) {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "save-medium");
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

                QSqlQuery sql_find(base);
                sql_find.prepare("SELECT * FROM medium WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() +
                                 "' AND campaign LIKE '" + vApp->id_campaign() + "' AND medium_name LIKE '" + ui->txt_medium->text() + "'");
                sql_find.exec();
                if ( !sql_find.next() ) {
                    QSqlQuery sql_insert(base);
                    sql_insert.prepare("INSERT INTO medium (user, profile, campaign, medium_name) VALUES (?, ?, ?, ?)");
                    sql_insert.bindValue(0, vApp->id_user());
                    sql_insert.bindValue(1, vApp->id_profile());
                    sql_insert.bindValue(2, vApp->id_campaign());
                    sql_insert.bindValue(3, ui->txt_medium->text());
                    sql_insert.exec();
                }
            }
            base.close();
        }
        QSqlDatabase::removeDatabase("save-medium");
    }
    else { // There is no source, so non will be saved
        QMessageBox msgbox;
        msgbox.setText("Medij je prazen! Prosim, navedite ga!");
        msgbox.exec();
    }

}

void AddLink::save() {

    // check for data correctness
    bool field_error = false; // false == no error // true == error

    // check for actual value in the fields
    if ( ui->txt_original_url->text() == "" ) {
        field_error = true;
        QMessageBox msgbox;
        msgbox.setText("Prosim, vnesite URL strani, za katero zelite postaviti oznake!");
        msgbox.exec();
        ui->txt_original_url->setFocus();
        ui->txt_original_url->setStyleSheet("QLineEdit{background: #DF6561;}");
        return;
    }

    if ( ui->txt_medium->text() == "" ) {
        field_error = true;
        QMessageBox msgbox;
        msgbox.setText("Prosim, vnesite medij, za katero zelite postaviti oznake!");
        msgbox.exec();
        ui->txt_medium->setFocus();
        ui->txt_medium->setStyleSheet("QLineEdit{background: #DF6561;}");
        return;
    }

    if ( ui->txt_source->text() == "" ) {
        field_error = true;
        QMessageBox msgbox;
        msgbox.setText("Prosim, vnesite vir, za katero zelite postaviti oznake!");
        msgbox.exec();
        ui->txt_source->setFocus();
        ui->txt_source->setStyleSheet("QLineEdit{background: #DF6561;}");
        return;
    }

    if ( ui->txt_content->text() == "" ) {
        field_error = true;
        QMessageBox msgbox;
        msgbox.setText("Prosim, vnesite vsebino znacilno za dano povezavo, za katero zelite postaviti oznake!");
        msgbox.exec();
        ui->txt_content->setFocus();
        ui->txt_content->setStyleSheet("QLineEdit{background: #DF6561;}");
        return;
    }

    // if no errors do the saving
    if ( field_error == false ) {
        // first, do the url creation once more - in case something changed
        create_url();

        // second, save source and medium
        save_source();
        save_medium();

        // now, save the data into
        if ( ui->txt_link_name->text() != "" ) {
            QString app_path = QApplication::applicationDirPath();
            QString dbase_path = app_path + "/base.bz";

            {
                QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "save-data");
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

                    // scroll through data to determinate if this is really new link or not
                    QSqlQuery sql_check(base);
                    sql_check.prepare("SELECT * FROM data WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND campaign LIKE '" + vApp->id_campaign() +
                                      "' AND link_name LIKE '" + ui->txt_link_name->text() + "' AND id NOT LIKE '" + ui->txt_link_id->text() + "'");
                    sql_check.exec();
                    if ( !sql_check.next() ) {
                        QSqlQuery sql_insert(base);
                        if ( ui->txt_link_id->text() == "" ) { // we insert new data
                            sql_insert.prepare("INSERT INTO data (user, profile, campaign, campaign_name, link_name, page_url, base_url, source, medium, content, "
                                               "preffix, comp_short, human_short, new_url, short_url) VALUES (?, ?, ?, ?, ?, ? ,?, ?, ?, ?, ?, ?, ?, ?, ?)");
                        }
                        else { // we update existing data
                            sql_insert.prepare("UPDATE data SET user = ?, profile = ?, campaign = ?, campaign_name = ?, link_name = ?, page_url = ?, base_url = ?, "
                                               "source = ?, medium = ?, content = ?, preffix = ?, comp_short = ?, human_short = ?, new_url = ?, short_url = ? "
                                               "WHERE id LIKE '" + ui->txt_link_id->text() + "'");
                        }
                        sql_insert.bindValue(0, vApp->id_user());
                        sql_insert.bindValue(1, vApp->id_profile());
                        sql_insert.bindValue(2, vApp->id_campaign());
                        sql_insert.bindValue(3, ui->txt_campaign_name->text());
                        sql_insert.bindValue(4, ui->txt_link_name->text());
                        sql_insert.bindValue(5, ui->txt_original_url->text());
                        sql_insert.bindValue(6, ui->txt_base_url->text());
                        sql_insert.bindValue(7, ui->txt_source->text());
                        sql_insert.bindValue(8, ui->txt_medium->text());
                        sql_insert.bindValue(9, ui->txt_content->text());
                        sql_insert.bindValue(10, ui->txt_url_preffix->text());
                        sql_insert.bindValue(11, ui->txt_short_computer->text());
                        sql_insert.bindValue(12, ui->txt_short_human->text());
                        sql_insert.bindValue(13, ui->txt_new_url->text());
                        sql_insert.bindValue(14, ui->txt_short_url->text());
                        sql_insert.exec();

                        QMessageBox msgbox;
                        msgbox.setText("Povezava je bila uspesno shranjena!");
                        msgbox.exec();
                    }
                    else { // there already is a link with this name
                        QMessageBox msgbox;
                        msgbox.setText("Povezava s tem imenom ze obstaja! Prosim, spremenite jo!");
                        msgbox.exec();
                    }
                }
                base.close();
            }
            QSqlDatabase::removeDatabase("save-data");
        }
        else {
            QMessageBox msgbox;
            msgbox.setText("Prosim vnesite ime povezave!");
            msgbox.exec();
        }

        // reload the completers
        introduce_completers();

        // send signal to the main window to refresh links table
        send("refresh-links");
    }

}

QString AddLink::string_sanitizer(QString word) {

    // set a reg. expr. for characters, that are NOT allowed
    QRegExp allowed_char("[^A-Za-z0-9\\_]");

    // replace all NOT allowed char's with dash
    word.replace(allowed_char, "-");

    // erase double dashs
    while ( word.contains("--") ) {
        word.replace("--", "-");
    }

    // set the string to the lower case
    word = word.toLower();

    // return the result
    return word;

}

void AddLink::create_url() {

    // put everything to lower case and eliminate special char's and spaces
    ui->txt_source->setText(string_sanitizer(ui->txt_source->text()));
    ui->txt_medium->setText(string_sanitizer(ui->txt_medium->text()));
    ui->txt_content->setText(string_sanitizer(ui->txt_content->text()));
    ui->txt_url_preffix->setText(string_sanitizer(ui->txt_url_preffix->text()));
    ui->txt_short_human->setText(string_sanitizer(ui->txt_short_human->text()));
    QString campaign_name = string_sanitizer(ui->txt_campaign_name->text());

    // break url on url, parameters and anchors
    QString url = ui->txt_original_url->text();
    QString parameters;
    QString anchors;

    if ( url.contains("#") ) {
        anchors = url.right(url.length() - url.indexOf("#", 0) - 1);
        url = url.left(url.indexOf("#", 0));
    }

    if ( url.contains("?") ) {
        parameters = url.right(url.length() - url.indexOf("?", 0) - 1);
        url = url.left(url.indexOf("?", 0));
    }

    // combine new parameters
    QString campaign;
    if ( campaign_name != "" ) {
        campaign = "&utm_campaign=" + campaign_name;
    }
    QString source;
    if ( ui->txt_source->text() != "" ) {
        source = "&utm_source=" + ui->txt_source->text();
    }
    QString medium;
    if ( ui->txt_medium->text() != "" ) {
        medium = "&utm_medium=" + ui->txt_medium->text();
    }
    QString content;
    if ( ui->txt_content->text() != "" ) {
        content = "&utm_content=" + ui->txt_content->text();
    }

    // replace possible duplicate differentiators
    QString new_url = url + "?" + parameters + "&" + campaign + source + medium + content + "#" + anchors;
    new_url.replace("??", "?");
    new_url.replace("&&", "&");
    new_url.replace("##", "#");
    new_url.replace(" ", "-");
    new_url.replace("?&", "?");
    new_url.toLower();

    if ( new_url.right(1) == "#" || new_url.right(1) == "?" ) {
        new_url = new_url.left(new_url.length() - 1);
    }

    // display new url
    ui->txt_new_url->setText(new_url);

    // look at the database if there is already the url that we build and get it's short form
    QString app_path = QApplication::applicationDirPath();
    QString dbase_path = app_path + "/base.bz";

    {
        QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "find-url");
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

            // compare url to the saved and if no match create short string used for url rewrite
            QSqlQuery sql_find(base);
            sql_find.prepare("SELECT * FROM data WHERE user LIKE '" + vApp->id_user() + "' AND new_url LIKE '" + new_url + "'");
            sql_find.exec();
            if ( sql_find.next() ) {
                ui->txt_short_computer->setText(sql_find.value(sql_find.record().indexOf("comp_short")).toString());
                ui->txt_short_human->setText(sql_find.value(sql_find.record().indexOf("human_short")).toString());
                QMessageBox msgbox;
                msgbox.setText("Kreiran URL ze obstaja, tako da nova dejanja niso potrebna.\nNajdete ga pod imenom:\n" +
                               sql_find.value(sql_find.record().indexOf("link_name")).toString() + ".");
                msgbox.exec();
                return;
            }
            sql_find.clear();

            // check is human provided short string is
            if ( ui->txt_short_human->text() != "" ) {
                sql_find.prepare("SELECT * FROM data WHERE user LIKE '" + vApp->id_user() + "' AND human_short LIKE '" + ui->txt_short_human->text() + "'");
                sql_find.exec();
                if ( sql_find.next() ) {
                    QMessageBox msgbox;
                    msgbox.setText("Rocna okrajsava ze obstaja. Prosim, spremenite jo!");
                    ui->txt_short_human->setText("");
                    return;
                }
                sql_find.clear();
            }
        }
        base.close();
    }
    QSqlDatabase::removeDatabase("find-url");

    // remove first and last / from url preffix
    while ( ui->txt_url_preffix->text().left(1) == "/" ) {
        ui->txt_url_preffix->setText(ui->txt_url_preffix->text().right(ui->txt_url_preffix->text().length() - 1));
    }
    while ( ui->txt_url_preffix->text().right(1) == "/" ) {
        ui->txt_url_preffix->setText(ui->txt_url_preffix->text().left(ui->txt_url_preffix->text().length() - 1));
    }

    url = ui->txt_base_url->text();
    if ( url.right(1) != "/" ) {
        url = url + "/";
    }
    url = url + ui->txt_url_preffix->text();
    if ( url.right(1) != "/" ) {
        url = url + "/";
    }

    // create short url
    if ( ui->txt_short_human->text() != "" ) {
        ui->txt_short_url->setText(url + ui->txt_short_human->text() + "/");
    }
    else if ( ui->txt_short_computer->text() != "" ) {
        ui->txt_short_url->setText(url + ui->txt_short_computer->text() + "/");
    }

}

void AddLink::randomizator(int zaporedna) {

    ui->txt_comp_try->setText(QString::number(zaporedna, 10));

    // timer wait for 1 milisecond than generates new letter
    QTimer::singleShot(1, this, SLOT(generator()));

}

void AddLink::generator() {

    int zaporedna = ui->txt_comp_try->text().toInt();

    int i_random = 0;
    QString s_number = "";

    while ( i_random > 90 || i_random < 65 ) {

        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());

        i_random = qrand() % 100;

    }

    s_number = QChar(i_random);

    ui->txt_short_computer->setText(ui->txt_short_computer->text().toLower() + s_number.toLower());

    // ce je stevilo generiranih znakov manj kot 5 klici nov timer
    if ( zaporedna < 8 ) {

        randomizator(zaporedna + 1);

    }
    else {
        QString app_path = QApplication::applicationDirPath();
        QString dbase_path = app_path + "/base.bz";

        {
            QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "find-string");
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

                QSqlQuery sql_find(base);
                sql_find.prepare("SELECT * FROM data WHERE comp_short LIKE '" + ui->txt_short_computer->text() + "'");
                sql_find.exec();
                if ( sql_find.next() ) {
                    // we have found the string already exist in the database, so we will create it again
                    ui->txt_short_computer->setText("");
                    randomizator(1);
                }
            }
            base.close();
        }
        QSqlDatabase::removeDatabase("find-string");
    }

}

void AddLink::recieve(QString state) {

    if ( state == "0" ) { // we have new entry
        ui->btn_save->setText("Vnesi");
        fill_fields();
    }
    else { // state has the ID of existing entry
        ui->btn_save->setText("Posodobi");
        show_data(state);
    }

}

void AddLink::show_data(QString id) {

    ui->txt_link_id->setText(id);

    ui->txt_link_id->setHidden(false);

    QString app_path = QApplication::applicationDirPath();
    QString dbase_path = app_path + "/base.bz";

    {
        QSqlDatabase base = QSqlDatabase::addDatabase("QSQLITE", "show-data");
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
            sql_fill.prepare("SELECT * FROM data WHERE user LIKE '" + vApp->id_user() + "' AND profile LIKE '" + vApp->id_profile() + "' AND campaign LIKE '" + vApp->id_campaign() +
                             "' AND id LIKE '" + id + "'");
            sql_fill.exec();
            if ( sql_fill.next() ) {
                ui->txt_link_id->setText(sql_fill.value(sql_fill.record().indexOf("id")).toString());
                ui->txt_original_url->setText(sql_fill.value(sql_fill.record().indexOf("page_url")).toString());
                ui->txt_source->setText(sql_fill.value(sql_fill.record().indexOf("source")).toString());
                ui->txt_medium->setText(sql_fill.value(sql_fill.record().indexOf("medium")).toString());
                ui->txt_content->setText(sql_fill.value(sql_fill.record().indexOf("content")).toString());
                ui->txt_short_computer->setText(sql_fill.value(sql_fill.record().indexOf("comp_short")).toString());
                ui->txt_short_human->setText(sql_fill.value(sql_fill.record().indexOf("human_short")).toString());
                ui->txt_new_url->setText(sql_fill.value(sql_fill.record().indexOf("new_url")).toString());
                ui->txt_short_url->setText(sql_fill.value(sql_fill.record().indexOf("short_url")).toString());
                ui->txt_link_name->setText(sql_fill.value(sql_fill.record().indexOf("link_name")).toString());
                ui->txt_campaign_name->setText(sql_fill.value(sql_fill.record().indexOf("campaign_name")).toString());
                ui->txt_base_url->setText(sql_fill.value(sql_fill.record().indexOf("base_url")).toString());
                ui->txt_url_preffix->setText(sql_fill.value(sql_fill.record().indexOf("preffix")).toString());
            }
        }
        base.close();
    }
    QSqlDatabase::removeDatabase("show-data");

}
