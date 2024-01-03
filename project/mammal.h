#ifndef MAMMAL_H
#define MAMMAL_H

#include <QMainWindow>

namespace Ui {
class Mammal;
}

class Mammal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mammal(QWidget *parent = nullptr);
    ~Mammal();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonSave_clicked();

    void showMsg(QString text, QString type);

private:
    Ui::Mammal *ui;
};

#endif // MAMMAL_H
