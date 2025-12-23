#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

struct Segment {
    int x1, y1, x2, y2;
};

Segment snake[100] = {
    {100, 100, 110, 110},
    {90, 100, 100, 110},
    {80, 100,  90, 110}
};

int r1, r2;  // food position
int dir;     // direction
int length;  // snake length
bool gameOver;

void resetGame();
void drawSnake();
void moveSnake();
void drawFood();
void drawBorder();
bool checkCollision();

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, const_cast<char*>(""));
    srand(time(0));

    resetGame();

    while (true) {
        if (kbhit()) {
            char key = getch();
            if (key == 77 && dir != 2) dir = 3; // right
            if (key == 75 && dir != 3) dir = 2; // left
            if (key == 72 && dir != 1) dir = 0; // up
            if (key == 80 && dir != 0) dir = 1; // down
            if (key == 'a') break;              // exit
        }

        moveSnake();
        cleardevice();
        drawBorder();
        drawFood();
        drawSnake();

        if (checkCollision()) {
            gameOver = true;
            setcolor(RED);
            settextstyle(3, 0, 5);
            outtextxy(150, 200, const_cast<char*>("YOU LOSE!"));
            settextstyle(3, 0, 2);
            outtextxy(150, 260, const_cast<char*>("Press 'r' to restart or 'a' to exit"));

            while (true) {
                char ch = getch();
                if (ch == 'r') {
                    resetGame();
                    break;
                } else if (ch == 'a') {
                    closegraph();
                    return 0;
                }
            }
        }

        delay(100);
    }

    closegraph();
    return 0;
}

void resetGame() {
    length = 3;
    dir = 3; // right
    gameOver = false;

    snake[0] = {100, 100, 110, 110};
    snake[1] = {90, 100, 100, 110};
    snake[2] = {80, 100, 90, 110};

    r1 = 60 + (rand() % 48) * 10;
    r2 = 60 + (rand() % 38) * 10;
}

void drawSnake() {
    for (int i = 0; i < length; i++) {
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, i == 0 ? YELLOW : GREEN);
        rectangle(snake[i].x1, snake[i].y1, snake[i].x2, snake[i].y2);
        floodfill(snake[i].x1 + 1, snake[i].y1 + 1, WHITE);
    }
}

void moveSnake() {
    // Shift body
    for (int i = length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    // Move head
    if (dir == 3) { snake[0].x1 += 10; snake[0].x2 += 10; }
    if (dir == 2) { snake[0].x1 -= 10; snake[0].x2 -= 10; }
    if (dir == 0) { snake[0].y1 -= 10; snake[0].y2 -= 10; }
    if (dir == 1) { snake[0].y1 += 10; snake[0].y2 += 10; }

    // Eat food
    if (snake[0].x1 == r1 && snake[0].y1 == r2) {
        length++;
        r1 = 60 + (rand() % 48) * 10;
        r2 = 60 + (rand() % 38) * 10;
    }
}

void drawFood() {
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(r1, r2, r1 + 10, r2 + 10);
    floodfill(r1 + 1, r2 + 1, RED);
}

void drawBorder() {
    setcolor(WHITE);
    rectangle(50, 50, 550, 450);
}

bool checkCollision() {
    // Border
    if (snake[0].x1 <= 50 || snake[0].x2 >= 550 ||
        snake[0].y1 <= 50 || snake[0].y2 >= 450) {
        return true;
    }
    // Self
    for (int i = 1; i < length; i++) {
        if (snake[0].x1 == snake[i].x1 && snake[0].y1 == snake[i].y1) {
            return true;
        }
    }
    return false;
}
