#include <iostream>

class Rectangulo {
private:
    float base;
    float altura;

public:
    Rectangulo(float base, float altura)
        : base(base), altura(altura) {}

    float calcularArea() const {
        return base * altura;
    }

    float calcularPerimetro() const {
        return 2 * (base + altura);
    }
};

int main() {
    Rectangulo rectangulo1(8, 5);

    std::cout << "Área: " << rectangulo1.calcularArea() << std::endl;
    std::cout << "Perímetro: " << rectangulo1.calcularPerimetro() << std::endl;

    return 0;
}