#ifndef AMPHIBIAN_H
#define AMPHIBIAN_H

#include <QMainWindow>

namespace Ui {
class Amphibian;
}

class Amphibian : public QMainWindow
{
    Q_OBJECT

public:
    explicit Amphibian(QWidget *parent = nullptr);
    ~Amphibian();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonSave_clicked();

    void showMsg(QString text, QString type);

private:
    Ui::Amphibian *ui;
};

#endif // AMPHIBIAN_H
