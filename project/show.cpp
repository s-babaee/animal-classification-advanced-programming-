#include "show.h"
#include "ui_show.h"
#include "window2.h"
#include "QFile"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

void Show::showMsg(QString text, QString type){
    QMessageBox msg(this);
    msg.setText(text);
    if(type == "Error"){
        msg.setIcon(QMessageBox::Critical);
        msg.setWindowTitle("ERROR");
        msg.setStyleSheet("background-color: #CF6679; border: none ;font-family: Arial"
                          "; font-style: normal;  font-size: 15pt; color: #000000 ;");
    }
    if(type == "Information"){
        msg.setIcon(QMessageBox::Information);
        msg.setWindowTitle("information");
        msg.setStyleSheet("background-color: #03DAC5; border: none ;font-family: Arial"
                          "; font-style: normal;  font-size: 15pt; color: rgb(255, 255, 255) ;");
    }
    msg.exec();
}

Show::Show(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Show)
{
    ui->setupUi(this);
    this->setWindowTitle("Show Animal");
}

Show::~Show()
{
    delete ui;
}

void Show::on_pushButton_back_clicked()
{
    window2 *pg2 = new window2;
    pg2->show();
    this->hide();
}


void Show::on_pushButtonShow_clicked()
{
    QString name = ui->lineEditName->text();
    QString nikeName = ui->lineEdit_NikeName->text();

    QFile f("D:/project/user.txt");
    f.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in(&f);
    QString user = in.readLine();
    f.flush();
    f.close();

    QString l1, l2, l3, l4 = " ", text;
    bool find = false;
    QFile f2("D:/project/userData/" + user + ".txt");
    f2.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in2(&f2);
    do {
        l1 = in2.readLine();
        if(l1 == "--------------------------"){
            l2 = in2.readLine();
            if(l2 == name){
                l3 = in2.readLine();
                if(l3 == nikeName){
                    QFile f3("D:/project/show.txt");
                    f3.open(QFile::WriteOnly | QFile :: Text);
                    QTextStream out3(&f3);
                    out3 << "Name : " << name << endl;
                    out3 << "Nike Name : " << nikeName << endl;

                    while(l4 != "--------------------------"){
                        l4 = in2.readLine();
                        if(l4.isNull())
                            break;
                        out3 << l4 << endl;
                    }
                    f3.flush();
                    f3.close();

                    QFile f4("D:/project/show.txt");
                    f4.open(QFile::ReadOnly | QFile :: Text);
                    QTextStream in(&f4);
                    text = in.readAll();
                    ui->plainTextEdit->setPlainText(text);
                    f4.flush();
                    f4.close();
                    find = true;
                    break;
                }
            }
        }
   } while (! l1.isNull() );
    if(!find)
        showMsg("No animals were found with this specification.","Error");
}


void Show::on_pushButton_clicked()
{
    QFile f("D:/project/user.txt");             // recive user
    f.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in(&f);
    QString user = in.readLine();
    f.flush();
    f.close();

    QFile f2("D:/project/userData/" + user + ".txt");
    f2.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in2(&f2);
    QString text = in2.readAll();
    ui->plainTextEdit->setPlainText(text);
    f2.flush();
    f2.close();
}

