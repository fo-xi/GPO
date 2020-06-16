#pragma once
#include <iostream>
#include "ClassRectangle.h"
#include "ClassRing.h"
#include "CollisionManager.h"

using namespace std;

static class GeometricProgram
{
	public:
		static void DemoRing();
		static void DemoRectangleWithPoint();
		static void DemoCollision();
};