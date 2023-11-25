#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WeatherGui.h"
#include "service.h"

class WeatherGui : public QMainWindow
{
    Q_OBJECT

public:
    WeatherGui(Service& serv, QWidget *parent = nullptr);
    ~WeatherGui();

private:
    Service& serv;
    Ui::WeatherGuiClass ui;
    void populateList();
    int getSelectedIndex();
    void connectSignalsAndSlots();
    void filterPrecipitation();
    void compute();
};
