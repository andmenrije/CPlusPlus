#include "pch.h"
#include "BattleField.h"

void BattleField::InitializeMonsterList()
{
	for (int i = 0; i < _levelMap.size(); ++i)
	{
		for (int j = 0; j < _levelMap[i].size(); ++j )
		{
			if (getElementAtMapLocation(i, j) == ENEMY)
			{
				Player obj;
				obj.SetPlayerCharacter(ENEMY);
				obj.UpdatePlayerLocation(i, j);
				obj.FillPlayerStats(5, 0.5f);
				monster.push_back(obj);
			}
		}
	}
}

BattleField::BattleField()
{
	fr.ReadFieldFile(_levelMap);
	InitializeMonsterList();
}



BattleField::~BattleField()
{
}

void BattleField::DisplayField()
{

	for (unsigned int i = 0; i < _levelMap.size(); i++)
	{
		std::cout << _levelMap[i] << std::endl;
	}

	return;
}

char BattleField::getElementAtMapLocation(int y, int x)
{
	return _levelMap[y][x];
}

bool BattleField::IsElementAtMapLocationPassable(int y, int x)
{
	if (getElementAtMapLocation(y, x) == WALL || getElementAtMapLocation(y, x) == ENEMY)
	{
		return false;
	}
	return true;
}

bool BattleField::IsElementAnEnemy(int y, int x)
{
	if ( getElementAtMapLocation(y, x) == ENEMY)
	{
		return true;
	}
	return false;
}



void BattleField::GetLocationOfCharacter(char charToFind, int &y, int &x)
{

	for (unsigned int i = 0; i < _levelMap.size(); ++i)
	{
		for (unsigned int j = 0; j < _levelMap[i].size(); ++j)
		{
			if (getElementAtMapLocation(i, j) == charToFind)
			{
				y = i;
				x = j;
			}
		}
	}

	return;
}

void BattleField::UpdateLocationOfCharacter(char charToUpdate, int fromY, int fromX, int newY, int newX)
{
	_levelMap[fromY][fromX] = AIR;
	_levelMap[newY][newX] = charToUpdate;

	return;
}

int BattleField::GetMonsterHealthAtLocation(int y, int x)
{
	for (int i = 0; i < monster.size(); ++i)
	{
		if (monster[i].GetPlayerXLocation() == x && monster[i].GetPlayerYLocation() == y)
		{
			return monster[i].GetHealth();
		}
	}
	return -1;
}

int BattleField::GetMonsterHitDamageAtLocation(int y, int x)
{
	for (int i = 0; i < monster.size(); ++i)
	{
		if (monster[i].GetPlayerXLocation() == x && monster[i].GetPlayerYLocation() == y)
		{
			return monster[i].GetAttackPts();
		}
	}
	return -1;
}

float BattleField::GetMonsterChanceOfHitAtLocation(int y, int x)
{
	for (int i = 0; i < monster.size(); ++i)
	{
		if (monster[i].GetPlayerXLocation() == x && monster[i].GetPlayerYLocation() == y)
		{
			return monster[i].GetChanceOfHit();
		}
	}
	return -1.0f;
}

void BattleField::UpdateMonsterHealthAtLocation(int additionalHealth, int y, int x)
{
	for (int i = 0; i < monster.size(); ++i)
	{
		if (monster[i].GetPlayerXLocation() == x && monster[i].GetPlayerYLocation() == y)
		{
			monster[i].AddHealth(additionalHealth);
		}
	}
}







