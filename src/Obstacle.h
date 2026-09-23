#pragma once
#include "Rectangle.h"
#include "Color.h"

const int ROWS = 10;
const int COLUMNS = 10;

struct Obstacle
{
	Rectangle hitbox;
	Color tint;
};