#pragma once
#include "Rectangle.h"
#include "Color.h"

#include "Sprite.h"

const int ROWS = 5; //6
const int COLUMNS = 12;  //8

const int OBSTACLE_WIDTH = 80; //80
const int OBSTACLE_HEIGHT = 80; //80

const int OBSTACLE_WIDTH_HITBOX = 50; //80
const int OBSTACLE_HEIGHT_HITBOX = 50; //80

struct Obstacle
{
	Rectangle hitbox;
	Color tint;
	bool isActive;
	Sprite texture;
};

void InitializeOneObstacle(Obstacle& currentObstacle, Vector2 position);

void InitializeObstacles(Obstacle obstacles[ROWS][COLUMNS], int screenWidth);

void DrawOneObstacle(Obstacle currentObstacle);

void DrawObstacles(Obstacle obstacles[ROWS][COLUMNS]);

void SetObstacleTexture(Obstacle obstacles[ROWS][COLUMNS], int obstacle1, int obstacle2, int obstacle3, int obstacle4);