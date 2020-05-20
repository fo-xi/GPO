#include "Album.h"
#include "ReadValue.h"

Album* MakeAlbum(string& albumTitle, int yearManufacture,
	int songsCount, Song** songs)
{
	Album* album = new Album();
	SetAlbumTitle(album, albumTitle);
	SetYearManufacture(album, yearManufacture);
	SetSongs(album, songsCount, songs);
	return album;
}

void SetAlbumTitle(Album* album, string& albumTitle)
{
	album->AlbumTitle = albumTitle;
}

void SetYearManufacture(Album* album, int yearManufacture)
{
	if ((yearManufacture < 0) || (yearManufacture > 2020))
	{
		throw exception("The year must be positive in the range from 0 to 2020 inclusive");
	}
	album->YearManufacture = yearManufacture;
}

void SetSongs(Album* album, int songsCount, Song** songs)
{
	album->SongsCount = ReadValue(songsCount);
	album->Songs = songs;
}