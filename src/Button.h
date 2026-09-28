#pragma once

#include "Text.h"
#include "Color.h"
#include "Rectangle.h"
#include "Sprite.h"

const double BUTTON_WIDTH = 200;
const double BUTTON_HEIGHT = 60;

struct Button
{
	bool isPressed;
	bool wasPressed;
	bool isMouseOnButton;
	Color currentColor;
	Color defaultColor;
	Color selectColor;
	Text text;
	Rectangle hitbox;
	Sprite currentSprite;
	Sprite defaultSprite;
	Sprite selectSprite;
};

void ButtonInit(Button& currentButton, Color buttonColor, Color selectColor, Rectangle hitbox, Text text, Vector2 position, Sprite defaultSprite, Sprite selectSprite);

void IsMouseOnButton(Button& currentButton, Vector2 mousePosition);

void DrawHitboxButton(Button currentButton);

void DrawButton(Button currentButton);