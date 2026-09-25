#include "ScreenGame.h"

#include "Player.h"
#include "Obstacle.h"
#include "Ball.h"

#include "Input.h"
#include "CollisionManager.h"

#include <sl.h>

bool WasPointScored(int& scorePlayer1, int& scorePlayer2, int& xpP1, int& xpP2, Ball& ball, float leftLimit, float rightLimit);

bool GameIsRunning(int scorePlayer1, int scorePlayer2, int endScore);


bool WasPointScored(int& scorePlayer1, int& scorePlayer2, int& xpP1, int& xpP2, Ball& ball, float leftLimit, float rightLimit)
{
	if (ball.center.x <= leftLimit)
	{
		scorePlayer2++;
		xpP2++;
		return true;
	}
	else if (ball.center.x >= rightLimit)
	{
		scorePlayer1++;
		xpP1++;
		return true;
	}

	return false;

}


//bool isWin()
//{
//
//}
//
//bool isDefeat()
//{
//
//}

bool GameIsRunning(int scorePlayer1, int scorePlayer2, int endScore)
{
	return ((scorePlayer1 >= endScore) || (scorePlayer2 >= endScore));
}

void DrawPlayerWin(Player player, int screenWidth, int screenHeight)
{
	const int FONT_WIN_SIZE = 20;

	/*if (player1.score >= endScore)
	{
		DrawText("Victoria para jugador 1", (screenWidth / 8), (screenHeight / 2) - FONT_WIN_SIZE, FONT_WIN_SIZE, player1.color);
	}
	else if (player2.score >= endScore)
	{
		DrawText("Victoria para jugador 2", (screenWidth / 8), (screenHeight / 2) - FONT_WIN_SIZE, FONT_WIN_SIZE, player2.color);
	}
	DrawText("ENTER para volver al menu", (screenWidth / 8), (screenHeight / 2) + FONT_WIN_SIZE / 2, FONT_WIN_SIZE, ORANGE);*/

}

void DrawGameFrame(Player& player, Obstacle obstacles[ROWS][COLUMNS], Ball& ball, float hudPlayer1X, float hudPlayer1Y, float hudPlayer2X, float hudPlayer2Y, int screenWidht, float screenHeight)
{
	const int HUD_TEXT_SCORE_SIZE = 50;
	const int BACK_TEXT_SIZE = 25;

	const int OFFSET_BACK_TEXT_X = 135;
	const int OFFSET_BACK_TEXT_Y = 30;

	//Dibujar players
	DrawPlayer(player);

	//Dibujar pelota
	DrawBall(ball);

	//Dibujar bloques
	DrawObstacles(obstacles);

	//Dibujar score
	/*DrawText(TextFormat("%02i", player1.score), hudPlayer1X, hudPlayer1Y, HUD_TEXT_SCORE_SIZE, GOLD);
	DrawText(TextFormat("%02i", player2.score), hudPlayer2X, hudPlayer2Y, HUD_TEXT_SCORE_SIZE, GOLD);
	DrawText("'P' para volver al menu", screenWidht / 2 - OFFSET_BACK_TEXT_X, screenHeight - OFFSET_BACK_TEXT_Y, BACK_TEXT_SIZE, GOLD);*/
}

void PlayGame(Player& player, Obstacle obstacles[ROWS][COLUMNS], Ball& ball, double deltaTime, double screenWidth, double screenHeight, bool& isGameOver, GameMode currentMode)
{
	if (!isGameOver)
	{
		//Chequeo de Input
		PlayerInput(player, ball, 0, screenWidth, deltaTime);

		//Actualización
		//CheckCollision(ball, player1.hitbox, player2.hitbox, 0, screenHeight);

		////limite izquiedo y derecho los chequeo en caso de que la pelota llegue sumo puntos y la vuelvo a setear
		//if (WasPointScored(player1.score, player2.score, player1.xp, player2.xp, ball, 0, screenWidth))
		//{
		//	SetBall(ball, screenWidth, screenHeight);
		//	InitializePlayer(player1);
		//	if (currentMode != GameMode::P1vsCPU)
		//	{
		//		InitializePlayer(player2);
		//	}
		//	else
		//	{
		//		SetPlayerCpu(player2);
		//	}
		//	player1.color = BLUE;
		//	player2.color = RED;
		//}

		//EvaluateLevel(player1, ball.speed, ball.color);
		//EvaluateLevel(player2, ball.speed, ball.color);

		UpdateBall(ball, deltaTime, player.hitbox.center);

		/*if (currentMode != GameMode::Unlimited)
		{
			isGameOver = GameIsRunning(player1.score, player2.score, END_SCORE);
		}*/
	}

}

