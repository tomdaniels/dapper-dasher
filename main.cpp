#include "raylib.h"

int main()
{
  int windowWidth = 850;
  int windowHeight = 700;
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(windowWidth, windowHeight, "Dapper Dasher");

  int rectWidth = 40;
  int rectHeight = 60;
  int posY = windowHeight - rectHeight;

  int velocity = 0;
  int gravity = 1;

  bool isInAir = false;
  const int jumpVelocity = -20;

  SetTargetFPS(75);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);

    // apply gravity w/ jumping
    if (posY >= windowHeight - rectHeight)
    {
      isInAir = false;
      velocity = 0;
    }
    else
    {
      isInAir = true;
      velocity += gravity;
    }

    if (IsKeyPressed(KEY_SPACE) && !isInAir)
      velocity += jumpVelocity;

    posY += velocity;
    DrawRectangle(windowWidth / 2, posY, rectWidth, rectHeight, BLUE);

    EndDrawing();
  }
  CloseWindow();
}