#include "Obstacle.h"

#include "Vector2.h"

#include "Color.h"

#include <sl.h>

void SetObstacleTexture(Obstacle obstacles[ROWS][COLUMNS], int obstacle1, int obstacle2, int obstacle3, int obstacle4)
{
	
	
	for (int i = 0; i < COLUMNS; i++)
	{
		obstacles[0][i].texture.texture2d = obstacle4;
		obstacles[0][i].texture.tint = WHITE;
		obstacles[0][i].texture.size.x = OBSTACLE_WIDTH;
		obstacles[0][i].texture.size.y = OBSTACLE_HEIGHT;
		obstacles[0][i].texture.position.x = obstacles[0][i].hitbox.center.x;
		obstacles[0][i].texture.position.y = obstacles[0][i].hitbox.center.y;
	}

	for (int i = 0; i < COLUMNS; i++)
	{
		obstacles[1][i].texture.texture2d = obstacle3;
		obstacles[1][i].texture.tint = WHITE;
		obstacles[1][i].texture.size.x = OBSTACLE_WIDTH;
		obstacles[1][i].texture.size.y = OBSTACLE_HEIGHT;
		obstacles[1][i].texture.position.x = obstacles[1][i].hitbox.center.x;
		obstacles[1][i].texture.position.y = obstacles[1][i].hitbox.center.y;
	}

	for (int i = 0; i < COLUMNS; i++)
	{
		obstacles[2][i].texture.texture2d = obstacle2;
		obstacles[2][i].texture.tint = WHITE;
		obstacles[2][i].texture.size.x = OBSTACLE_WIDTH;
		obstacles[2][i].texture.size.y = OBSTACLE_HEIGHT;
		obstacles[2][i].texture.position.x = obstacles[2][i].hitbox.center.x;
		obstacles[2][i].texture.position.y = obstacles[2][i].hitbox.center.y;
	}

	for (int i = 0; i < COLUMNS; i++)
	{
		obstacles[3][i].texture.texture2d = obstacle1;
		obstacles[3][i].texture.tint = WHITE;
		obstacles[3][i].texture.size.x = OBSTACLE_WIDTH;
		obstacles[3][i].texture.size.y = OBSTACLE_HEIGHT;
		obstacles[3][i].texture.position.x = obstacles[3][i].hitbox.center.x;
		obstacles[3][i].texture.position.y = obstacles[3][i].hitbox.center.y;
	}

	for (int i = 0; i < COLUMNS; i++)
	{
		obstacles[4][i].texture.texture2d = obstacle1;
		obstacles[4][i].texture.tint = WHITE;
		obstacles[4][i].texture.size.x = OBSTACLE_WIDTH;
		obstacles[4][i].texture.size.y = OBSTACLE_HEIGHT;
		obstacles[4][i].texture.position.x = obstacles[4][i].hitbox.center.x;
		obstacles[4][i].texture.position.y = obstacles[4][i].hitbox.center.y;
	}

	/*for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{

		}
	}*/
}

void InitializeOneObstacle(Obstacle& currentObstacle, Vector2 position)
{
	currentObstacle.isActive = true;
	currentObstacle.tint = WHITE;

	currentObstacle.hitbox.width = OBSTACLE_WIDTH_HITBOX;
	currentObstacle.hitbox.height = OBSTACLE_HEIGHT_HITBOX;

	currentObstacle.hitbox.minPosition.x = position.x;
	currentObstacle.hitbox.minPosition.y = position.y - currentObstacle.hitbox.height;

	currentObstacle.hitbox.center.x = currentObstacle.hitbox.minPosition.x + (currentObstacle.hitbox.width / 2);
	currentObstacle.hitbox.center.y = currentObstacle.hitbox.minPosition.y + (currentObstacle.hitbox.height / 2);
}

void InitializeObstacles(Obstacle obstacles[ROWS][COLUMNS], int screenWidth)
{
	const double INITAL_POS_Y = 580;
	
	const double VERTICAL_SEPARATION = 15;

	double HORIZONTAL_SEPARATION = static_cast<double>((screenWidth - (COLUMNS * OBSTACLE_WIDTH_HITBOX)) / (COLUMNS + 1));
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
			position.x += OBSTACLE_WIDTH_HITBOX + HORIZONTAL_SEPARATION;
		}

		position.y -= (OBSTACLE_HEIGHT_HITBOX + VERTICAL_SEPARATION);
	}
}

void DrawOneObstacle(Obstacle currentObstacle)
{
#ifdef _DEBUG
	slSetForeColor(currentObstacle.tint.red, currentObstacle.tint.green, currentObstacle.tint.blue, 1.0);
	slRectangleFill(currentObstacle.hitbox.center.x, currentObstacle.hitbox.center.y, currentObstacle.hitbox.width, currentObstacle.hitbox.height);
#endif 
	slSetForeColor(currentObstacle.texture.tint.red, currentObstacle.texture.tint.green, currentObstacle.texture.tint.blue, 1.0);
	slSprite(currentObstacle.texture.texture2d, currentObstacle.texture.position.x, currentObstacle.texture.position.y, currentObstacle.texture.size.x, currentObstacle.texture.size.y);
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