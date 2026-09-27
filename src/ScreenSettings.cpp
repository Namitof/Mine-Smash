//#include "ScreenSettings.h"
//#include "Ball.h"
//
//void UpdateSettings(Button& backButton, Button& gameModeButton)
//{
//	Vector2 mousePosition = GetMousePosition();
//
//	IsMouseOnButton(backButton, mousePosition);
//
//	IsMouseOnButton(gameModeButton, mousePosition);
//
//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && backButton.isMouseOnButton)
//	{
//		backButton.isPressed = true;
//	}
//	else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameModeButton.isMouseOnButton)
//	{
//		gameModeButton.isPressed = true;
//	}
//}
//
//void DrawSettings(Button backButton, Button gameModeButton, int screenWidht, int screenHeight)
//{
//	const int FONT_SIZE = 35;
//	const int FONT_SIZE_TITLE = 50;
//	const int FONT_SIZE_GAMEMODE = 40;
//
//	const int OFFSET_TITLE_X = 250;
//	const int OFFSET_TITLE_Y = 50;
//
//	const int OFFSET_PLAYER1_X = 80;
//	const int OFFSET_PLAYER1_Y = 135;
//
//	const int OFFSET_P1_CONTROLS_X = 80;
//	const int OFFSET_P1_CONTROLS_Y = 170;
//
//	const int OFFSET_PLAYER2_X = 80;
//	const int OFFSET_PLAYER2_Y = 225;
//
//	const int OFFSET_P2_CONTROLS_X = 80;
//	const int OFFSET_P2_CONTROLS_Y = 260;
//
//	const int OFFSET_GAMEMODE_X = 210;
//	const int OFFSET_GAMEMODE_Y = 20;
//
//	DrawText("Ajustes y controles", screenWidht / 2 - OFFSET_TITLE_X, OFFSET_TITLE_Y, FONT_SIZE_TITLE, WHITE);
//	DrawText("Player 1", screenWidht / 2 - OFFSET_PLAYER1_X, OFFSET_PLAYER1_Y, FONT_SIZE, BLUE);
//	DrawText("'W' / 'S'", screenWidht / 2 - OFFSET_P1_CONTROLS_X, OFFSET_P1_CONTROLS_Y, FONT_SIZE, BLUE);
//	DrawText("Player 2", screenWidht / 2 - OFFSET_PLAYER2_X, OFFSET_PLAYER2_Y, FONT_SIZE, RED);
//	DrawText("Flechas", screenWidht / 2 - OFFSET_P2_CONTROLS_X, OFFSET_P2_CONTROLS_Y, FONT_SIZE, RED);
//
//	DrawText("Modo de juego actual", screenWidht / 2 - OFFSET_GAMEMODE_X, screenHeight / 2 + OFFSET_GAMEMODE_Y, FONT_SIZE_GAMEMODE, WHITE);
//
//	DrawButton(gameModeButton);
//	DrawButton(backButton);
//}