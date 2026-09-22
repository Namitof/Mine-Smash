#pragma once

#include "Vector2.h"
#include "Color.h"

struct Sprite
{
	int texture2d;
	Vector2 scale;
	Vector2 position;
	Color tint;
};