#include <iostream>
using namespace std;

class Pyramid {
private:
    double sideLength;
    double apothem;

public:
    Pyramid(double s, double a);
    double calculateBasePerimeter() const;
    double calculateBaseArea() const;
    double calculateVolume() const;
    void displayInfo() const;
};

Pyramid::Pyramid(double s, double a) : sideLength(s), apothem(a) {
    // Конструктор
}

double Pyramid::calculateBasePerimeter() const {
    return 4 * sideLength;
}

double Pyramid::calculateBaseArea() const {
    return sideLength * sideLength;
}

double Pyramid::calculateVolume() const {
    return (1.0 / 3) * calculateBaseArea() * apothem;
}

void Pyramid::displayInfo() const {
    cout << "Base Perimeter: " << calculateBasePerimeter() << std::endl;
    cout << "Base Area: " << calculateBaseArea() << std::endl;
    cout << "Volume: " << calculateVolume() << std::endl;
}

int main() {
    const int N = 3;
    Pyramid pyramids[N] = {Pyramid(2.0, 1.5), Pyramid(3.0, 2.0), Pyramid(1.5, 1.0)};

    double maxBaseArea = 0.0;
    int maxBaseAreaIndex = 0;

    double maxVolume = 0.0;
    int maxVolumeIndex = 0;

    for (int i = 0; i < N; ++i) {
        if (pyramids[i].calculateBaseArea() > maxBaseArea) {
            maxBaseArea = pyramids[i].calculateBaseArea();
            maxBaseAreaIndex = i;
        }

        if (pyramids[i].calculateVolume() > maxVolume) {
            maxVolume = pyramids[i].calculateVolume();
            maxVolumeIndex = i;
        }
    }

    cout << "Pyramid with the largest Base Area:" << endl;
    pyramids[maxBaseAreaIndex].displayInfo();

    cout << "Pyramid with the largest Volume:" << endl;
    pyramids[maxVolumeIndex].displayInfo();

    return 0;
}
