#include "ScreenSettings.h"
#include "Ball.h"

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
	const int FONT_SIZE = 35;
	const int FONT_SIZE_TITLE = 50;
	const int FONT_SIZE_GAMEMODE = 40;

	const int OFFSET_TITLE_X = 250;
	const int OFFSET_TITLE_Y = 50;

	const int OFFSET_PLAYER1_X = 80;
	const int OFFSET_PLAYER1_Y = 135;

	const int OFFSET_P1_CONTROLS_X = 80;
	const int OFFSET_P1_CONTROLS_Y = 170;

	const int OFFSET_PLAYER2_X = 80;
	const int OFFSET_PLAYER2_Y = 225;

	const int OFFSET_P2_CONTROLS_X = 80;
	const int OFFSET_P2_CONTROLS_Y = 260;

	const int OFFSET_GAMEMODE_X = 210;
	const int OFFSET_GAMEMODE_Y = 20;

	DrawSprite(background);

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

	//DrawText("Ajustes y controles", screenWidht / 2 - OFFSET_TITLE_X, OFFSET_TITLE_Y, FONT_SIZE_TITLE, WHITE);
	//DrawText("Player 1", screenWidht / 2 - OFFSET_PLAYER1_X, OFFSET_PLAYER1_Y, FONT_SIZE, BLUE);
	//DrawText("'W' / 'S'", screenWidht / 2 - OFFSET_P1_CONTROLS_X, OFFSET_P1_CONTROLS_Y, FONT_SIZE, BLUE);
	//DrawText("Player 2", screenWidht / 2 - OFFSET_PLAYER2_X, OFFSET_PLAYER2_Y, FONT_SIZE, RED);
	//DrawText("Flechas", screenWidht / 2 - OFFSET_P2_CONTROLS_X, OFFSET_P2_CONTROLS_Y, FONT_SIZE, RED);

	//DrawText("Modo de juego actual", screenWidht / 2 - OFFSET_GAMEMODE_X, screenHeight / 2 + OFFSET_GAMEMODE_Y, FONT_SIZE_GAMEMODE, WHITE);

	DrawButton(gameModeButton);

	DrawButton(backButton);
}