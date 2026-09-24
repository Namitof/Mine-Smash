#include "ScreenManager.h"

#include <sl.h>

#include <ctime>

#include <cstdlib>

#include "Color.h"

#include "Obstacle.h"
#include "Player.h"
#include "Ball.h"

#include "Button.h"

#include "ScreenMenu.h"

void Init(Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton);

void Update(ScreenOptions& currentOption, Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton);

void Draw(ScreenOptions currentOption, Button playButton, Button settingsButton, Button rulesButton, Button creditsButton, Button exitButton, Button backButton, Button gameModeButton);


void Init(Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton)
{
	slWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mine-Smash", false);

	srand(time(NULL));

	const int CREDITS_TEXT_SIZE = 38;

	const int OFFSET_PLAYBUTTON_Y = 30;
	const int OFFSET_TEXT_PLAYBUTTON_X = 30;
	const int OFFSET_TEXT_PLAYBUTTON_Y = 8;

	const int OFFSET_SETTINGS_BUTTON_Y = 26;
	const int OFFSET_TEXT_SETTINGS_BUTTON_X = 5;
	const int OFFSET_TEXT_SETTINGS_BUTTON_Y = 8;

	const int OFFSET_RULES_BUTTON_Y = 22;
	const int OFFSET_TEXT_RULES_BUTTON_X = 18;
	const int OFFSET_TEXT_RULES_BUTTON_Y = 8;

	const int OFFSET_CREDITS_BUTTON_Y = 18;
	const int OFFSET_TEXT_CREDITS_BUTTON_X = 5;
	const int OFFSET_TEXT_CREDITS_BUTTON_Y = 8;

	const int OFFSET_EXIT_BUTTON_Y = 14;
	const int OFFSET_TEXT_EXIT_BUTTON_X = 45;
	const int OFFSET_TEXT_EXIT_BUTTON_Y = 8;

	const int OFFSET_BACK_BUTTON_Y = 20;
	const int OFFSET_TEXT_BACK_BUTTON_X = 14;
	const int OFFSET_TEXT_BACK_BUTTON_Y = 8;

	const int OFFSET_MODE_BUTTON_Y = 20;
	const int OFFSET_TEXT_MODE_BUTTON_X = 8;
	const int OFFSET_TEXT_MODE_BUTTON_Y = 15;

	int font = slLoadFont("../res/KiwiSoda.ttf");

	double fontSize = 20;

	Rectangle buttonHitbox;
	buttonHitbox.width = BUTTON_WIDTH;
	buttonHitbox.height = BUTTON_HEIGHT;
	buttonHitbox.minPosition.x = SCREEN_WIDTH / 2 - (buttonHitbox.width / 2);
	buttonHitbox.minPosition.y = SCREEN_HEIGHT / 2 - (buttonHitbox.height / 2);

	Vector2 buttonPosition;
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = SCREEN_HEIGHT / 2;

	Text playText;
	Vector2 textPosition;
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - 2; //Normalizar ese 2 en base a el font size

	TextInit(playText, font, fontSize, "Play", textPosition, WHITE);



	ButtonInit(playButton, ORANGE, BROWN, buttonHitbox, playText, buttonPosition);



	/*
	ButtonInit(playButton, BUTTON_WIDTH, BUTTON_HEIGHT, BLUE, DARKBLUE, TEXT_SIZE, RAYWHITE, "Jugar", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - OFFSET_PLAYBUTTON_Y);
	SetTextPos(playButton.text, playButton.hitbox.x + OFFSET_TEXT_PLAYBUTTON_X, playButton.hitbox.y + OFFSET_TEXT_PLAYBUTTON_Y);

	ButtonInit(settingsButton, BUTTON_WIDTH, BUTTON_HEIGHT, BLUE, DARKBLUE, TEXT_SIZE, RAYWHITE, "Ajustes", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + BUTTON_HEIGHT * 1 - OFFSET_SETTINGS_BUTTON_Y);
	SetTextPos(settingsButton.text, settingsButton.hitbox.x + OFFSET_TEXT_SETTINGS_BUTTON_X, settingsButton.hitbox.y + OFFSET_TEXT_SETTINGS_BUTTON_Y);

	ButtonInit(rulesButton, BUTTON_WIDTH, BUTTON_HEIGHT, BLUE, DARKBLUE, TEXT_SIZE, RAYWHITE, "Reglas", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + BUTTON_HEIGHT * 2 - OFFSET_RULES_BUTTON_Y);
	SetTextPos(rulesButton.text, rulesButton.hitbox.x + OFFSET_TEXT_RULES_BUTTON_X, rulesButton.hitbox.y + OFFSET_TEXT_RULES_BUTTON_Y);

	ButtonInit(creditsButton, BUTTON_WIDTH, BUTTON_HEIGHT, BLUE, DARKBLUE, TEXT_SIZE - 5, RAYWHITE, "Creditos", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + BUTTON_HEIGHT * 3 - OFFSET_CREDITS_BUTTON_Y);
	SetTextPos(creditsButton.text, creditsButton.hitbox.x + OFFSET_TEXT_CREDITS_BUTTON_X, creditsButton.hitbox.y + OFFSET_TEXT_CREDITS_BUTTON_Y);

	ButtonInit(exitButton, BUTTON_WIDTH, BUTTON_HEIGHT, RED, MAROON, TEXT_SIZE, RAYWHITE, "Salir", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + BUTTON_HEIGHT * 4 - OFFSET_EXIT_BUTTON_Y);
	SetTextPos(exitButton.text, exitButton.hitbox.x + OFFSET_TEXT_EXIT_BUTTON_X, exitButton.hitbox.y + OFFSET_TEXT_EXIT_BUTTON_Y);

	ButtonInit(backButton, BUTTON_WIDTH, BUTTON_HEIGHT, BLUE, DARKBLUE, TEXT_SIZE, RAYWHITE, "Volver", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + BUTTON_HEIGHT * 4 - OFFSET_BACK_BUTTON_Y);
	SetTextPos(backButton.text, backButton.hitbox.x + OFFSET_TEXT_BACK_BUTTON_X, backButton.hitbox.y + OFFSET_TEXT_BACK_BUTTON_Y);

	ButtonInit(gameModeButton, BUTTON_WIDTH, BUTTON_HEIGHT, BLUE, DARKBLUE, CREDITS_TEXT_SIZE, RAYWHITE, " P1 vs P2 ", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + BUTTON_HEIGHT * 2 - OFFSET_MODE_BUTTON_Y);

	SetTextPos(gameModeButton.text, gameModeButton.hitbox.x + OFFSET_TEXT_MODE_BUTTON_X, gameModeButton.hitbox.y + OFFSET_TEXT_MODE_BUTTON_Y);

	SetPlayers(player1, player2, SCREEN_WIDTH, SCREEN_HEIGHT);

	SetBall(ball, SCREEN_WIDTH, SCREEN_HEIGHT);
	*/


}

void Update(ScreenOptions& currentOption, Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton)
{
	switch (currentOption)
	{
	case ScreenOptions::Menu:
		UpdateMenu(playButton, settingsButton, rulesButton, creditsButton, exitButton);
		/*if (playButton.isPressed)
		{
			currentOption = ScreenOptions::Play;
			playButton.isPressed = false;
			switch (currentMode)
			{
			case GameMode::P1vsP2:
				SetPlayers(player1, player2, SCREEN_WIDTH, SCREEN_HEIGHT);
				break;
			case GameMode::P1vsCPU:
				SetPlayers(player1, player2, SCREEN_WIDTH, SCREEN_HEIGHT);
				SetPlayerCpu(player2);
				break;
			case GameMode::Unlimited:
				SetPlayers(player1, player2, SCREEN_WIDTH, SCREEN_HEIGHT);
				break;
			default:
				break;
			}
			SetBall(ball, SCREEN_WIDTH, SCREEN_HEIGHT);
		}
		else if (creditsButton.isPressed)
		{
			currentOption = ScreenOptions::Credits;
			creditsButton.isPressed = false;
		}
		else if (exitButton.isPressed)
		{
			currentOption = ScreenOptions::Exit;
			exitButton.isPressed = false;
		}
		else if (rulesButton.isPressed)
		{
			currentOption = ScreenOptions::Rules;
			rulesButton.isPressed = false;
		}
		else if (settingsButton.isPressed)
		{
			currentOption = ScreenOptions::Settings;
			settingsButton.isPressed = false;
		}*/
		break;
	case ScreenOptions::Play:
		/*PlayGame(player1, player2, ball, mid, deltaTime, SCREEN_WIDTH, SCREEN_HEIGHT, isGameOver, currentMode);
		if (isGameOver)
		{
			currentOption = ScreenOptions::Win;
		}
		else if (IsKeyDown(KEY_P))
		{
			currentOption = ScreenOptions::Menu;
		}*/
		break;
	case ScreenOptions::Settings:
		/*UpdateSettings(backButton, gameModeButton);
		if (backButton.isPressed)
		{
			currentOption = ScreenOptions::Menu;
			backButton.isPressed = false;
		}
		else if (gameModeButton.isPressed)
		{
			switch (currentMode)
			{
			case GameMode::P1vsP2:
				currentMode = GameMode::P1vsCPU;
				gameModeButton.text.text = "P1 vs CPU ";
				break;
			case GameMode::P1vsCPU:
				currentMode = GameMode::Unlimited;
				gameModeButton.text.text = " Ilimitado ";
				break;
			case GameMode::Unlimited:
				currentMode = GameMode::P1vsP2;
				gameModeButton.text.text = " P1 vs P2 ";
				break;
			default:
				break;
			}
			gameModeButton.isPressed = false;
		}*/
		break;
	case ScreenOptions::Rules:
		/*UpdateRules(backButton);
		if (backButton.isPressed)
		{
			currentOption = ScreenOptions::Menu;
			backButton.isPressed = false;
		}*/
		break;
	case ScreenOptions::Credits:
		/*UpdateCredits(backButton);
		if (backButton.isPressed)
		{
			currentOption = ScreenOptions::Menu;
			backButton.isPressed = false;
		}*/

		break;
	case ScreenOptions::Pause:
		break;
	case ScreenOptions::Win:
		/*if (IsKeyDown(KEY_ENTER))
		{
			currentOption = ScreenOptions::Menu;
			isGameOver = false;
		}*/
		break;
	default:
		break;
	}
}

void Draw(ScreenOptions currentOption, Button playButton, Button settingsButton, Button rulesButton, Button creditsButton, Button exitButton, Button backButton, Button gameModeButton)
{
	slSetBackColor(BLACK.red, BLACK.green, BLACK.blue);
	switch (currentOption)
	{
	case ScreenOptions::Menu:
		DrawMenu(playButton, settingsButton, rulesButton, creditsButton, exitButton, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	case ScreenOptions::Play:
		//DrawGameFrame(player1, player2, ball, mid, hudPlayer1X, hudPlayer1Y, hudPlayer2X, hudPlayer2Y, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	case ScreenOptions::Settings:
		//DrawSettings(backButton, gameModeButton, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	case ScreenOptions::Rules:
		//DrawRules(backButton, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	case ScreenOptions::Credits:
		//DrawCredits(backButton, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	case ScreenOptions::Pause:
		break;
	case ScreenOptions::Win:
		//DrawGameFrame(player1, player2, ball, mid, hudPlayer1X, hudPlayer1Y, hudPlayer2X, hudPlayer2Y, SCREEN_WIDTH, SCREEN_HEIGHT);
		//DrawPlayerWin(player1, player2, END_SCORE, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	default:
		break;
	}
	slRender();
}

void Run()
{
	//Botones
	Button playButton;
	Button settingsButton;
	Button rulesButton;
	Button creditsButton;
	Button exitButton;
	Button backButton;
	Button gameModeButton;

	//Variable de escena
	ScreenOptions currentOption = ScreenOptions::Menu;

	//Variables para el gameplay
	bool isGameOver = false;
	//GameMode currentMode = GameMode::P1vsP2;

	//Variables de juego
	Player player1;
	Obstacle obstacles[ROWS][COLUMNS] = {};
	Ball ball;

	//Constantes para el HUD
	//const int HUD_PLAYER_1_X = SCREEN_WIDTH / 4;
	//const int HUD_PLAYER_1_Y = 12;
	//const int HUD_PLAYER_2_X = ((SCREEN_WIDTH / 4) * 3) - 50;
	//const int HUD_PLAYER_2_Y = 12;

	double deltaTime = 0;

	//Inicialización
	Init(playButton, settingsButton, rulesButton, creditsButton, exitButton, backButton, gameModeButton);

	//Loop
	while (!slShouldClose() && currentOption != ScreenOptions::Exit && !slGetKey(SL_KEY_ESCAPE))
	{
		deltaTime = slGetDeltaTime();

		//Update (actualizacion)
		Update(currentOption, playButton, settingsButton, rulesButton, creditsButton, exitButton, backButton, gameModeButton);

		//Draw (dibujado)
		Draw(currentOption, playButton, settingsButton, rulesButton, creditsButton, exitButton, backButton, gameModeButton);
		
		/*
		slSetBackColor(BLACK.red, BLACK.green, BLACK.blue);
		slText(100, 100, "HOLA");
		slRender();
		*/
	}

	//Cierre
	slClose();
}