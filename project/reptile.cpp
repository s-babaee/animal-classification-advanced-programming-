#include "reptile.h"
#include "ui_reptile.h"
#include "add.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <QString>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QDebug>
#include <iostream>
#include <edit.h>
#include <addobj.h>

const QString f1 = "Vegetarians", f2 = "Meat eater", f3 = "Omnivorous";
const QString m1 = "Swim", m2 = "Swim and walk", m3 = "Crawl", m4 = "Fly", m5 = "Walk";
const QString r1 = "Egg laying", r2 = "Childbirth";
const QString c1 = "Soft Scales", c2 = "Naked", c3 = "Hard Scales", c4 = "Feather", c5 = "Hair";

void Reptile::showMsg(QString text, QString type){
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

Reptile::Reptile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reptile)
{
    ui->setupUi(this);
    this->setWindowTitle("Reptile");
}

Reptile::~Reptile()
{
    delete ui;
}


void Reptile::on_pushButtonBack_clicked()
{
    Add *add = new Add;
    add->show();
    this->hide();
}

void Reptile::on_pushButton_clicked()
{
    QString name, nikeName, age, food, family, sex, description;

    name = ui->lineEditName->text();                  // animal name
    if(name == ""){
        showMsg("complete name!","Error");
        return;
    }

    nikeName = ui->lineEditNikeName->text();          // animal nike name
    if(nikeName == ""){
        showMsg("complete nike name!","Error");
       return;
    }

    age = ui->lineEditAge->text();                    // animal age
    if(age == ""){
        showMsg("complete age!","Error");
        return;
    }

    if(ui->radioButtonMale->isChecked()){             // animal sex
            sex = "Male";
        }else if(ui->radioButtonFemale->isChecked()){
            sex = "Female";
        }else{
            showMsg("complete sex!","Error");
            return;
        }

                                                      // animal food
    if(ui->radioButtonVegetarian->isChecked()){
        food = f1;
    }else if(ui->radioButtonMeatEater->isChecked()){
        food = f2;
    }else if(ui->radioButtonOmnivorous->isChecked()){
        food = f3;
    }else{
        showMsg("complete Food!","Error");
        return;
    }
                                                     // animal family
    if(ui->radioButtonCrocodile->isChecked()){
        family = "Crocodile";
    }else if(ui->radioButtonTurtle->isChecked()){
        family = "Turtle";
    }else if(ui->radioButtonSnake->isChecked()){
        family = "Snake";
    }else if(ui->radioButtonLizard->isChecked()){
        family = "Lizard";
    }else{
        showMsg("complete family!","Error");
        return;
    }

                                                      // animal description
    description = ui->plainTextEdit->toPlainText();
//-------------------------------------------------------------
                                                      // save to file
    QFile f("D:/project/appData/infoAnimal.txt");
    f.open(QFile::WriteOnly | QFile :: Text);
    QTextStream out(&f);
    out << "Reptile" << endl;
    out << name << endl;
    out << nikeName << endl;
    out << age << endl;
    out << sex << endl;
    out << food << endl;
    out << family << endl;
    out << description << endl;
    f.flush();
    f.close();

    addObj *ad = new addObj;
    ad->show();
    this->hide();

}

