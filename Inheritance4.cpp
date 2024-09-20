#include <iostream>
#include <cmath>
#include <vector>

class Quadrilateral {
protected:
    double x[4], y[4]; // Координаты 4-х точек

public:
    Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    virtual ~Quadrilateral();

    double calculateSideLength(int side) const;
    double calculateDiagonalLength(int diagonal) const;
    double calculatePerimeter() const;
    virtual double calculateArea() const;
    bool isTrapezoid() const;
    virtual void displayInfo() const;
};

Quadrilateral::Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    x[0] = x1; y[0] = y1;
    x[1] = x2; y[1] = y2;
    x[2] = x3; y[2] = y3;
    x[3] = x4; y[3] = y4;
}

Quadrilateral::~Quadrilateral() {
    // Деструктор
}

double Quadrilateral::calculateSideLength(int side) const {
    int nextPoint = (side + 1) % 4;
    return sqrt(pow(x[nextPoint] - x[side], 2) + pow(y[nextPoint] - y[side], 2));
}

double Quadrilateral::calculateDiagonalLength(int diagonal) const {
    return sqrt(pow(x[(diagonal + 2) % 4] - x[diagonal], 2) + pow(y[(diagonal + 2) % 4] - y[diagonal], 2));
}

double Quadrilateral::calculatePerimeter() const {
    double perimeter = 0.0;
    for (int i = 0; i < 4; ++i) {
        perimeter += calculateSideLength(i);
    }
    return perimeter;
}

double Quadrilateral::calculateArea() const {
    // Здесь вычисление площади четырехугольника
    return 0.0;
}

bool Quadrilateral::isTrapezoid() const {
    return (calculateSideLength(0) == calculateSideLength(2)) || (calculateSideLength(1) == calculateSideLength(3));
}

void Quadrilateral::displayInfo() const {
    std::cout << "Sides: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << calculateSideLength(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Diagonals: ";
    for (int i = 0; i < 2; ++i) {
        std::cout << calculateDiagonalLength(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Perimeter: " << calculatePerimeter() << std::endl;
    std::cout << "Is Trapezoid: " << (isTrapezoid() ? "Yes" : "No") << std::endl;
}

class Trapezoid : public Quadrilateral {
public:
    Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    void displayInfo() const override;
};

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : Quadrilateral(x1, y1, x2, y2, x3, y3, x4, y4) {
    // Конструктор
}

void Trapezoid::displayInfo() const {
    Quadrilateral::displayInfo();
}

int main() {
    const int N = 3; // Количество четырехугольников
    const int M = 2; // Количество трапеций

    std::vector<Quadrilateral*> quadrilaterals;
    quadrilaterals.push_back(new Quadrilateral(0, 0, 1, 0, 1, 1, 0, 1));
    quadrilaterals.push_back(new Quadrilateral(0, 0, 2, 0, 2, 2, 0, 2));
    quadrilaterals.push_back(new Quadrilateral(0, 0, 3, 0, 3, 3, 0, 3));

    std::vector<Trapezoid*> trapezoids;
    trapezoids.push_back(new Trapezoid(0, 0, 1, 0, 1, 1, 0, 1));
    trapezoids.push_back(new Trapezoid(0, 0, 2, 0, 2, 2, 0, 2));

    // Найти четырехугольник с минимальной площадью
    Quadrilateral* minAreaQuadrilateral = quadrilaterals[0];
    for (int i = 1; i < N; ++i) {
        if (quadrilaterals[i]->calculateArea() < minAreaQuadrilateral->calculateArea()) {
            minAreaQuadrilateral = quadrilaterals[i];
        }
    }

    // Найти трапецию с максимальной средней линией
    Trapezoid* maxAverageLineTrapezoid = trapezoids[0];
    for (int i = 1; i < M; ++i) {
        if (trapezoids[i]->calculatePerimeter() / 4 > maxAverageLineTrapezoid->calculatePerimeter() / 4) {
            maxAverageLineTrapezoid = trapezoids[i];
        }
    }

    std::cout << "Quadrilateral with the minimum area:" << std::endl;
    minAreaQuadrilateral->displayInfo();

    std::cout << "Trapezoid with the maximum average line length:" << std::endl;
    maxAverageLineTrapezoid->displayInfo();

    // Освобождение памяти
    for (int i = 0; i < N; ++i) {
        delete quadrilaterals[i];
    }

    for (int i = 0; i < M; ++i) {
        delete trapezoids[i];
    }

    return 0;
}

