#pragma once
#include <iostream>
#include <string>
#include"Song.h"

struct Album
{
	string AlbumTitle;
	int YearManufacture;
	Song** Songs = nullptr;
	int SongsCount;
};
//TODO: ������ �� ������? (+)
Album* MakeAlbum(string&, int, int, Song**);
void SetAlbumTitle(Album*, string&);
void SetYearManufacture(Album*, int);
void SetSongs(Album*, int, Song**);