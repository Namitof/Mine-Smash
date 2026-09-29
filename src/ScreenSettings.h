#pragma once
#include "Button.h"

void UpdateSettings(Button& backButton, Button& gameModeButton, Button& soundsButton, Button& musicButton);

void DrawSettings(Button backButton, Button gameModeButton, Button& soundsButton, Button& musicButton, int screenWidht, int screenHeight, int fontHUD, Sprite background);
