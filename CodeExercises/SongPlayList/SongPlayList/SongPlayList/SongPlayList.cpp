// SongPlayList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <map>

class Song
{
public:
	Song(std::string name) : name(name), nextSong(NULL) {}

	void next(Song* song)
	{
		this->nextSong = song;
	}


	bool isRepeatingPlaylist()
	{
		if (this == nullptr || this->nextSong == nullptr)
		{
			return false;
		}

		Song *slow = this, *fast = this;

		slow = slow->nextSong;
		fast = fast->nextSong->nextSong;

		while (fast && fast->nextSong)
		{
			if (slow == fast)
			{
				break;
			}
			slow = slow->nextSong;
			fast = fast->nextSong->nextSong;

		}

		if (slow == fast)
		{
			return true;

		}
		else
		{
			return false;
		}

	}

private:
	const std::string name;
	Song* nextSong;
};

int main()
{
	Song* first = new Song("Hello");
	Song* second = new Song("Eye of the tiger");
	Song* third = new Song("Eye of the Lion");

	first->next(second);
	second->next(third);
	third->next(second);

	std::cout << std::boolalpha << first->isRepeatingPlaylist();
}