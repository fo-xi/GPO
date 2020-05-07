#pragma once
#include <iostream>
#include <string>
#include "Genre.h"

using namespace std;

class Song
{
	private:
		string _songTitle;
		int _duration;
		Genre _genre;
	public:
	//TODO: Строку по ссылке?
		Song* MakeSong(string, int, Genre);
		void SetTitle(string);
		void SetDuration(int);
		void SetGenre(Genre);

		string GetTitle();
		int GetDuration();
		Genre GetGenre();
};