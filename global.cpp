#include <QMessageBox>

#include "global.h"

global::global(int &argc, char *argv[]) :
QApplication(argc, argv) {

}

global::~global() {

}

// Getters
QString global::id_user() const {

    return m_id_user;

}

QString global::id_profile() const {

    return m_id_profile;

}

QString global::id_campaign() const {

    return m_id_campaign;

}

//Setters
void global::set_id_user(const QString &id_user) {

    m_id_user = id_user;

    QMessageBox msgbox;
    msgbox.setText("Novi prijavljeni uporabnik je " + id_user);
//    msgbox.exec();

    emit id_user_changed();

}

void global::set_id_profile(const QString &id_profile)	{

    m_id_profile = id_profile;

    QMessageBox msgbox;
    msgbox.setText("Novi profil je " + id_profile);
//    msgbox.exec();

    emit id_profile_changed();

}

void global::set_id_campaign(const QString &id_campaign) {

    m_id_campaign = id_campaign;

    QMessageBox msgbox;
    msgbox.setText("Nova kampanija je " + id_campaign);
//    msgbox.exec();

    emit id_campaign_changed();

}
