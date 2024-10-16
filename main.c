#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>



// Функция для рисования лабиринта
void drawMaze(int width, int height, char maze[height][width], int PosX, int PosY) {
    clear(); // Очищаем экран
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == PosX && y == PosY) {
                mvaddch(y, x, '$'); //Player
            } else {
                mvaddch(y, x, maze[y][x]); //Lab
            }
        }
    }
}

// Заполняем начальный массив
void createMaze(int width, int height, char maze[height][width]) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                maze[y][x] = '#';
            } else {
                maze[y][x] = '.';
            }
        }
    }
}


int main() {
    int key;
    int width, height;
    int PosX = 1, PosY = 1;
    setlocale(LC_ALL, "");

    initscr();
    keypad(stdscr, TRUE);

    printw("Введите размеры - ширину и высоту через пробел: ");
    scanw("%d %d", &width, &height);

    // Создаем лабиринт
    char maze[height][width];
    createMaze(width, height, maze);


    while (1) {
        // Отображаем лаб
        drawMaze(width, height, maze, PosX, PosY);

        key = getch();

        if (key == KEY_UP) {
            if (PosY > 0) PosY--;
        }
        if (key == KEY_DOWN) {
            if (PosY < height - 1) PosY++;
        }
        if (key == KEY_RIGHT) {
            if (PosX < width - 1) PosX++;
        }
        if (key == KEY_LEFT) {
            if (PosX > 0) PosX--;
        }
        if (key == 49) {
            maze[PosY][PosX] = '#';
        }
        if (key == 127) {
            maze[PosY][PosX] = '.';
        }
        if (key == 96) {
            break;
        }
    }
    endwin();
    return 0;
}