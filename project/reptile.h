#ifndef REPTILE_H
#define REPTILE_H

#include <QMainWindow>

namespace Ui {
class Reptile;
}

class Reptile : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reptile(QWidget *parent = nullptr);
    ~Reptile();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButton_clicked();

    void showMsg(QString text, QString type);

private:
    Ui::Reptile *ui;
};

#endif // REPTILE_H
