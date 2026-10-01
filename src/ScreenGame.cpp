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

void DrawGameFrame(Player& player, Obstacle obstacles[ROWS][COLUMNS], Ball& ball, float hudPlayer1X, float hudPlayer1Y, float hudPlayer2X, float hudPlayer2Y, int screenWidht, float screenHeight, int fontHUD, Sprite background)
{
	const int HUD_TEXT_SIZE = 40;

	const int HUD_POS_Y = 15;

	const int LIVE_POS_X = 10;
	const int SCORE_POS_X = SCREEN_WIDTH - 10;

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
	lifeHUD.fontSize = HUD_TEXT_SIZE;
	lifeHUD.position.x = LIVE_POS_X;
	lifeHUD.position.y = HUD_POS_Y;
	lifeHUD.tint = WHITE;
	lifeHUD.text = "Lives: " + std::to_string(player.life);

	Text scoreHUD;
	scoreHUD.font = fontHUD;
	scoreHUD.fontSize = HUD_TEXT_SIZE;
	scoreHUD.position.x = SCORE_POS_X;
	scoreHUD.position.y = HUD_POS_Y;
	scoreHUD.tint = WHITE;
	scoreHUD.text = "Score: " + std::to_string(player.score);

	DrawText(lifeHUD, SL_ALIGN_LEFT);
	DrawText(scoreHUD, SL_ALIGN_RIGHT);
}



