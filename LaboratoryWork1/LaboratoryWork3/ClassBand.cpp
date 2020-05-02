#include "ClassBand.h"

Band* Band::MakeBand(string bandName, string description, int albumsCount, Album** albums)
{
	Band* band = new Band;
	this->SetBandName(bandName);
	this->SetDescription(description);
	this->SetAlbums(albumsCount, albums);
	return band;
}

void Band::SetBandName(string bandName)
{
	this->_bandName = bandName;
}

void Band::SetDescription(string description)
{
	this->_description = description;
}

void Band::SetAlbums(int albumsCount, Album** albums)
{
	if (albumsCount < 0)
	{
		throw exception("Songs count cannot be negative");
	}
	this->_albumsCount = albumsCount;
	this->_albums = albums;
}

Song* Band::FindSong(string songTitle)
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

void Band::DemoBand()
{
	const int songsCount = 4;
	Song** song1 = new Song * [songsCount];
	song1[0] = song1[0]->MakeSong("Unfunny Clown", 200, Blues);
	song1[1] = song1[1]->MakeSong("Cute Clown", 210, Jazz);
	song1[2] = song1[2]->MakeSong("Beautiful Clown", 203, Rap);
	song1[3] = song1[3]->MakeSong("Scary Clown", 179, Rap);

	Song** song2 = new Song * [songsCount];
	song2[0] = song2[0]->MakeSong("Watermelon", 185, Rap);
	song2[1] = song2[1]->MakeSong("Peach", 193, Chanson);
	song2[2] = song2[2]->MakeSong("Tasteless Banana", 167, Blues);
	song2[3] = song2[3]->MakeSong("Kiwi", 212, Rock);

	Song** song3 = new Song * [songsCount];
	song3[0] = song3[0]->MakeSong("Dewlap", 197, Rap);
	song3[1] = song3[1]->MakeSong("Heart", 216, Rock);
	song3[2] = song3[2]->MakeSong("Little Heart", 200, Blues);
	song3[3] = song3[3]->MakeSong("Jowls", 230, Rock);

	const int albumsCount = 3;
	Album** album = new Album * [albumsCount];
	album[0] = album[0]->MakeAlbum("Clowns", 2020, songsCount, song1);
	album[1] = album[1]->MakeAlbum("Funny fruits", 2012, songsCount, song2);
	album[2] = album[2]->MakeAlbum("Cakes", 1998, songsCount, song3);

	Band* band = MakeBand("Peaches", "Ben, Rosie, Lily", albumsCount, album);

	Song* foundSong = band->FindSong("Heart");
	cout << "Title: " << foundSong->GetTitle() << "\t"
		<< "Duration: " << foundSong->GetDuration() << "\t"
		<< "Genre: " << foundSong->GetGenre() << "\n" << endl;

	Album* foundAlbum = band->FindAlbum(song2[2]);
	cout << "Album title: " << foundAlbum->GetAlbumTitle() << "\t"
		<< "Year manufacture: " << foundAlbum->GetYearManufacture()
		<< "\n" << endl;

	int allSongsCount = 0;
	Song** allFoundSongs = band->GetAllSongs(allSongsCount);
	cout << "Number of songs ->\t" << allSongsCount << "\n" << endl;
	for (int i = 0; i < allSongsCount; i++)
	{
		cout << "Title: " << allFoundSongs[i]->GetTitle() << "\t"
			<< "Duration: " << allFoundSongs[i]->GetDuration() << "\t"
			<< "Genre: " << allFoundSongs[i]->GetGenre() << endl;
	}

	int allSongsCountInGenre = 0;
	Song** allGenreSongs = band->GetAllGenreSongs(Blues, allSongsCountInGenre);
	cout << "\nNumber of songs in genre ->\t" 
		<< allSongsCountInGenre << "\n" << endl;
	for (int i = 0; i < allSongsCountInGenre; i++)
	{
		cout << "Title: " << allGenreSongs[i]->GetTitle() << "\t"
			<< "Duration: " << allGenreSongs[i]->GetDuration() << "\t"
			<< "Genre: " << allGenreSongs[i]->GetGenre() << endl;
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