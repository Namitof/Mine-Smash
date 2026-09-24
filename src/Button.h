#pragma once

#include "Text.h"
#include "Color.h"
#include "Rectangle.h"

const double BUTTON_WIDTH = 200;
const double BUTTON_HEIGHT = 60;

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

void ButtonInit(Button& currentButton, Color buttonColor, Color selectColor, Rectangle hitbox, Text text, Vector2 position);

void IsMouseOnButton(Button& currentButton, Vector2 mousePosition);

void DrawButton(Button currentButton);