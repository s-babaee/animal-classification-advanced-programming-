#ifndef BIRD_H
#define BIRD_H

#include <QMainWindow>

namespace Ui {
class Bird;
}

class Bird : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bird(QWidget *parent = nullptr);
    ~Bird();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonSave_clicked();

    void showMsg(QString text, QString type);

private:
    Ui::Bird *ui;
};

#endif // BIRD_H
