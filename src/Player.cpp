#include "Player.h"

#include "Rectangle.h"


#include <sl.h>

void UpdatePlayerPosition(Rectangle& player)
{
	player.minPosition.x = player.center.x - (player.width / 2);
	player.minPosition.y = player.center.y - (player.height / 2);
}

void PlayerLeft(Rectangle& player, double speed, int leftLimit, double deltaTime)
{
	if ((player.center.x - (player.width/2)) > leftLimit)
	{
		//player.minPosition.x -= speed * deltaTime;
		player.center.x -= speed * deltaTime;
	}
	else
	{
		//player.minPosition.x = leftLimit;
		player.center.x = leftLimit + (player.width/2);
	}

	UpdatePlayerPosition(player);

}

void PlayerRight(Rectangle& player, double speed, int rightLimit, double deltaTime)
{
	if ((player.center.x + (player.width / 2)) < rightLimit)
	{
		player.center.x += speed * deltaTime;
	}
	else
	{
		player.center.x = rightLimit - (player.width / 2);
	}
	UpdatePlayerPosition(player);
}

void InitializePlayer(Player& currentPlayer, int screenWidth)
{
	currentPlayer.hitbox.center.x = screenWidth / 2;
	currentPlayer.hitbox.center.y = 50;

	currentPlayer.hitbox.width = PLAYER_WIDTH;
	currentPlayer.hitbox.height = PLAYER_HEIGHT;

	UpdatePlayerPosition(currentPlayer.hitbox);

	currentPlayer.speed = DEFAULT_SPEED_PLAYER;

	currentPlayer.tint = WHITE;

	currentPlayer.score = 0;

	currentPlayer.life = INITIAL_LIFE;
}

void UpdatePlayer(Player& currentPlayer, int addScore, int addLife)
{
	currentPlayer.life = (currentPlayer.life <= 0) ? 0 : currentPlayer.life + addLife;

	currentPlayer.score += addScore;
}


void DrawPlayer(Player currentPlayer)
{
	slSetForeColor(currentPlayer.tint.red, currentPlayer.tint.green, currentPlayer.tint.blue, 1.0);
	slRectangleFill(currentPlayer.hitbox.center.x, currentPlayer.hitbox.center.y, currentPlayer.hitbox.width, currentPlayer.hitbox.height);
}

//void EvaluateLevel(Player& currentPlayer, float& ballSpeed, Color& ballColor)
//{
//	int randomEvent = 0;
//
//	Powers currentPower = Powers::None;
//
//	if (currentPlayer.xp >= REQUIRED_XP)
//	{
//		randomEvent = GetRandomValue(static_cast<int>(Powers::SpeedBoost), static_cast<int>(Powers::IncreaseSize));
//
//		currentPower = static_cast<Powers>(randomEvent);
//
//		switch (currentPower)
//		{
//		case Powers::SpeedBoost: //Player mas rapido
//			currentPlayer.color = GOLD;
//			if (currentPlayer.speed < DEFAULT_SPEED_PLAYER * 4)
//			{
//				currentPlayer.speed += 100.0f;
//			}
//			break;
//		case Powers::FastBall: //Pelota mas rapida
//			ballColor = RED;
//			ballSpeed += 150.0f;
//			break;
//		case Powers::IncreaseSize: //Player mas alto
//			currentPlayer.color = PURPLE;
//			if (currentPlayer.hitbox.height < 200.0f)
//			{
//				currentPlayer.hitbox.height += 50.0f;
//			}
//			break;
//		default:
//			break;
//		}
//		currentPlayer.level += 1;
//		currentPlayer.xp = 0;
//	}
//}