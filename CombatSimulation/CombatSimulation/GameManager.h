#pragma once

#include <iostream>
#include <string>
#include "BattleField.h"
#include "Player.h"

class GameManager
{

private:

	static const char player1Char = '@';

	BattleField _bf;
	Player _player;

public:
	GameManager();
	~GameManager();
	void StartGame();
	void ClearScreen();
	void MovePlayer(char moveInput, int y, int x);
	void Advance(char characterToMove, int origY, int origX, int newY, int newX);
	void InitializePlayerLocation(char playerchar, int &y, int &x);
	void EngageEnemy(int y, int x);
};

