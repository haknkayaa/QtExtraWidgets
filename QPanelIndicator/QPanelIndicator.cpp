// QPanelIndicator
// @author     : Hakan Kaya
// @created    : 22.09.2022
// @description:
//

#include "QPanelIndicator.h"

QPanelIndicator::QPanelIndicator(QWidget *parent) : QLabel(parent) {
    this->setAlignment(Qt::AlignCenter);
    this->setFixedSize(200, 100);
}

QPanelIndicator::~QPanelIndicator() {
    delete this;
}

void QPanelIndicator::turnOn() {
    this->setStyleSheet(onStyle);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(50);
    if (colorStyle == RED) {
        effect->setColor(QColor(255, 0, 0));
    } else if (colorStyle == BLUE) {
        effect->setColor(QColor(0, 241, 255));
    } else if (colorStyle == GREEN) {
        effect->setColor(QColor(0, 255, 0));
    } else if (colorStyle == YELLOW) {
        effect->setColor(QColor(255, 255, 0));
    }
    effect->setOffset(0, 0);
    this->setGraphicsEffect(effect);
}

void QPanelIndicator::turnOff() {
    this->setStyleSheet(offStyle);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(0);
    effect->setColor(QColor(0, 0, 0, 0));
    effect->setOffset(0, 0);
    this->setGraphicsEffect(effect);
}

void QPanelIndicator::toggle() {
    if (isOn) {
        turnOff();
        isOn = false;
    } else {
        turnOn();
        isOn = true;
    }
}

void QPanelIndicator::setResize(double width, double height) {
    this->setGeometry(0, 0, width, height);
}


void QPanelIndicator::setLabel(QString label) {
    this->setText(label);
}

void QPanelIndicator::setColorStyle(IndicatorColorStyle style) {
    colorStyle = style;
    if (style == RED) {
        onStyle = "background-color: rgb(255, 0, 0);"
                  "border-radius: 10px;"
                  "border: 1px solid rgb(0, 0, 0);"
                  "color: rgb(0, 0, 0);"
                  "font: 75 14pt \"MS Shell Dlg 2\";";

        offStyle = "background-color: rgb(241, 149, 149);"
                   "border-radius: 10px;"
                   "border: 1px solid rgb(0, 0, 0);"
                   "color: rgb(0, 0, 0);"
                   "font: 75 14pt \"MS Shell Dlg 2\";";
    } else if (style == BLUE) {
        onStyle = "background-color: rgb(0, 241, 255);"
                  "border-radius: 10px;"
                  "border: 1px solid rgb(0, 0, 0);"
                  "color: rgb(0, 0, 0);"
                  "font: 75 14pt \"MS Shell Dlg 2\";";

        offStyle = "background-color: rgb(137, 213, 217);"
                   "border-radius: 10px;"
                   "border: 1px solid rgb(0, 0, 0);"
                   "color: rgb(0, 0, 0);"
                   "font: 75 14pt \"MS Shell Dlg 2\";";
    } else if (style == GREEN) {
        onStyle = "background-color: rgb(0, 255, 0);"
                  "border-radius: 10px;"
                  "border: 1px solid rgb(0, 0, 0);"
                  "color: rgb(0, 0, 0);"
                  "font: 75 14pt \"MS Shell Dlg 2\";";

        offStyle = "background-color: rgb(173, 236, 162);"
                   "border-radius: 10px;"
                   "border: 1px solid rgb(0, 0, 0);"
                   "color: rgb(0, 0, 0);"
                   "font: 75 14pt \"MS Shell Dlg 2\";";
    } else if (style == YELLOW) {
        onStyle = "background-color: rgb(255, 255, 0);"
                  "border-radius: 10px;"
                  "border: 1px solid rgb(0, 0, 0);"
                  "color: rgb(0, 0, 0);"
                  "font: 75 14pt \"MS Shell Dlg 2\";";

        offStyle = "background-color: rgb(213, 231, 127);"
                   "border-radius: 10px;"
                   "border: 1px solid rgb(0, 0, 0);"
                   "color: rgb(0, 0, 0);"
                   "font: 75 14pt \"MS Shell Dlg 2\";";
    }

    this->setStyleSheet(offStyle);
}