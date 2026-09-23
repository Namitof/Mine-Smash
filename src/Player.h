#pragma once
#include "Rectangle.h"
#include "Color.h"

const double DEFAULT_SPEED_PLAYER = 500.0f;

const int PLAYER_WIDTH = 10;
const int PLAYER_HEIGHT = 100;

struct Player
{
	Rectangle hitbox;
	double speed;
	int score;
	Color tint;
};