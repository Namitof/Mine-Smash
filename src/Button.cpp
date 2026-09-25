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

	currentButton.hitbox.center.x = position.x;
	currentButton.hitbox.center.y = position.y;

	currentButton.hitbox.minPosition.x = currentButton.hitbox.center.x - (currentButton.hitbox.width / 2);
	currentButton.hitbox.minPosition.y = currentButton.hitbox.center.y - (currentButton.hitbox.height / 2);
}

void IsMouseOnButton(Button& currentButton, Vector2 mousePosition)
{
	double minX = currentButton.hitbox.minPosition.x;
	double minY = currentButton.hitbox.minPosition.y;
	double maxX = currentButton.hitbox.minPosition.x + currentButton.hitbox.width;
	double maxY = currentButton.hitbox.minPosition.y + currentButton.hitbox.height;

	if ((mousePosition.x >= minX && mousePosition.x <= maxX) && (mousePosition.y >= minY && mousePosition.y <= maxY))
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
	slSetForeColor(currentButton.currentColor.red, currentButton.currentColor.green, currentButton.currentColor.blue, 1.0);
	slRectangleFill(currentButton.hitbox.center.x, currentButton.hitbox.center.y, currentButton.hitbox.width, currentButton.hitbox.height);
	slSetForeColor(currentButton.text.tint.red, currentButton.text.tint.green, currentButton.text.tint.blue, 1.0);
	DrawText(currentButton.text, SL_ALIGN_CENTER);
}