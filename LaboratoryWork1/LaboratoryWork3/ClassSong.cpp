#include "ClassSong.h"

Song* Song::MakeSong(string songTitle, int duration, Genre genre)
{
	Song* song = new Song();
	this->SetTitle(songTitle);
	this->SetDuration(duration);
	this->SetGenre(genre);
	return song;
}

void Song::SetTitle(string songTitle)
{
	this->_songTitle = songTitle;
}

void Song::SetDuration(int duration)
{
	//TODO: Дублируется между cpp файлами
	if (duration < 0)
	{
		throw exception("Duration cannot be negative");
	}
	this->_duration = duration;
}

void Song::SetGenre(Genre genre)
{
	this->_genre = genre;
}

string Song::GetTitle()
{
	return this->_songTitle;
}

int Song::GetDuration()
{
	return this->_duration;
}

Genre Song::GetGenre()
{
	return this->_genre;
}