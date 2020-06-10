#pragma once
#include <iostream>
#include "ClassRectangle.h"
#include "ClassRing.h"
#include "CollisionManager.h"

using namespace std;

//TODO: Почему не сделать статическим? (+)
//В задании было сказано создать сервисный не статический класс
//TODO: А у сервисного класса есть какое-то отдельное слово? Тут же вопрос в том - есть ли смысл 
//TODO: создавать экземпляр. Т.к. класс сервисный - нет, значит делаем статическим. (+)
static class GeometricProgram
{
	public:
		static void DemoRing();
		static void DemoRectangleWithPoint();
		static void DemoCollision();
};