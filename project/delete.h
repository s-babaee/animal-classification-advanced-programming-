#ifndef DELETE_H
#define DELETE_H

#include <QMainWindow>

namespace Ui {
class Delete;
}

class Delete : public QMainWindow
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = nullptr);
    ~Delete();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButtonDelete_clicked();

    void showMsg(QString text, QString type);

private:
    Ui::Delete *ui;
};

#endif // DELETE_H
