#pragma once

#include "domain.h"
#include <vector>
#include <string>

using namespace std;

class Repository {
private:
	vector<weather> elements;
	void loadData();

public:
	Repository();
	~Repository();
	vector<weather> getAll();
	void sortElements();
	
};