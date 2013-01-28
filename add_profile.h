#ifndef ADD_PROFILE_H
#define ADD_PROFILE_H

#include <QWidget>

namespace Ui {
class add_profile;
}

class add_profile : public QWidget
{
    Q_OBJECT
    
public:
    explicit add_profile(QWidget *parent = 0);
    ~add_profile();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_delete_clicked();

    // Functions
    void fill_fields();

    // receiver slot
    void recieve(QString state);

signals:
    void send(QString state);

private:
    Ui::add_profile *ui;
};

#endif // ADD_PROFILE_H
