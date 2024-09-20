#include <iostream>
using namespace std;

class Vector {
private:
    int dimension;
    int *array;

public:
    Vector();
    Vector(int *data, int size);
    Vector(const Vector &other); // Конструктор копирования
    Vector& operator=(const Vector &other); // Оператор присваивания
    ~Vector();

    void display() const;
    void resize(int k);
    int length() const;
};

Vector::Vector() : dimension(0), array(nullptr) {
    // Конструктор по умолчанию
}

Vector::Vector(int *data, int size) : dimension(size) {
    array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = data[i];
    }
}

Vector::Vector(const Vector &other) : dimension(other.dimension) {
    if (dimension > 0) {
        array = new int[dimension];
        for (int i = 0; i < dimension; ++i) {
            array[i] = other.array[i];
        }
    } else {
        array = nullptr;
    }
}

Vector& Vector::operator=(const Vector &other) {
    if (this != &other) {
        delete[] array;
        dimension = other.dimension;
        if (dimension > 0) {
            array = new int[dimension];
            for (int i = 0; i < dimension; ++i) {
                array[i] = other.array[i];
            }
        } else {
            array = nullptr;
        }
    }
    return *this;
}

Vector::~Vector() {
    delete[] array;
}

void Vector::display() const {
    cout << "Vector: ";
    for (int i = 0; i < dimension; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Vector::resize(int k) {
    if (dimension + k < 0) {
        cout << "Error: resize results in negative dimension" << endl;
        return;
    }
    int newDimension = dimension + k;
    int *newArray = new int[newDimension];
    for (int i = 0; i < min(dimension, newDimension); ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    dimension = newDimension;
}

int Vector::length() const {
    return dimension;
}

int main() {
    const int N = 3;
    int data[N] = {1, 2, 3};

    Vector vectors[N];
    for (int i = 0; i < N; ++i) {
        vectors[i] = Vector(data, i + 1);
        vectors[i].display();
    }

    int maxLength = 0;
    int maxLengthIndex = 0;
    for (int i = 0; i < N; ++i) {
        if (vectors[i].length() > maxLength) {
            maxLength = vectors[i].length();
            maxLengthIndex = i;
        }
    }

    cout << "Longest Vector: ";
    vectors[maxLengthIndex].display();

    vectors[0].resize(2);
    vectors[1].resize(-1);
    vectors[2].resize(1);

    cout << "Resized Vectors:" << endl;
    for (int i = 0; i < N; ++i) {
        vectors[i].display();
    }

    return 0;
}
