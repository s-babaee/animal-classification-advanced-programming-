#include "window2.h"
#include "ui_window2.h"
#include "QPushButton"
#include "add.h"
#include "show.h"
#include "edit.h"
#include "delete.h"
#include "search.h"
#include <QHash>
#include <QCryptographicHash>
#include <QDataStream>
#include <iostream>




window2::window2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window2)
{
    ui->setupUi(this);
    this->setWindowTitle("list");
}

window2::~window2()
{
    delete ui;
}

void window2::on_pushButton_clicked()
{
    Add *add = new Add;
    add->show();
    this->hide();
}

void window2::on_pushButton_2_clicked()
{
    Show *show = new Show;
    show->show();
    this->hide();
}

void window2::on_pushButton_3_clicked()
{
    Edit *edit = new Edit;
    edit->show();
    this->hide();
}

void window2::on_pushButton_4_clicked()
{
    Delete *dlt = new Delete;
    dlt->show();
    this->hide();
}

