#include "fish.h"
#include "ui_fish.h"
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

using namespace std;

void Fish::showMsg(QString text, QString type){
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


Fish::Fish(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fish)
{
    ui->setupUi(this);
    this->setWindowTitle("Fish");
}

Fish::~Fish()
{
    delete ui;
}

void Fish::on_pushButtonBack_clicked()
{
    Add *add = new Add;
    add->show();
    this->hide();
}

void Fish::on_pushButtonSave_clicked()
{
    QString name, nikeName, age, description, food, skelet, jaw, sex;
    int fins = 0;

    name = ui->lineEditName->text();                  // fish name
    if(name == ""){
        showMsg("complete name!","Error");
        return;
    }

    nikeName = ui->lineEditNikeName->text();          // fish nike name
    if(nikeName == ""){
        showMsg("complete nike name!","Error");
        return;
    }

    age = ui->lineEditAge->text();                    // fish age
    if(age == ""){
        showMsg("complete age!","Error");
        return;
    }

    fins = ui->spinBoxFins->value();                  // fish fins


    if(ui->radioButtonMale->isChecked()){             // fish sex
        sex = "Male";
    }else if(ui->radioButtonFemale->isChecked()){
        sex = "Female";
    }else{
        showMsg("complete sex!","Error");
        return;
    }
                                                      // fish food
    if(ui->radioButtonVegetarian->isChecked()){
        food = f1;
    }else if(ui->radioButtonMeatEater->isChecked()){
        food = f2;
    }else if(ui->radioButtonOmnivorous->isChecked()){
        food = f3;
    }else{
        showMsg("complete food!","Error");
        return;
    }

                                                     // fish skelet
    if(ui->radioButtonBony->isChecked()){
        skelet = "Bony";
    }else if(ui->radioButtonCartilaginous->isChecked()){
        skelet = "Cartilaginous";
    }else{
        showMsg("complete skelet!","Error");
        return;
    }
                                                      // fish jaw
    if(ui->radioButtonwithJaw->isChecked()){
        jaw = "with jaw";
    }else if(ui->radioButtonWithoutJaw->isChecked()){
        jaw = "without jaw";
    }else{
        showMsg("complete jaw!","Error");
        return;
    }
                                                      // descripton
    description = ui->plainTextEditDescription->toPlainText();
//--------------------------------------------------------------------------
                                                      // save to file
    QFile f("D:/project/appData/infoAnimal.txt");
    f.open(QFile::WriteOnly | QFile :: Text);
    QTextStream out(&f);
    out << "Fish" << endl;
    out << name << endl;
    out << nikeName << endl;
    out << age << endl;
    out << fins << endl;
    out << sex << endl;
    out << food << endl;
    out << skelet << endl;
    out << jaw << endl;
    out << description << endl;
    f.flush();
    f.close();

    addObj *ad = new addObj;
    ad->show();
    this->hide();
 }
