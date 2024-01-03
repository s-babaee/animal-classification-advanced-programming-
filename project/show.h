#ifndef SHOW_H
#define SHOW_H

#include <QMainWindow>

namespace Ui {
class Show;
}

class Show : public QMainWindow
{
    Q_OBJECT

public:
    explicit Show(QWidget *parent = nullptr);
    ~Show();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButtonShow_clicked();

    void on_pushButton_clicked();

    void showMsg(QString text, QString type);

private:
    Ui::Show *ui;
};

#endif // SHOW_H
