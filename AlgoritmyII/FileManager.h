#pragma once

#include <iostream>
#include <vector>
#include <string>

class FileManager
{
public:
	std::vector<char> GetDataFromFile(std::string);
	bool SaveDataToFile(std::string, std::vector<char>);
};

