#include "ScreenMenu.h"
#include "Button.h"
#include "Vector2.h"
#include "Sprite.h"

#include <sl.h>

void UpdateMenu(Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton)
{
	Vector2 mousePosition;
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	IsMouseOnButton(playButton, mousePosition);

	IsMouseOnButton(rulesButton, mousePosition);

	IsMouseOnButton(creditsButton, mousePosition);

	IsMouseOnButton(settingsButton, mousePosition);

	IsMouseOnButton(exitButton, mousePosition);

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && playButton.isMouseOnButton)
	{
		playButton.isPressed = true;
	}
	else if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && creditsButton.isMouseOnButton)
	{
		creditsButton.isPressed = true;
	}
	else if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && exitButton.isMouseOnButton)
	{
		exitButton.isPressed = true;
	}
	else if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && rulesButton.isMouseOnButton)
	{
		rulesButton.isPressed = true;
	}
	else if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && settingsButton.isMouseOnButton)
	{
		settingsButton.isPressed = true;
	}
}

void DrawLogo(int screenWidht, int screenHeight, int fontHUD)
{
	const Color YELLOW_TITLE_A = { 1, 0.796, 0.4 };
	const Color YELLOW_TITLE_B = { 0.878, 0.596, 0.0627 };

	Text titleA;
	titleA.font = fontHUD;
	titleA.fontSize = 80;
	titleA.tint = YELLOW_TITLE_A;
	titleA.position.x = screenWidht / 2;
	titleA.position.y = ((screenHeight / 4) * 3) + 70;
	titleA.text = "MINE";

	Text titleB;
	titleB.font = fontHUD;
	titleB.fontSize = 80;
	titleB.tint = YELLOW_TITLE_B;
	titleB.position.x = screenWidht / 2;
	titleB.position.y = ((screenHeight / 4) * 3) - 10;
	titleB.text = "SMASH";

	DrawText(titleA, SL_ALIGN_CENTER);
	DrawText(titleB, SL_ALIGN_CENTER);
}

void DrawMenu(Button playButton, Button settingsButton, Button rulesButton, Button creditsButton, Button exitButton, int screenWidht, int screenHeight, int fontHUD, Sprite background)
{
	DrawSprite(background);

	DrawLogo(screenWidht, screenHeight, fontHUD);

	DrawButton(playButton);

	DrawButton(settingsButton);

	DrawButton(rulesButton);
	
	DrawButton(creditsButton);

	DrawButton(exitButton);

}
