#include "pch.h"
#include "GameManager.h"
#include <conio.h>
#include <string>

#include <random>
#include <ctime>

std::default_random_engine randomEngine(time(0));

GameManager::GameManager()
{
	_player.SetPlayerCharacter(player1Char);
}


GameManager::~GameManager()
{
}

void GameManager::StartGame()
{
	char moveInput;
	int x, y;
	_player.FillPlayerStats(6, 0.6f);
	while (true)
	{
		InitializePlayerLocation(_player.GetPlayerCharacter(), y, x);
		ClearScreen();
		// DisplayMap
		_bf.DisplayField();
		// Display message waiting for input
		std::cout << "Please enter an action to take w/s/a/d (Q to quit): ";
		// Update map according to input
		moveInput = _getch();

		if(moveInput == 'Q' || moveInput == 'q')
		{
			break;
		}

		MovePlayer(moveInput, y, x);

		if (_player.GetHealth() <= 0)
		{
			printf("PLAYER LOST... SORRY\n");
			break;
		}
	}

}


void GameManager::ClearScreen()
{
	std::cout << std::string(100, '\n');
}

void GameManager::MovePlayer(char moveInput, int y, int x)
{

	switch (moveInput)
	{
	case 'a':
		if (_bf.IsElementAtMapLocationPassable(y, x-1))
		{
			Advance(_player.GetPlayerCharacter(), y, x, y, x - 1);
		}
		else
		{
			if (_bf.IsElementAnEnemy(y, x - 1))
			{
				EngageEnemy(y, x-1);

				if (_bf.GetMonsterHealthAtLocation(y, x - 1) <= 0)
				{
					printf("Player won the battle!!!");
					Advance(_player.GetPlayerCharacter(), y, x, y, x - 1);
				}

			}
		}
		break;
	case 'w':
		if (_bf.IsElementAtMapLocationPassable(y-1, x))
		{
			Advance(_player.GetPlayerCharacter(), y, x, y-1, x);
		}
		else
		{
			if (_bf.IsElementAnEnemy(y - 1, x))
			{
				EngageEnemy(y - 1, x);

				if (_bf.GetMonsterHealthAtLocation(y - 1, x) <= 0)
				{
					printf("Player won the battle!!!");
					Advance(_player.GetPlayerCharacter(), y, x, y - 1, x);
				}

			}
		}
		break;
	case 's':
		if (_bf.IsElementAtMapLocationPassable(y + 1, x))
		{
			Advance(_player.GetPlayerCharacter(), y, x, y + 1, x);
		}
		else
		{
			if (_bf.IsElementAnEnemy(y + 1, x))
			{
				EngageEnemy(y + 1, x);

				if (_bf.GetMonsterHealthAtLocation(y + 1, x) <= 0)
				{
					printf("Player won the battle!!!");
					Advance(_player.GetPlayerCharacter(), y, x, y + 1, x);
				}

			}
		}
		break;
	case 'd':
		if (_bf.IsElementAtMapLocationPassable(y, x + 1))
		{
			Advance(_player.GetPlayerCharacter(), y, x, y, x + 1);
		}
		else
		{
			if (_bf.IsElementAnEnemy(y, x + 1))
			{
				EngageEnemy(y, x + 1);

				if (_bf.GetMonsterHealthAtLocation(y, x + 1) <= 0)
				{
					printf("Player won the battle!!!");
					Advance(_player.GetPlayerCharacter(), y, x, y, x + 1);
				}

			}
		}
		break;
	}

}

void GameManager::Advance(char characterToMove, int origY, int origX, int newY, int newX)
{
	_bf.UpdateLocationOfCharacter(characterToMove, origY, origX, newY, newX);
	_player.UpdatePlayerLocation(newY, newX);
}

void GameManager::InitializePlayerLocation(char playerChar, int & y, int & x)
{
	_bf.GetLocationOfCharacter(playerChar, y, x);
}

void GameManager::EngageEnemy(int y, int x)
{
	char input;
	bool playerTurn = true;


	std::cout << "\nAn enemy has been detected, do you want to engage? (Y - Yes / N - No) ";
	input = _getch();

	if (input == 'Y' || input == 'y')
	{

		std::cout << "Engaging enemy" << std::endl;

		std::uniform_int_distribution<int> playerHitDamage(1, _player.GetAttackPts());
		std::uniform_real_distribution<float> playerHit(0, 1);
		std::uniform_int_distribution<int> enemyHitDamage(1, _bf.GetMonsterHitDamageAtLocation(y, x));

		
		while (_player.GetHealth() > 0 && _bf.GetMonsterHealthAtLocation(y, x) > 0)
		{
			printf("Player health: %d\n", _player.GetHealth());
			printf("Enemy health:  %d\n", _bf.GetMonsterHealthAtLocation(y, x));

			if (playerTurn)
			{
				if (playerHit(randomEngine) <= _player.GetChanceOfHit())
				{
					int damage = playerHitDamage(randomEngine);
					_bf.UpdateMonsterHealthAtLocation(-damage, y, x);
					printf("Enemy got hit with %d damage\n", damage);
				}
				
				playerTurn = false;
			}
			else
			{
				if (playerHit(randomEngine) <= _bf.GetMonsterChanceOfHitAtLocation(y, x))
				{
					int damage = enemyHitDamage(randomEngine);
					_player.AddHealth(-damage);
					printf("Player got hit with %d damage\n", damage);
				}
				playerTurn = true;
			}
		}


		printf("Player health: %d\n", _player.GetHealth());
		printf("Enemy health:  %d\n", _bf.GetMonsterHealthAtLocation(y, x));

	}


}
