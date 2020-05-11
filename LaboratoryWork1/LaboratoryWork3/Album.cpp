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
		//TODO: В следующем году программа будет работать не верно, лучше указать конкретный год. Код дублируется между файлами...
		throw exception("Year of manufacture should be positive and not more than this year");
	}
	album->YearManufacture = yearManufacture;
}

void SetSongs(Album* album, int songsCount, Song** songs)
{
	album->SongsCount = ReadValue(songsCount);
	album->Songs = songs;
}