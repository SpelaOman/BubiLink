#ifndef VARNOST_H
#define VARNOST_H

#include <QApplication>
#define vApp ((global *) qApp)

class global : public QApplication
{
    Q_OBJECT

public:
    explicit global(int &argc, char *argv[]);
    ~global();

    // Getters
    QString id_user() const;
    QString id_profile() const;
    QString id_campaign() const;;

    // Setters
    void set_id_user(const QString &id_user);
    void set_id_profile(const QString &id_profile);
    void set_id_campaign(const QString &id_campaign);

signals:
    void id_user_changed();
    void id_profile_changed();
    void id_campaign_changed();

private:
    QString m_id_user;
    QString m_id_profile;
    QString m_id_campaign;

};


#endif // GLOBAL_H
