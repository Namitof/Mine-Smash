#include "Input.h"
#include "Player.h"
#include <sl.h>

void PlayerInput(Player& player, double leftLimit, double rightLimit, double deltaTime)
{
	if (slGetKey('A') || slGetKey('a'))
	{
		PlayerLeft(player.hitbox, player.speed, leftLimit, deltaTime);
	}

	if (slGetKey('D') || slGetKey('d'))
	{
		PlayerRight(player.hitbox, player.speed, rightLimit, deltaTime);
	}

	/*
	if (w)
	{

	}
	*/

	/*
	if (p)
	{

	}
	*/
}