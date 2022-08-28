#include "qems.h"
#include "./ui_qems.h"

#include "elemitem/elemitem.h"

#include <string>

QEms::QEms(QWidget *parent)
		: QMainWindow(parent), ui(new Ui::QEms) {
	ui->setupUi(this);

	for (int i = 0; i < 20; ++i)
		ui->ElemsVerticalLayout->addWidget(new ElemItem(QString::fromStdString("ElemItem: " + std::to_string(i))));
}

QEms::~QEms() {
	delete ui;
}
