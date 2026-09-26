#include "ScreenManager.h"

#include "Color.h"
#include "Vector2.h"

#include "Obstacle.h"
#include "Player.h"
#include "Ball.h"
#include "Button.h"

#include "ScreenMenu.h"
#include "ScreenGame.h"

#include <sl.h>
#include <ctime>
#include <cstdlib>


void Init(Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton, Player& player, Ball& ball, Obstacle obstacles[ROWS][COLUMNS]);

void Update(ScreenOptions& currentOption, Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton, Player& player, Ball& ball, Obstacle obstacles[ROWS][COLUMNS], double deltaTime, bool& isGameOver, GameMode currentMode);

void Draw(ScreenOptions currentOption, Button playButton, Button settingsButton, Button rulesButton, Button creditsButton, Button exitButton, Button backButton, Button gameModeButton, Player player, Ball ball, Obstacle obstacles[ROWS][COLUMNS]);


void Init(Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton, Player& player, Ball& ball, Obstacle obstacles[ROWS][COLUMNS])
{
	slWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mine-Smash", false);

	srand(time(NULL));

	int font = slLoadFont("../res/KiwiSoda.ttf");

	const double fontSize = 32;

	const double NORMALIZE = 0.2;

	const double SPACE_BETWEEN_BUTTONS = 10;

	Rectangle buttonHitbox;
	buttonHitbox.width = BUTTON_WIDTH;
	buttonHitbox.height = BUTTON_HEIGHT;
	buttonHitbox.minPosition.x = SCREEN_WIDTH / 2 - (buttonHitbox.width / 2);
	buttonHitbox.minPosition.y = SCREEN_HEIGHT / 2 - (buttonHitbox.height / 2);

	Vector2 buttonPosition;

	Text currentText;

	Vector2 textPosition;

	//Init a playButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (-1 * buttonHitbox.height) - (-1 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Play", textPosition, WHITE);
	ButtonInit(playButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition);

	//Init a settingsButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (0 * buttonHitbox.height) - (0 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Settings", textPosition, WHITE);
	ButtonInit(settingsButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition);

	//Init a rulesButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (1 * buttonHitbox.height) - (1 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Rules", textPosition, WHITE);
	ButtonInit(rulesButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition);

	//Init a creditsButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (2 * buttonHitbox.height) - (2 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Credits", textPosition, WHITE);
	ButtonInit(creditsButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition);

	//Init a exitButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (3 * buttonHitbox.height) - (3 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Exit", textPosition, WHITE);
	ButtonInit(exitButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition);


	/*
	ButtonInit(backButton, BUTTON_WIDTH, BUTTON_HEIGHT, BLUE, DARKBLUE, TEXT_SIZE, RAYWHITE, "Volver", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + BUTTON_HEIGHT * 4 - OFFSET_BACK_BUTTON_Y);
	SetTextPos(backButton.text, backButton.hitbox.x + OFFSET_TEXT_BACK_BUTTON_X, backButton.hitbox.y + OFFSET_TEXT_BACK_BUTTON_Y);

	ButtonInit(gameModeButton, BUTTON_WIDTH, BUTTON_HEIGHT, BLUE, DARKBLUE, CREDITS_TEXT_SIZE, RAYWHITE, " P1 vs P2 ", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + BUTTON_HEIGHT * 2 - OFFSET_MODE_BUTTON_Y);

	SetTextPos(gameModeButton.text, gameModeButton.hitbox.x + OFFSET_TEXT_MODE_BUTTON_X, gameModeButton.hitbox.y + OFFSET_TEXT_MODE_BUTTON_Y);
	*/

	InitializePlayer(player, SCREEN_WIDTH);

	Vector2 ballPosition = player.hitbox.center;
	ballPosition.y += (player.hitbox.height * 2);

	InitializeBall(ball, ballPosition);

	InitializeObstacles(obstacles);

	//InitializeObstacles(obstacles, SCREEN_WIDTH);
}

void Update(ScreenOptions& currentOption, Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton, Player& player, Ball& ball, Obstacle obstacles[ROWS][COLUMNS], double deltaTime, bool& isGameOver, GameMode currentMode)
{
	switch (currentOption)
	{
	case ScreenOptions::Menu:
		UpdateMenu(playButton, settingsButton, rulesButton, creditsButton, exitButton);
		if (playButton.isPressed)
		{
			currentOption = ScreenOptions::Play;
			playButton.isPressed = false;
			/*switch (currentMode)
			{
			case GameMode::Normal:
				SetPlayers(player1, player2, SCREEN_WIDTH, SCREEN_HEIGHT);
				break;
			case GameMode::Unlimited:
				SetPlayers(player1, player2, SCREEN_WIDTH, SCREEN_HEIGHT);
				break;
			default:
				break;
			}
			SetBall(ball, SCREEN_WIDTH, SCREEN_HEIGHT);*/
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
		}
		break;
	case ScreenOptions::Play:
		PlayGame(player, obstacles, ball, deltaTime, SCREEN_WIDTH, SCREEN_HEIGHT, isGameOver, currentMode);
		/*if (isGameOver)
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
			case GameMode::Normal:
				currentMode = GameMode::Unlimited;
				gameModeButton.text.text = " Ilimitado ";
				break;
			case GameMode::Unlimited:
				currentMode = GameMode::Normal;
				gameModeButton.text.text = " Normal ";
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
		/*
		
		*/
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

void Draw(ScreenOptions currentOption, Button playButton, Button settingsButton, Button rulesButton, Button creditsButton, Button exitButton, Button backButton, Button gameModeButton, Player player, Ball ball, Obstacle obstacles[ROWS][COLUMNS])
{

	float hudPlayer1X = 0;
	float hudPlayer1Y = 0;
	float hudPlayer2X = 0;
	float hudPlayer2Y = 0;

	slSetBackColor(BLACK.red, BLACK.green, BLACK.blue);
	switch (currentOption)
	{
	case ScreenOptions::Menu:
		DrawMenu(playButton, settingsButton, rulesButton, creditsButton, exitButton, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	case ScreenOptions::Play:
		DrawGameFrame(player, obstacles, ball, hudPlayer1X, hudPlayer1Y, hudPlayer2X, hudPlayer2Y, SCREEN_WIDTH, SCREEN_HEIGHT);
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
	GameMode currentMode = GameMode::Normal;

	//Variables para sonido
	bool musicOn = true;
	bool soundsOn = true;

	//Variables de juego
	Player player;

	Obstacle obstacles[ROWS][COLUMNS] = {};
	int activeObstacles = ROWS * COLUMNS;

	Ball ball;

	//Constantes para el HUD
	//const int HUD_PLAYER_1_X = SCREEN_WIDTH / 4;
	//const int HUD_PLAYER_1_Y = 12;
	//const int HUD_PLAYER_2_X = ((SCREEN_WIDTH / 4) * 3) - 50;
	//const int HUD_PLAYER_2_Y = 12;

	double deltaTime = 0;

	//Inicialización
	Init(playButton, settingsButton, rulesButton, creditsButton, exitButton, backButton, gameModeButton, player, ball, obstacles);

	//Loop
	while (!slShouldClose() && currentOption != ScreenOptions::Exit && !slGetKey(SL_KEY_ESCAPE))
	{
		deltaTime = slGetDeltaTime();

		//Update (actualizacion)
		Update(currentOption, playButton, settingsButton, rulesButton, creditsButton, exitButton, backButton, gameModeButton, player, ball, obstacles, deltaTime, isGameOver, currentMode);

		//Draw (dibujado)
		Draw(currentOption, playButton, settingsButton, rulesButton, creditsButton, exitButton, backButton, gameModeButton, player, ball, obstacles);
	}

	//Cierre
	slClose();
}