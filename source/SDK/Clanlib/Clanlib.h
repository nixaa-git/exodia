#pragma once

#include <iostream>

class CL_Vec2f
{
public:
	CL_Vec2f(float xx, float yy) : x(xx), y(yy) {}

	float x;
	float y;
};

class CL_Vec2i
{
public:
	CL_Vec2i(int xx, int yy) : x(xx), y(yy) {}

	int x;
	int y;
};