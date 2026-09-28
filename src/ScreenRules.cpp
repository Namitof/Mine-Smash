#include "ScreenRules.h"
#include "Button.h"
#include "Vector2.h"

#include <sl.h>

void UpdateRules(Button& backButton)
{
	Vector2 mousePosition;
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	IsMouseOnButton(backButton, mousePosition);

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && backButton.isMouseOnButton)
	{
		backButton.isPressed = true;
	}
	else
	{
		backButton.isPressed = false;
	}
}

void DrawRules(Button backButton, int screenWidth, int screenHeight, int fontHUD, Sprite background)
{
	const int FONT_SIZE = 20;
	const int TITLE_FONT_SIZE = 50;

	const int OFFSET_TITLE_X = 80;

	const int OFFSET_TEXT_X = 20;


	DrawSprite(background);

	Text credits;
	credits.font = fontHUD;
	credits.fontSize = 20;
	credits.position.x = screenWidth / 2;
	credits.position.y = (screenHeight / 10) * 6 + 20;
	credits.tint = WHITE;
	credits.text = "Creado por:";

	DrawText(credits, SL_ALIGN_CENTER);


	credits.position.x = screenWidth / 2;
	credits.position.y = (screenHeight / 10) * 6 + 0;
	credits.tint = WHITE;
	credits.text = "Suarez Nahuel";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidth / 2;
	credits.position.y = (screenHeight / 10) * 5 + 40;
	credits.tint = WHITE;
	credits.text = "Profesores:";

	DrawText(credits, SL_ALIGN_CENTER);


	credits.position.x = screenWidth / 2;
	credits.position.y = (screenHeight / 10) * 5 + 20;
	credits.tint = WHITE;
	credits.text = "Stefano Juan Cvitanich";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidth / 2;
	credits.position.y = (screenHeight / 10) * 5 + 0;
	credits.tint = WHITE;
	credits.text = "Sergio Baretto";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidth / 2;
	credits.position.y = (screenHeight / 10) * 4 + 40;
	credits.tint = WHITE;
	credits.text = "Agradecimientos especiales:";

	DrawText(credits, SL_ALIGN_CENTER);


	credits.position.x = screenWidth / 2;
	credits.position.y = (screenHeight / 10) * 4 + 20;
	credits.tint = WHITE;
	credits.text = "Lucio Stefano Piccioni";

	DrawText(credits, SL_ALIGN_CENTER);

	credits.position.x = screenWidth / 2;
	credits.position.y = (screenHeight / 10) * 4 + 0;
	credits.tint = WHITE;
	credits.text = "Sofia Belen Alvarez Franze";

	DrawText(credits, SL_ALIGN_CENTER);

	/*DrawText("Reglas", screenWidth / 2 - OFFSET_TITLE_X, FONT_SIZE * 3, TITLE_FONT_SIZE, GOLD);
	DrawText("Cada jugador controla una paleta y debe evitar", OFFSET_TEXT_X, FONT_SIZE * 9, FONT_SIZE, WHITE);
	DrawText("que la pelota salga por su lado de la pantalla.", OFFSET_TEXT_X, FONT_SIZE * 10, FONT_SIZE, WHITE);
	DrawText("Cuando la pelota golpea una paleta, rebota en una nueva direccion.", OFFSET_TEXT_X, FONT_SIZE * 12, FONT_SIZE, WHITE);
	DrawText("El angulo del rebote depende del impacto con la paleta.", OFFSET_TEXT_X, FONT_SIZE * 14, FONT_SIZE, WHITE);
	DrawText("Si un jugador no logra devolver la pelota, su oponente obtiene un punto.", OFFSET_TEXT_X, FONT_SIZE * 16, FONT_SIZE, WHITE);
	DrawText("Cada 3 puntos obtenidos por un jugador, se consigue un potenciador.", OFFSET_TEXT_X, FONT_SIZE * 18, FONT_SIZE, WHITE);
	DrawText("La partida termina cuando uno de los jugadores alcanza 10 puntos", OFFSET_TEXT_X, FONT_SIZE * 20, FONT_SIZE, WHITE);*/

	DrawButton(backButton);
}