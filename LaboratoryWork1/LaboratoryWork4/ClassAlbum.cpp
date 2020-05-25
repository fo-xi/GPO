#include <iostream>
#include "ClassAlbum.h"
#include "DoubleValidator.h"

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
	{
		throw exception("The year must be positive in the range from 0 to 2020 inclusive");
	}
	this->_yearManufacture = yearManufacture;
}

void Album::SetSongs(int songsCount, Song** songs)
{
	DoubleValidator::AssertPositiveValue(songsCount);
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