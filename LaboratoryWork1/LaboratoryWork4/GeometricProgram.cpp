#include <exception>
#include "GeometricProgram.h"

void GeometricProgram::DemoRing()
{
	Ring* ring1 = new Ring(4.47, 1.45, 2.5, 0.45);
	cout << "���������� �����" << ": " << Ring::GetAllRingsCount();
	cout << endl;
	Ring* ring2 = new Ring(3.69, 0.56, 7.56, 2.43);
	cout << "���������� �����" << ": " << Ring::GetAllRingsCount();
	cout << endl;
	Ring* ring3 = new Ring(7.65, 6.89, 8.11, 17.71);
	cout << "���������� �����" << ": " << Ring::GetAllRingsCount();
	cout << endl;

	cout << "Area of the first ring" << " = " << ring1->GetArea() << endl;
	cout << "Area of the second ring" << " = " << ring2->GetArea() << endl;
	cout << "Area of the third ring" << " = " << ring3->GetArea() << endl;

	try
	{
		Ring* ring4 = new Ring(-1.78, -3.89, 32.31, 4.79);
		delete ring4;
	}
	catch (exception exception)
	{
		cout << "Exception catched!" << endl
			<< exception.what() << endl;
	}
	try
	{
		Ring* ring5 = new Ring(2.12, 6.65, 11.11, 5.66);
		delete ring5;
	}
	catch (exception exception)
	{
		cout << "Exception catched!" << endl
			<< exception.what() << endl;
	}

	cout << "���������� ����� �� ������ ������������: "
		<< Ring::GetAllRingsCount() << endl;
	Ring* ring6 = new Ring(10.0, 5.0, 25.0, 25.0);
	cout << "���������� ����� ����� ������ ������������: "
		<< Ring::GetAllRingsCount() << endl;
	delete ring6;
	cout << "���������� ����� ����� ������ �����������: "
		<< Ring::GetAllRingsCount() << endl;

	delete ring1;
	delete ring2;
	delete ring3;
	cout << "���������� ����� ����� ������ �����������: "
		<< Ring::GetAllRingsCount() << endl;
}

void GeometricProgram::DemoRectangleWithPoint()
{
	const int countRectangles = 5;
	Rectangle* rectangles[countRectangles];
	rectangles[0] = new Rectangle(45.47, 7.45, 2.5, 0.45);
	rectangles[1] = new Rectangle(17.69, 33.56, 43.56, 77.43);
	rectangles[2] = new Rectangle(90.65, 21.89, 11.11, 22.71);
	rectangles[3] = new Rectangle(27.12, 3.21, 90.09, 47.56);
	rectangles[4] = new Rectangle(15.12, 3.76, 1.98, 59.17);

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
	for (int i = 0; i < countRectangles; i++)
	{
		delete rectangles[i];
	}
}

void GeometricProgram::DemoCollision()
{
	cout << "�������������� ������������: ";
	Rectangle* rectangle1 = new Rectangle(18.47, 20.45, 3.5, 6.45);
	Rectangle* rectangle2 = new Rectangle(5.47, 2.45, 2.5, 0.45);
	if (CollisionManager::IsCollision(*rectangle1, *rectangle2))
	{
		cout << "true" << endl << endl;
	}
	cout << "���������������� ��������������: ";
	Rectangle* rectangle3 = new Rectangle(4.54, 20.45, 7.22, 12.45);
	Rectangle* rectangle4 = new Rectangle(1.54, 19.45, 3.22, 10.45);
	if (!(CollisionManager::IsCollision(*rectangle3, *rectangle4)))
	{
		cout << "false" << endl << endl;
	}

	cout << "�������������� ������: ";
	Ring* ring1 = new Ring(20.45, 18.47, 17.32, 56.45);
	Ring* ring2 = new Ring(2.45, 1.47, 15.32, 50.45);
	if (CollisionManager::IsCollision(*ring1, *ring2))
	{
		cout << "true" << endl << endl;
	}
	cout << "���������������� ������: ";
	Ring* ring3 = new Ring(4.33, 1.87, 20.22, 13.98);
	Ring* ring4 = new Ring(3.33, 2.87, 3.22, 1.98);
	if (!(CollisionManager::IsCollision(*ring3, *ring4)))
	{
		cout << "false" << endl << endl;
	}
	delete rectangle1;
	delete rectangle2;
	delete rectangle3;
	delete rectangle4;
	delete ring1;
	delete ring2;
	delete ring3;
	delete ring4;
}