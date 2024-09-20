#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator; // числитель
    int denominator; // знаминатель

public:
    Fraction(int num, int denom);
    ~Fraction();

    Fraction reciprocal() const;
    double toDecimal() const;
    static Fraction fromDecimal(double decimal);
    void display() const;
};

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    // Конструктор
}

Fraction::~Fraction() {
    // Деструктор
}

Fraction Fraction::reciprocal() const {
    return Fraction(denominator, numerator);
}

double Fraction::toDecimal() const {
    return static_cast<double>(numerator) / denominator;
}

Fraction Fraction::fromDecimal(double decimal) {
    int precision = 1000000;  // Желаемая точность
    int num = static_cast<int>(decimal * precision);
    return Fraction(num, precision);
}

void Fraction::display() const {
    cout << numerator << "/" << denominator;
}

int main() {
    Fraction fraction(1, 2);
    fraction.display();
    cout << " Reciprocal: ";
    fraction.reciprocal().display();
    cout << " Decimal: " << fraction.toDecimal() << std::endl;

    double decimalValue = 0.75;
    Fraction convertedFraction = Fraction::fromDecimal(decimalValue);
    cout << "Converted from Decimal (" << decimalValue << "): ";
    convertedFraction.display();
    cout << std::endl;

    return 0;
}
