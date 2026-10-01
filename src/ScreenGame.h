#pragma once

#include "Player.h"
#include "Obstacle.h"
#include "Ball.h"
#include "Sprite.h"

const int END_SCORE = 10;

enum class GameMode
{
	None = 0,
	Normal,
	Unlimited
};

void GameInit(Player& player, Ball& ball, Obstacle obstacles[ROWS][COLUMNS], int screenWidth, bool& isGameOver, int& activeObstacles);

void PlayGame(Player& player, Obstacle obstacles[ROWS][COLUMNS], Ball& ball, double deltaTime, double screenWidth, double screenHeight, bool& isGameOver, GameMode currentMode, int& activeObstacles, bool& inGame);

void DrawGameFrame(Player& player, Obstacle obstacles[ROWS][COLUMNS], Ball& ball, float hudPlayer1X, float hudPlayer1Y, float hudPlayer2X, float hudPlayer2Y, int screenWidht, float screenHeight, int fontHUD, Sprite background);

