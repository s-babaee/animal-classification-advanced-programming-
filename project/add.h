#ifndef ADD_H
#define ADD_H

#include <QMainWindow>

namespace Ui {
class Add;
}

class Add : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButtonFish_clicked();

    void on_pushButtonAmphibian_clicked();

    void on_pushButtonReptile_clicked();

    void on_pushButtonBird_clicked();

    void on_pushButtonMammal_clicked();

    void on_pushButtonSpecial_clicked();

private:
    Ui::Add *ui;
};

#endif // ADD_H
