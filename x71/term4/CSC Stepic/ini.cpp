// Eugene Auduchinok, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

using namespace std;

// string trim(string& str)
// {
// 	if (str.empty())
// 	{
// 		return "";
// 	}
//     size_t begin = str.find_first_not_of(' ');
//     size_t end = str.find_last_not_of(' ');
//     return str.substr(begin, (end - begin + 1));
// }

string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

int main()
{
	string searchQueue;
	getline(cin, searchQueue);
	searchQueue = trim(searchQueue);
	searchQueue.erase(0,1);
	searchQueue = trim(searchQueue);
	searchQueue.erase(0,1);

	stringstream queue(searchQueue);
	string searchSection;
	string searchKey;
	getline(queue, searchSection, '.');
	getline(queue, searchKey, '.');
	searchSection = trim(searchSection);
	searchKey = trim(searchKey);

	map<string,map<string, string> > sections;
	string line;
	string currentSection;

	while (getline(cin, line))
	{
		// Clean comments
		size_t commentAt = line.find('#');
		if (commentAt != string::npos)
		{
			line.erase(line.begin() + commentAt, line.end());
		}

		line = trim(line);

		if (line.empty())
		{
			continue;
		}

		// Section beginning
		if (line[0] == '[')
		{
			line.erase(0, 1);
			line.erase(line.find(']'), 1);
			line = trim(line);

			sections[line] = map<string, string>();
			currentSection = line;

			continue;
		}

		size_t equalsAt = line.find('=');
		if (equalsAt == string::npos)
		{
			continue;
		}

		stringstream pair(line);
		string key;
		string value;
		getline(pair, key, '=');
		getline(pair, value, '=');
		key = trim(key);
		if (key == "")
		{
			continue;
		}

		value = trim(value);

		sections[currentSection][key] = value;
	}

	// for(auto const &section : sections)
	// {
	// 	cout << section.first << " " << section.second.size() << endl;
	// 	for(auto const &pair : section.second)
	// 	{
	// 		cout << pair.first << " " << pair.second << endl;
	// 	}

	// 	cout << endl;
	// }


	map<string,map<string,string> >::iterator foundSection = sections.find(searchSection);
	if (foundSection == sections.end())
	{
		cout << searchSection << "." << searchKey << "is not found" << endl;
		return 0;
	}

	map<string,string>::iterator foundValue = sections[searchSection].find(searchKey);
	if (foundValue == sections[searchSection].end())
	{
		cout << searchSection << "." << searchKey << " is not found" << endl;
		return 0;
	}

	cout << searchSection << "." << searchKey << " is equal to " << "\"" << foundValue->second << "\"" << endl;

	return 0;
}
