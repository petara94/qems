#include "qems.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QEms w;
	w.show();
	return a.exec();
}
