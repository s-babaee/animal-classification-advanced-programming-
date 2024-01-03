#include "amphibian.h"
#include "ui_amphibian.h"
#include "add.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <QString>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QDebug>
#include <iostream>
#include <addobj.h>

const QString f1 = "Vegetarians", f2 = "Meat eater", f3 = "Omnivorous";
const QString m1 = "Swim", m2 = "Swim and walk", m3 = "Crawl", m4 = "Fly", m5 = "Walk";
const QString r1 = "Egg laying", r2 = "Childbirth";
const QString c1 = "Soft Scales", c2 = "Naked", c3 = "Hard Scales", c4 = "Feather", c5 = "Hair";

void Amphibian::showMsg(QString text, QString type){
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

Amphibian::Amphibian(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Amphibian)
{
    ui->setupUi(this);
    this->setWindowTitle("Amphbian");
}

Amphibian::~Amphibian()
{
    delete ui;
}

void Amphibian::on_pushButtonBack_clicked()
{
    Add *add = new Add;
    add->show();
    this->hide();
}

void Amphibian::on_pushButtonSave_clicked()
{
    QString name, nikeName, age, description, sex, food, tail, family;

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

    if(ui->radioButtonVegetarian->isChecked()){      // animal food
        food = f1;
    }else if(ui->radioButtonMeatEater->isChecked()){
        food = f2;
    }else if(ui->radioButtonOmnivorous->isChecked()){
        food = f3;
    }else{
        showMsg("complete Food!","Error");
        return;
    }

    if(ui->radioButtonSalamander->isChecked()){        // animal family
        family = "Salamander";
    }else if(ui->radioButtonFrog->isChecked()){
        family = "Frog";
    }else if(ui->radioButtonVez->isChecked()){
        family = "Vez";
    }else{
        showMsg("complete Family!","Error");
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
                                                      // animal tail
    if(ui->radioButtonWithTail->isChecked()){
        tail = "With Tail";
    }else if(ui->radioButtonWithoutTail->isChecked()){
        tail = "without Tail";
    }else{
        showMsg("complete Tail!","Error");
        return;
    }
                                                      // animal description
    description = ui->plainTextEdit->toPlainText();
//--------------------------------------------------------------------------
                                                       // save to temporary file
    QFile f("D:/project/appData/infoAnimal.txt");
    f.open(QFile::WriteOnly | QFile :: Text);
    QTextStream out(&f);
    out << "Amphibian" << endl;
    out << name << endl;
    out << nikeName << endl;
    out << age << endl;
    out << food << endl;
    out << family << endl;
    out << sex << endl;
    out << tail << endl;
    out << description << endl;
    f.flush();
    f.close();

    addObj *ad = new addObj;
    ad->show();
    this->hide();
}

