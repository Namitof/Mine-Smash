#include "Text.h"
#include <sl.h>

void TextInit(Text& currentText, int font, double fontSize, std::string text, Vector2 position, Color tint)
{
	currentText.font = font;
	currentText.fontSize = fontSize;
	currentText.text = text;
	currentText.position = position;
	currentText.tint = tint;
}

void SetTextPos(Text& currentText, double textPosX, double textPosY)
{
	currentText.position.x = textPosX;
	currentText.position.y = textPosY;
}

void DrawText(Text& currentText, int textAlign)
{
	slSetFont(currentText.font, currentText.fontSize);
	slSetTextAlign(textAlign);
	slText(currentText.position.x, currentText.position.y, (currentText.text).c_str());
}