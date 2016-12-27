#include "bondcons.h"
#include "ui_bondcons.h"

BondCons::BondCons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BondCons)
{
    ui->setupUi(this);
}

BondCons::~BondCons()
{
    delete ui;
}
