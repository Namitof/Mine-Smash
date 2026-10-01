#include "Player.h"
#include "Rectangle.h"
#include <sl.h>

void SetPlayerTexture(Player& player, int playerTexture)
{
	player.texture.texture2d = playerTexture;
	player.texture.tint = WHITE;
	player.texture.position.x = player.hitbox.center.x;
	player.texture.position.y = player.hitbox.center.y - OFFSET_PLAYER_TEXTURE_Y;
	player.texture.size.x = PLAYER_TEXTURE_WIDTH;
	player.texture.size.y = PLAYER_TEXTURE_HEIGHT;
}

void UpdatePlayerPosition(Rectangle& player)
{
	player.minPosition.x = player.center.x - (player.width / 2);
	player.minPosition.y = player.center.y - (player.height / 2);
}

void UpdateSpritePosition(Player& player)
{
	player.texture.position.x = player.hitbox.center.x;
	player.texture.position.y = player.hitbox.center.y - OFFSET_PLAYER_TEXTURE_Y;
}

void PlayerLeft(Rectangle& player, double speed, int leftLimit, double deltaTime)
{
	if ((player.center.x - (player.width/2)) > leftLimit)
	{
		player.center.x -= speed * deltaTime;
	}
	else
	{
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
	currentPlayer.hitbox.center.y = POS_Y;

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
	slSetForeColor(currentPlayer.texture.tint.red, currentPlayer.texture.tint.green, currentPlayer.texture.tint.blue, 1.0);
	slSprite(currentPlayer.texture.texture2d, currentPlayer.texture.position.x, currentPlayer.texture.position.y, currentPlayer.texture.size.x, currentPlayer.texture.size.y);

#ifdef _DEBUG
	slSetForeColor(currentPlayer.tint.red, currentPlayer.tint.green, currentPlayer.tint.blue, 1.0);
	slRectangleFill(currentPlayer.hitbox.center.x, currentPlayer.hitbox.center.y, currentPlayer.hitbox.width, currentPlayer.hitbox.height);
#endif
	
}