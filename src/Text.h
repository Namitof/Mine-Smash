#pragma once
#include <string>

#include "Vector2.h"
#include "Color.h"

struct Text
{
	int font;
	double fontSize;
	std::string text;
	Vector2 position;
	Color tint;
};