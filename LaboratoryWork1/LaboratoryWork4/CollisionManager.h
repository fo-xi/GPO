#pragma once
#include <iostream>
#include "ClassRectangle.h"
#include "ClassRing.h"

using namespace std;

static class CollisionManager
{
	public:
		static bool IsCollision(Rectangle&, Rectangle&);
		static bool IsCollision(Ring&, Ring&);
};