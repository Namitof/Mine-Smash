#include "ScreenSettings.h"

#include "Button.h"
#include "Vector2.h"

#include <sl.h>

void UpdateSettings(Button& backButton, Button& gameModeButton)
{
	Vector2 mousePosition;
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	IsMouseOnButton(backButton, mousePosition);

	IsMouseOnButton(gameModeButton, mousePosition);

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && backButton.isMouseOnButton)
	{
		backButton.isPressed = true;
	}
	else
	{
		backButton.isPressed = false;
	}
	
	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && gameModeButton.isMouseOnButton)
	{
		gameModeButton.isPressed = true;
	}
	else
	{
		gameModeButton.isPressed = false;
	}
}

void DrawSettings(Button backButton, Button gameModeButton, int screenWidht, int screenHeight, int fontHUD, Sprite background)
{
	const int FONT_SIZE = 30;
	const int TITLE_FONT_SIZE = 40;

	const int OFFSET_Y = 30;

	const int PARTS_OF_THE_HEIGHT_OF_THE_SCREEN = (screenHeight / 10);

	DrawSprite(background);

	Text credits;
	credits.font = fontHUD;
	credits.fontSize = TITLE_FONT_SIZE;
	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 8 + OFFSET_Y;
	credits.tint = ORANGE;
	credits.text = "Settings";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.fontSize = FONT_SIZE;

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 7 + OFFSET_Y;
	credits.tint = WHITE;
	credits.text = "Move: A / D";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 6 + OFFSET_Y;
	credits.tint = WHITE;
	credits.text = "Shoot Ball: W";

	DrawText(credits, SL_ALIGN_CENTER);


	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 5 + OFFSET_Y;
	credits.tint = WHITE;
	credits.text = "Pause: P";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.fontSize = TITLE_FONT_SIZE;

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 3 + OFFSET_Y;
	credits.tint = ORANGE;
	credits.text = "GAME MODE";

	DrawText(credits, SL_ALIGN_CENTER);

	DrawButton(gameModeButton);

	DrawButton(backButton);
}