#include "ScreenEndGame.h"
#include "Button.h"
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
	const int FONT_SIZE = 50;

	const int ENDGAME_OFFSET_Y = 20;

	const double ALPHA_BACKGROUND_VALUE = 0.5;

	slSetForeColor(BLACK.red, BLACK.green, BLACK.blue, ALPHA_BACKGROUND_VALUE);
	slRectangleFill(screenWidht / 2, screenHeight / 2, screenWidht, screenHeight);

	const Color RED = { 0.749, 0, 0 };
	const Color YELLOW = { 1, 0.937, 0};

	Text endGame;
	endGame.font = fontHUD;
	endGame.fontSize = FONT_SIZE;
	endGame.position.x = screenWidht / 2;
	endGame.position.y = (screenHeight / 10) * 6 + ENDGAME_OFFSET_Y;
	endGame.tint = (obstaclesActives <= 0) ? YELLOW : RED;
	endGame.text = (obstaclesActives <= 0) ? "Win" : "Defeat";

	DrawText(endGame, SL_ALIGN_CENTER);

	DrawButton(backButton);

	DrawButton(continueButton);
}

