#include "ScreenRules.h"
#include "Button.h"
#include "Vector2.h"
#include <sl.h>

void UpdateRules(Button& backButton)
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

void DrawRules(Button backButton, int screenWidth, int screenHeight, int fontHUD, Sprite background)
{
	const int FONT_SIZE = 30;
	const int TITLE_FONT_SIZE = 50;

	const int OFFSET_Y = 30;

	const int PARTS_OF_THE_HEIGHT_OF_THE_SCREEN = (screenHeight / 10);

	DrawSprite(background);

	Text rules;
	rules.font = fontHUD;
	rules.fontSize = TITLE_FONT_SIZE;
	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 9;
	rules.tint = ORANGE;
	rules.text = " Rules ";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.fontSize = FONT_SIZE;

	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 9 - OFFSET_Y;
	rules.tint = WHITE;
	rules.text = "- The player controls a minecart and must destroy ";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 9 - (OFFSET_Y * 2);
	rules.tint = WHITE;
	rules.text = " minerals by hitting them with the ball. ";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 8 - OFFSET_Y;
	rules.tint = WHITE;
	rules.text = "- When the ball hits the minecart ";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 8 - (OFFSET_Y * 2);
	rules.tint = WHITE;
	rules.text = " it bounces off in a new direction.";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 7 - OFFSET_Y;
	rules.tint = WHITE;
	rules.text = "- The angle of the bounce depends on";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 7 - (OFFSET_Y * 2);
	rules.tint = WHITE;
	rules.text = " which part of the cart the ball hits. ";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 6 - OFFSET_Y;
	rules.tint = WHITE;
	rules.text = "- If the player fails to hit the ball, they lose a life.";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.fontSize = TITLE_FONT_SIZE;
	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 5 - OFFSET_Y;
	rules.tint = ORANGE;
	rules.text = "Game Modes";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.fontSize = FONT_SIZE;
	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 5 - (OFFSET_Y * 2);
	rules.tint = WHITE;
	rules.text = "- Normal: You win the game by destroying all the blocks.";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 5 - (OFFSET_Y * 3);
	rules.tint = WHITE;
	rules.text = "- Unlimited: The game has no limits once ";

	DrawText(rules, SL_ALIGN_CENTER);

	rules.position.x = screenWidth / 2;
	rules.position.y = PARTS_OF_THE_HEIGHT_OF_THE_SCREEN * 5 - (OFFSET_Y * 4);
	rules.tint = WHITE;
	rules.text = " you destroy all the blocks, they regenerate. ";

	DrawText(rules, SL_ALIGN_CENTER);

	DrawButton(backButton);
}