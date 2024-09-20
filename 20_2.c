#include <stdio.h>
#include <math.h>

int main() {
    printf("Введите порядок квадратной матрицы: ");
    int M;
    scanf("%d", &M);

    int matrix[M][M];

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int cntr; 
    if (M % 2 != 0) {
        cntr = ceil(M/2) + 1;
    } else {
        cntr = M/2;
    }
    for (int i = 0; i < cntr; ++i) {
        for (int j = i; j < M-i; ++j) {
            matrix[i][j] = 0;
        }
    }

    printf("Обновленная матрица:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
