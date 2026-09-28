#include "ScreenManager.h"

#include "Color.h"
#include "Vector2.h"

#include "Obstacle.h"
#include "Player.h"
#include "Ball.h"
#include "Button.h"

#include "Sprite.h"

#include "ScreenMenu.h"
#include "ScreenGame.h"
#include "ScreenCredits.h"

#include <sl.h>
#include <ctime>
#include <cstdlib>


void Init(Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton, Player& player, Ball& ball, Obstacle obstacles[ROWS][COLUMNS], int& activeObstacles, bool& isGameOver, int& fontHUD, Sprite& background);

void Update(ScreenOptions& currentOption, Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton, Player& player, Ball& ball, Obstacle obstacles[ROWS][COLUMNS], double deltaTime, bool& isGameOver, GameMode currentMode, int& activeObstacles);

void Draw(ScreenOptions currentOption, Button playButton, Button settingsButton, Button rulesButton, Button creditsButton, Button exitButton, Button backButton, Button gameModeButton, Player player, Ball ball, Obstacle obstacles[ROWS][COLUMNS], int fontHUD, Sprite background);


void Init(Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton, Player& player, Ball& ball, Obstacle obstacles[ROWS][COLUMNS], int& activeObstacles, bool& isGameOver, int& fontHUD, Sprite& background)
{
	slWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mine-Smash", false);

	srand(time(NULL));

	int font = slLoadFont("../res/Font/KiwiSoda.ttf");

	const double fontSize = 32;

	const double NORMALIZE = 0.2;

	const double SPACE_BETWEEN_BUTTONS = 10;

	Sprite defaultButton;
	defaultButton.texture2d = slLoadTexture("../res/Buttons/Dbutton.png");
	defaultButton.size.x = BUTTON_WIDTH;
	defaultButton.size.y = BUTTON_HEIGHT;
	defaultButton.position.x = 0;
	defaultButton.position.y = 0;
	defaultButton.tint = WHITE;

	Sprite selectButton;
	selectButton.texture2d = slLoadTexture("../res/Buttons/Sbutton.png");
	selectButton.size.x = BUTTON_WIDTH;
	selectButton.size.y = BUTTON_HEIGHT;
	selectButton.position.x = 0;
	selectButton.position.y = 0;
	selectButton.tint = WHITE;

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
	defaultButton.position.x = buttonPosition.x;
	defaultButton.position.y = buttonPosition.y;
	selectButton.position.x = buttonPosition.x;
	selectButton.position.y = buttonPosition.y;
	ButtonInit(playButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition, defaultButton, selectButton);

	//Init a settingsButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (0 * buttonHitbox.height) - (0 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Settings", textPosition, WHITE);
	defaultButton.position.x = buttonPosition.x;
	defaultButton.position.y = buttonPosition.y;
	selectButton.position.x = buttonPosition.x;
	selectButton.position.y = buttonPosition.y;
	ButtonInit(settingsButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition, defaultButton, selectButton);

	//Init a rulesButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (1 * buttonHitbox.height) - (1 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Rules", textPosition, WHITE);
	defaultButton.position.x = buttonPosition.x;
	defaultButton.position.y = buttonPosition.y;
	selectButton.position.x = buttonPosition.x;
	selectButton.position.y = buttonPosition.y;
	ButtonInit(rulesButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition, defaultButton, selectButton);

	//Init a creditsButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (2 * buttonHitbox.height) - (2 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Credits", textPosition, WHITE);
	defaultButton.position.x = buttonPosition.x;
	defaultButton.position.y = buttonPosition.y;
	selectButton.position.x = buttonPosition.x;
	selectButton.position.y = buttonPosition.y;
	ButtonInit(creditsButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition, defaultButton, selectButton);

	//Init a exitButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (3 * buttonHitbox.height) - (3 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Exit", textPosition, WHITE);
	defaultButton.position.x = buttonPosition.x;
	defaultButton.position.y = buttonPosition.y;
	selectButton.position.x = buttonPosition.x;
	selectButton.position.y = buttonPosition.y;
	ButtonInit(exitButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition, defaultButton, selectButton);

	//Init a backButton
	buttonPosition.x = SCREEN_WIDTH / 2;
	buttonPosition.y = (SCREEN_HEIGHT / 2) - (3 * buttonHitbox.height) - (3 * SPACE_BETWEEN_BUTTONS);
	textPosition.x = buttonPosition.x;
	textPosition.y = buttonPosition.y - (fontSize * NORMALIZE);
	TextInit(currentText, font, fontSize, "Back", textPosition, WHITE);
	defaultButton.position.x = buttonPosition.x;
	defaultButton.position.y = buttonPosition.y;
	selectButton.position.x = buttonPosition.x;
	selectButton.position.y = buttonPosition.y;
	ButtonInit(backButton, ORANGE, BROWN, buttonHitbox, currentText, buttonPosition, defaultButton, selectButton);

	/*
	SetTextPos(backButton.text, backButton.hitbox.x + OFFSET_TEXT_BACK_BUTTON_X, backButton.hitbox.y + OFFSET_TEXT_BACK_BUTTON_Y);

	ButtonInit(gameModeButton, BUTTON_WIDTH, BUTTON_HEIGHT, BLUE, DARKBLUE, CREDITS_TEXT_SIZE, RAYWHITE, " P1 vs P2 ", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + BUTTON_HEIGHT * 2 - OFFSET_MODE_BUTTON_Y);

	SetTextPos(gameModeButton.text, gameModeButton.hitbox.x + OFFSET_TEXT_MODE_BUTTON_X, gameModeButton.hitbox.y + OFFSET_TEXT_MODE_BUTTON_Y);
	*/

	GameInit(player, ball, obstacles, SCREEN_WIDTH, isGameOver, activeObstacles);

	//InitializePlayer(player, SCREEN_WIDTH);

	//Vector2 ballPosition = player.hitbox.center;
	//ballPosition.y += (player.hitbox.height * 2);

	//InitializeBall(ball, ballPosition);

	////InitializeObstacles(obstacles);

	//InitializeObstacles(obstacles, SCREEN_WIDTH);

	fontHUD = font;

	background.texture2d = slLoadTexture("../res/Background/Background.png");
	background.position.x = SCREEN_WIDTH / 2;
	background.position.y = SCREEN_HEIGHT / 2;
	background.size.x = SCREEN_WIDTH;
	background.size.y = SCREEN_HEIGHT;
	background.tint = WHITE;
}

void Update(ScreenOptions& currentOption, Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Button& backButton, Button& gameModeButton, Player& player, Ball& ball, Obstacle obstacles[ROWS][COLUMNS], double deltaTime, bool& isGameOver, GameMode currentMode, int& activeObstacles)
{
	switch (currentOption)
	{
	case ScreenOptions::Menu:
		UpdateMenu(playButton, settingsButton, rulesButton, creditsButton, exitButton);
		if (playButton.isPressed)
		{
			GameInit(player, ball, obstacles, SCREEN_WIDTH, isGameOver, activeObstacles);
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
		PlayGame(player, obstacles, ball, deltaTime, SCREEN_WIDTH, SCREEN_HEIGHT, isGameOver, currentMode, activeObstacles);
		if (isGameOver)
		{
			currentOption = ScreenOptions::Menu; //Cambiar a gameOver
		}
		else if (activeObstacles <= 0)
		{
			currentOption = ScreenOptions::Menu; //Cambiar a win
		}
		/*else if (IsKeyDown(KEY_P))
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
	case ScreenOptions::EndGame:
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

void Draw(ScreenOptions currentOption, Button playButton, Button settingsButton, Button rulesButton, Button creditsButton, Button exitButton, Button backButton, Button gameModeButton, Player player, Ball ball, Obstacle obstacles[ROWS][COLUMNS], int fontHUD, Sprite background)
{

	float hudPlayer1X = 0;
	float hudPlayer1Y = 0;
	float hudPlayer2X = 0;
	float hudPlayer2Y = 0;

	slSetBackColor(BLACK.red, BLACK.green, BLACK.blue);
	switch (currentOption)
	{
	case ScreenOptions::Menu:
		DrawMenu(playButton, settingsButton, rulesButton, creditsButton, exitButton, SCREEN_WIDTH, SCREEN_HEIGHT, fontHUD, background);
		break;
	case ScreenOptions::Play:
		DrawGameFrame(player, obstacles, ball, hudPlayer1X, hudPlayer1Y, hudPlayer2X, hudPlayer2Y, SCREEN_WIDTH, SCREEN_HEIGHT, fontHUD, background);
		break;
	case ScreenOptions::Settings:
		//DrawSettings(backButton, gameModeButton, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	case ScreenOptions::Rules:
		//DrawRules(backButton, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	case ScreenOptions::Credits:
		DrawCredits(backButton, SCREEN_WIDTH, SCREEN_HEIGHT, fontHUD, background);
		break;
	case ScreenOptions::Pause:

		break;
	case ScreenOptions::EndGame:
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
	GameMode currentMode = GameMode::Unlimited;

	//Variables para sonido
	bool musicOn = true;
	bool soundsOn = true;

	//Variables de juego
	Player player;

	Obstacle obstacles[ROWS][COLUMNS] = {};
	int activeObstacles = ROWS * COLUMNS;

	Ball ball;
	
	//Variables para el HUD
	int fontHUD = 0;
	Sprite background;

	//Constantes para el HUD
	//const int HUD_PLAYER_1_X = SCREEN_WIDTH / 4;
	//const int HUD_PLAYER_1_Y = 12;
	//const int HUD_PLAYER_2_X = ((SCREEN_WIDTH / 4) * 3) - 50;
	//const int HUD_PLAYER_2_Y = 12;

	double deltaTime = 0;

	//Inicialización
	Init(playButton, settingsButton, rulesButton, creditsButton, exitButton, backButton, gameModeButton, player, ball, obstacles, activeObstacles, isGameOver, fontHUD, background);

	//Loop
	while (!slShouldClose() && currentOption != ScreenOptions::Exit && !slGetKey(SL_KEY_ESCAPE))
	{
		deltaTime = slGetDeltaTime();

		//Update (actualizacion)
		Update(currentOption, playButton, settingsButton, rulesButton, creditsButton, exitButton, backButton, gameModeButton, player, ball, obstacles, deltaTime, isGameOver, currentMode, activeObstacles);

		//Draw (dibujado)
		Draw(currentOption, playButton, settingsButton, rulesButton, creditsButton, exitButton, backButton, gameModeButton, player, ball, obstacles, fontHUD, background);
	}

	//Cierre
	slClose();
}