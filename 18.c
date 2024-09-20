#include <stdio.h>
#include <string.h>

// Определение структуры Note
struct Note {
    char name[50];
    char phoneNumber[12];
    int birthday[3];
};

// Прототипы функций
void inputArray(struct Note array[], int size);
void sortByPhoneNumber(struct Note array[], int size);
void printPersonInfo(struct Note array[], int size, const char *surname);
void saveArrayToFile(struct Note array[], int size, const char *filename);

int main() {
    const int size = 3;
    struct Note notes[size];

    // Ввод данных и упорядочивание записей по номеру телефона
    inputArray(notes, size);
    sortByPhoneNumber(notes, size);

    // Вывод на экран информации о человеке по фамилии
    char searchSurname[50];
    printf("Введите фамилию для поиска: ");
    scanf("%s", searchSurname);
    printPersonInfo(notes, size, searchSurname);

    // Сохранение массива в файл
    saveArrayToFile(notes, size, "notes111.txt");

    return 0;
}

// Функция ввода данных с клавиатуры
void inputArray(struct Note array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("Введите данные для записи %d:\n", i + 1);
        printf("Фамилия, имя (через пробел): ");
        scanf("%s %s", array[i].name, array[i+1].name);
        printf("Номер телефона: ");
        scanf("%s", array[i].phoneNumber);
        printf("День рождения (через пробел): ");
        scanf("%d %d %d", &array[i].birthday[0], &array[i].birthday[1], &array[i].birthday[2]);
    }
}

// Функция упорядочивания записей по трем первым цифрам номера телефона
void sortByPhoneNumber(struct Note array[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strncmp(array[j].phoneNumber, array[j + 1].phoneNumber, 3) > 0) {
                // Обмен элементов массива
                struct Note temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Функция вывода информации о человеке по фамилии
void printPersonInfo(struct Note array[], int size, const char *surname) {
    int found = 0;
    for (int i = 0; i < size + 1; ++i) {
        if (strcmp(array[i].name, surname) == 0) {
            printf("Найдена информация для фамилии %s:\n", surname);
            printf("Фамилия, имя: %s %s\n", array[i].name, array[i+1].name);
            printf("Номер телефона: %s\n", array[i].phoneNumber);
            printf("День рождения: %d %d %d\n", array[i].birthday[0], array[i].birthday[1], array[i].birthday[2]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Информация для фамилии %s не найдена.\n", surname);
    }
}

// Функция записи массива в файл
void saveArrayToFile(struct Note array[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Не удалось открыть файл для записи.\n");
        return;
    }

    for (int i = 0; i < size; ++i) {
        fprintf(file, "Фамилия, имя: %s %s\n", array[i].name, array[i+1].name);
        fprintf(file, "Номер телефона: %s\n", array[i].phoneNumber);
        fprintf(file, "День рождения: %d %d %d\n", array[i].birthday[0], array[i].birthday[1], array[i].birthday[2]);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Массив успешно записан в файл %s.\n", filename);
}
