#include "Player.h"

#include "Rectangle.h"

void PlayerLeft(Rectangle& player, double speed, int leftLimit, double deltaTime)
{
	if (player.x > leftLimit)
	{
		player.x -= speed * deltaTime;
	}
	else
	{
		player.x = leftLimit;
	}
}

void PlayerRight(Rectangle& player, double speed, int rightLimit, double deltaTime)
{
	if (player.x < rightLimit)
	{
		player.x += speed * deltaTime;
	}
	else
	{
		player.x = rightLimit;
	}
}

void InitializePlayer(Player& currentPlayer)
{
	/*
	Rectangle hitbox;
	double speed;
	int score;
	Color tint;
	*/
	currentPlayer.hitbox.width = PLAYER_WIDTH;
	currentPlayer.hitbox.height = PLAYER_HEIGHT;
	currentPlayer.speed = DEFAULT_SPEED_PLAYER;
}

//Setear posiciones de obstaculos y player
void SetPlayersPositions(Player& player1, Player& player2, float screenWidth, float screenHeight)
{
	//Posicion del jugador 1
	player1.hitbox.x = screenWidth / 16;
	player1.hitbox.y = (screenHeight / 2) - (player1.hitbox.height / 2);

	//Posicion del jugador 2
	player2.hitbox.x = screenWidth - player2.hitbox.width - (screenWidth / 16);
	player2.hitbox.y = (screenHeight / 2) - (player2.hitbox.height / 2);

}

void SetPlayers(Player& player1, Player& player2, float screenWidth, float screenHeight)
{
	InitializePlayer(player1);
	player1.score = 0;
	player1.xp = 0;
	player1.level = 0;
	InitializePlayer(player2);
	player2.score = 0;
	player2.xp = 0;
	player2.level = 0;

	player1.color = BLUE;
	player2.color = RED;
	SetPlayersPositions(player1, player2, screenWidth, screenHeight);
}

void SetPlayerCpu(Player& playerCpu)
{
	InitializePlayer(playerCpu);
	playerCpu.speed = DEFAULT_SPEED_CPU;
}

void DrawPlayer(Player currentPlayer)
{
	slSetForeColor(double red, double green, double blue, double alpha);
	slRectangleFill(double x, double y, double width, double height);
	DrawRectangleRec(currentPlayer.hitbox, currentPlayer.color);
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