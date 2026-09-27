#pragma once

#include "Rectangle.h"

#include "Obstacle.h"

#include "Ball.h"

void CheckCollision(Ball& ball, Rectangle player, Obstacle obstacles[ROWS][COLUMNS], int& activeObstacles, int& playerScore, double upperLimit, double leftLimit, double rightLimit);


