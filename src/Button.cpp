#include "Button.h"
#include "Color.h"
#include "Text.h"
#include "Sprite.h"

#include <sl.h>

void ButtonInit(Button& currentButton, Color buttonColor, Color selectColor, Rectangle hitbox, Text text, Vector2 position, Sprite defaultSprite, Sprite selectSprite)
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

	currentButton.defaultSprite = defaultSprite;
	currentButton.currentSprite = defaultSprite;
	currentButton.selectSprite = selectSprite;
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
		currentButton.currentSprite = currentButton.selectSprite;
	}
	else
	{
		currentButton.isMouseOnButton = false;
		currentButton.currentColor = currentButton.defaultColor;
		currentButton.currentSprite = currentButton.defaultSprite;

	}
}

void DrawHitboxButton(Button currentButton)
{
	//Hitbox
	slSetForeColor(currentButton.currentColor.red, currentButton.currentColor.green, currentButton.currentColor.blue, 1.0);
	slRectangleFill(currentButton.hitbox.center.x, currentButton.hitbox.center.y, currentButton.hitbox.width, currentButton.hitbox.height);
}

void DrawButton(Button currentButton)
{
	DrawSprite(currentButton.currentSprite);
	slSetForeColor(currentButton.text.tint.red, currentButton.text.tint.green, currentButton.text.tint.blue, 1.0);
	DrawText(currentButton.text, SL_ALIGN_CENTER);
}