#include "delete.h"
#include "ui_delete.h"
#include "window2.h"
#include "QFile"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <fish.h>
#include <amphibian.h>
#include <reptile.h>
#include <bird.h>
#include <mammal.h>
#include <special.h>
#include <QDebug>

void Delete::showMsg(QString text, QString type){
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

Delete::Delete(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
    this->setWindowTitle("Delete animal");
}

Delete::~Delete()
{
    delete ui;
}

void deleteAnimal(QString user, int sum){

    QFile f("D:/project/userData/" + user + ".txt");  // source for files A,B,C
    f.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in(&f);

    QString line;
    QFile f3("D:/project/appData/piece_A.txt");       //Pouring into file A
    f3.open(QFile::WriteOnly | QFile :: Text);
    QTextStream out3(&f3);
    for(int i = 1; i <= sum; i++){
      line = in.readLine();
      out3 << line << endl;
    }
    f3.flush();
    f3.close();

    line = in.readLine();  // skip file B
    do {
        if(line.isNull()){
            break;
        }
        line = in.readLine();
     } while (line != "--------------------------");


    QFile f4("D:/project/appData/piece_C.txt"); //Pouring into file C
    f4.open(QFile::WriteOnly | QFile :: Text);
    QTextStream out4(&f4);
    out4 << line << endl;
    while(!line.isNull()){
      line = in.readLine();
      out4 << line << endl;
    }
    f4.flush();
    f4.close();

    f.flush();
    f.close();
    //*************************************************
    QString text_A = "", text_B, text_C = "";

    QFile file_a("D:/project/appData/piece_A.txt");   // copy to string text A
    file_a.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in_a(&file_a);
    text_A = in_a.readAll();
    file_a.flush();
    file_a.close();

    QFile file_c("D:/project/appData/piece_C.txt");   // copy to string text C
    file_c.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in_c(&file_c);
    text_C = in_c.readAll();
    file_c.flush();
    file_c.close();

    QFile source_file("D:/project/userData/" + user + ".txt");
    source_file.open(QFile::WriteOnly | QFile :: Text);
    QTextStream out_src(&source_file);

    out_src << text_A << text_C;

    source_file.flush();
    source_file.close();

}

void Delete::on_pushButton_back_clicked()
{
    window2 *pg2 = new window2;
    pg2->show();
    this->hide();
}

void Delete::on_pushButtonDelete_clicked()
{
    QString name = ui->lineEditName->text();
    QString nikeName = ui->lineEditNikeName->text();

    if(name == ""){
        showMsg("complete name please.","Error");
        return;
    }

    if(nikeName == ""){
        showMsg("complete nike name please.","Error");
        return;
    }

    QFile f("D:/project/user.txt");       // find username
    f.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in(&f);
    QString user = in.readLine();
    f.flush();
    f.close();

    bool find = false;                   // find animal
    QString l1, l2, l3;
    int sum = 0;
    QFile f2("D:/project/userData/" + user + ".txt");
    f2.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in2(&f2);

    do {
        l1 = in2.readLine();
        sum++;
        if(l1 == "--------------------------"){
            l2 = in2.readLine();
            sum++;
            if(l2 == name){
                l3 = in2.readLine();
                sum++;
                if(l3 == nikeName){
                    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                      "Delete animal","Are you sure you want to delete this information?",
                                                       QMessageBox::Yes | QMessageBox::No );
                    if(reply == QMessageBox::Yes){
                        find = true;
                        deleteAnimal(user, sum - 3);
                        showMsg("Animal information was successfully deleted.","information");
                    }else{
                        return;
                    }
                }
            }

         }
    }while (! l1.isNull());
    if(!find){
        QMessageBox::critical(this,"ERROR","   animal not Found !  ");
    }
}

