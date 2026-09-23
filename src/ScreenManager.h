#pragma once

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

enum class ScreenOptions
{
	None = 0,
	Menu,
	Play,
	Settings,
	Rules,
	Credits,
	Exit,
	Pause,
	Win
};

void Run();