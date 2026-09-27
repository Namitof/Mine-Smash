#pragma once

#include "Vector2.h"
#include "Color.h"

struct Sprite
{
	int texture2d;
	Vector2 size;
	Vector2 position;
	Color tint;
};

void SpriteIniti(Sprite& currentSprite, int texture, Vector2 size, Vector2 position, Color tint);

void DrawSprite(Sprite currentSprite);