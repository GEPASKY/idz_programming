#include <stdio.h>

int main() {
    printf("Введите три числа: ");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int minNumber = a;
    if (b < minNumber) minNumber = b;
    if (c < minNumber) minNumber = c;

    int maxNumber = a;
    if (b > maxNumber) maxNumber = b;
    if (c > maxNumber) maxNumber = c;

    printf("Наименьшее число: %d\n", minNumber);
    printf("Наибольшее число: %d\n", maxNumber);

    return 0;
}
