#pragma once
#include "Rectangle.h"
#include "Color.h"

const double DEFAULT_SPEED_PLAYER = 500.0f;

const int PLAYER_WIDTH = 100;
const int PLAYER_HEIGHT = 10;

const int INITIAL_LIFE = 3;

struct Player
{
	Rectangle hitbox;
	double speed;
	int score;
	int life;
	Color tint;
};

void UpdatePlayerPosition(Rectangle& player);

void PlayerLeft(Rectangle& player, double speed, int leftLimit, double deltaTime);

void PlayerRight(Rectangle& player, double speed, int rightLimit, double deltaTime);

void InitializePlayer(Player& currentPlayer, int screenWidth);

void UpdatePlayer(Player& currentPlayer, int addScore, int addLife);


void DrawPlayer(Player currentPlayer);