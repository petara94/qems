#include "qems.h"
#include "./ui_qems.h"

QEms::QEms(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QEms)
{
    ui->setupUi(this);
}

QEms::~QEms()
{
    delete ui;
}

