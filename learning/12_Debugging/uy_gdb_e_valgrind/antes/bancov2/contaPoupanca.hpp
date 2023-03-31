#pragma once
#include "conta.hpp"

class ContaPoupanca: public Conta {
    public:
        ContaPoupanca(Cliente* const cli);
        bool Sacar(double quantia) override;
};