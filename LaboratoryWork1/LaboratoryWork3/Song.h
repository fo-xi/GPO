#pragma once
#include <iostream>
#include <string>
#include"Genre.h"

using namespace std;

struct Song
{
	string SongTitle;
	int Duration;
	Genre Genre;
};

Song* MakeSong(string, int, Genre);
void SetTitle(Song*, string);
void SetDuration(Song*, int);
void SetGenre(Song*, Genre);
