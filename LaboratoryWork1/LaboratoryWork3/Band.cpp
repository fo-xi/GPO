#include "Band.h"
#include "ReadValue.h"

Band* MakeBand(string& bandName, string& description, int albumsCount,
	Album** albums)
{
	Band* band = new Band;
	SetBandName(band, bandName);
	SetDescription(band, description);
	SetAlbums(band, albumsCount, albums);
	return band;
}

void SetBandName(Band* band, string& bandName)
{
	band->BandName = bandName;
}

void SetDescription(Band* band, string& description)
{
	band->Description = description;
}

void SetAlbums(Band* band, int albumsCount, Album** albums)
{
	//TODO: Дублируется между cpp файлами (+)
	band->AlbumsCount = ReadValue(albumsCount);
	band->Albums = albums;
}

Song* FindSong(Band* band, string& songTitle)
{
	for (int i = 0; i < band->AlbumsCount; i++)
	{
		for (int j = 0; j < band->Albums[i]->SongsCount; j++)
		{
			if (band->Albums[i]->Songs[j]->SongTitle == songTitle)
			{
				return band->Albums[i]->Songs[j];
			}
		}
	}
	return nullptr;
}

Album* FindAlbum(Band* band, Song* song)
{
	for (int i = 0; i < band->AlbumsCount; i++)
	{
		for (int j = 0; j < band->Albums[i]->SongsCount; j++)
		{
			if (band->Albums[i]->Songs[j] == song)
			{
				return band->Albums[i];
			}
		}
	}
	return nullptr;
}

Song** GetAllSongs(Band* band, int& allSongsCount)
{
	allSongsCount = 0;
	for (int i = 0; i < band->AlbumsCount; i++)
	{
		for (int j = 0; j < band->Albums[i]->SongsCount; j++)
		{
			allSongsCount++;
		}
	}
	Song** allSongs = new Song * [allSongsCount];
	int count = 0;
	for (int i = 0; i < band->AlbumsCount; i++)
	{
		for (int j = 0; j < band->Albums[i]->SongsCount; j++)
		{
			allSongs[count] = band->Albums[i]->Songs[j];
			count++;
		}
	}
	return allSongs;
}

Song** GetAllGenreSongs(Band* band, Genre findingGenre, int& allSongsCountInGenre)
{
	allSongsCountInGenre = 0;
	for (int i = 0; i < band->AlbumsCount; i++)
	{
		for (int j = 0; j < band->Albums[i]->SongsCount; j++)
		{
			if (band->Albums[i]->Songs[j]->Genre == findingGenre)
			{
				allSongsCountInGenre++;
			}
		}
	}
	Song** allSongs = new Song * [allSongsCountInGenre];
	int count = 0;
	for (int i = 0; i < band->AlbumsCount; i++)
	{
		for (int j = 0; j < band->Albums[i]->SongsCount; j++)
		{
			if (band->Albums[i]->Songs[j]->Genre == findingGenre)
			{
				allSongs[count] = band->Albums[i]->Songs[j];
				count++;
			}
		}
	}
	return allSongs;
}

void WriteGenre(Genre genre)
{
	switch (genre)
	{
		case 0:
		{
			cout << "Blues";
			break;
		}
		case 1:
		{
			cout << "Jazz";
			break;
		}
		case 2:
		{
			cout << "Pop";
			break;
		}
		case 3:
		{
			cout << "Rock";
			break;
		}
		case 4:
		{
			cout << "Rap";
			break;
		}
		case 5:
		{
			cout << "Chanson";
			break;
		}
		default:
			break;
	}
}

void WriteSongs(Song* song)
{
	cout << "Title: " << song->SongTitle << "\t"
		<< "Duration: " << song->Duration << "\t"
		<< "Genre: ";
	WriteGenre(song->Genre);
	cout << endl;
}

void DemoBand()
{
	const int songsCount = 4;
	Song** song1 = new Song * [songsCount];

	string songTitle1 = "Unfunny Clown";
	string songTitle2 = "Cute Clown";
	string songTitle3 = "Beautiful Clown";
	string songTitle4 = "Scary Clown";

	song1[0] = MakeSong(songTitle1, 200, Blues);
	song1[1] = MakeSong(songTitle2, 210, Jazz);
	song1[2] = MakeSong(songTitle3, 203, Rap);
	song1[3] = MakeSong(songTitle4, 179, Rap);

	Song** song2 = new Song * [songsCount];

	songTitle1 = "Melon";
	songTitle2 = "Peach";
	songTitle3 = "Banana";
	songTitle4 = "Kiwi";

	song2[0] = MakeSong(songTitle1, 185, Rap);
	song2[1] = MakeSong(songTitle2, 193, Chanson);
	song2[2] = MakeSong(songTitle3, 167, Blues);
	song2[3] = MakeSong(songTitle4, 212, Rock);

	Song** song3 = new Song * [songsCount];

	songTitle1 = "Dewlap";
	songTitle2 = "Heart";
	songTitle3 = "Ear";
	songTitle4 = "Jowls";

	song3[0] = MakeSong(songTitle1, 197, Rap);
	song3[1] = MakeSong(songTitle2, 216, Rock);
	song3[2] = MakeSong(songTitle3, 200, Blues);
	song3[3] = MakeSong(songTitle4, 230, Rock);

	const int albumsCount = 3;
	Album** album = new Album * [albumsCount];

	string albumTitle = "Clown";
	album[0] = MakeAlbum(albumTitle, 2020, songsCount, song1);
	albumTitle = "Funny fruits";
	album[1] = MakeAlbum(albumTitle, 2012, songsCount, song2);
	albumTitle = "Cakes";
	album[2] = MakeAlbum(albumTitle, 1998, songsCount, song3);

	string bandName = "Peaches";
	string description = "Ben, Rosie, Lily";
	Band* band = MakeBand(bandName, description, albumsCount, album);

	Song* foundSong = FindSong(band, songTitle2);
	cout << "Title: " << foundSong->SongTitle << "\t"
		<< "Duration: " << foundSong->Duration << "\t"
		<< "Genre: ";
	WriteGenre(foundSong->Genre);
	cout << endl;

	Album* foundAlbum = FindAlbum(band, song2[2]);
	cout << "Album title: " << foundAlbum->AlbumTitle << "\t"
		<< "Year manufacture: " << foundAlbum->YearManufacture
		<< "\n" << endl;

	int allSongsCount = 0;
	Song** allFoundSongs = GetAllSongs(band, allSongsCount);
	cout << "Number of songs ->\t" << allSongsCount << "\n" << endl;
	//TODO: Дубль (+)
	for (int i = 0; i < allSongsCount; i++)
	{
		WriteSongs(allFoundSongs[i]);
	}

	int allSongsCountInGenre = 0;
	Song** allGenreSongs = GetAllGenreSongs(band, Blues, allSongsCountInGenre);
	cout << "\nNumber of songs in genre ->\t";
	WriteGenre(Blues);
	cout << "\n" << endl;
	//TODO: Дубль (+)
	for (int i = 0; i < allSongsCountInGenre; i++)
	{
		WriteSongs(allGenreSongs[i]);
	}
	for (int i = 0; i < songsCount; i++)
	{
		delete song1[i];
		delete song2[i];
		delete song3[i];
	}
	delete[] song1;
	delete[] song2;
	delete[] song3;
	for (int i = 0; i < albumsCount; i++)
	{
		delete album[i];
	}
	delete[] album;
	delete band;
	delete[] allFoundSongs;
	delete[] allGenreSongs;
}