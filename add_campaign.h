#ifndef ADD_CAMPAIGN_H
#define ADD_CAMPAIGN_H

#include <QWidget>

namespace Ui {
class add_campaign;
}

class add_campaign : public QWidget
{
    Q_OBJECT
    
public:
    explicit add_campaign(QWidget *parent = 0);
    ~add_campaign();

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
    Ui::add_campaign *ui;
};

#endif // ADD_CAMPAIGN_H
