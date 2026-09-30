#include "ScreenCredits.h"
#include "Button.h"
#include "ScreenMenu.h"

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

	DrawSprite(background);

	DrawLogo(screenWidht, screenHeight, fontHUD);

	Text credits;
	credits.font = fontHUD;
	credits.fontSize = 20;
	credits.position.x = screenWidht / 2;
	credits.position.y = (screenHeight / 10) * 6 + 20;
	credits.tint = WHITE;
	credits.text = "Creado por:";

	DrawText(credits, SL_ALIGN_CENTER);


	credits.position.x = screenWidht / 2;
	credits.position.y = (screenHeight / 10) * 6 + 0;
	credits.tint = WHITE;
	credits.text = "Suarez Nahuel";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = (screenHeight / 10) * 5 + 40;
	credits.tint = WHITE;
	credits.text = "Profesores:";

	DrawText(credits, SL_ALIGN_CENTER);


	credits.position.x = screenWidht / 2;
	credits.position.y = (screenHeight / 10) * 5 + 20;
	credits.tint = WHITE;
	credits.text = "Stefano Juan Cvitanich";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = (screenHeight / 10) * 5 + 0;
	credits.tint = WHITE;
	credits.text = "Sergio Baretto";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = (screenHeight / 10) * 4 + 40;
	credits.tint = WHITE;
	credits.text = "Agradecimientos especiales:";

	DrawText(credits, SL_ALIGN_CENTER);


	credits.position.x = screenWidht / 2;
	credits.position.y = (screenHeight / 10) * 4 + 20;
	credits.tint = WHITE;
	credits.text = "Lucio Stefano Piccioni";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidht / 2;
	credits.position.y = (screenHeight / 10) * 4 + 0;
	credits.tint = WHITE;
	credits.text = "Sofia Belen Alvarez Franze";

	DrawText(credits, SL_ALIGN_CENTER);

	DrawButton(backButton);
}

