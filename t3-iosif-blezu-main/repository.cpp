#include "repository.h"
#include <fstream>

void Repository::loadData()
{
    ifstream inFile(R"(input.txt)");
    weather CurrentElement;
    this->elements.clear();
    while (inFile >> CurrentElement)
    {
        this->elements.push_back(CurrentElement);
    }
    inFile.close();
}

Repository::Repository()
{
    this->loadData();
}

Repository::~Repository()
{
}

vector<weather> Repository::getAll()
{
    return this->elements;
}

void Repository::sortElements()
{
    for (int i = 0; i < this->elements.size() - 1; i++)
    {
        for (int j = i + 1; j < this->elements.size(); j++)
        {
            if (stoi(this->elements[i].getStart()) > stoi(this->elements[j].getStart()))
            {
				weather aux = this->elements[i];
				this->elements[i] = this->elements[j];
				this->elements[j] = aux;
			}
		}
	}
}

