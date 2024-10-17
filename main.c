#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int key;
int width, height;
int PosX = 1, PosY = 1;
int position = 0;
int n_button;

void menu() {
    printw("%s", "Labirint by Tikhanov Oleg\n");
    printw("%s", "ver 0.1\n");
    printw("%s", "\n");
    printw("%s", "Перед использованием прочитайте инструкцию 3 п.\n");
    printw("%s", "-----------------\n");
    printw("%s", "\n");

    char screen[5][35] = {
        "1. Лабиринт",
        "2. Посчитать путь",
        "3. Инструкция",
        "4. Выход",
        "",
    };

    for (int i = 0; i <= 4; ++i) {
        if (i == position) {
            printw("%s  %s\n", screen[i], "<---");
        } else {
            printw("%s\n", screen[i]);
        }
    }
}

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

void keywork(char maze[height][width]) {
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
    if (key == 'b') {
        maze[PosY][PosX] = '#';
    }
    if (key == 127) {
        maze[PosY][PosX] = '.';
    }

}

int main() {
    setlocale(LC_ALL, "");
    initscr();
    keypad(stdscr, FALSE);

    while (true) {
        menu(position);

        n_button = getch();

        if (n_button == 27) {
            // ESC
            n_button = getch();
            if (n_button == 91) {
                // enter
                n_button = getch();
                if (n_button == 65) {
                    // up
                    position = position - 1;
                    if (position < 0) {
                        position = 3;
                    }
                } else if (n_button == 66) {
                    // down
                    position = position + 1;
                    if (position > 3) {
                        position = 0;
                    }
                }
            }
        }

        //1 lab
        if ((position == 0 && n_button == 10) || n_button == 27) {
            keypad(stdscr, TRUE);
            clear();
            printw("Введите размеры - ширину и высоту через пробел: ");
            scanw("%d %d", &width, &height);
            clear();
            // Создаем лабиринт
            char maze[height][width];
            createMaze(width, height, maze);


            while (1) {
                // Отображаем лаб
                keywork(maze);

                if (key == 27) {
                    keypad(stdscr, FALSE);
                    break;
                }
            }
        }

        //exit
        if ((position == 3 && n_button == 10) || n_button == 27) {
            break;
        }

        clear();
        endwin();
    }
    return 0;
}