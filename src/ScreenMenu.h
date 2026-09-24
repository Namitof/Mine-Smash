#pragma once

#include "Button.h"

void UpdateMenu(Button& playButton, Button& settingsButton, Button& rulesButton, Button& creditsButton, Button& exitButton);

void DrawLogo(int screenWidht, int screenHeight);

void DrawMenu(Button playButton, Button settingsButton, Button rulesButton, Button creditsButton, Button exitButton, int screenWidht, int screenHeight);