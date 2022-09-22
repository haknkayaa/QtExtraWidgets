// main cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>

#include <QtWidgets>

// user libraries
#include "QLedIndicator.h"
#include "QPanelIndicator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *widget = new QWidget();
    widget->setWindowTitle("Hello World");
//    widget->setMinimumSize(400, 300);

    auto layout = new QVBoxLayout(widget);

    auto label = new QLabel("Hello World");
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    auto ledIndicator = new QLedIndicator(widget);
    ledIndicator->setResize(50, 50);
    layout->addWidget(ledIndicator);

    auto panelIndicator = new QPanelIndicator();
    panelIndicator->setResize(120, 75);
    panelIndicator->setColorStyle(IndicatorColorStyle::RED);
    panelIndicator->setLabel("Hello World");
    layout->addWidget(panelIndicator);

    auto panelIndicator2 = new QPanelIndicator();
    panelIndicator2->setResize(120, 75);
    panelIndicator2->setColorStyle(IndicatorColorStyle::BLUE);
    panelIndicator2->setLabel("Hello World");
    layout->addWidget(panelIndicator2);

    auto panelIndicator3 = new QPanelIndicator();
    panelIndicator3->setResize(120, 75);
    panelIndicator3->setColorStyle(IndicatorColorStyle::GREEN);
    panelIndicator3->setLabel("Hello World");
    layout->addWidget(panelIndicator3);

    auto panelIndicator4 = new QPanelIndicator();
    panelIndicator4->setResize(120, 75);
    panelIndicator4->setColorStyle(IndicatorColorStyle::YELLOW);
    panelIndicator4->setLabel("Hello World");
    layout->addWidget(panelIndicator4);

//    widget->setStyleSheet("background-color: black");

    QTimer *timer = new QTimer(widget);
    QObject::connect(timer, &QTimer::timeout, [=](){
        ledIndicator->toggle();
        panelIndicator->toggle();
        panelIndicator2->toggle();
        panelIndicator3->toggle();
        panelIndicator4->toggle();
    });
    timer->start(1000);


    widget->setLayout(layout);
    widget->show();
    return app.exec();
}