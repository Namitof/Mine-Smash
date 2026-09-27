//#include "ScreenRules.h"
//
//
//void UpdateRules(Button& backButton)
//{
//	Vector2 mousePosition = GetMousePosition();
//
//	IsMouseOnButton(backButton, mousePosition);
//
//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && backButton.isMouseOnButton)
//	{
//		backButton.isPressed = true;
//	}
//}
//
//void DrawRules(Button backButton, int screenWidth, int screenHeight)
//{
//	const int FONT_SIZE = 20;
//	const int TITLE_FONT_SIZE = 50;
//
//	const int OFFSET_TITLE_X = 80;
//
//	const int OFFSET_TEXT_X = 20;
//
//	DrawText("Reglas", screenWidth / 2 - OFFSET_TITLE_X, FONT_SIZE * 3, TITLE_FONT_SIZE, GOLD);
//	DrawText("Cada jugador controla una paleta y debe evitar", OFFSET_TEXT_X, FONT_SIZE * 9, FONT_SIZE, WHITE);
//	DrawText("que la pelota salga por su lado de la pantalla.", OFFSET_TEXT_X, FONT_SIZE * 10, FONT_SIZE, WHITE);
//	DrawText("Cuando la pelota golpea una paleta, rebota en una nueva direccion.", OFFSET_TEXT_X, FONT_SIZE * 12, FONT_SIZE, WHITE);
//	DrawText("El angulo del rebote depende del impacto con la paleta.", OFFSET_TEXT_X, FONT_SIZE * 14, FONT_SIZE, WHITE);
//	DrawText("Si un jugador no logra devolver la pelota, su oponente obtiene un punto.", OFFSET_TEXT_X, FONT_SIZE * 16, FONT_SIZE, WHITE);
//	DrawText("Cada 3 puntos obtenidos por un jugador, se consigue un potenciador.", OFFSET_TEXT_X, FONT_SIZE * 18, FONT_SIZE, WHITE);
//	DrawText("La partida termina cuando uno de los jugadores alcanza 10 puntos", OFFSET_TEXT_X, FONT_SIZE * 20, FONT_SIZE, WHITE);
//
//	DrawButton(backButton);
//}