#include "ScreenEndGame.h"

#include "Button.h"

#include "Sprite.h"
#include "Vector2.h"

#include <sl.h>

void UpdateEndGame(Button& backButton, Button& continueButton)
{
	Vector2 mousePosition;
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	IsMouseOnButton(backButton, mousePosition);

	IsMouseOnButton(continueButton, mousePosition);

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && backButton.isMouseOnButton)
	{
		backButton.isPressed = true;
	}
	else
	{
		backButton.isPressed = false;
	}

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && continueButton.isMouseOnButton)
	{
		continueButton.isPressed = true;
	}
	else
	{
		continueButton.isPressed = false;
	}
}

void DrawEndGame(Button backButton, Button continueButton, int screenWidht, int screenHeight, int fontHUD, int obstaclesActives)
{
	const int FONT_SIZE = 20;

	const int OFFSET_TEXT_ONE_X = 55;

	const int OFFSET_TEXT_TWO_X = 70;
	const int OFFSET_TEXT_TWO_Y = 22;

	const int OFFSET_TEXT_THREE_X = 55;

	const int OFFSET_TEXT_FOUR_X = 115;
	const int OFFSET_TEXT_FOUR_Y = 22;

	const int OFFSET_TEXT_FIVE_X = 70;
	const int OFFSET_TEXT_FIVE_Y = 40;

	const int OFFSET_TEXT_SIX_X = 140;
	const int OFFSET_TEXT_SIX_Y = 22;

	const int OFFSET_TEXT_SEVEN_X = 112;
	const int OFFSET_TEXT_SEVEN_Y = 44;

	const int OFFSET_TEXT_EIGHT_X = 140;
	const int OFFSET_TEXT_EIGHT_Y = 66;

	slSetForeColor(BLACK.red, BLACK.green, BLACK.blue, 0.5);
	slRectangleFill(screenWidht / 2, screenHeight / 2, screenWidht, screenHeight);

	Text credits;
	credits.font = fontHUD;
	credits.fontSize = 20;
	credits.position.x = screenWidht / 2;
	credits.position.y = (screenHeight / 10) * 6 + 20;
	credits.tint = WHITE;
	credits.text = (obstaclesActives <= 0) ? "Win" : "Defeat";

	DrawText(credits, SL_ALIGN_CENTER);

	DrawButton(backButton);

	DrawButton(continueButton);
}

