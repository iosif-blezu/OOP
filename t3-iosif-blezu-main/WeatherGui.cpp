#include "WeatherGui.h"
#include <QtWidgets/QApplication>
#include "service.h"
#include <qmessagebox.h>
#include <string>

WeatherGui::WeatherGui(Service& serv, QWidget *parent)
    : QMainWindow(parent), serv{ serv }
{
    ui.setupUi(this);
    this->populateList();
    this->connectSignalsAndSlots();
}

WeatherGui::~WeatherGui()
{}

void WeatherGui::populateList()
{
    this->ui.weatherlistWidget->clear();

    this->serv.sortElements();
    vector <weather> weathers = this->serv.getAll();
    
    for (auto& weather : weathers)
    {
        QString str = QString::fromStdString(weather.toString());
        QListWidgetItem* item = new QListWidgetItem{ str };
        this->ui.weatherlistWidget->addItem(item);
    }
}



int WeatherGui::getSelectedIndex()
{
    QModelIndexList selectedIndexes = this->ui.weatherlistWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.size() == 0)
    {
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void WeatherGui::connectSignalsAndSlots()
{
    QObject::connect(this->ui.filterpushButton, &QPushButton::clicked, this, &WeatherGui::filterPrecipitation);
    QObject::connect(this->ui.computepushButton, &QPushButton::clicked, this, &WeatherGui::compute);
}

void WeatherGui::filterPrecipitation()
{
    string precipitation = this->ui.filterlineEdit->text().toStdString();
    if (precipitation == "")
    {
		QMessageBox::critical(this, "Error", "Invalid precipitation!");
	}
    else if (precipitation.find_first_not_of("0123456789") != string::npos)
    {
		QMessageBox::critical(this, "Error", "Invalid precipitation!");
	}
    else
    {
		int precipitationchance = stoi(precipitation);
        if (precipitationchance < 0 || precipitationchance > 100)
        {
			QMessageBox::critical(this, "Error", "Invalid precipitation!");
		}
        else
        {   
            vector<weather> filtered = this->serv.getFiltered(precipitationchance);
			this->ui.filterlistWidget->clear();
            for (auto& weather : filtered)
            {
				QString str = QString::fromStdString(weather.getInterval());
				QListWidgetItem* item = new QListWidgetItem{ str };
				this->ui.filterlistWidget->addItem(item);
			}
            if (filtered.size() == 0)
            {
                QMessageBox::critical(this, "Error", "No such elements!");
            }
		}
	}	
}

void WeatherGui::compute()
{
    string start = this->ui.startlineEdit->text().toStdString();
    string description = this->ui.desclineEdit->text().toStdString();
    if (start == "")
    {
        QMessageBox::critical(this, "Error", "Invalid start!");
    }
    else if (start.find_first_not_of("0123456789") != string::npos)
    {
        QMessageBox::critical(this, "Error", "Invalid start!");
    }
    else
    {
        int newstart = stoi(start);
        if (newstart < 0 || newstart > 23)
        {
            QMessageBox::critical(this, "Error", "Invalid start!");
        }
        else
        {
            this->ui.computelistWidget->clear();
            int computed = this->serv.getComputed(newstart, description);
            vector<weather> filtered = this->serv.getComputedList(newstart, description);
            for (auto& weather : filtered)
            {
                QString str = QString::fromStdString(weather.getInterval());
                QListWidgetItem* item = new QListWidgetItem{ str };
                this->ui.computelistWidget->addItem(item);
            }
            string computedStr = to_string(computed) + " total hours";
            QString str = QString::fromStdString(computedStr);
            QListWidgetItem* item = new QListWidgetItem{ str };
            this->ui.computelistWidget->addItem(item);
            if (this->serv.getComputed(newstart, description) == 0)
            {
                QMessageBox::critical(this, "Error", "No such elements!");
            }
        }
    }
}
