#ifndef ELEMITEM_H
#define ELEMITEM_H

#include <QWidget>
#include <QPixmap>
#include <QLine>
#include <QImage>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QStyle>
#include <QDebug>
#include <QMessageBox>

#define BASE_ELEM_IMAGE_PATH ":/res/icons/box.png"
#define BASE_ELEM_IMAGE_WIDTH 50
#define BASE_ELEM_IMAGE_HEIGHT 50

class ElemItem : public QWidget {
Q_OBJECT
public:
	explicit ElemItem(QWidget *parent = nullptr);

	ElemItem(const QString &name);

	ElemItem(const QString &name, const QString &filename);

	virtual ~ElemItem();

private:
	QFrame *_mainFrame;
	QImage *_img;
	QLabel *_img_label;
	QLabel *_elem_name;
	QFrame *_line;
	QHBoxLayout *_vert_layout;
	QHBoxLayout *_main_layout;

signals:


protected:


protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
};

#endif // ELEMITEM_H
