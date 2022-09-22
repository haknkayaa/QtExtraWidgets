// QLedIndicator
// @author     : Hakan Kaya
// @created    : 21.09.2022
// @description:
//

// You may need to build the project (run Qt uic code generator) to get "ui_QLedIndicator.h" resolved

#include "QLedIndicator.h"

#define onImage ":/icons/led-green-black.svg"
#define offImage ":/icons/led-red-black.svg"

QPixmap FromSvgToPixmap(const QSize &ImageSize, const QString &SvgFile)
{
    const qreal PixelRatio = qApp->primaryScreen()->devicePixelRatio();
    QSvgRenderer SvgRenderer(SvgFile);
    QPixmap Image(ImageSize * PixelRatio);
    QPainter Painter;

    Image.fill(Qt::transparent);

    Painter.begin(&Image);
    SvgRenderer.render(&Painter);
    Painter.end();

    Image.setDevicePixelRatio(PixelRatio);

    return Image;
}

QLedIndicator::QLedIndicator(QWidget *parent) :
        QLabel(parent){



    onPixmap = FromSvgToPixmap(QSize(20, 20), onImage);

    offPixmap = FromSvgToPixmap(QSize(20, 20), offImage);

    this->setPixmap(offPixmap);
    this->show();
}

QLedIndicator::~QLedIndicator() {
    delete this;
}

void QLedIndicator::turnOn() {
   this->setPixmap(onPixmap);
}

void QLedIndicator::turnOff() {
    this->setPixmap(offPixmap);
}

void QLedIndicator::toggle() {
    if(isOn) {
        turnOff();
        isOn = false;
    } else {
        turnOn();
        isOn = true;
    }
}

void QLedIndicator::setResize(double width, double height) {
    onPixmap = FromSvgToPixmap(QSize(width, height), onImage);
    offPixmap = FromSvgToPixmap(QSize(width, height), offImage);
    this->repaint();
}