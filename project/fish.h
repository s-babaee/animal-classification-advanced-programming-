#ifndef FISH_H
#define FISH_H

#include <QMainWindow>

namespace Ui {
class Fish;
}

class Fish : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fish(QWidget *parent = nullptr);
    ~Fish();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonSave_clicked();

    void showMsg(QString text, QString type);

private:
    Ui::Fish *ui;
};

#endif // FISH_H
