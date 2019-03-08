#pragma once

#include <ctime>
#include <random>

class Player
{

private:
	int _xLoc;
	int _yLoc;
	char _playerCharacter;
	int _health;
	int _attackPts;
	float _chanceOfHits;


public:
	Player();
	Player(char playerChar, int y, int x);
	~Player();

	void UpdatePlayerLocation(int y, int x);
	void SetPlayerCharacter(char playerChar);
	char GetPlayerCharacter() { return _playerCharacter; }
	void FillPlayerStats(int attackPts, float chanceOfHit);
	float GetChanceOfHit() { return _chanceOfHits; }
	int GetHealth() { return _health; }
	int GetPlayerXLocation() { return _xLoc; }
	int GetPlayerYLocation() { return _yLoc; }
	void AddHealth(int healthAmnt) {_health += healthAmnt; }
	int GetAttackPts() { return _attackPts; }



};

