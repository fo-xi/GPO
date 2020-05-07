#include <iostream>
#include "ClassAlbum.h"

Album* Album::MakeAlbum(string albumTitle, int yearManufacture,
	int songsCount, Song** songs)
{
	Album* album = new Album();
	this->SetAlbumTitle(albumTitle);
	this->SetYearManufacture(yearManufacture);
	this->SetSongs(songsCount, songs);
	return album;
}

void Album::SetAlbumTitle(string albumTitle)
{
	this->_albumTitle = albumTitle;
}

void Album::SetYearManufacture(int yearManufacture)
{
	if ((yearManufacture < 0) || (yearManufacture > 2020))
	{//TODO: Сообщение не отражает ограничения сверху
		throw exception("Year manufacture cannot be negative");
	}
	this->_yearManufacture = yearManufacture;
}

void Album::SetSongs(int songsCount, Song** songs)
{
	//TODO: Дублируется между cpp файлами
	if (songsCount < 0)
	{
		throw exception("Songs count cannot be negative");
	}
	this->_songsCount = songsCount;
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