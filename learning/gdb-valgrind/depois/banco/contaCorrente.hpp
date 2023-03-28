#pragma once
#include "conta.hpp"

class ContaCorrente: public Conta {
    public:
        ContaCorrente(Cliente* const cli);
        bool Sacar(double quantia) override;
};