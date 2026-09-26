#include "Obstacle.h"

#include "Vector2.h"

#include "Color.h"

#include <sl.h>

void InitializeOneObstacle(Obstacle& currentObstacle, Vector2 position)
{
	currentObstacle.isActive = true;
	currentObstacle.tint = WHITE;

	currentObstacle.hitbox.width = OBSTACLE_WIDTH;
	currentObstacle.hitbox.height = OBSTACLE_HEIGHT;

	currentObstacle.hitbox.minPosition.x = position.x;
	currentObstacle.hitbox.minPosition.y = position.y - currentObstacle.hitbox.height;

	currentObstacle.hitbox.center.x = currentObstacle.hitbox.minPosition.x + (currentObstacle.hitbox.width / 2);
	currentObstacle.hitbox.center.y = currentObstacle.hitbox.minPosition.y + (currentObstacle.hitbox.height / 2);
}

void InitializeObstacles(Obstacle obstacles[ROWS][COLUMNS])
{
	const double INITAL_POS_Y = 600;

	const double VERTICAL_SEPARATION = 10;
	const double HORIZONTAL_SEPARATION = 18.18;

	Vector2 position;
	position.x = HORIZONTAL_SEPARATION;
	position.y = INITAL_POS_Y;

	for (int i = 0; i < ROWS; i++)
	{
		position.x = HORIZONTAL_SEPARATION;

		for (int j = 0; j < COLUMNS; j++)
		{
			InitializeOneObstacle(obstacles[i][j], position);
			position.x += OBSTACLE_WIDTH + HORIZONTAL_SEPARATION;
		}

		position.y -= (OBSTACLE_HEIGHT + VERTICAL_SEPARATION);
	}
}

void InitializeObstacles(Obstacle obstacles[ROWS][COLUMNS], int screenWidth)
{
	const double INITAL_POS_Y = 600;
	
	const double VERTICAL_SEPARATION = 10;

	double HORIZONTAL_SEPARATION = static_cast<double>((screenWidth - (COLUMNS * OBSTACLE_WIDTH)) / (COLUMNS + 1));
	//Hacer lo mismo para la separacion vertical IMPORTANTE NO USAR TODO EL SCREEN HEIGHT PORQUE LA ZONA JUGABLE DEBERIA SER MITAD DE PANTALLA O 3 CUARTOS

	Vector2 position;
	position.x = HORIZONTAL_SEPARATION;
	position.y = INITAL_POS_Y;

	for (int i = 0; i < ROWS; i++)
	{
		position.x = HORIZONTAL_SEPARATION;

		for (int j = 0; j < COLUMNS; j++)
		{
			InitializeOneObstacle(obstacles[i][j], position);
			position.x += OBSTACLE_WIDTH + HORIZONTAL_SEPARATION;
		}

		position.y -= (OBSTACLE_HEIGHT + VERTICAL_SEPARATION);
	}
}

void DrawOneObstacle(Obstacle currentObstacle)
{
	slSetForeColor(currentObstacle.tint.red, currentObstacle.tint.green, currentObstacle.tint.blue, 1.0);
	slRectangleFill(currentObstacle.hitbox.center.x, currentObstacle.hitbox.center.y, currentObstacle.hitbox.width, currentObstacle.hitbox.height);
}

void DrawObstacles(Obstacle obstacles[ROWS][COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (obstacles[i][j].isActive)
			{
				DrawOneObstacle(obstacles[i][j]);
			}
		}
	}
}