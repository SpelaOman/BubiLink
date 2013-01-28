#include <QApplication>

#include "mainwindow.h"
#include "global.h"

int main(int argc, char *argv[])
{
    global app(argc, argv);

    MainWindow *global_MainWindow = new MainWindow;
    QObject::connect(&app, SIGNAL(id_user_changed()), global_MainWindow, SLOT(global_id_user_changed()));
    QObject::connect(&app, SIGNAL(id_profile_changed()), global_MainWindow, SLOT(global_id_profile_changed()));
    QObject::connect(&app, SIGNAL(id_campaign_changed()), global_MainWindow, SLOT(global_id_campaign_changed()));

    global_MainWindow->show();

    return app.exec();

}
