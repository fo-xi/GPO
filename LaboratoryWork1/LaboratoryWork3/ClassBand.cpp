#include "ClassBand.h"
#include "ReadValue.h"

Band::Band(string& bandName, string& description, int albumsCount, Album** albums)
{
	this->SetBandName(bandName);
	this->SetDescription(description);
	this->SetAlbums(albumsCount, albums);
}

void Band::SetBandName(string& bandName)
{
	this->_bandName = bandName;
}

void Band::SetDescription(string& description)
{
	this->_description = description;
}

void Band::SetAlbums(int albumsCount, Album** albums)
{
	//TODO: ����������� ����� cpp ������� (+)
	this->_albumsCount = ReadValue(albumsCount);
	this->_albums = albums;
}

Song* Band::FindSong(string& songTitle)
{
	for (int i = 0; i < this->GetAlbumsCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i]->GetSongsCount(); j++)
		{
			if (this->GetAlbums()[i]->GetSongs()[j]->GetTitle() == songTitle)
			{
				return this->GetAlbums()[i]->GetSongs()[j];
			}
		}
	}
	return nullptr;
}

Album* Band::FindAlbum(Song* song)
{
	for (int i = 0; i < this->GetAlbumsCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i]->GetSongsCount(); j++)
		{
			if (this->GetAlbums()[i]->GetSongs()[j] == song)
			{
				return this->GetAlbums()[i];
			}
		}
	}
	return nullptr;
}

Song** Band::GetAllSongs(int& allSongsCount)
{
	allSongsCount = 0;
	for (int i = 0; i < this->GetAlbumsCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i]->GetSongsCount(); j++)
		{
			allSongsCount++;
		}
	}
	Song** allSongs = new Song * [allSongsCount];
	int count = 0;
	for (int i = 0; i < this->GetAlbumsCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i]->GetSongsCount(); j++)
		{
			allSongs[count] = this->GetAlbums()[i]->GetSongs()[j];
			count++;
		}
	}
	return allSongs;
}

Song** Band::GetAllGenreSongs(Genre findingGenre, int& allSongsCountInGenre)
{
	allSongsCountInGenre = 0;
	for (int i = 0; i < this->GetAlbumsCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i]->GetSongsCount(); j++)
		{
			if (this->GetAlbums()[i]->GetSongs()[j]->GetGenre() == findingGenre)
			{
				allSongsCountInGenre++;
			}
		}
	}
	Song** allSongs = new Song * [allSongsCountInGenre];
	int count = 0;
	for (int i = 0; i < this->GetAlbumsCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i]->GetSongsCount(); j++)
		{
			if (this->GetAlbums()[i]->GetSongs()[j]->GetGenre() == findingGenre)
			{
				allSongs[count] = this->GetAlbums()[i]->GetSongs()[j];
				count++;
			}
		}
	}
	return allSongs;
}

void WriteSongs(Song* song)
{
	cout << "Title: " << song->GetTitle() << "\t"
		<< "Duration: " << song->GetDuration() << "\t"
		<< "Genre: " << song->GetGenre() << endl;
}

void Band::DemoBand()
{
	const int songsCount = 4;
	Song** song1 = new Song * [songsCount];

	string songTitle1 = "Unfunny Clown";
	string songTitle2 = "Cute Clown";
	string songTitle3 = "Beautiful Clown";
	string songTitle4 = "Scary Clown";

	song1[0] = song1[0]->MakeSong(songTitle1, 200, Blues);
	song1[1] = song1[1]->MakeSong(songTitle2, 210, Jazz);
	song1[2] = song1[2]->MakeSong(songTitle3, 203, Rap);
	song1[3] = song1[3]->MakeSong(songTitle4, 179, Rap);

	Song** song2 = new Song * [songsCount];

	songTitle1 = "Watermelon";
	songTitle2 = "Peach";
	songTitle3 = "Tasteless Banana";
	songTitle4 = "Kiwi";

	song2[0] = song2[0]->MakeSong(songTitle1, 185, Rap);
	song2[1] = song2[1]->MakeSong(songTitle2, 193, Chanson);
	song2[2] = song2[2]->MakeSong(songTitle3, 167, Blues);
	song2[3] = song2[3]->MakeSong(songTitle4, 212, Rock);

	Song** song3 = new Song * [songsCount];

	songTitle1 = "Dewlap";
	songTitle2 = "Heart";
	songTitle3 = "Little Heart";
	songTitle4 = "Jowls";

	song3[0] = song3[0]->MakeSong(songTitle1, 197, Rap);
	song3[1] = song3[1]->MakeSong(songTitle2, 216, Rock);
	song3[2] = song3[2]->MakeSong(songTitle3, 200, Blues);
	song3[3] = song3[3]->MakeSong(songTitle4, 230, Rock);

	const int albumsCount = 3;
	Album** album = new Album * [albumsCount];

	string albumTitle = "Clown";
	album[0] = album[0]->MakeAlbum(albumTitle, 2020, songsCount, song1);
	albumTitle = "Funny fruits";
	album[1] = album[1]->MakeAlbum(albumTitle, 2012, songsCount, song2);
	albumTitle = "Cakes";
	album[2] = album[2]->MakeAlbum(albumTitle, 1998, songsCount, song3);

	string bandName = "Peaches";
	string description = "Ben, Rosie, Lily";
	Band* band = MakeBand(bandName, description, albumsCount, album);

	Song* foundSong = band->FindSong(songTitle2);
	cout << "Title: " << foundSong->GetTitle() << "\t"
		<< "Duration: " << foundSong->GetDuration() << "\t"
		<< "Genre: " << foundSong->GetGenre() << "\n" << endl;

	Album* foundAlbum = band->FindAlbum(song2[2]);
	cout << "Album title: " << foundAlbum->GetAlbumTitle() << "\t"
		<< "Year manufacture: " << foundAlbum->GetYearManufacture()
		<< "\n" << endl;

	int allSongsCount = 0;
	Song** allFoundSongs = band->GetAllSongs(allSongsCount);
	//TODO: ����� (+)
	cout << "Number of songs ->\t" << allSongsCount << "\n" << endl;
	for (int i = 0; i < allSongsCount; i++)
	{
		WriteSongs(allFoundSongs[i]);
	}

	int allSongsCountInGenre = 0;
	Song** allGenreSongs = band->GetAllGenreSongs(Blues, allSongsCountInGenre);
	cout << "\nNumber of songs in genre ->\t" 
		<< allSongsCountInGenre << "\n" << endl;
	//TODO: ����� (+)
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

string Band::GetBandName()
{
	return this->_bandName;
}

string Band::GetDescription()
{
	return this->_description;
}

Album** Band::GetAlbums()
{
	return this->_albums;
}

int Band::GetAlbumsCount()
{
	return this->_albumsCount;
}