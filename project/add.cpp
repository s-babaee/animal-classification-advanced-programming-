#include "add.h"
#include "ui_add.h"
#include "window2.h"
#include "fish.h"
#include "amphibian.h"
#include "reptile.h"
#include "bird.h"
#include "mammal.h"
#include "special.h"

Add::Add(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Animal");
}

Add::~Add()
{
    delete ui;
}

void Add::on_pushButton_back_clicked()
{
    window2 *pg2 = new window2;
    pg2->show();
    this->hide();
}


void Add::on_pushButtonFish_clicked()
{
    Fish *fish = new Fish;
    fish->show();
    this->hide();
}


void Add::on_pushButtonAmphibian_clicked()
{
    Amphibian *amph = new Amphibian;
    amph->show();
    this->hide();
}


void Add::on_pushButtonReptile_clicked()
{
    Reptile *rep = new Reptile;
    rep->show();
    this->hide();
}


void Add::on_pushButtonBird_clicked()
{
    Bird *brd = new Bird;
    brd->show();
    this->hide();
}


void Add::on_pushButtonMammal_clicked()
{
    Mammal *mml = new Mammal;
    mml->show();
    this->hide();
}


void Add::on_pushButtonSpecial_clicked()
{
    Special *spe = new Special;
    spe->show();
    this->hide();
}

