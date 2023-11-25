#include "WeatherGui.h"
#include <QtWidgets/QApplication>
#include "service.h"
#include "repository.h"
#include "domain.h"
#include <iostream>


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Service service(repo);

    WeatherGui gui{ service };
    gui.show();
    return a.exec();
}
