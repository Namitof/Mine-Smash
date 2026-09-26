#pragma once
#include "Rectangle.h"
#include "Color.h"

const int ROWS = 6; //6
const int COLUMNS = 8;  //8

const int OBSTACLE_WIDTH = 80; //80
const int OBSTACLE_HEIGHT = 80; //80

struct Obstacle
{
	Rectangle hitbox;
	Color tint;
	bool isActive;
};

void InitializeOneObstacle(Obstacle& currentObstacle, Vector2 position);

void InitializeObstacles(Obstacle obstacles[ROWS][COLUMNS]);

void InitializeObstacles(Obstacle obstacles[ROWS][COLUMNS], int screenWidth);


void DrawOneObstacle(Obstacle currentObstacle);

void DrawObstacles(Obstacle obstacles[ROWS][COLUMNS]);