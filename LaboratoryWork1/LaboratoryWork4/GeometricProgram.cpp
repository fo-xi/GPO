#include <exception>
#include "GeometricProgram.h"

void GeometricProgram::DemoBand()
{
	const int songsCount = 4;
	Song** song1 = new Song * [songsCount];

	string songTitle1 = "Unfunny Clown";
	string songTitle2 = "Cute Clown";
	string songTitle3 = "Beautiful Clown";
	string songTitle4 = "Scary Clown";

	song1[0] = new Song(songTitle1, 200, Blues);
	song1[1] = new Song(songTitle2, 210, Jazz);
	song1[2] = new Song(songTitle3, 203, Rap);
	song1[3] = new Song(songTitle4, 179, Rap);

	Song** song2 = new Song * [songsCount];

	songTitle1 = "Melon";
	songTitle2 = "Peach";
	songTitle3 = "Banana";
	songTitle4 = "Kiwi";

	song2[0] = new Song(songTitle1, 185, Rap);
	song2[1] = new Song(songTitle2, 193, Chanson);
	song2[2] = new Song(songTitle3, 167, Blues);
	song2[3] = new Song(songTitle4, 212, Rock);

	Song** song3 = new Song * [songsCount];

	songTitle1 = "Dewlap";
	songTitle2 = "Heart";
	songTitle3 = "Ear";
	songTitle4 = "Jowls";

	song3[0] = new Song(songTitle1, 197, Rap);
	song3[1] = new Song(songTitle2, 216, Rock);
	song3[2] = new Song(songTitle3, 200, Blues);
	song3[3] = new Song(songTitle4, 230, Rock);

	const int albumsCount = 3;
	Album** album = new Album * [albumsCount];

	string albumTitle = "Clown";
	album[0] = new Album(albumTitle, 2020, songsCount, song1);
	albumTitle = "Funny fruits";
	album[1] = new Album(albumTitle, 2012, songsCount, song2);
	albumTitle = "Cakes";
	album[2] = new Album(albumTitle, 1998, songsCount, song3);

	string bandName = "Peaches";
	string description = "Ben, Rosie, Lily";
	Band* band = new Band(bandName, description, albumsCount, album);

	Song* foundSong = band->FindSong(songTitle2);
	cout << "Title: " << foundSong->GetTitle() << "\t"
		<< "Duration: " << foundSong->GetDuration() << "\t"
		<< "Genre: ";
	WriteGenre(foundSong->GetGenre());
	cout << endl;

	Album* foundAlbum = band->FindAlbum(song2[2]);
	cout << "Album title: " << foundAlbum->GetAlbumTitle() << "\t"
		<< "Year manufacture: " << foundAlbum->GetYearManufacture()
		<< "\n" << endl;

	int allSongsCount = 0;
	Song** allFoundSongs = band->GetAllSongs(allSongsCount);
	cout << "Number of songs ->\t" << allSongsCount << "\n" << endl;
	for (int i = 0; i < allSongsCount; i++)
	{
		WriteSongs(allFoundSongs[i]);
	}

	int allSongsCountInGenre = 0;
	Song** allGenreSongs = band->GetAllGenreSongs(Blues, allSongsCountInGenre);
	cout << "\nNumber of songs in genre ->\t";
	WriteGenre(Blues);
	cout << "\n" << endl;
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

void GeometricProgram::DemoRing()
{
	Ring* ring1 = new Ring(4.47, 1.45, new Point(2.5, 0.45));
	cout << "Количество колец" << ": " << Ring::GetAllRingsCount();
	Ring* ring2 = new Ring(3.69, 0.56, new Point(7.56, 2.43));
	cout << "Количество колец" << ": " << Ring::GetAllRingsCount();
	Ring* ring3 = new Ring(7.65, 6.89, new Point(8.11, 17.71));
	cout << "Количество колец" << ": " << Ring::GetAllRingsCount();

	cout << "Area of the first ring" << " = " << ring1->GetArea() << endl;
	cout << "Area of the second ring" << " = " << ring2->GetArea() << endl;
	cout << "Area of the third ring" << " = " << ring3->GetArea() << endl;

	try
	{
		Ring* ring4 = new Ring(-1.78, -3.89, new Point(32.31, 4.79));
		delete ring4;
	}
	catch (exception exception)
	{
		cout << "Exception catched!" << endl
			<< exception.what() << endl;
	}
	try
	{
		Ring* ring5 = new Ring(2.12, 6.65, new Point(11.11, 5.66));
		delete ring5;
	}
	catch (exception exception)
	{
		cout << "Exception catched!" << endl
			<< exception.what() << endl;
	}

	cout << "Количество колец до вызова конструктора: "
		<< Ring::GetAllRingsCount() << endl;
	Ring* ring6 = new Ring(10.0, 5.0, new Point(25.0, 25.0));
	cout << "Количество колец после вызова конструктора: "
		<< Ring::GetAllRingsCount() << endl;
	delete ring6;
	cout << "Количество колец после вызова деструктора: "
		<< Ring::GetAllRingsCount() << endl;

	delete ring1;
	delete ring2;
	delete ring3;
	cout << "Количество колец после вызова деструктора: "
		<< Ring::GetAllRingsCount() << endl;
}

void GeometricProgram::DemoRectangleWithPoint()
{
	const int countCenters = 5;
	Point* centers[countCenters];
	centers[0] = new Point(2.5, 0.45);
	centers[1] = new Point(43.56, 77.43);
	centers[2] = new Point(11.11, 22.71);
	centers[3] = new Point(90.09, 47.56);
	centers[4] = new Point(1.98, 59.17);

	const int countRectangles = 5;
	Rectangle* rectangles[countRectangles];
	rectangles[0] = new Rectangle(45.47, 7.45, centers[0]);
	rectangles[1] = new Rectangle(17.69, 33.56, centers[1]);
	rectangles[2] = new Rectangle(90.65, 21.89, centers[2]);
	rectangles[3] = new Rectangle(27.12, 3.21, centers[3]);
	rectangles[4] = new Rectangle(15.12, 3.76, centers[4]);

	for (int i = 0; i < countRectangles; i++)
	{
		cout << "X = " << rectangles[i]->GetCenter()->GetX() << ";\t"
			<< "Y = " << rectangles[i]->GetCenter()->GetY() << ";\t"
			<< "Length = " << rectangles[i]->GetLength() << ";\t"
			<< "Width = " << rectangles[i]->GetWidth() << ";\t" << endl;
	}

	double xCenter = 0.0;
	double yCenter = 0.0;
	for (int i = 0; i < countRectangles; i++)
	{
		xCenter += rectangles[i]->GetCenter()->GetX();
		yCenter += rectangles[i]->GetCenter()->GetY();
	}

	xCenter /= countRectangles;
	yCenter /= countRectangles;
	cout << "\nXcenter = " << xCenter
		<< ";\t" << "Ycenter = " << yCenter << "\n" << endl;
	for (int i = 0; i < countCenters; i++)
	{
		delete centers[i];
	}
	for (int i = 0; i < countRectangles; i++)
	{
		delete rectangles[i];
	}
}

void GeometricProgram::DemoCollision()
{
	cout << "Пересекающиеся треугольники: ";
	Rectangle* rectangle1 = new Rectangle(18.47, 20.45, new Point(3.5, 6.45));
	Rectangle* rectangle2 = new Rectangle(5.47, 2.45, new Point(2.5, 0.45));
	if (CollisionManager::IsCollision(rectangle1, rectangle2))
	{
		cout << "true" << endl << endl;
	}
	cout << "Непересекающиеся треульгольники: ";
	Rectangle* rectangle3 = new Rectangle(4.54, 20.45, new Point(7.22, 12.45));
	Rectangle* rectangle4 = new Rectangle(1.54, 19.45, new Point(3.22, 10.45));
	if (!(CollisionManager::IsCollision(rectangle3, rectangle4)))
	{
		cout << "false" << endl << endl;
	}

	cout << "Пересекающиеся кольца: ";
	Ring* ring1 = new Ring(20.45, 18.47, new Point(17.32, 56.45));
	Ring* ring2 = new Ring(2.45, 1.47, new Point(15.32, 50.45));
	if (CollisionManager::IsCollision(ring1, ring2))
	{
		cout << "true" << endl << endl;
	}
	cout << "Непересекающиеся кольца: ";
	Ring* ring3 = new Ring(4.33, 1.87, new Point(20.22, 13.98));
	Ring* ring4 = new Ring(3.33, 2.87, new Point(3.22, 1.98));
	if (!(CollisionManager::IsCollision(ring3, ring4)))
	{
		cout << "false" << endl << endl;
	}
}