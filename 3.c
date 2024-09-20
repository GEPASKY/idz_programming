#include <stdio.h>

int main() {
    printf("Введите натуральное число N: ");
    int N;
    scanf("%d", &N);

    int remainder = N % 4;

    if (remainder == 0) {
        printf("N = 4k, где k = %d\n", N / 4);
    } else if (remainder == 1) {
        printf("N = 4k + 1, где k = %d\n", N / 4);
    } else if (remainder == 2) {
        printf("N = 4k + 2, где k = %d\n", N / 4);
    } else if (remainder == 3) {
        printf("N = 4k + 3, где k = %d\n", N / 4);
    } else {
        printf("Введено некорректное число\n");
    }

    return 0;
}
