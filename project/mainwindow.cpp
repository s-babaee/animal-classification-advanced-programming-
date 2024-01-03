#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGroupBox"
#include "QPushButton"
#include "QLabel"
#include "iostream"
#include "fstream"
#include "stdlib.h"
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QDebug>
#include "window2.h"
#include <addobj.h>

QString fileAddress;

//*****************************************
void MainWindow::showMsg(QString text, QString type){
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


void MainWindow::sign_up(){
    QString user = ui->lineEdit_user_signup->text();
    QString pass = ui->lineEdit_pass_signup->text();

     if (test_user(user)) {
         if(test_pass(pass)){
             fileAddress = "D:/project/userData/" + user + ".txt";
             QFile f("D:/project/userInfo/userIinfo.txt");
             f.open(QFile::WriteOnly | QFile::Append);
             QTextStream out(&f);
             out << user << endl;
             out << pass << endl;
             out << fileAddress << endl;
             out << "---------------------------\n";
             f.flush();
             f.close();

             QFile f2("D:/project/userData/" + user + ".txt");
             f2.open(QFile::WriteOnly | QFile::Append);
             f2.flush();
             f2.close();

             window2 *pg2 = new window2;
             pg2->show();
             this->hide();
             showMsg("Your sign up was successful.","Information");

             QFile f3("D:/project/user.txt");
             f3.open(QFile::WriteOnly | QFile::Text);
             QTextStream out3(&f3);
             out3 << user << endl;
             f3.flush();
             f3.close();
         }
     }
}

bool MainWindow::test_user(QString user){

    if(user == ""){                                // test 1
            showMsg("Please enter your username in the relevant field.","Error");
            return false;
        }

    for (int i = 0; user[i] != '\0'; ++i) {         // test 2
            if(user[i] == ' '){
                showMsg("Your username cannot contain space.try again.","Error");
                return false;
            }
        }


    QFile f("D:/project/userInfo/userIinfo.txt");    //test 3
    f.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in(&f);
    QString l1, l2, l3, l4;
    l1 = in.readLine();
    while(! l1.isNull() ){
        l2 = in.readLine();
        l3 = in.readLine();
        l4 = in.readLine();
        l1 = in.readLine();
        if(user == l2){
            showMsg("this username already exist.\n enter another one.\n","Error");
            return false;
        }
    }

    return true;
}

bool MainWindow::test_pass(QString pass){
    if(pass == ""){                            // test 1
            showMsg("Please enter your password in the relevant field.","Error");
            return false;
        }

    for (int i = 0; pass[i] != '\0'; ++i)       //test 2
            if(pass[i] == ' '){
                showMsg("Your password cannot contain space.try again.","Error");
                return false;
            }

        for (int i = 0; pass[i] != '\0'; ++i)   //test 3
            if(pass[i] == '"'){
                showMsg("Your password cannot contain cottation.try again.","Error");
                return false;
            }

        int num = 0;                             //test 4
        for (int i = 0; pass[i] != '\0'; ++i)
            if(pass[i] >= '0' && pass[i] <= '9'){
                num++;
                break;
            }
        if(num == 0){
            showMsg("Your password must be contain number, try again.","Error");
            return false;
        }
        if(pass != ui->lineEdit_confirm_pass_signup->text()){
            showMsg("The input password is not the same in the (password) and (confirm password) sections.","Error");
            return false;
        }
        return true;
}


void MainWindow::log_in(){
    QString user = ui->lineEdit_user_login->text();
    QString pass = ui->lineEdit_pass_login->text();

    if(find_user(user, pass)){
        window2 *pg2 = new window2;
        pg2->show();
        this->hide();

        QFile f3("D:/project/user.txt");
        f3.open(QFile::WriteOnly | QFile::Text);
        QTextStream out3(&f3);
        out3 << user << endl;
        f3.flush();
        f3.close();
    }
}

bool MainWindow::find_user(QString user, QString pass){
    if(user == ""){                                // test 1
            showMsg("Please enter your username in the relevant field.","Error");
            return false;
        }

    if(pass == ""){                                // test 2
            showMsg("Please enter your password in the relevant field.","Error");
            return false;
        }

    QFile f("D:/project/userInfo/userIinfo.txt");    //test 3
    f.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in(&f);
    QString l1, l2, l3, l4;
    l1 = in.readLine();
    while(! l1.isNull() ){
        l2 = in.readLine();
        l3 = in.readLine();
        l4 = in.readLine();
        l1 = in.readLine();
        if(user == l2 && pass == l3){
            fileAddress = l4;
            return true;
        }
        if(user == l2 && pass != l3){
            showMsg("Your password incorrect !!!","Error");
            return false;
        }

    }

    QMessageBox msg(this);
    showMsg("username not found !!!","Error");
    return false;
}

//*****************************************
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("login & Sign up");
    ui->groupBoxSignUp->hide();

    QDir d;
    d.mkpath("D:/project/userInfo");
    d.mkpath("D:/project/userData");
    d.mkpath("D:/project/appData");


    if(!QFile::exists("D:/project/userInfo/userIinfo.txt")){
        QFile f("D:/project/userInfo/userIinfo.txt");
        f.open(QFile::WriteOnly | QFile::Text);
        QTextStream out(&f);
        out << "---------------------------\n";
        f.flush();
        f.close();
    }

    QFile f1("D:/project/appData/mode.txt");
    f1.open(QFile::WriteOnly | QFile :: Text);
    QTextStream out1(&f1);
    out1 << "add\n";
    f1.flush();
    f1.close();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    log_in();
}


void MainWindow::on_pushButton_signup_clicked()
{
    sign_up();
}

//**********************************************
