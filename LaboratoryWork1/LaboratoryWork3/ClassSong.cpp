#include "ClassSong.h"
#include "ReadValue.h"

Song::Song(string& songTitle, int duration, Genre genre)
{
	this->SetTitle(songTitle);
	this->SetDuration(duration);
	this->SetGenre(genre);
}

void Song::SetTitle(string& songTitle)
{
	this->_songTitle = songTitle;
}

void Song::SetDuration(int duration)
{
	//TODO: Дублируется между cpp файлами (+)
	this->_duration = ReadValue(duration);
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