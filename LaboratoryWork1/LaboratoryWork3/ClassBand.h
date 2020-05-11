#pragma once
#include <iostream>
#include <string>
#include"ClassAlbum.h"

class Band
{
	private:
		string _bandName;
		string _description;
		Album** _albums = nullptr;
		int _albumsCount;
	public:
		Band(string&, string&, int, Album**);
		void SetBandName(string&);
		void SetDescription(string&);
		void SetAlbums(int, Album**);

		Song* FindSong(string&);
		Album* FindAlbum(Song*);
		Song** GetAllSongs(int&);
		Song** GetAllGenreSongs(Genre, int&);
		void WriteGenre(Genre);
		void WriteSongs(Song*);
		void DemoBand();

		string GetBandName();
		string GetDescription();
		Album** GetAlbums();
		int GetAlbumsCount();
};
