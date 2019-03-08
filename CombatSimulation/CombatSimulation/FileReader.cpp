#include "pch.h"
#include "FileReader.h"


FileReader::FileReader()
{
}
	


FileReader::~FileReader()
{
}

void FileReader::ReadFieldFile(std::vector<std::string> &levelMap)
{
	std::ifstream fileToOpen;
	fileToOpen.open(FILE_NAME);

	if (!fileToOpen.fail())
	{
		std::string fromFile;
		while (std::getline(fileToOpen, fromFile))
		{
			levelMap.push_back(fromFile);
		}
	}
	else
	{
		printf("Error opening file: %s", FILE_NAME.c_str());
	}

	fileToOpen.close();

}
