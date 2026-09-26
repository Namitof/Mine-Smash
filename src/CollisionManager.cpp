#include "CollisionManager.h"

#include "Ball.h"

#include "Obstacle.h"

#include "Rectangle.h"

#include <cmath>
#include <iostream>

double CalculateAbsoluteValue(double number);

void SeparateBall(Ball& ball, double absDiffX, double absDiffY, double diffX, double diffY);

bool CollisionAABB(Rectangle rectA, double minX, double minY, double maxX, double maxY);

void ApplyNewAngle(Ball& ball, Rectangle currentPlayer, double centerY);


double CalculateAbsoluteValue(double number)
{
	double aux = 0.0f;

	if (number < 0)
	{
		aux = number * (-1);
	}
	else
	{
		aux = number;
	}

	return aux;
}

void SeparateBall(Ball& ball, double absDiffX, double absDiffY, double diffX, double diffY)
{
	if (absDiffX < absDiffY)
	{
		ball.center.x += diffX;
	}
	else
	{
		ball.center.y += diffY;
	}
}

bool CollisionAABB(Rectangle rectA, double minX, double minY, double maxX, double maxY)
{

	/*
		Chequeo de colisiones de rectangulo a rectangulo
		Datos -> Punto de origen (x, y) de rectangulo A
				 {En este caso es el vertice izquierdo}
			  -> Altura (height) de rectangulo A
			  -> Ancho (width) de rectangulo A
			  -> Valor minimo en x del rectangulo B
			  -> Valor minimo en y del rectangulo B
			  -> Valor maximo en x del rectangulo B
			  -> Valor maximo en y del rectangulo B
	*/

	//Chequeo si el rectangulo A esta a la izquierda de B
	bool isAToTheLeftOfB = false;
	if (rectA.minPosition.x + rectA.width < minX)
	{
		isAToTheLeftOfB = true;
	}

	//Chequeo si el rectangulo A esta a la derecha de B
	bool isAToTheRightOfB = false;
	if (rectA.minPosition.x > maxX)
	{
		isAToTheRightOfB = true;
	}

	//Chequeo si el rectangulo A esta encima de B
	bool AisAboveB = false;
	if (rectA.minPosition.y > maxY)
	{
		AisAboveB = true;
	}

	//Chequeo si el rectangulo A esta por debajo de B
	bool AisBelowB = false;
	if (rectA.minPosition.y + rectA.height < minY)
	{
		AisBelowB = true;
	}

	//Si se cumplen todas -> Los rectangulos estan colisionando
	return !(isAToTheRightOfB || isAToTheLeftOfB || AisAboveB || AisBelowB);
}

void ApplyNewAngle(Ball& ball, Rectangle currentPlayer, double leftBorderX)
{
	const double PI = 3.1415;

	const double MIN_ANGLE = 45.0;
	const double MAX_ANGLE = 135.0;

	double impact = ball.center.x - leftBorderX;

	double normalizedImpact = impact / (currentPlayer.width) ;

	if (normalizedImpact <= 0)
	{
		normalizedImpact = 0;
	}
	else if (normalizedImpact >= 1)
	{
		normalizedImpact = 1;
	}

	std::cout << normalizedImpact << std::endl;

	double newAngle = MAX_ANGLE - (normalizedImpact * (MAX_ANGLE - MIN_ANGLE));

	std::cout << newAngle << std::endl;

	//Convertir a radianes
	newAngle *= (PI / 180);

	ball.angle = newAngle;
}

void CheckCollision(Ball& ball, Rectangle player, Obstacle obstacles[ROWS][COLUMNS], double upperLimit, double leftLimit, double rightLimit)
{
	bool inCollision = false;

	double diffX = 0;
	double diffY = 0;

	double minX = ball.center.x - ball.radius;
	double maxX = ball.center.x + ball.radius;
	double minY = ball.center.y - ball.radius;
	double maxY = ball.center.y + ball.radius;

	//Chequeo colision con player
	if (!ball.isCatch)
	{
		inCollision = CollisionAABB(player, minX, minY, maxX, maxY);
	}

	if (inCollision)
	{
		double centerX = player.center.x;
		double centerY = player.center.y;

		ApplyNewAngle(ball, player, player.minPosition.x);
		/*ball.dir.x = sin(ball.angle);
		ball.dir.y = cos(ball.angle);*/
		ball.dir.x = cos(ball.angle);
		ball.dir.y = sin(ball.angle);

		if (maxX < centerX) //golpea de izquieda
		{
			diffX = player.minPosition.x - maxX;
			diffY = player.minPosition.y + player.height - minY;
		}
		else if (minX > centerX) //golpea de derecha
		{
			diffX = player.minPosition.x + player.width - minX;
			diffY = player.minPosition.y + player.height - minY;
		}

		/*if (diffX < 0)
		{
			diffX -= 5;
		}
		else
		{
			diffX += 5;
		}*/

		double absDiffX = CalculateAbsoluteValue(diffX);
		double absDiffY = CalculateAbsoluteValue(diffY);
		SeparateBall(ball, absDiffX, absDiffY, diffX, diffY);
	}
	else if (maxY >= upperLimit) //Borde superior de la pantalla
	{
		ball.center.y -= ball.radius;
		ball.dir.y *= -1;
	}
	else if (minX <= leftLimit) //Borde izquierdo de la pantalla
	{
		ball.center.x += ball.radius;
		ball.dir.x *= -1;
	}
	else if (maxX >= rightLimit) //Borde derecho de la pantalla
	{
		ball.center.x -= ball.radius;
		ball.dir.x *= -1;
	}
	else
	{
		////Chequeo colision con cada obstaculo
		//for (int i = 0; i < ROWS; i++)
		//{
		//	for (int j = 0; j < COLUMNS; j++)
		//	{
		//		if (obstacles[i][j].isActive)
		//		{
		//			inCollision = CollisionAABB(obstacles[i][j].hitbox, minX, minY, maxX, maxY);
		//			if (inCollision)
		//			{
		//				double centerX = obstacles[i][j].hitbox.center.x;
		//				double centerY = obstacles[i][j].hitbox.center.y;

		//				ApplyNewAngle(ball, player, centerX);
		//				ball.dir.x = sin(ball.angle);
		//				ball.dir.y = cos(ball.angle);

		//				if (maxX < centerX) //golpea de izquieda
		//				{
		//					diffX = maxX - obstacles[i][j].hitbox.minPosition.x;
		//					diffY = obstacles[i][j].hitbox.minPosition.y + obstacles[i][j].hitbox.height - minY;
		//				}
		//				else if (minX > centerX) //golpea de derecha
		//				{
		//					diffX = obstacles[i][j].hitbox.minPosition.x + obstacles[i][j].hitbox.width - minX;
		//					diffY = obstacles[i][j].hitbox.minPosition.y + obstacles[i][j].hitbox.height - minY;
		//				}

		//				double absDiffX = CalculateAbsoluteValue(diffX);
		//				double absDiffY = CalculateAbsoluteValue(diffY);
		//				SeparateBall(ball, absDiffX, absDiffY, diffX, diffY);


		//				if (maxY < centerY) //golpea de arriba
		//				{
		//					ball.dir.y *= -1;

		//				}
		//				else if (minY > centerY) //golpea de abajo
		//				{
		//					ball.dir.x *= -1;

		//				}

		//				obstacles[i][j].isActive = false;
		//			}
		//		}
		//	}
		//}
	}

	

	//inCollision = CollisionAABB(player1, minX, minY, maxX, maxY);
	//if (inCollision)
	//{
	//	float centerX = player1.x + (player1.width / 2);
	//	float centerY = player1.y + (player1.height / 2);

	//	ApplyNewAngle(ball, player1, centerY);
	//	ball.dirX = cos(ball.angle);
	//	ball.dirY = sin(ball.angle);

	//	if (maxY < centerY) //golpea de arriba
	//	{
	//		diffX = player1.x + player1.width - minX;
	//		diffY = player1.y - maxY;
	//	}
	//	else if (minY > centerY) //golpea de abajo
	//	{
	//		diffX = player1.x + player1.width - minX;
	//		diffY = player1.y + player1.height - minY;
	//	}

	//	float absDiffX = CalculateAbsoluteValue(diffX);
	//	float absDiffY = CalculateAbsoluteValue(diffY);
	//	SeparateBall(ball, absDiffX, absDiffY, diffX, diffY);

	//}

}