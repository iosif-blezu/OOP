#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class weather {
private:
	int start;
	int end;
	int temperature;
	int precipitation;
	string description;

public:
	static vector<string> tokenize(string str, char delimiter);
	friend istream& operator>>(istream&, weather&);
	weather(int start, int end, int temperature, int precipitation, string description);
	weather() = default;
	~weather();
	string toString();
	int getPrecipitation() { return precipitation; }
	string getStart();
	string getDescription() { return description; }
	int getEnd() { return end; }
	string getInterval();
};