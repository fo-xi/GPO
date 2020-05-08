#include <iostream>
#include "ClassAlbum.h"
#include "ReadValue.h"

Album::Album(string& albumTitle, int yearManufacture,
	int songsCount, Song** songs)
{
	this->SetAlbumTitle(albumTitle);
	this->SetYearManufacture(yearManufacture);
	this->SetSongs(songsCount, songs);
}

void Album::SetAlbumTitle(string& albumTitle)
{
	this->_albumTitle = albumTitle;
}

void Album::SetYearManufacture(int yearManufacture)
{
	if ((yearManufacture < 0) || (yearManufacture > 2020))
	{//TODO: Сообщение не отражает ограничения сверху (+)
		throw exception("Year of manufacture should be positive and not more than this year");
	}
	this->_yearManufacture = yearManufacture;
}

void Album::SetSongs(int songsCount, Song** songs)
{
	//TODO: Дублируется между cpp файлами (+)
	this->_songsCount = ReadValue(songsCount);
	this->_songs = songs;
}

string Album::GetAlbumTitle()
{
	return this->_albumTitle;
}

int Album::GetYearManufacture()
{
	return this->_yearManufacture;
}

Song** Album::GetSongs()
{
	return this->_songs;
}

int Album::GetSongsCount()
{
	return this->_songsCount;
}