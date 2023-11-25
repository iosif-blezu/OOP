#include "service.h"

Service::Service(Repository& repo) : repo{ repo }
{
}

Service::~Service()
{
}

vector<weather> Service::getAll()
{
	return this->repo.getAll();
}


vector<weather> Service::getFiltered(int precipitation)
{
	vector<weather> elements = this->repo.getAll();
	vector<weather> filtered;
	for (auto element : elements)
	{
		if (element.getPrecipitation() <= precipitation)
			filtered.push_back(element);
	}
	return filtered;
}

int Service::getComputed(int start, string description)
{
	vector<weather> elements = this->repo.getAll();
	int numberOfHours = 0;
	for (auto element : elements)
	{
		if (element.getDescription() == description && stoi(element.getStart()) >= start)
			numberOfHours += element.getEnd() - stoi(element.getStart());
	}
	return numberOfHours;
}

vector<weather> Service::getComputedList(int start, string description)
{
	vector<weather> elements = this->repo.getAll();
	vector<weather> filtered;
	for (auto element : elements)
	{
		if (element.getDescription() == description && stoi(element.getStart()) >= start)
			filtered.push_back(element);
	}
	return filtered;
}
