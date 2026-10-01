#include "Sprite.h"
#include "Vector2.h"
#include "Color.h"
#include <sl.h>

void SpriteIniti(Sprite& currentSprite, int texture, Vector2 size, Vector2 position, Color tint)
{
	currentSprite.texture2d = texture;
	currentSprite.size = size;
	currentSprite.position = position;
	currentSprite.tint = tint;
}

void DrawSprite(Sprite currentSprite)
{
	slSetForeColor(currentSprite.tint.red, currentSprite.tint.green, currentSprite.tint.blue, 1.0);
	slSprite(currentSprite.texture2d, currentSprite.position.x, currentSprite.position.y, currentSprite.size.x, currentSprite.size.y);
}