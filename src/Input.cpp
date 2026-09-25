#include "Input.h"

#include "Player.h"

#include "Ball.h"


#include <sl.h>

void PlayerInput(Player& player, Ball& ball, double leftLimit, double rightLimit, double deltaTime)
{
	if (slGetKey('A') || slGetKey('a'))
	{
		PlayerLeft(player.hitbox, player.speed, leftLimit, deltaTime);
		if (ball.isCatch)
		{
			if (player.hitbox.minPosition.x != leftLimit)
			{
				BallLeft(ball, player.speed, deltaTime);
			}
			else
			{
				ball.center.x = player.hitbox.center.x;
			}
		}
		
	}

	if (slGetKey('D') || slGetKey('d'))
	{
		PlayerRight(player.hitbox, player.speed, rightLimit, deltaTime);
		if (ball.isCatch)
		{
			if ((player.hitbox.minPosition.x + player.hitbox.width) != rightLimit)
			{
				BallRight(ball, player.speed, deltaTime);
			}
			else
			{
				ball.center.x = player.hitbox.center.x;
			}
		}
		
	}

	if (slGetKey('W') || slGetKey('w'))
	{
		ShootBall(ball);
	}
	

	/*
	if (p)
	{

	}
	*/
}