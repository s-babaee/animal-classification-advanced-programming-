#ifndef ADDOBJ_H
#define ADDOBJ_H

#include <QMainWindow>

namespace Ui {
class addObj;
}

class addObj : public QMainWindow
{
    Q_OBJECT

public:
    explicit addObj(QWidget *parent = nullptr);
    ~addObj();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButton_clicked();

    void on_pushButtonBack_clicked();

    void showMsg(QString text, QString type);

private:
    Ui::addObj *ui;
};

#endif // ADDOBJ_H
