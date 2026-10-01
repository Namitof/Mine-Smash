#include "ScreenPause.h"
#include "Button.h"
#include "Vector2.h"
#include <sl.h>

void UpdatePause(Button& backButton, Button& continueButton)
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

void DrawPause(Button backButton, Button continueButton,  int screenWidht, int screenHeight, int fontHUD)
{
	const int FONT_SIZE = 50;

	const double ALPHA_BACKGROUND_VALUE = 0.5;
	const int PAUSE_OFFSET_Y = 20;

	slSetForeColor(BLACK.red, BLACK.green, BLACK.blue, ALPHA_BACKGROUND_VALUE);
	slRectangleFill(screenWidht / 2, screenHeight / 2, screenWidht, screenHeight);

	Text pause;
	pause.font = fontHUD;
	pause.fontSize = FONT_SIZE;
	pause.position.x = screenWidht / 2;
	pause.position.y = (screenHeight / 10) * 6 + PAUSE_OFFSET_Y;
	pause.tint = ORANGE;
	pause.text = "- Pause -";

	DrawText(pause, SL_ALIGN_CENTER);

	DrawButton(backButton);

	DrawButton(continueButton);
}

