#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    // Menu
    void on_actionDodaj_Profil_triggered();
    void on_actionDodaj_Kampanjo_triggered();
    void on_actionDodaj_Povezavo_triggered();
    void on_actionUvoz_baze_triggered();
    void on_actionIzvoz_baze_triggered();

    // Buttons
    void on_new_profile_clicked();
    void on_new_campaign_clicked();
    void on_btn_add_link_clicked();

    // Functions
    void create_database();
    void fill_profiles();
    void fill_campaigns();
    void fill_links();

    // Actions
    void on_profile_id_textChanged();
    void on_profile_name_currentIndexChanged();
    void on_campaign_id_textChanged();
    void on_campaign_name_currentIndexChanged();
    void on_tbl_links_doubleClicked();

    // Global actions
    void global_id_user_changed();
    void global_id_profile_changed();
    void global_id_campaign_changed();

    void recieve(QString state);

signals:
    void send(QString state);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
