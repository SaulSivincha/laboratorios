#include <iostream>

class CuentaBancaria {
private:
    float saldo;

public:
    CuentaBancaria(float saldoInicial)
        : saldo(saldoInicial) {}

    void depositar(float monto) {
        if (monto > 0) {
            saldo += monto;
            std::cout << "Depósito realizado: S/ " << monto << std::endl;
        }
    }

    void retirar(float monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            std::cout << "Retiro realizado: S/ " << monto << std::endl;
        } else {
            std::cout << "No se puede realizar el retiro por saldo insuficiente."
                      << std::endl;
        }
    }

    float consultarSaldo() const {
        return saldo;
    }
};

int main() {
    CuentaBancaria cuenta(500);

    std::cout << "Saldo inicial: S/ " << cuenta.consultarSaldo() << std::endl;

    cuenta.depositar(200);
    cuenta.retirar(300);
    cuenta.retirar(500);

    std::cout << "Saldo final: S/ " << cuenta.consultarSaldo() << std::endl;

    return 0;
}