#ifndef WINDOW2_H
#define WINDOW2_H

#include <QMainWindow>

namespace Ui {
class window2;
}

class window2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit window2(QWidget *parent = nullptr);
    ~window2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::window2 *ui;
};

#endif // WINDOW2_H
