#include <stdio.h>
//#include <termios.h>
//#include <unistd.h>
//
//// Функция для захвата одного символа без ожидания Enter
//char getch() {
//    char buf = 0;
//    struct termios old = {0};
//    if (tcgetattr(STDIN_FILENO, &old) < 0) {
//        perror("tcgetattr()");
//    }
//    old.c_lflag &= ~ICANON; // Выключаем канонический режим
//    old.c_lflag &= ~ECHO;   // Выключаем отображение символов
//    if (tcsetattr(STDIN_FILENO, TCSANOW, &old) < 0) {
//        perror("tcsetattr ICANON");
//    }
//    if (read(STDIN_FILENO, &buf, 1) < 0) {
//        perror("read()");
//    }
//    old.c_lflag |= ICANON;
//    old.c_lflag |= ECHO;
//    if (tcsetattr(STDIN_FILENO, TCSADRAIN, &old) < 0) {
//        perror("tcsetattr ~ICANON");
//    }
//    return buf;
//}
//
//int main() {
//    char ch;
//    printf("Нажмите клавишу (для выхода нажмите 'q'):\n");
//    while (1) {
//        ch = getch(); // Захватываем один символ
//        printf("Вы нажали: %c, ASCII код: %d\n", ch, ch);
//        if (ch == 'q') // Прерываем цикл, если нажата 'q'
//            break;
//    }
//    return 0;
//}

int main(){
    int width, height;

    printf("Введите размеры - ширину и высоту через пробел: ");
    scanf("%d %d", &width, &height);

    // Создаем лабиринт
    char maze[height][width];
    printf("%c" , maze[][]);
}