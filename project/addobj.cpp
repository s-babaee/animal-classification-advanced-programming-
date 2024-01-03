#include "addobj.h"
#include "ui_addobj.h"
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

using namespace std;

const QString f1 = "Vegetarians", f2 = "Meat eater", f3 = "Omnivorous";
const QString m1 = "Swim", m2 = "Swim and walk", m3 = "Crawl", m4 = "Fly", m5 = "Walk";
const QString r1 = "Egg laying", r2 = "Childbirth";
const QString c1 = "Soft Scales", c2 = "Naked", c3 = "Hard Scales", c4 = "Feather", c5 = "Hair";

void addObj::showMsg(QString text, QString type){
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

class b_animal {    //base class
protected:
    bool vertebrate;
    bool warm_blood;

    QString name;
    QString nikeName;
    QString age;
    QString description;
    QString sex;

    QString food;
    QString move;
    QString reproduction;
    QString cover;
public:
    b_animal() {
        vertebrate = true;
        warm_blood = true;

        name = "EMPTY";
        nikeName = "EMPTY";
        description = "EMPTY";
        age = "EMPTY";
        sex = "EMPTY";

        food = "EMPTY";
        move = "Empty";
        reproduction = "Empty";
        cover = "Empty";
    };

    void set_vertebrate(bool vertebrate) {
                    this -> vertebrate = vertebrate;
                };

    void set_warm_blood(bool warm_blood) {
                this -> warm_blood = warm_blood;
            };

    void set_name(QString name) {
                this -> name = name;
            };

    void set_nikeName(QString nikeName) {
                this -> nikeName = nikeName;
            };

    void set_description(QString description) {
                this -> description = description;
            };

    void set_age(QString age){
                this -> age = age;
            }

    void set_sex(QString sex) {
                this -> sex = sex;
            };

    void set_food(QString food) {
                this -> food = food;
            };

    void set_move(QString move) {
                this -> move = move;
            };

    void set_reproduction(QString reproduction) {
                this -> reproduction = reproduction;
            };

    void set_cover(QString cover) {
                this -> cover = cover;
            }

    QString getName(){
        return name;
    }

    QString getNikeName(){
        return nikeName;
    }

    QString getAge(){
        return age;
    }

    QString getSex(){
        return sex;
    }

    QString getFood(){
        return food;
    }

    QString getReproduction(){
        return reproduction;
    }

    QString getDescription(){
        return description;
    }
};
//*********************************************************
class d1_Invertebrate : public b_animal{
public:
    d1_Invertebrate() {
        set_vertebrate(0);
    };
};
//*********************************************************
class d1_vertebrate : public b_animal{
public:
    d1_vertebrate() {
       set_vertebrate(1);
    };
};
//*********************************************************
class d2_fishes : public d1_vertebrate{
protected:
    int fins;
    bool jaw;
    QString skelet;
public:
    d2_fishes(){

        set_warm_blood(false);
        set_move(m1);
        set_reproduction(r1);
        set_cover(c1);

        set_fins(0);
        set_jaw(true);
        set_skelet("EMPTY");
}

    void set_fins(int fins){
         this -> fins = fins;
    }

    void set_jaw(bool jaw){
        this -> jaw = jaw;
    }

    void set_skelet(QString skelet){
                this -> skelet = skelet;
    }

    QString getFins(){
        return QString::number(fins);
    }

    QString getjaw(){
        if(jaw)
            return "with jaw";
        else
            return "without jaw";
    }

    QString getSkelet(){
        return skelet;
    }
};
//*********************************************************
class d2_amphibians : public d1_vertebrate{
protected:
    QString tail;
    QString family;
public:
    d2_amphibians(){
        set_warm_blood(false);

        set_move(m2);
        set_reproduction(r1);
        set_cover(c2);
    }

    void set_tail(QString tail){
        this -> tail = tail;
    }

    void set_family(QString family){
        this -> family = family;
    }

    QString get_tail(){
        return tail;
    }

    QString get_family(){
        return family;
    }
};
//*********************************************************
class d2_reptiles : public d1_vertebrate{
protected:
    QString family;
public:
    d2_reptiles(){
        set_warm_blood(false);

        set_move(m3);
        set_reproduction(r1);
        set_cover(c3);
    }

    void set_family(QString family){
        this -> family = family;
    }

    QString get_family(){
        return family;
    }
};
//*********************************************************
class d2_birds : virtual public d1_vertebrate{
protected:
    QString move;
public:
    d2_birds(){
        set_warm_blood(1);

        set_reproduction(r1);
        set_cover(c4);
    }

    void set_move(QString move){
        this -> move = move;
    }

    QString get_move(){
        return move;
    }
};
//*********************************************************
class d2_mammals : virtual public d1_vertebrate{
protected:
    QString move;
public:
    d2_mammals(){
        set_warm_blood(1);

        set_reproduction(r2);
        set_cover(c5);
    }

    void set_move(QString move){
        this -> move = move;
    }

    QString get_move(){
        return move;
    }
};
//*********************************************************
class d3_special : public d2_mammals, public d2_birds{
protected:
    QString move;
public:
    d3_special(){
        set_reproduction(r1);
        set_cover(c5);
    }
    void set_move(QString move){
        this -> move = move;
    }

    QString get_move(){
        return move;
    }
};

//-----------------------------------------------------------
int saveFish(QString user, QString mode){

    QFile file1("D:/project/appData/infoAnimal.txt");    // save to var
    file1.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in1(&file1);
    QString type = in1.readLine();
    QString name = in1.readLine();
    QString nikeName = in1.readLine();
    QString age = in1.readLine();
    QString fins = in1.readLine();
    QString sex = in1.readLine();
    QString food = in1.readLine();
    QString skelet = in1.readLine();
    QString jaw = in1.readLine();
    QString description = "";

    QString line = in1.readLine();
    while(!line.isNull()){
        description += line + "\n";
        line = in1.readLine();
    }

    file1.flush();
    file1.close();


    d2_fishes f;                                        // obj fish
    f.set_name(name);
    f.set_nikeName(nikeName);
    f.set_age(age);
    f.set_food(food);
    f.set_sex(sex);
    f.set_skelet(skelet);
    if(jaw == "with jaw"){
        f.set_jaw(true);
    }
    else{
        f.set_jaw(false);
    }
    bool ok;
    f.set_fins(fins.toInt(&ok));
    f.set_description(description);


    if(mode == "add"){
        QFile f2("D:/project/userData/" + user + ".txt");
        f2.open(QFile::WriteOnly | QFile :: Append);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << f.getName() << endl;
        out2 << f.getNikeName() << endl;
        out2 << "age : " + f.getAge() << endl;
        out2 << "sex : " + f.getSex() << endl;
        out2 << "food : " + f.getFood() << endl;

        out2 << "skelet : " + f.getSkelet() << endl;
        if(f.getjaw() == "with jaw"){
            out2 << "with jaw" << endl;
        }else{
            out2 << "without jaw" << endl;
        }

        out2 << "fins : " + f.getFins() << endl;
        out2 << "description : \n" + f.getDescription() << endl;
        f2.flush();
        f2.close();

        return 1;
        }

    if(mode == "edit"){

        QFile f2("D:/project/appData/piece_B.txt");
        f2.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << f.getName() << endl;
        out2 << f.getNikeName() << endl;
        out2 << "age : " + f.getAge() << endl;
        out2 << "sex : " + f.getSex() << endl;
        out2 << "food : " + f.getFood() << endl;

        out2 << "skelet : " + f.getSkelet() << endl;
        if(f.getjaw() == "with jaw"){
            out2 << "with jaw" << endl;
        }else{
            out2 << "without jaw" << endl;
        }

        out2 << "fins : " + f.getFins() << endl;
        out2 << "description : \n" + f.getDescription() << endl;
        f2.flush();
        f2.close();

        //*********************************************************************

        QString text_A = "", text_B, text_C = "";

        QFile file_a("D:/project/appData/piece_A.txt");   // copy to string text A
        file_a.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_a(&file_a);
        text_A = in_a.readAll();
        file_a.flush();
        file_a.close();

        QFile file_b("D:/project/appData/piece_B.txt");   // copy to string text B
        file_b.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_b(&file_b);
        text_B = in_b.readAll();
        file_b.flush();
        file_b.close();

        QFile file_c("D:/project/appData/piece_C.txt");   // copy to string text C
        file_c.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_c(&file_c);
        text_C = in_c.readAll();
        file_c.flush();
        file_c.close();

        QFile source_file("D:/project/userData/" + user + ".txt");  // replace source with A + B + C file
        source_file.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out_src(&source_file);

        out_src << text_A << text_B << text_C;

        source_file.flush();
        source_file.close();
        //*********************************************************************

        QFile f21("D:/project/appData/mode.txt");      // go to add mode
        f21.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out21(&f21);
        out21 << "add\n";
        f21.flush();
        f21.close();

        return 2;
    }
}

int saveAmphibian(QString user, QString mode){

    QFile file1("D:/project/appData/infoAnimal.txt");    // save to var
    file1.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in1(&file1);
    QString type = in1.readLine();
    QString name = in1.readLine();
    QString nikeName = in1.readLine();
    QString age = in1.readLine();
    QString food = in1.readLine();
    QString family = in1.readLine();
    QString sex = in1.readLine();
    QString tail = in1.readLine();
    QString description = "";

    QString line = in1.readLine();
    while(!line.isNull()){
        description += line + "\n";
        line = in1.readLine();
    }

    file1.flush();
    file1.close();


    d2_amphibians a;                                        // obj amphibian

    a.set_name(name);
    a.set_nikeName(nikeName);
    a.set_age(age);
    a.set_sex(sex);
    a.set_tail(tail);
    a.set_family(family);
    a.set_food(food);
    a.set_description(description);
    qDebug() << "mode : " << mode ;


    if(mode == "add"){
        QFile f2("D:/project/userData/" + user + ".txt");
        f2.open(QFile::WriteOnly | QFile :: Append);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << a.getName() << endl;
        out2 << a.getNikeName() << endl;
        out2 << "age : " + a.getAge() << endl;
        out2 << "sex : " + a.getSex() << endl;
        out2 << "tail : " + a.get_tail() << endl;
        out2 << "family : " + a.get_family() << endl;
        out2 << "food : " + a.getFood() << endl;
        out2 << "description : \n" + a.getDescription() << endl;
        f2.flush();
        f2.close();

        return 1;
        }

    if(mode == "edit"){

        QFile f2("D:/project/appData/piece_B.txt");
        f2.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << a.getName() << endl;
        out2 << a.getNikeName() << endl;
        out2 << "age : " + a.getAge() << endl;
        out2 << "sex : " + a.getSex() << endl;
        out2 << "tail : " + a.get_tail() << endl;
        out2 << "family : " + a.get_family() << endl;
        out2 << "food : " + a.getFood() << endl;
        out2 << "description : \n" + a.getDescription() << endl;
        f2.flush();
        f2.close();

        //*********************************************************************

        QString text_A = "", text_B, text_C = "";

        QFile file_a("D:/project/appData/piece_A.txt");   // copy to string text A
        file_a.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_a(&file_a);
        text_A = in_a.readAll();
        file_a.flush();
        file_a.close();

        QFile file_b("D:/project/appData/piece_B.txt");   // copy to string text B
        file_b.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_b(&file_b);
        text_B = in_b.readAll();
        file_b.flush();
        file_b.close();

        QFile file_c("D:/project/appData/piece_C.txt");   // copy to string text C
        file_c.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_c(&file_c);
        text_C = in_c.readAll();
        file_c.flush();
        file_c.close();

        QFile source_file("D:/project/userData/" + user + ".txt");  // replace source with A + B + C file
        source_file.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out_src(&source_file);

        out_src << text_A << text_B << text_C;

        source_file.flush();
        source_file.close();
        //*********************************************************************

        QFile f21("D:/project/appData/mode.txt");      // go to add mode
        f21.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out21(&f21);
        out21 << "add\n";
        f21.flush();
        f21.close();

        return 2;
    }
}

int saveReptile(QString user, QString mode){

    QFile file1("D:/project/appData/infoAnimal.txt");    // save to var
    file1.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in1(&file1);
    QString type = in1.readLine();
    QString name = in1.readLine();
    QString nikeName = in1.readLine();
    QString age = in1.readLine();
    QString sex = in1.readLine();
    QString food = in1.readLine();
    QString family = in1.readLine(); 
    QString description = "";

    QString line = in1.readLine();
    while(!line.isNull()){
        description += line + "\n";
        line = in1.readLine();
    }

    file1.flush();
    file1.close();


    d2_reptiles r;                                        // obj reptile

    r.set_name(name);
    r.set_nikeName(nikeName);
    r.set_age(age);
    r.set_sex(sex);
    r.set_food(food);
    r.set_family(family);
    r.set_description(description);


    if(mode == "add"){
        QFile f2("D:/project/userData/" + user + ".txt");
        f2.open(QFile::WriteOnly | QFile :: Append);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << r.getName() << endl;
        out2 << r.getNikeName() << endl;
        out2 << "age : " + r.getAge() << endl;
        out2 << "sex : " + r.getSex() <<endl;
        out2 << "food : " + r.getFood() << endl;
        out2 << "family : " + r.get_family() << endl;
        out2 << "description : \n" + r.getDescription() << endl;
        f2.flush();
        f2.close();

        return 1;
        }

    if(mode == "edit"){

        QFile f2("D:/project/appData/piece_B.txt");
        f2.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << r.getName() << endl;
        out2 << r.getNikeName() << endl;
        out2 << "age : " + r.getAge() << endl;
        out2 << "sex : " + r.getSex() <<endl;
        out2 << "food : " + r.getFood() << endl;
        out2 << "family : " + r.get_family() << endl;
        out2 << "description : \n" + r.getDescription() << endl;
        f2.flush();
        f2.close();

        //*********************************************************************

        QString text_A = "", text_B, text_C = "";

        QFile file_a("D:/project/appData/piece_A.txt");   // copy to string text A
        file_a.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_a(&file_a);
        text_A = in_a.readAll();
        file_a.flush();
        file_a.close();

        QFile file_b("D:/project/appData/piece_B.txt");   // copy to string text B
        file_b.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_b(&file_b);
        text_B = in_b.readAll();
        file_b.flush();
        file_b.close();

        QFile file_c("D:/project/appData/piece_C.txt");   // copy to string text C
        file_c.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_c(&file_c);
        text_C = in_c.readAll();
        file_c.flush();
        file_c.close();

        QFile source_file("D:/project/userData/" + user + ".txt");  // replace source with A + B + C file
        source_file.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out_src(&source_file);

        out_src << text_A << text_B << text_C;

        source_file.flush();
        source_file.close();
        //*********************************************************************

        QFile f21("D:/project/appData/mode.txt");      // go to add mode
        f21.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out21(&f21);
        out21 << "add\n";
        f21.flush();
        f21.close();

        return 2;
    }
}

int saveBird(QString user, QString mode){
    QFile file1("D:/project/appData/infoAnimal.txt");    // save to var
    file1.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in1(&file1);
    QString type = in1.readLine();
    QString name = in1.readLine();
    QString nikeName = in1.readLine();
    QString age = in1.readLine();
    QString sex = in1.readLine();
    QString move = in1.readLine();
    QString food = in1.readLine();
    QString description = "";

    QString line = in1.readLine();
    while(!line.isNull()){
        description += line + "\n";
        line = in1.readLine();
    }

    file1.flush();
    file1.close();


    d2_birds b;                                        // obj bird

    b.set_name(name);
    b.set_nikeName(nikeName);
    b.set_age(age);
    b.set_sex(sex);
    b.set_food(food);
    b.set_move(move);
    b.set_description(description);


    if(mode == "add"){
        QFile f2("D:/project/userData/" + user + ".txt");
        f2.open(QFile::WriteOnly | QFile :: Append);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << b.getName() << endl;
        out2 << b.getNikeName() << endl;
        out2 << "age : " + b.getAge() << endl;
        out2 << "sex : " + b.getSex() << endl;
        out2 << "food : " + b.getFood() << endl;
        out2 << "family : " + b.get_move() << endl;
        out2 << "description : \n" + b.getDescription() << endl;
        f2.flush();
        f2.close();

        return 1;
        }

    if(mode == "edit"){

        QFile f2("D:/project/appData/piece_B.txt");
        f2.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << b.getName() << endl;
        out2 << b.getNikeName() << endl;
        out2 << "age : " + b.getAge() << endl;
        out2 << "sex : " + b.getSex() << endl;
        out2 << "food : " + b.getFood() << endl;
        out2 << "family : " + b.get_move() << endl;
        out2 << "description : \n" + b.getDescription() << endl;
        f2.flush();
        f2.close();

        //*********************************************************************

        QString text_A = "", text_B, text_C = "";

        QFile file_a("D:/project/appData/piece_A.txt");   // copy to string text A
        file_a.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_a(&file_a);
        text_A = in_a.readAll();
        file_a.flush();
        file_a.close();

        QFile file_b("D:/project/appData/piece_B.txt");   // copy to string text B
        file_b.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_b(&file_b);
        text_B = in_b.readAll();
        file_b.flush();
        file_b.close();

        QFile file_c("D:/project/appData/piece_C.txt");   // copy to string text C
        file_c.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_c(&file_c);
        text_C = in_c.readAll();
        file_c.flush();
        file_c.close();

        QFile source_file("D:/project/userData/" + user + ".txt");  // replace source with A + B + C file
        source_file.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out_src(&source_file);

        out_src << text_A << text_B << text_C;

        source_file.flush();
        source_file.close();
        //*********************************************************************

        QFile f21("D:/project/appData/mode.txt");      // go to add mode
        f21.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out21(&f21);
        out21 << "add\n";
        f21.flush();
        f21.close();

        return 2;
    }
}

int saveMammal(QString user, QString mode){
    QFile file1("D:/project/appData/infoAnimal.txt");    // save to var
    file1.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in1(&file1);
    QString type = in1.readLine();
    QString name = in1.readLine();
    QString nikeName = in1.readLine();
    QString age = in1.readLine();
    QString sex = in1.readLine();
    QString food = in1.readLine();
    QString move = in1.readLine();
    QString description = "";

    QString line = in1.readLine();
    while(!line.isNull()){
        description += line + "\n";
        line = in1.readLine();
    }

    file1.flush();
    file1.close();


    d2_mammals m;                                        // obj bird

    m.set_name(name);
    m.set_nikeName(nikeName);
    m.set_age(age);
    m.set_sex(sex);
    m.set_food(food);
    m.set_move(move);
    m.set_description(description);


    if(mode == "add"){
        QFile f2("D:/project/userData/" + user + ".txt");
        f2.open(QFile::WriteOnly | QFile :: Append);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << m.getName() << endl;
        out2 << m.getNikeName() << endl;
        out2 << "age : " + m.getAge() << endl;
        out2 << "sex : " + m.getSex() << endl;
        out2 << "food : " + m.getFood() << endl;
        out2 << "family : " + m.get_move() << endl;
        out2 << "description : \n" + m.getDescription() << endl;
        f2.flush();
        f2.close();

        return 1;
        }

    if(mode == "edit"){

        QFile f2("D:/project/appData/piece_B.txt");
        f2.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << m.getName() << endl;
        out2 << m.getNikeName() << endl;
        out2 << "age : " + m.getAge() << endl;
        out2 << "sex : " + m.getSex() << endl;
        out2 << "food : " + m.getFood() << endl;
        out2 << "family : " + m.get_move() << endl;
        out2 << "description : \n" + m.getDescription() << endl;
        f2.flush();
        f2.close();

        //*********************************************************************

        QString text_A = "", text_B, text_C = "";

        QFile file_a("D:/project/appData/piece_A.txt");   // copy to string text A
        file_a.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_a(&file_a);
        text_A = in_a.readAll();
        file_a.flush();
        file_a.close();

        QFile file_b("D:/project/appData/piece_B.txt");   // copy to string text B
        file_b.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_b(&file_b);
        text_B = in_b.readAll();
        file_b.flush();
        file_b.close();

        QFile file_c("D:/project/appData/piece_C.txt");   // copy to string text C
        file_c.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_c(&file_c);
        text_C = in_c.readAll();
        file_c.flush();
        file_c.close();

        QFile source_file("D:/project/userData/" + user + ".txt");  // replace source with A + B + C file
        source_file.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out_src(&source_file);

        out_src << text_A << text_B << text_C;

        source_file.flush();
        source_file.close();
        //*********************************************************************

        QFile f21("D:/project/appData/mode.txt");      // go to add mode
        f21.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out21(&f21);
        out21 << "add\n";
        f21.flush();
        f21.close();

        return 2;
    }
}

int saveSpecial(QString user, QString mode){
    QFile file1("D:/project/appData/infoAnimal.txt");    // save to var
    file1.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in1(&file1);
    QString type = in1.readLine();
    QString name = in1.readLine();
    QString nikeName = in1.readLine();
    QString age = in1.readLine();
    QString sex = in1.readLine();
    QString food = in1.readLine();
    QString move = in1.readLine();
    QString description = "";

    QString line = in1.readLine();
    while(!line.isNull()){
        description += line + "\n";
        line = in1.readLine();
    }

    file1.flush();
    file1.close();


    d3_special s;                                        // obj bird

    s.set_name(name);
    s.set_nikeName(nikeName);
    s.set_age(age);
    s.set_sex(sex);
    s.set_food(food);
    s.set_move(move);
    s.set_description(description);


    if(mode == "add"){
        QFile f2("D:/project/userData/" + user + ".txt");
        f2.open(QFile::WriteOnly | QFile :: Append);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << s.getName() << endl;
        out2 << s.getNikeName() << endl;
        out2 << "age : " + s.getAge() << endl;
        out2 << "sex : " + s.getSex() << endl;
        out2 << "food : " + s.getFood() << endl;
        out2 << "family : " + s.get_move() << endl;
        out2 << "description : \n" + s.getDescription() << endl;
        f2.flush();
        f2.close();

        return 1;
        }

    if(mode == "edit"){

        QFile f2("D:/project/appData/piece_B.txt");
        f2.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out2(&f2);
        out2 << "--------------------------\n";
        out2 << s.getName() << endl;
        out2 << s.getNikeName() << endl;
        out2 << "age : " + s.getAge() << endl;
        out2 << "sex : " + s.getSex() << endl;
        out2 << "food : " + s.getFood() << endl;
        out2 << "family : " + s.get_move() << endl;
        out2 << "description : \n" + s.getDescription() << endl;
        f2.flush();
        f2.close();

        //*********************************************************************

        QString text_A = "", text_B, text_C = "";

        QFile file_a("D:/project/appData/piece_A.txt");   // copy to string text A
        file_a.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_a(&file_a);
        text_A = in_a.readAll();
        file_a.flush();
        file_a.close();

        QFile file_b("D:/project/appData/piece_B.txt");   // copy to string text B
        file_b.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_b(&file_b);
        text_B = in_b.readAll();
        file_b.flush();
        file_b.close();

        QFile file_c("D:/project/appData/piece_C.txt");   // copy to string text C
        file_c.open(QFile::ReadOnly | QFile :: Text);
        QTextStream in_c(&file_c);
        text_C = in_c.readAll();
        file_c.flush();
        file_c.close();

        QFile source_file("D:/project/userData/" + user + ".txt");  // replace source with A + B + C file
        source_file.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out_src(&source_file);

        out_src << text_A << text_B << text_C;

        source_file.flush();
        source_file.close();
        //*********************************************************************

        QFile f21("D:/project/appData/mode.txt");      // go to add mode
        f21.open(QFile::WriteOnly | QFile :: Text);
        QTextStream out21(&f21);
        out21 << "add\n";
        f21.flush();
        f21.close();

        return 2;
    }
}
////****************************************************************
/*bool is_exit(QString user, QString name, QString nikeName){

    QString l1, l2, l3, l4 = " ", text;
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
                    return true;
                 }
            }
        }
   } while (! l1.isNull() );
    return false;
}
*/
addObj::addObj(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addObj)
{
    ui->setupUi(this);
    this->setWindowTitle("information");
}

addObj::~addObj()
{
    delete ui;
}

void addObj::on_pushButtonSave_clicked()
{
    QFile file1("D:/project/appData/infoAnimal.txt");     // find type
    file1.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in1(&file1);
    QString type = in1.readLine();
    file1.flush();
    file1.close();

    QFile f1("D:/project/user.txt");              // find user
    f1.open(QFile::ReadOnly | QFile :: Text);
    QTextStream in11(&f1);
    QString user = in11.readLine();
    QString name = in11.readLine();
    QString nikeName = in11.readLine();
    f1.flush();
    f1.close();
 /*   if(is_exit(user,name,nikeName)){
             showMsg("this animal already exist.","Error");
             return;
        }*/

    QFile file("D:/project/appData/mode.txt");    // find mode
    file.open(QFile::ReadOnly | QFile :: Text);
    QTextStream infile(&file);
    QString mode = infile.readLine();
    file.flush();
    file.close();

    if(type == "Fish"){

        if(saveFish(user, mode) == 1){
            showMsg("animal added.","Information");
            Add *add = new Add;
            add->show();
            this->hide();
        }else{
            showMsg("animal edited.","Information");
            Edit *edit = new Edit;
            edit->show();
            this->hide();
        }
    }

    if(type == "Amphibian"){
        if(saveAmphibian(user, mode) == 1){
            showMsg("animal added.","Information");
            Add *add = new Add;
            add->show();
            this->hide();
        }else{
            showMsg("animal edited.","Information");
            Edit *edit = new Edit;
            edit->show();
            this->hide();
        }
    }

    if(type == "Reptile"){
        if(saveReptile(user, mode) == 1){
            showMsg("animal added.","Information");
            Add *add = new Add;
            add->show();
            this->hide();
        }else{
            showMsg("animal edited.","Information");
            Edit *edit = new Edit;
            edit->show();
            this->hide();
        }
    }

    if(type == "Bird"){
        if(saveBird(user, mode) == 1){
            showMsg("animal added.","Information");
            Add *add = new Add;
            add->show();
            this->hide();
        }else{
            showMsg("animal edited.","Information");
            Edit *edit = new Edit;
            edit->show();
            this->hide();
        }
    }

    if(type == "Mammal"){
        if(saveMammal(user, mode) == 1){
            showMsg("animal added.","Information");
            Add *add = new Add;
            add->show();
            this->hide();
        }else{
            showMsg("animal edited.","Information");
            Edit *edit = new Edit;
            edit->show();
            this->hide();
        }
    }

    if(type == "Special"){
        if(saveSpecial(user, mode) == 1){
            showMsg("animal added.","Information");
            Add *add = new Add;
            add->show();
            this->hide();
        }else{
            showMsg("animal edited.","Information");
            Edit *edit = new Edit;
            edit->show();
            this->hide();
        }
    }

///**************************************************
}

void addObj::on_pushButtonBack_clicked()
{
    Add *ad = new Add;
    ad->show();
    this->hide();
}

