#include "domain.h"
#include <sstream>	

using namespace std;

vector<string> weather::tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}

weather::weather(int start, int end, int temperature, int precipitation, string description) : start{ start }, end{ end }, temperature{ temperature }, precipitation{ precipitation }, description{ description }
{
}

weather::~weather()
{
}

string weather::toString()
{
	return "Time: " + to_string(start) + " - " + to_string(end) + " | Temperature: " + to_string(temperature) + " degrees | Precipitation: " + to_string(precipitation) + "% | Description: " + description;
}

string weather::getStart()
{
	return to_string(start);
}

string weather::getInterval()
{
	return to_string(start) + " - " + to_string(end);
}

istream& operator>>(istream &input, weather &w)
{
	string line;
	getline(input, line);
	vector<string> tokens = weather::tokenize(line, ';');
	if (tokens.size() != 5)
		return input;
	w.start = stoi(tokens[0]);
	w.end = stoi(tokens[1]);
	w.temperature = stoi(tokens[2]);
	w.precipitation = stoi(tokens[3]);
	w.description = tokens[4];
	return input;
}
