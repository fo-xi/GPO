#include "Band.h"

Band* MakeBand(string bandName, string description, int albumsCount,
	Album** albums)
{
	Band* band = new Band;
	SetBandName(band, bandName);
	SetDescription(band, description);
	SetAlbums(band, albumsCount, albums);
	return band;
}

void SetBandName(Band* band, string bandName)
{
	band->BandName = bandName;
}

void SetDescription(Band* band, string description)
{
	band->Description = description;
}

void SetAlbums(Band* band, int albumsCount, Album** albums)
{
	//TODO: Дублируется между cpp файлами
	if (albumsCount < 0)
	{
		throw exception("Songs count cannot be negative");
	}
	band->AlbumsCount = albumsCount;
	band->Albums = albums;
}

Song* FindSong(Band* band, string songTitle)
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

void DemoBand()
{
	const int songsCount = 4;
	Song** song1 = new Song * [songsCount];
	song1[0] = MakeSong("Unfunny Clown", 200, Blues);
	song1[1] = MakeSong("Cute Clown", 210, Jazz);
	song1[2] = MakeSong("Beautiful Clown", 203, Rap);
	song1[3] = MakeSong("Scary Clown", 179, Rap);

	Song** song2 = new Song * [songsCount];
	song2[0] = MakeSong("Watermelon", 185, Rap);
	song2[1] = MakeSong("Peach", 193, Chanson);
	song2[2] = MakeSong("Tasteless Banana", 167, Blues);
	song2[3] = MakeSong("Kiwi", 212, Rock);

	Song** song3 = new Song * [songsCount];
	song3[0] = MakeSong("Dewlap", 197, Rap);
	song3[1] = MakeSong("Heart", 216, Rock);
	song3[2] = MakeSong("Little Heart", 200, Blues);
	song3[3] = MakeSong("Jowls", 230, Rock);

	const int albumsCount = 3;
	Album** album = new Album * [albumsCount];
	album[0] = MakeAlbum("Clowns", 2020, songsCount, song1);
	album[1] = MakeAlbum("Funny fruits", 2012, songsCount, song2);
	album[2] = MakeAlbum("Cakes", 1998, songsCount, song3);

	Band* band = MakeBand("Peaches", "Ben, Rosie, Lily", albumsCount, album);

	Song* foundSong = FindSong(band, "Heart");
	cout << "Title: " << foundSong->SongTitle << "\t"
		<< "Duration: " << foundSong->Duration << "\t"
		<< "Genre: " << foundSong->Genre << "\n" << endl;

	Album* foundAlbum = FindAlbum(band, song2[2]);
	cout << "Album title: " << foundAlbum->AlbumTitle << "\t"
		<< "Year manufacture: " << foundAlbum->YearManufacture
		<< "\n" << endl;

	int allSongsCount = 0;
	Song** allFoundSongs = GetAllSongs(band, allSongsCount);
	cout << "Number of songs ->\t" << allSongsCount << "\n" << endl;
	//TODO: Дубль
	for (int i = 0; i < allSongsCount; i++)
	{
		cout << "Title: " << allFoundSongs[i]->SongTitle << "\t"
			<< "Duration: " << allFoundSongs[i]->Duration << "\t"
			<< "Genre: " << allFoundSongs[i]->Genre << endl;
	}

	int allSongsCountInGenre = 0;
	Song** allGenreSongs = GetAllGenreSongs(band, Blues, allSongsCountInGenre);
	cout << "\nNumber of songs in genre ->\t" 
		<< allSongsCountInGenre << "\n" << endl;
	//TODO: Дубль
	for (int i = 0; i < allSongsCountInGenre; i++)
	{
		cout << "Title: " << allGenreSongs[i]->SongTitle << "\t"
			<< "Duration: " << allGenreSongs[i]->Duration << "\t"
			<< "Genre: " << allGenreSongs[i]->Genre << endl;
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