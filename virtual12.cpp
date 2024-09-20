#include <iostream>
using namespace std;

// Определение абстрактного базового класса fig (фигура)
const int N=10;
class fig {
protected:
    float x0, y0; // Координаты фигуры
public:
    // Конструктор с параметрами по умолчанию
    fig(float x1=0, float y1=0): x0(x1), y0(y1) {}
    // Конструктор копирования
    fig(fig& f): x0(f.x0), y0(f.y0) {}
    // Виртуальная функция для вычисления площади фигуры
    virtual float sqr() const = 0;
    // Виртуальная функция для создания копии фигуры
    virtual fig* copyf() const = 0;
    // Виртуальная функция для вывода информации о фигуре
    virtual ostream& show(ostream& os) {
        return os << "x0 = " << x0 << ", y0 = " << y0;
    }
    // Перегрузка оператора вывода для вывода информации о фигуре
    friend ostream &operator<<(ostream &os, fig &tmp) { 
        return tmp.show(os); 
    }
};

// Класс для окружности, наследуется от fig
class okr: public fig {
    float r; // Радиус окружности
public:
    // Конструктор с параметрами
    okr(float x1, float y1, float r1): fig(x1,y1), r(r1) {}
    // Конструктор копирования
    okr(okr& f): fig(f) { r=f.r; }
    // Функция для создания копии окружности
    fig* copyf() const { return new okr(x0, y0, r); }
    // Функция для вычисления площади окружности
    float sqr() const { return 2 * 3.14 * r; }
    // Функция для вывода информации о окружности
    ostream& show(ostream& os) {
        fig::show(os);
        return os << ", radius = " << r << endl;
    }
};

// Класс для прямоугольника, наследуется от fig
class pr: public fig {
    float a, b; // Стороны прямоугольника
public:
    // Конструктор с параметрами
    pr(float x1, float y1, float a1, float b1): fig(x1,y1), a(a1), b(b1) {}
    // Конструктор копирования
    pr(pr& f): fig(f) { a=f.a; b=f.b; }
    // Функция для создания копии прямоугольника
    fig* copyf() const { return new pr(x0, y0, a, b); }
    // Функция для вычисления площади прямоугольника
    float sqr() const { return a * b; }
    // Функция для вывода информации о прямоугольнике
    ostream& show(ostream& os) {
        fig::show(os);
        return os << ", side1 = " << a << ", side2 = " << b << endl;
    }
};

// Класс для набора фигур
class fmnog {
    int free;
    int msize;
    fig** v;
public:
    // Конструктор с параметром, создает массив указателей на fig
    fmnog(int n): free(0), msize((n > N) ? N : n) { v = new fig*[msize]; }
    // Конструктор копирования
    fmnog(const fmnog& fm): free(fm.free), msize(fm.msize) {
        v = new fig*[msize];
        for (int i=0; i<free; ++i) v[i] = fm.v[i]->copyf();
    }
    // Деструктор, освобождает выделенную память
    ~fmnog() {
        for (int i = 0; i < free;) delete v[i++];
        delete [] v;
    }
    // Функция для увеличения размера массива v
    int resize() {
        msize *= 2;
        fig** newv = new fig*[msize];
        if (newv) {
            for (int i=0; i<free; ++i) newv[i]=v[i];
            delete[] v;
            v = newv; 
            return 1; 
        }
        cerr << "Error memory allocation!" << endl;
        return 0; 
    }
    // Перегрузка оператора вывода для вывода информации о наборе фигур
    friend ostream& operator<<(ostream& os, fmnog &fs);
    // Функция для получения размера набора
    int get_size() { return free; }
    // Функция для получения максимального размера набора
    int get_msize() { return msize; }
    // Перегрузка оператора += для добавления фигуры в набор
    fmnog& operator +=(fig& f) {
        if (free == msize) resize();
        v[free++] = f.copyf();
        return *this; 
    }
};

// Перегрузка оператора вывода для вывода информации о наборе фигур
ostream& operator<<(ostream& os, fmnog &f) {
    os << endl << "***** Set of geometric objects: *****" << endl;
    for (int i=0; i < f.free;)
        os << "i = " << i << ", figure = " << *f.v[i++] << endl;
    return os;
}
//по коду выше уже спросил. остался main

// main функция для демонстрации работы кода
int main() {
    // Создание набора фигур
    fmnog figures(5);

    // Создание и добавление окружностей и прямоугольников в набор
    okr circle1(1.0, 2.0, 3.0);
    pr rectangle1(4.0, 5.0, 6.0, 7.0);
    okr circle2(1.5, 2.5, 3.5);
    pr rectangle2(4.5, 5.5, 6.5, 7.5);

    figures += circle1;
    figures += rectangle1;
    figures += circle2;
    figures += rectangle2;

    // Вывод информации о всех фигурах в наборе
    cout << figures;

    // Создание копии набора фигур и вывод информации о ней
    fmnog figuresCopy = figures;
    cout << figuresCopy;

    return 0;
}

