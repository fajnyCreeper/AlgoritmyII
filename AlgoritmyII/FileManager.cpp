#include "FileManager.h"
#include <fstream>

std::vector<char> FileManager::GetDataFromFile(std::string filename)
{
	std::vector<char> output;

	char currentChar;
	std::ifstream filestream(filename);
	while (filestream >> std::noskipws >> currentChar)
		output.push_back(currentChar);

	filestream.close();
	return output;
}

bool FileManager::SaveDataToFile(std::string filename, std::vector<char> input)
{
	std::ofstream filestream(filename);

	for (auto i : input)
		filestream << i;

	bool hasFail = filestream.fail();
	filestream.close();
	return !hasFail;
}