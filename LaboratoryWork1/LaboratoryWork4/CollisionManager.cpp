#include <exception>
#include "CollisionManager.h"

bool CollisionManager::IsCollision(Rectangle* rectangle1,
	Rectangle* rectangle2)
{
	double xCoordinatDifference = abs(rectangle1->GetCenter()->GetX() -
		rectangle2->GetCenter()->GetX());
	double yCoordinatDifference = abs(rectangle1->GetCenter()->GetY() -
		rectangle2->GetCenter()->GetY());
	double sumWidths = rectangle1->GetWidth() -
		rectangle2->GetWidth();
	double sumLengths = rectangle1->GetLength() -
		rectangle2->GetLength();
	if (xCoordinatDifference < (sumWidths / 2) &&
		yCoordinatDifference < (sumLengths / 2))
	{
		return true;
	}
	return false;
}

bool CollisionManager::IsCollision(Ring* ring1, Ring* ring2)
{
	double xCoordinatDifference = abs(ring1->GetCenter()->GetX() -
		ring2->GetCenter()->GetX());
	double yCoordinatDifference = abs(ring1->GetCenter()->GetY() -
		ring2->GetCenter()->GetY());
	double hypotenuse = sqrt((pow(xCoordinatDifference, 2) +
		pow(yCoordinatDifference, 2)));
	if (hypotenuse < (ring1->GetOuterRadius() - ring2->GetOuterRadius()))
	{
		return true;
	}
	return false;
}

void DemoCollision()
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