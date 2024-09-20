#include <stdio.h>

int main() {
    printf("Введите число от 0 до 24: ");
    int hour;
    scanf("%d", &hour);

    if (hour >= 0 && hour < 6) {
        printf("Ночь\n");
    } else if (hour >= 6 && hour < 12) {
        printf("Утро\n");
    } else if (hour >= 12 && hour < 18) {
        printf("День\n");
    } else if (hour >= 18 && hour < 24) {
        printf("Вечер\n");
    } else {
        printf("Введено некорректное число\n");
    }

    return 0;
}
