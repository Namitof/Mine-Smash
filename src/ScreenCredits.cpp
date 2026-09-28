#include "ScreenCredits.h"
#include "Button.h"
#include "ScreenMenu.h"

#include <sl.h>

void DrawCredits(Button backButton, int screenWidht, int screenHeight, int fontHUD)
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

	DrawLogo(screenWidht, screenHeight, fontHUD);

	Text credits;
	credits.font = 0;
	credits.fontSize = 0;
	credits.position.x = 0;
	credits.position.y = 0;
	/*credits.tint = 0;
	credits.text = 0;*/

	//DrawText(credits, SL_ALIGN_CENTER);

	//DrawText("Creado por:", screenWidht / 2 - OFFSET_TEXT_ONE_X, (screenHeight / 10) * 4, FONT_SIZE, BLUE);
	//DrawText("Suarez Nahuel", screenWidht / 2 - OFFSET_TEXT_TWO_X, (screenHeight / 10) * 4 + OFFSET_TEXT_TWO_Y, FONT_SIZE, WHITE);

	//DrawText("Profesores:", screenWidht / 2 - OFFSET_TEXT_THREE_X, (screenHeight / 10) * 5, FONT_SIZE, BLUE);
	//DrawText("Stefano Juan Cvitanich", screenWidht / 2 - OFFSET_TEXT_FOUR_X, (screenHeight / 10) * 5 + OFFSET_TEXT_FOUR_Y, FONT_SIZE, WHITE);
	//DrawText("Sergio Baretto", screenWidht / 2 - OFFSET_TEXT_FIVE_X, (screenHeight / 10) * 5 + OFFSET_TEXT_FIVE_Y, FONT_SIZE, WHITE);

	//DrawText("Agradecimientos especiales:", screenWidht / 2 - OFFSET_TEXT_SIX_X, (screenHeight / 10) * 6 + OFFSET_TEXT_SIX_Y, FONT_SIZE, RED);
	//DrawText("Lucio Stefano Piccioni", screenWidht / 2 - OFFSET_TEXT_SEVEN_X, (screenHeight / 10) * 6 + OFFSET_TEXT_SEVEN_Y, FONT_SIZE, WHITE);
	//DrawText("Sofia Belen Alvarez Franze", screenWidht / 2 - OFFSET_TEXT_EIGHT_X, (screenHeight / 10) * 6 + OFFSET_TEXT_EIGHT_Y, FONT_SIZE, WHITE);

	//DrawButton(backButton);
}

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
}