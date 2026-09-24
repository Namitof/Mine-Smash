#include "ScreenMenu.h"
#include "Button.h"
#include "Vector2.h"

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

void DrawLogo(int screenWidht, int screenHeight)
{
	/*const int FONT_SIZE = 50;

	const float RECTANGLE_LOGO_HEIGHT = 120.0f;
	const float RECTANGLE_LOGO_WIDTH = 10.0f;

	const int OFFSET_TEXT_ONE_X = 65;

	const int OFFSET_TEXT_TWO_X = 28;
	const int OFFSET_TEXT_TWO_Y = 38;

	const int OFFSET_TEXT_ONE_THREE_X = 65;
	const int OFFSET_TEXT_ONE_THREE_Y = 75;

	Text namePartA;
	namePartA.color = BLUE;
	namePartA.text = "NAMI";
	namePartA.size = FONT_SIZE;
	Text namePartB;
	namePartB.color = RAYWHITE;
	namePartB.text = " - ";
	namePartB.size = FONT_SIZE;
	Text namePartC;
	namePartC.color = RED;
	namePartC.text = "PONG";
	namePartC.size = FONT_SIZE;

	Rectangle leftRectangle;
	leftRectangle.width = RECTANGLE_LOGO_WIDTH;
	leftRectangle.height = RECTANGLE_LOGO_HEIGHT;
	leftRectangle.x = static_cast<float>(screenWidht / 8) * 3;
	leftRectangle.y = static_cast<float>(screenHeight / 8);

	Rectangle rightRectangle;
	rightRectangle.width = RECTANGLE_LOGO_WIDTH;
	rightRectangle.height = RECTANGLE_LOGO_HEIGHT;
	rightRectangle.x = static_cast<float>(screenWidht / 8) * 5 - rightRectangle.width;
	rightRectangle.y = static_cast<float>(screenHeight / 8);

	DrawText(namePartA.text.c_str(), (screenWidht / 2) - OFFSET_TEXT_ONE_X, (screenHeight / 8), namePartA.size, namePartA.color);
	DrawText(namePartB.text.c_str(), (screenWidht / 2) - OFFSET_TEXT_TWO_X, (screenHeight / 8) + OFFSET_TEXT_TWO_Y, namePartB.size, namePartB.color);
	DrawText(namePartC.text.c_str(), (screenWidht / 2) - OFFSET_TEXT_ONE_THREE_X, (screenHeight / 8) + OFFSET_TEXT_ONE_THREE_Y, namePartC.size, namePartC.color);

	DrawRectangleRec(leftRectangle, BLUE);
	DrawRectangleRec(rightRectangle, RED);*/
}

void DrawMenu(Button playButton, Button settingsButton, Button rulesButton, Button creditsButton, Button exitButton, int screenWidht, int screenHeight)
{
	//DrawLogo(screenWidht, screenHeight);
	DrawButton(playButton);

	//DrawButton(rulesButton);
	
	//DrawButton(creditsButton);
	//DrawButton(exitButton);

	//DrawButton(settingsButton);
}
