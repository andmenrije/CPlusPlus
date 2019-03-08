#pragma once
#include <string>
#include <vector>
#include "FileReader.h"
#include "Player.h"

class BattleField
{
private:
	static const char WALL = '#';
	static const char AIR = '.';
	static const char ENEMY = '$';
	std::vector<std::string> _levelMap;
	FileReader fr;
	std::vector<Player> monster;

	void InitializeMonsterList();

public:
	BattleField();
	~BattleField();
	void DisplayField();
	char getElementAtMapLocation(int y, int x);
	bool IsElementAtMapLocationPassable(int y, int x);
	bool IsElementAnEnemy(int x, int y);

	// Gets the location of the first instance of character parameter from the field;
	void GetLocationOfCharacter(char charToFind, int &y, int &x);
	void UpdateLocationOfCharacter(char charToUpdate, int fromY, int fromX, int newY, int newX);

	int GetMonsterHealthAtLocation(int y, int x);
	int GetMonsterHitDamageAtLocation(int y, int x);
	float GetMonsterChanceOfHitAtLocation(int y, int x);
	void UpdateMonsterHealthAtLocation(int additionalHealth, int y, int x);
};

