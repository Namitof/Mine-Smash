#include "Button.h"
#include "Color.h"
#include "Text.h"

#include <sl.h>

void ButtonInit(Button& currentButton, Color buttonColor, Color selectColor, Rectangle hitbox, Text text, Vector2 position)
{
	currentButton.isPressed = false;
	currentButton.isMouseOnButton = false;
	currentButton.currentColor = buttonColor;
	currentButton.defaultColor = buttonColor;
	currentButton.selectColor = selectColor;

	currentButton.hitbox = hitbox;

	currentButton.text = text;

	currentButton.hitbox.x = position.x - currentButton.hitbox.width / 2;
	currentButton.hitbox.y = position.y - currentButton.hitbox.height / 2;
}

void IsMouseOnButton(Button& currentButton, Vector2 mousePosition)
{
	double minX = currentButton.hitbox.x;
	double minY = currentButton.hitbox.y;
	double maxX = currentButton.hitbox.x + currentButton.hitbox.width;
	double maxY = currentButton.hitbox.y + currentButton.hitbox.height;

	if ((mousePosition.x > minX && mousePosition.x < maxX) && (mousePosition.y > minY && mousePosition.y < maxY))
	{
		currentButton.isMouseOnButton = true;
		currentButton.currentColor = currentButton.selectColor;
	}
	else
	{
		currentButton.isMouseOnButton = false;
		currentButton.currentColor = currentButton.defaultColor;
	}
}

void DrawButton(Button currentButton)
{
	slRectangleFill(currentButton.hitbox.x, currentButton.hitbox.y, currentButton.hitbox.width, currentButton.hitbox.height);
	DrawText(currentButton.text, SL_ALIGN_CENTER);
}