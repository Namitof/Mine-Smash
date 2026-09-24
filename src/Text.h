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

void TextInit(Text& currentText, int font, double fontSize, std::string text, Vector2 position, Color tint);

void SetTextPos(Text& currentText, double textPosX, double textPosY);

void DrawText(Text& currentText, int textAlign);