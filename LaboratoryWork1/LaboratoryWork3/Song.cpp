#include "Song.h"

Song* MakeSong(string songTitle, int duration, Genre genre)
{
	Song* song = new Song();
	SetTitle(song, songTitle);
	SetDuration(song, duration);
	SetGenre(song, genre);
	return song;
}

void SetTitle(Song* song, string songTitle)
{
	song->SongTitle = songTitle;
}

void SetDuration(Song* song, int duration)
{
	if (duration < 0)
	{
		throw exception("Duration cannot be negative");
	}
	song->Duration = duration;
}

void SetGenre(Song* song, Genre genre)
{
	song->Genre = genre;
}