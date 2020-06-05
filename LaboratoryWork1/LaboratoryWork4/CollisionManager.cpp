#include <exception>
#include "CollisionManager.h"

//TODO: ������ �� ��������? (���������� �� ���������) (+)
bool CollisionManager::IsCollision(Rectangle& rectangle1,
	Rectangle& rectangle2)
{
	double xCoordinatDifference = abs(rectangle1.GetCenter()->GetX() -
		rectangle2.GetCenter()->GetX());
	double yCoordinatDifference = abs(rectangle1.GetCenter()->GetY() -
		rectangle2.GetCenter()->GetY());
	double sumWidths = rectangle1.GetWidth() -
		rectangle2.GetWidth();
	double sumLengths = rectangle1.GetLength() -
		rectangle2.GetLength();
	//TODO: ����� ����� ���������� ������� ��� if-�� (+)
	return (xCoordinatDifference < (sumWidths / 2) &&
		yCoordinatDifference < (sumLengths / 2));
}

//TODO: ������ �� ��������? (���������� �� ���������) (+)
bool CollisionManager::IsCollision(Ring& ring1, Ring& ring2)
{
	double xCoordinatDifference = abs(ring1.GetCenter()->GetX() -
		ring2.GetCenter()->GetX());
	double yCoordinatDifference = abs(ring1.GetCenter()->GetY() -
		ring2.GetCenter()->GetY());
	double hypotenuse = sqrt((pow(xCoordinatDifference, 2) +
		pow(yCoordinatDifference, 2)));
	//TODO: ����� ����� ���������� ������� ��� if-�� (+)
	return (hypotenuse < (ring1.GetOuterRadius() - ring2.GetOuterRadius()));
}