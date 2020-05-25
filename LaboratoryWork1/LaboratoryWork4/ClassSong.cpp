#include "ClassSong.h"
#include "DoubleValidator.h"

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
	DoubleValidator::AssertPositiveValue(duration);
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