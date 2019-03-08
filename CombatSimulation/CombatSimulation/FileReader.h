#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "FileReader.h"

class FileReader
{
private:
	const std::string FILE_NAME = "BattlefieldL1.txt";


public:
	FileReader();
	~FileReader();
	void ReadFieldFile(std::vector<std::string> &levelMap);
};

