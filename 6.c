#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 231 // Максимальный размер магического квадрата

// Функция для отображения контекстного меню
void displayMenu() {
    printf("Лабораторная работа No4\n");
    printf("Выполнил: Ганиев Абубакр\n");
    printf("Группа: 453505\n");
    printf("Задание: Построить магический квадрат заданного порядка.\n");
    printf("===========================================\n");
}

// Функция для инициализации магического квадрата
void initializeMagicSquare(int n, int magicSquare[MAX_SIZE][MAX_SIZE]) {
    int i = 0, j = n / 2; // Начальная позиция

    for (int num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num; // Устанавливаем число

        // Вычисляем новую позицию
        int newI = (i - 1 + n) % n; // Поднимаемся вверх
        int newJ = (j + 1) % n; // Перемещаемся вправо

        // Если новая позиция занята, перемещаемся вниз
        if (magicSquare[newI][newJ] != 0) {
            i = (i + 1) % n; // Перемещаемся вниз
        } else {
            i = newI; // Перемещаемся в новую позицию
            j = newJ; // Перемещаемся вправо
        }
    }
}

// Функция для вывода магического квадрата
void printMagicSquare(int n, int magicSquare[MAX_SIZE][MAX_SIZE]) {
    printf("Магический квадрат порядка %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", magicSquare[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    char choice;

    while (1) {
        // Вывод контекстного меню
        displayMenu();

        // Ввод порядка магического квадрата с проверкой
        printf("Введите порядок магического квадрата (нечетное число до %d): ", MAX_SIZE);
        while (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE || n % 2 == 0) {
            printf("Неверный ввод. Пожалуйста, введите нечетное положительное целое число (до %d): ", MAX_SIZE);
            while (getchar() != '\n'); // очищаем буфер
        }

        int magicSquare[MAX_SIZE][MAX_SIZE] = {0}; // Инициализация магического квадрата

        // Построение магического квадрата
        initializeMagicSquare(n, magicSquare);

        // Вывод магического квадрата
        printMagicSquare(n, magicSquare);

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