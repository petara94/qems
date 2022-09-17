#include "elemitem.h"
#include <string>

ElemItem::ElemItem(QWidget *parent)
        : QWidget{parent} {

    this->setContentsMargins(0, 0, RIGHT_MARGIN_HOVER, 0);

    // Box with border
    _mainFrame = new QFrame();
    _mainFrame->setFrameShape(QFrame::Shape::StyledPanel);
    _mainFrame->setLineWidth(1);

    // Load default image
    _img = new QImage(BASE_ELEM_IMAGE_PATH);

    if (_img->isNull()) {
        auto q = QMessageBox();

        q.setText(QString("can't find image: %s").arg(BASE_ELEM_IMAGE_PATH));

        q.setIcon(QMessageBox::Critical);
        q.exec();
        exit(1);
    }

    _img_label = new QLabel("ElemItem");
    _img_label->setPixmap(
            QPixmap::fromImage(*_img)
                    .scaled(BASE_ELEM_IMAGE_WIDTH, BASE_ELEM_IMAGE_HEIGHT, Qt::KeepAspectRatio));
    _img_label->setMaximumSize(QSize(BASE_ELEM_IMAGE_WIDTH, BASE_ELEM_IMAGE_HEIGHT));

    _elem_name = new QLabel("ElemItem");
    _elem_name->setAlignment(Qt::AlignmentFlag::AlignLeft | Qt::AlignmentFlag::AlignVCenter);
    _elem_name->setMargin(5);

    _line = new QFrame();
    _line->setGeometry(QRect());
    _line->setFrameShape(QFrame::Shape::StyledPanel);
    _line->setMaximumWidth(1);
    _line->setLineWidth(1);
    _line->setFrameShadow(QFrame::Raised);

    _vert_layout = new QHBoxLayout(_mainFrame);
    _vert_layout->addWidget(_img_label);
    _vert_layout->addWidget(_line);
    _vert_layout->addWidget(_elem_name);
    _vert_layout->setContentsMargins(QMargins(0, 0, 0, 0));
    _vert_layout->setSpacing(0);

    _main_layout = new QHBoxLayout(this);
    _main_layout->addWidget(this->_mainFrame);
    _main_layout->setContentsMargins(QMargins(0, 0, 0, 0));
    _main_layout->setSpacing(0);
}

ElemItem::~ElemItem() {
    delete _mainFrame;
    delete _img;
    delete _img_label;
    delete _elem_name;
    delete _line;
    delete _vert_layout;
    delete _main_layout;
}

ElemItem::ElemItem(const QString &name) : ElemItem() {
    _elem_name->setText(name);
}

ElemItem::ElemItem(const QString &name, const QString &filename) : ElemItem(name) {
    _img = new QImage(filename);

    if (_img->isNull()) {
        delete _img;
        _img = new QImage(BASE_ELEM_IMAGE_PATH);
    }

    _img_label->setPixmap(
            QPixmap::fromImage(*_img)
                    .scaled(BASE_ELEM_IMAGE_WIDTH, BASE_ELEM_IMAGE_HEIGHT, Qt::KeepAspectRatio));
}

void ElemItem::enterEvent(QEnterEvent *event) {
    this->setContentsMargins(0, 0, 0, 0);
}

void ElemItem::leaveEvent(QEvent *event) {
    this->setContentsMargins(0, 0, RIGHT_MARGIN_HOVER, 0);
}

void ElemItem::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        auto *drag = new QDrag(this);

        auto *mimeData = new QMimeData();
        mimeData->setProperty("width", "50");
        mimeData->setProperty("height", "100");

        drag->setMimeData(mimeData);
        drag->exec();

        Qt::DropAction result = drag->exec(Qt::MoveAction);
        qDebug() << "Drop action result: " << result;
        if (result == Qt::MoveAction) {
        }
    }
}

void ElemItem::mouseReleaseEvent(QMouseEvent *event) {
}
