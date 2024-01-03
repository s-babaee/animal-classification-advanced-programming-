#include "edit.h"
#include "ui_edit.h"
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

void Edit::showMsg(QString text, QString type){
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

Edit::Edit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit Animal");
}

Edit::~Edit()
{
    delete ui;
}


void Edit::reciveEditAnimal(int k){

    QFile f1("D:/project/appData/mode.txt");      // enter edit mode
    f1.open(QFile::WriteOnly | QFile :: Text);
    QTextStream out1(&f1);
    out1 << "edit\n";
    f1.flush();
    f1.close();

    if(k == 1){
        Fish *fish = new Fish;
        fish->show();
        this->hide();
    }
    if(k == 2){
        Amphibian *amph = new Amphibian;
        amph->show();
        this->hide();
    }
    if(k == 3){
        Reptile *rep = new Reptile;
            rep->show();
            this->hide();
    }
    if(k == 4){
        Bird *brd = new Bird;
            brd->show();
            this->hide();
    }
    if(k == 5){
        Mammal *mml = new Mammal;
            mml->show();
            this->hide();
    }
}

void replaceAnimal(QString user, int sum){

    QFile f("D:/project/userData/" + user + ".txt");  // source for files A,B,C
    f.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in(&f);

    QString line;
    QFile f3("D:/project/appData/piece_A.txt");      //Pouring into file A
    f3.open(QFile::WriteOnly | QFile :: Text);
    QTextStream out3(&f3);
    for(int i = 1; i <= sum; i++){
      line = in.readLine();
      out3 << line << endl;
    }
    f3.flush();
    f3.close();

    line = in.readLine();                            // skip file B
    do {
        if(line.isNull()){
            break;
        }
        line = in.readLine();
     } while (line != "--------------------------");


    QFile f4("D:/project/appData/piece_C.txt");       //Pouring into file C
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

    //----------------------------------------------------
}

void Edit::on_pushButton_back_clicked()
{
    window2 *pg2 = new window2;
    pg2->show();
    this->hide();
}

void Edit::on_pushButtonSearch_clicked()
{
    int k = 0;

    if(ui->radioButtonFish->isChecked()){
        k = 1;
    }
    if(ui->radioButtonAmphibian->isChecked()){
        k = 2;
    }
    if(ui->radioButtonReptile->isChecked()){
        k = 3;
    }
    if(ui->radioButtonBird->isChecked()){
        k = 4;
    }
    if(ui->radioButtonMamal->isChecked()){
        k = 5;
    }
    if(k == 0){
        showMsg("choose animal in Box please.","Error");
    }

    if(k != 0){
        qDebug() << "k = " << k;
        QString name = ui->lineEditName->text();
        QString nikeName = ui->lineEditNikName->text();

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
                        find = true;
                        reciveEditAnimal(k);
                        replaceAnimal(user, sum - 3);
                        break;
                    }
                }

             }
        }while (! l1.isNull());
        if(!find){
            showMsg("animal not Found !","Error");
        }
    }
}
