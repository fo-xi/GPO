#pragma once
#include <iostream>
#include <string>
#include"Album.h"

struct Band
{
	string BandName;
	string Description;
	Album** Albums = nullptr;
	int AlbumsCount;
};
//TODO: Строку по ссылке? (+)
Band* MakeBand(string&, string&, int, Album**);
void SetBandName(Band*, string&);
void SetDescription(Band*, string&);
void SetAlbums(Band*, int, Album**);
Song* FindSong(Band*, string&);
Album* FindAlbum(Band*, Song*);
Song** GetAllSongs(Band*, int&);
Song** GetAllGenreSongs(Band*, Genre, int&);
void WriteGenre(Genre);
void WriteSongs(Song*);
void DemoBand();
