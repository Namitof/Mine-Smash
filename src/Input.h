#pragma once
#include "Player.h"

#include "ScreenManager.h"


#include "Ball.h"

void PlayerInput(Player& player, Ball& ball, double leftLimit, double rightLimit, double deltaTime, bool& inGame);
