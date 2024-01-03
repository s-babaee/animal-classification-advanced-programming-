#ifndef SPECIAL_H
#define SPECIAL_H

#include <QMainWindow>

namespace Ui {
class Special;
}

class Special : public QMainWindow
{
    Q_OBJECT

public:
    explicit Special(QWidget *parent = nullptr);
    ~Special();

private slots:
    void on_pushButtonBack_clicked();

    void showMsg(QString text, QString type);
    void on_pushButtonSave_clicked();

private:
    Ui::Special *ui;
};

#endif // SPECIAL_H
