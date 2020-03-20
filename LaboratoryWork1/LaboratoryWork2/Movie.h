#pragma once
#include <string>
#include "Genre.h"

using namespace std;

struct Movie
{
	string Title;
	int DurationInMinutes;
	int Year;
	Genre Genre;
	double Rating;
};

void WriteMovie(Movie&);
void ReadMovie(Movie&);
void DemoMovie();
Movie* MakeMovie(string&, int, int, Genre, double);
Movie* CopyFlight(Movie&);
void DemoMovieWithGenre();
int CountMoviesByGenre(Movie*, int, Genre);
Movie* FindBestGenreMovie(Movie*, int, Genre);