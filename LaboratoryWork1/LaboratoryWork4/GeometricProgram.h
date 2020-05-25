#pragma once
#include <iostream>
#include "ClassRectangle.h"
#include "ClassRing.h"
#include "ClassBand.h"
#include "CollisionManager.h"

using namespace std;

class GeometricProgram
{
public:
	void DemoBand();
	void DemoRing();
	void DemoRectangleWithPoint();
	void DemoCollision();
};