#pragma once

#include "Vector2.h"
#include "Color.h"

const float DEFAULT_SPEED_BALL = 350.0f;
const float DEFAULT_RADIUS = 10.0f;

const int DEFAULT_NUM_VERTICES = 100;

struct Ball
{
	Vector2 center;
	double radius;
	double speed;
	Vector2 dir;
	double angle;
	int numVertices;
	Color tint; 
	bool isCatch;
};

void ShootBall(Ball& ball);

void InitializeBall(Ball& ball, Vector2 position);

void UpdateBall(Ball& ball, float deltaTime, Vector2 position);

void BallLeft(Ball& ball, double speed, double deltaTime);

void BallRight(Ball& ball, double speed, double deltaTime);

void DrawBall(Ball ball);