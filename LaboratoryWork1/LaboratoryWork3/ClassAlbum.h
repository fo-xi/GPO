#pragma once
#include <string>
#include"ClassSong.h"

class Album
{
	private:
		string _albumTitle;
		int _yearManufacture;
		Song** _songs = nullptr;
		int _songsCount;
	public:
		Album(string&, int, int, Song**);
		void SetAlbumTitle(string&);
		void SetYearManufacture(int);
		void SetSongs(int, Song**);

		string GetAlbumTitle();
		int GetYearManufacture();
		Song** GetSongs();
		int GetSongsCount();
};