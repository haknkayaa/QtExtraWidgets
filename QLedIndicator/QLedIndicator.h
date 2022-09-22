// QLedIndicator
// @author     : Hakan Kaya
// @created    : 21.09.2022
// @description:
//

#ifndef QTPROJECT_QLEDINDICATOR_H
#define QTPROJECT_QLEDINDICATOR_H

#include <QtWidgets>
#include <QLabel>
#include <QSvgRenderer>

#include <QtQuickWidgets/QtQuickWidgets>
#include <QQuickWidget>

class QLedIndicator : public QLabel {
Q_OBJECT

public:
    explicit QLedIndicator(QWidget *parent = nullptr);
    ~QLedIndicator() override;

    void turnOn();
    void turnOff();
    void toggle();
    void setResize(double width, double height);
private:
    bool isOn = false;

    QPixmap onPixmap;
    QPixmap offPixmap;
};


#endif //QTPROJECT_QLEDINDICATOR_H
