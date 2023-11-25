#pragma once

#include "repository.h"

class Service {
private:
	Repository& repo;

public:
	Service(Repository& repo);
	~Service();
	vector<weather> getAll();
	vector<weather> getFiltered(int precipitation);
	int getComputed(int start, string description);
	vector<weather> getComputedList(int start, string description);
	void sortElements() { this-> repo.sortElements(); }
};