#include "pch.h"
#include "Player.h"


Player::Player()
{
}

Player::Player(char playerChar, int y, int x)
{
	_playerCharacter = playerChar;
	UpdatePlayerLocation(y, x);

}


Player::~Player()
{
}



void Player::UpdatePlayerLocation(int y, int x)
{
	_xLoc = x;
	_yLoc = y;
}

void Player::SetPlayerCharacter(char playerChar)
{
	_playerCharacter = playerChar;
}


void Player::FillPlayerStats(int attackPts, float chanceOfHit)
{
	_health = 100;
	_attackPts = attackPts;
	_chanceOfHits = chanceOfHit;
	return;
}




