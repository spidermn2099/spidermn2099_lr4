#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Максимальный размер поля

// Функция для отображения контекстного меню
void displayMenu() {
    printf("Лабораторная работа No4\n");
    printf("Выполнил: Ганиев Абубакр\n");
    printf("Группа: 453505\n");
    printf("Задание: Дополнить поле для игры в 'сапёр' числами.\n");
    printf("===========================================\n");
}

// Функция для заполнения поля числом бомб вокруг каждой клетки
void fillMinesweeperField(char field[MAX_SIZE][MAX_SIZE], int n, int m) {
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, // Верхний ряд
        {0, -1},          {0, 1},   // Боковые клетки
        {1, -1}, {1, 0}, {1, 1}     // Нижний ряд
    };

    // Обходим каждую клетку поля
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Если клетка содержит бомбу, пропускаем её
            if (field[i][j] == '*') {
                continue;
            }
            
            // Считаем количество бомб вокруг текущей клетки
            int bombCount = 0;
            for (int d = 0; d < 8; d++) {
                int newX = i + directions[d][0];
                int newY = j + directions[d][1];
                // Проверка на границы поля
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    if (field[newX][newY] == '*') {
                        bombCount++;
                    }
                }
            }

            // Если вокруг клетка нет бомб, ставим '.'
            if (bombCount == 0) {
                field[i][j] = '.';
            } else {
                // Вставляем количество бомб в клетку
                field[i][j] = bombCount + '0'; // Преобразуем в символ
            }
        }
    }
}

// Функция для вывода поля
void printField(char field[MAX_SIZE][MAX_SIZE], int n, int m) {
    printf("Поле для игры в 'сапёр':\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    char choice;
    char field[MAX_SIZE][MAX_SIZE];

    while (1) {
        // Вывод контекстного меню
        displayMenu();

        // Ввод размеров поля с проверкой
        printf("Введите количество строк (n): ");
        while (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
            printf("Неверный ввод. Пожалуйста, введите положительное целое число (до %d): ", MAX_SIZE);
            while (getchar() != '\n'); // очищаем буфер
        }

        printf("Введите количество столбцов (m): ");
        while (scanf("%d", &m) != 1 || m <= 0 || m > MAX_SIZE) {
            printf("Неверный ввод. Пожалуйста, введите положительное целое число (до %d): ", MAX_SIZE);
            while (getchar() != '\n'); // очищаем буфер
        }

        // Ввод поля
        printf("Введите поле (используйте '.' для пустого места и '*' для бомбы):\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                while (1) {
                    scanf(" %c", &field[i][j]);
                    if (field[i][j] == '.' || field[i][j] == '*') {
                        break; // правильный ввод
                    } else {
                        printf("Неверный ввод. Пожалуйста, введите '.' или '*': ");
                    }
                }
            }
        }

        // Заполнение поля числом бомб вокруг каждой клетки
        fillMinesweeperField(field, n, m);

        // Вывод итогового поля
        printField(field, n, m);

        // Спрашиваем, хочет ли пользователь повторить
        printf("Хотите выполнить программу снова? (y/n): ");
        while (getchar() != '\n'); // очищаем буфер
        choice = getchar();

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}
