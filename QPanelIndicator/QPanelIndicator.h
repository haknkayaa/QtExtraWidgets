// QPanelIndicator
// @author     : Hakan Kaya
// @created    : 22.09.2022
// @description:
//

#ifndef QPANELINDICATOR_H
#define QPANELINDICATOR_H

#include <QtWidgets>

enum IndicatorColorStyle{
    RED,
    BLUE,
    GREEN,
    YELLOW,
};
class QPanelIndicator : public QLabel{
Q_OBJECT
public:
    explicit QPanelIndicator(QWidget *parent = nullptr);
    ~QPanelIndicator() override;

    void turnOn();
    void turnOff();
    void toggle();
    void setResize(double width, double height);
    void setLabel(QString label);
    void setColorStyle(IndicatorColorStyle style);
private:
    bool isOn = false;
    bool isOff = true;

    QString offStyle;
    QString onStyle;
    IndicatorColorStyle colorStyle;
};


#endif //QPANELINDICATOR_H
