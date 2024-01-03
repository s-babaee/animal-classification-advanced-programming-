#include "search.h"
#include "ui_search.h"
#include "window2.h"

Search::Search(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_back_clicked()
{
    window2 *pg2 = new window2;
    pg2->show();
    this->hide();
}

