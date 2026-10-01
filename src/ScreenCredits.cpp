#include "ScreenCredits.h"
#include "Button.h"
#include "Sprite.h"
#include "Vector2.h"
#include <sl.h>

void UpdateCredits(Button& backButton)
{
	Vector2 mousePosition;
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	IsMouseOnButton(backButton, mousePosition);

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && backButton.isMouseOnButton)
	{
		backButton.isPressed = true;
	}
	else
	{
		backButton.isPressed = false;
	}
}

void DrawCredits(Button backButton, int screenWidht, int screenHeight, int fontHUD, Sprite background)
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
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 9 - OFFSET_Y;
	credits.tint = WHITE;
	credits.text = "Game developed by: Suarez Nahuel";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.fontSize = FONT_SIZE;

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 7 + (OFFSET_Y * 1);
	credits.tint = WHITE;
	credits.text = "Resources:";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 7;
	credits.tint = WHITE;
	credits.text = "\"Top - Down Crystals Pixel Art\" by craftpix.net";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 7 - OFFSET_Y;
	credits.tint = WHITE;
	credits.text = "https://craftpix.net/freebies/top-down-crystals-pixel-art/";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 6 - (OFFSET_Y * 1);
	credits.tint = WHITE;
	credits.text = "Font: \"Kiwi Soda\"by jeti";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 6 - (OFFSET_Y * 2);
	credits.tint = WHITE;
	credits.text = "https://fontenddev.com/fonts/kiwi-soda/";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 5 - (OFFSET_Y * 2);
	credits.tint = WHITE;
	credits.text = "Tools used in development: Aseprite, Photopea, BeepBox";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 5 - (OFFSET_Y * 3);
	credits.tint = WHITE;
	credits.text = "Game developed in Visual Studio 2026";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 5 - (OFFSET_Y * 4);
	credits.tint = WHITE;
	credits.text = "using C++ and the SIGIL library";

	DrawText(credits, SL_ALIGN_CENTER);

	DrawButton(backButton);
}

