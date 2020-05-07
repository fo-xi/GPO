#include "Album.h"

Album* MakeAlbum(string albumTitle, int yearManufacture,
	int songsCount, Song** songs)
{
	Album* album = new Album();
	SetAlbumTitle(album, albumTitle);
	SetYearManufacture(album, yearManufacture);
	SetSongs(album, songsCount, songs);
	return album;
}

void SetAlbumTitle(Album* album, string albumTitle)
{
	album->AlbumTitle = albumTitle;
}

void SetYearManufacture(Album* album, int yearManufacture)
{
	if ((yearManufacture < 0) || (yearManufacture > 2020))
	{
		//TODO: Сообщение не отражает ограничения сверху
		throw exception("Year manufacture cannot be negative");
	}
	album->YearManufacture = yearManufacture;
}

void SetSongs(Album* album, int songsCount, Song** songs)
{
	//TODO: Дублируется между cpp файлами
	if (songsCount < 0)
	{
		throw exception("Songs count cannot be negative");
	}
	album->SongsCount = songsCount;
	album->Songs = songs;
}