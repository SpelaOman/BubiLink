#ifndef ADDLINK_H
#define ADDLINK_H

#include <QWidget>

namespace Ui {
class AddLink;
}

class AddLink : public QWidget
{
    Q_OBJECT
    
public:
    explicit AddLink(QWidget *parent = 0);
    ~AddLink();
    
private slots:
    // actions
    void on_btn_save_clicked();
    void on_btn_create_clicked();
    void on_btn_delete_clicked();

    // field actions
    void on_txt_original_url_textChanged();
    void on_txt_medium_textChanged();
    void on_txt_source_textChanged();
    void on_txt_content_textChanged();

    // functions
    void fill_fields();
    void show_data(QString id);
    void introduce_completers();
    void randomizator(int zaporedna);
    void generator();
    QString string_sanitizer(QString word);

    // save functions
    void save_source();
    void save_medium();
    void save();

    // create new url
    void create_url();

    // receiver slot
    void recieve(QString state);

signals:
    void send(QString state);

private:
    Ui::AddLink *ui;
};

#endif // ADDLINK_H
