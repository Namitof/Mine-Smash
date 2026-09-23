#pragma once

#include "Vector2.h"
#include "Color.h"

const float DEFAULT_SPEED_BALL = 350.0f;
const float DEFAULT_RADIUS = 10.0f;

struct Ball
{
	Vector2 center;
	double radius;
	double speed;
	Vector2 dir;
	double angle;
	int numVertices;
	Color color; 
};