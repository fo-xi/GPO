#pragma once
#include <iostream>
#include "ClassRectangle.h"
#include "ClassRing.h"
#include "CollisionManager.h"

using namespace std;

//TODO: ѕочему не сделать статической? (+)
//¬ задании было сказано создать сервисный не статический класс
static class GeometricProgram
{
	public:
		void DemoRing();
		void DemoRectangleWithPoint();
		void DemoCollision();
};