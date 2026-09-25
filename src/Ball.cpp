#include "Ball.h"

#include "Vector2.h"
#include "Color.h"

#include <sl.h>

#include <cmath>

void ShootBall(Ball& ball)
{
	ball.isCatch = false;

	ball.dir.x = 0;
	ball.dir.y = 1;
}

void InitializeBall(Ball& ball, Vector2 position)
{
	ball.center.x = position.x;
	ball.center.y = position.y;

	ball.radius = DEFAULT_RADIUS;

	ball.speed = DEFAULT_SPEED_BALL;

	ball.dir.x = 0;
	ball.dir.y = 0;

	ball.angle = 90;

	ball.numVertices = DEFAULT_NUM_VERTICES;

	ball.tint = WHITE;

	ball.isCatch = true;
}

void UpdateBall(Ball& ball, float deltaTime, Vector2 position)
{
	ball.center.x += (ball.speed * ball.dir.x) * deltaTime;
	ball.center.y += (ball.speed * ball.dir.y) * deltaTime;

	/*if (ball.isCatch)
	{
		ball.center.x += position.x;
		ball.center.y += position.y;
	}
	else
	{
		ball.center.x += (ball.speed * ball.dir.x) * deltaTime;
		ball.center.y += (ball.speed * ball.dir.y) * deltaTime;
	}*/
}

void BallLeft(Ball& ball, double speed, double deltaTime)
{
	ball.center.x -= speed * deltaTime;
}

void BallRight(Ball& ball, double speed, double deltaTime)
{
	ball.center.x += speed * deltaTime;
}

void DrawBall(Ball ball)
{
	//Dibujar pelota
	slSetForeColor(ball.tint.red, ball.tint.green, ball.tint.blue, 1.0);
	slCircleFill(ball.center.x, ball.center.y, ball.radius, ball.numVertices);
}