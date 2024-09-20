#include <stdio.h>

int main() {
    printf("Введите размер массива: ");
    int size;
    scanf("%d", &size);

    int arr[size];

    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Индексы нечетных чисел в порядке убывания:\n");
    int countOdd = 0;
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] % 2 != 0) {
            printf("%d ", i);
            countOdd++;
        }
    }

    printf("\nКоличество нечетных чисел: %d\n", countOdd);

    return 0;
}
