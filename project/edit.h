#ifndef EDIT_H
#define EDIT_H

#include <QMainWindow>

namespace Ui {
class Edit;
}

class Edit : public QMainWindow
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    ~Edit();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButtonSearch_clicked();

    void reciveEditAnimal(int k);

    void showMsg(QString text, QString type);
private:
    Ui::Edit *ui;
};

#endif // EDIT_H
