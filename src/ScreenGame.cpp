#include "ScreenGame.h"

#include "Player.h"
#include "Obstacle.h"
#include "Ball.h"

#include "Vector2.h"
#include "Text.h"
#include "Color.h"
#include "Sprite.h"

#include "Input.h"
#include "CollisionManager.h"

#include <sl.h>

#include <string>

void WasALifeLost(Player& player, Ball& ball, int downLimit);

void GameInit(Player& player, Ball&	ball, Obstacle obstacles[ROWS][COLUMNS], int screenWidth, bool& isGameOver, int& activeObstacles)
{
	InitializePlayer(player, screenWidth);

	Vector2 ballPosition = player.hitbox.center;
	ballPosition.y += (player.hitbox.height * 2);

	InitializeBall(ball, ballPosition);

	//InitializeObstacles(obstacles);

	isGameOver = false;

	activeObstacles = ROWS * COLUMNS;

	InitializeObstacles(obstacles, screenWidth);
}

void WasALifeLost(Player& player, Ball& ball, int downLimit)
{
	if (ball.center.y <= downLimit)
	{
		Vector2 ballPosition = player.hitbox.center;
		ballPosition.y += (player.hitbox.height * 2);

		InitializeBall(ball, ballPosition);

		UpdatePlayer(player, 0, -1);
	}
}

void DrawGameFrame(Player& player, Obstacle obstacles[ROWS][COLUMNS], Ball& ball, float hudPlayer1X, float hudPlayer1Y, float hudPlayer2X, float hudPlayer2Y, int screenWidht, float screenHeight, int fontHUD, Sprite background)
{
	const int HUD_TEXT_SCORE_SIZE = 50;
	const int BACK_TEXT_SIZE = 25;

	const int OFFSET_BACK_TEXT_X = 135;
	const int OFFSET_BACK_TEXT_Y = 30;

	//Dibujar fondo
	DrawSprite(background);

	//Dibujar bloques
	DrawObstacles(obstacles);

	//Dibujar players
	DrawPlayer(player);

	//Dibujar pelota
	DrawBall(ball);

	//Dibujar score
	Text lifeHUD;
	lifeHUD.font = fontHUD;
	lifeHUD.fontSize = 40;
	lifeHUD.position.x = 10;
	lifeHUD.position.y = 10;
	lifeHUD.tint = WHITE;
	lifeHUD.text = "Lives: " + std::to_string(player.life);

	Text scoreHUD;
	scoreHUD.font = fontHUD;
	scoreHUD.fontSize = 40;
	scoreHUD.position.x = screenWidht;
	scoreHUD.position.y = 10;
	scoreHUD.tint = WHITE;
	scoreHUD.text = "Score: " + std::to_string(player.score);

	DrawText(lifeHUD, SL_ALIGN_LEFT);
	DrawText(scoreHUD, SL_ALIGN_RIGHT);
}

void PlayGame(Player& player, Obstacle obstacles[ROWS][COLUMNS], Ball& ball, double deltaTime, double screenWidth, double screenHeight, bool& isGameOver, GameMode currentMode, int& activeObstacles, bool& inGame)
{
	if (!isGameOver)
	{
		//Chequeo de Input
		PlayerInput(player, ball, 0, screenWidth, deltaTime, inGame);

		UpdateSpritePosition(player);

		//Actualizacion
		CheckCollision(ball, player.hitbox, obstacles, activeObstacles, player.score, screenHeight, 0, screenWidth);

		//Chequeo si se perdio una vida
		WasALifeLost(player, ball, 0);

		UpdateBall(ball, deltaTime, player.hitbox.center);

		if (player.life <= 0)
		{
			isGameOver = true;
		}

		if (activeObstacles <= 0)
		{
			if (currentMode == GameMode::Unlimited)
			{
				//Actualizar mapa
				InitializeObstacles(obstacles, screenWidth);
				activeObstacles = ROWS * COLUMNS;

				Vector2 ballPosition = player.hitbox.center;
				ballPosition.y += (player.hitbox.height * 2);
				InitializeBall(ball, ballPosition);
			}
		}
	}

}

