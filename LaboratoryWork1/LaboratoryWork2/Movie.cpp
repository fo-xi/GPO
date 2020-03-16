#include <iostream>
#include "Movie.h"
#include "..\Common\ReadNumber.h"

Genre ReadGenre()
{
	Genre genre;
	cout << "\n0 - comedy\n 1 - drama\n 2 - thriller\n "
		<< "3 - actionMovie\n 4 - horror\n 5 - blockbuster\n"
		<< "Enter a number from 0 to 6:\t";

	switch (ReadNumber<int>())
	{
		//TODO: RSDN
	case 0:
	{
		genre = Comedy;
		break;
	}
	case 1:
	{
		genre = Drama;
		break;
	}
	case 2:
	{
		genre = Thriller;
		break;
	}
	case 3:
	{
		genre = ActionMovie;
		break;
	}
	case 4:
	{
		genre = Horror;
		break;
	}
	case 5:
	{
		genre = Blockbuster;
		break;
	}
		//TODO: default?
	}
	return genre;
}

void WriteMovie(Movie& movie)
{
	cout << "Title:\t" << movie.Title << "\n"
		<< "DurationInMinutes:\t" << movie.DurationInMinutes << "\n"
		<< "Genre:\t" << movie.Genre << "\n"
		<< "Rating:\t" << movie.Rating << "\n"
		<< "YearOfIssuel:\t" << movie.YearOfIssuel << endl;
}

void ReadMovie(Movie& movie)
{
	cout << "Title ->\t";
	cin >> movie.Title;
	cout << "DurationInMinutes ->\t";
	movie.DurationInMinutes = ReadNumber<int>();
	cout << "Genre ->\t";
	movie.Genre = ReadGenre();
	cout << "Rating ->\t";
	movie.Rating = ReadNumber<double>();
	//TODO: naming
	cout << "YearOfIssuel ->\t";
	movie.YearOfIssuel = ReadNumber<int>();
}

void DemoMovie()
{
	//2.2.3.1
	Movie movie1;
	movie1.Title = "Titanic";
	movie1.DurationInMinutes = 210;
	movie1.Genre = Drama;
	movie1.Rating = 8.4;
	movie1.YearOfIssuel = 1997;
	//2.2.3.2
	Movie movie2;
	cout << "Title:\t";
	cin >> movie2.Title;
	cout << "DurationInMinutes:\t";
	movie2.DurationInMinutes = ReadNumber<int>();
	cout << "Genre:\t";
	movie2.Genre = ReadGenre();
	cout << "Rating:\t";
	movie2.Rating = ReadNumber<double>();
	cout << "YearOfIssuel:\t";
	movie2.YearOfIssuel = ReadNumber<int>();

	cout << endl;
	cout << "Title:\t" << movie2.Title << "\n"
		<< "DurationInMinutes:\t" << movie2.DurationInMinutes << "\n"
		<< "Genre:\t" << movie2.YearOfIssuel << "\n"
		<< "Rating:\t" << movie2.Genre << "\n"
		<< "YearOfIssuel:\t" << movie2.Rating << endl;
	cout << endl;
	//2.2.3.3
	const int count = 3;
	Movie arrayMovie[count] = {};

	for (int i = 0; i < count; i++)
	{
		ReadMovie(arrayMovie[i]);
		cout << endl;
	}
	for (int i = 0; i < count; i++)
	{
		WriteMovie(arrayMovie[i]);
		cout << endl;
	}
	//2.2.4.1
	Movie* pointerMovie1;
	pointerMovie1 = &movie1;
	//2.2.4.2
	Movie* pointer2Movie1;
	pointer2Movie1 = &movie1;
	cout << "The address that is stored in the first pointer to the structure: "
		<< pointerMovie1 << "\n"
		<< "The address that is stored in the first pointer to the structure: "
		<< pointer2Movie1 << endl;
}

Movie* MakeMovie(string title, int durationInMinutes, int yearOfIssuel, Genre genre, double rating)
{
	Movie* movie = new Movie();
	movie->Title = title;
	movie->DurationInMinutes = durationInMinutes;
	movie->YearOfIssuel = yearOfIssuel;
	movie->Genre = genre;
	movie->Rating = rating;
	WriteMovie(*movie);
	return movie;
}

Movie* CopyFlight(Movie& movie)
{
	Movie* copiedMovie = new Movie();
	copiedMovie->Title = movie.Title;
	copiedMovie->DurationInMinutes = movie.DurationInMinutes;
	copiedMovie->YearOfIssuel = movie.YearOfIssuel;
	copiedMovie->Genre = movie.Genre;
	copiedMovie->Rating = movie.Rating;
	WriteMovie(*copiedMovie);
	return copiedMovie;
}

int CountMoviesByGenre(Movie* movies, int count, Genre findGenre)
{
	int counterMovies = 0;
	for (int i = 0; i < count; i++)
	{
		if (movies[i].Genre == findGenre)
		{
			counterMovies++;
		}
	}
	cout << "Quantity of films found:\t" << counterMovies << endl;
	return counterMovies;
}

void DemoMovieWithGenre()
{
	Movie movie1;
	movie1.Title = "Choco";
	movie1.DurationInMinutes = 210;
	movie1.Genre = Horror;
	movie1.Rating = 8.4;
	movie1.YearOfIssuel = 1997;
	//2.2.9.3
	//TODO: RSDN
	Movie* movie2 = MakeMovie("Witch", 96, 2005, Drama, 3.4);
	delete movie2;
	//2.2.9.4
	cout << endl;
	const int count = 10;
	Movie* movies = new Movie[count];
	for (int i = 0; i < count; i++)
	{
		ReadMovie(movies[i]);
	}
	CountMoviesByGenre(movies, count, ReadGenre());
	delete[] movies;
	//2.2.9.5
	FindBestGenreMovie(movies, count, ReadGenre());
}

Movie* FindBestGenreMovie(Movie* movies, int count, Genre findGenre)
{
	if (findGenre)
	{
		Movie* findBestGenre = &movies[0];
		for (int i = 0; i < count; i++)
		{
			if (movies[i].Genre == findGenre)
			{
				if (findBestGenre->Rating < movies[i].Rating)
				{
					findBestGenre = &movies[i];
				}
			}
		}
		return findBestGenre;
	}
	else
	{
		return nullptr;
	}
}