#include <iostream>
#include<raylib.h>
using namespace std;

Color Green = Color{ 38, 185, 154, 255 };
Color Dark_Green = Color{ 20, 160, 133, 255 };
Color Light_Green = Color{ 129, 204, 184, 255 };
Color Yellow = Color{ 243, 213, 91, 255 };

int playerScore = 0;
int cpuScore = 0;

class Ball {
public:
	float x, y;
	int speedX, speedY;
	int radius;
	bool waiting;

	void draw() {
		DrawCircle(x, y, radius, Yellow);
	}
	void update() {
		if (waiting) return;

		x += speedX;
		y += speedY;
		if (y + radius >= GetScreenHeight() || y - radius <= 0) speedY *= -1;

		if (x + radius >= GetScreenWidth()) {
			cpuScore++;
			resetBall();
		}
		if (x - radius <= 0) {
			playerScore++;
			resetBall();
		}
	}
	void resetBall() {
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;

		int speedChoice[2] = { -1,1 };
		speedX = 7 * speedChoice[GetRandomValue(0, 1)];
		speedY = 7 * speedChoice[GetRandomValue(0, 1)];
		waiting = true;
	}
};
class Paddle {
protected:
	void limitMovememt() {
		if (y <= 0) y = 0;;
		if (y + paddleHeight >= GetScreenHeight()) y = GetScreenHeight() - paddleHeight;
	}
public:
	float x, y;
	float paddleWidth, paddleHeight;
	int speed;

	void draw() {
		DrawRectangleRounded(Rectangle{ x,y,paddleWidth,paddleHeight }, 0.8, 0, WHITE);
	}
	void update() {
		if (IsKeyDown(KEY_UP)) {
			y = y - speed;
		}
		if (IsKeyDown(KEY_DOWN)) {
			y = y + speed;
		}
		limitMovememt();
	}
};
class CpuPaddle : public Paddle {
public:
	void update(int ball_y) {
		if (y + paddleHeight / 2 > ball_y) {
			y -= speed;   
		}
		if (y + paddleHeight / 2 < ball_y) {
			y += speed;   
		}
		limitMovememt();
	}
};

Ball ball;
Paddle player;
CpuPaddle cpu;

int main() {
		const int screenWidth = 1280;
		const int screenHeight = 800;
		InitWindow(screenWidth, screenHeight, "Pong Game");
		SetTargetFPS(60);

		//Ball object
		ball.radius = 20;
		ball.x = screenWidth / 2;
		ball.y = screenHeight / 2;
		ball.speedX = 7;
		ball.speedY = 7;
		ball.waiting = true;

		//Player Paddle
		player.paddleWidth = 25;
		player.paddleHeight = 120;
		player.x = screenWidth - player.paddleWidth - 10;
		player.y = screenHeight / 2 - player.paddleHeight / 2;
		player.speed = 6;

		//CPU Paddle
		cpu.paddleWidth = 25;
		cpu.paddleHeight = 120;
		cpu.x = 10;
		cpu.y = screenHeight / 2 - cpu.paddleHeight / 2;
		cpu.speed = 5;

	bool gameOver = false;


	while (!WindowShouldClose()) {
		BeginDrawing();

		if (!gameOver) {
			// Start ball if SPACE pressed after reset
			if (ball.waiting && IsKeyPressed(KEY_SPACE)) {
				ball.waiting = false;
			}

			//Update
			ball.update();
			player.update();
			cpu.update(ball.y);

			if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ player.x,player.y,player.paddleWidth, player.paddleHeight })) {
				ball.speedX = -abs(ball.speedX);   // always go left
				ball.x = player.x - ball.radius;
			}
			if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ cpu.x,cpu.y,cpu.paddleWidth, cpu.paddleHeight })) {
				ball.speedX = abs(ball.speedX);    // always go right
				ball.x = cpu.x + cpu.paddleWidth + ball.radius; // push ball outside paddle
			}

			if (playerScore >= 5 || cpuScore >= 5) {
				gameOver = true;
			}
		}

		//Drawing
		ClearBackground(Dark_Green);
		DrawRectangle(screenWidth / 2, 0, screenWidth / 2, screenHeight, Green);
		DrawCircle(screenWidth / 2, screenHeight / 2, 150, Light_Green);
		DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

		ball.draw();
		cpu.draw();
		player.draw();

		DrawText(TextFormat("%i", cpuScore), screenWidth / 4 - 20, 20, 80, WHITE);
		DrawText(TextFormat("%i", playerScore), 3 * screenWidth / 4 - 20, 20, 80, WHITE);

		if (ball.waiting && !gameOver) {
			DrawText("Press SPACE to serve", screenWidth / 2 - 220, screenHeight / 2 + 200, 40, WHITE);
		}
		if (gameOver) {
			if (playerScore >= 5) {
				DrawText("YOU WIN!", screenWidth / 2 - 200, screenHeight / 2 - 50, 60, YELLOW);
			}
			else {
				DrawText("You Lost!", screenWidth / 2 - 150, screenHeight / 2 - 50, 60, YELLOW);
			}
			DrawText("Press SPACE to restart", screenWidth / 2 - 220, screenHeight / 2 + 20, 40, WHITE);

			if (IsKeyPressed(KEY_SPACE)) {
				playerScore = 0;
				cpuScore = 0;
				gameOver = false;
				ball.resetBall();
			}
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}