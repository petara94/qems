#ifndef QEMS_H
#define QEMS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QEms; }
QT_END_NAMESPACE

class QEms : public QMainWindow
{
	Q_OBJECT

  public:
	QEms(QWidget *parent = nullptr);
	~QEms();

  private:
	Ui::QEms *ui;
};
#endif // QEMS_H
