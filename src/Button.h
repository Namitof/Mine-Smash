#pragma once

#include "Text.h"
#include "Color.h"
#include "Rectangle.h"

struct Button
{
	bool isPressed;
	bool isMouseOnButton;
	Color currentColor;
	Color defaultColor;
	Color selectColor;
	Text text;
	Rectangle hitbox;
};