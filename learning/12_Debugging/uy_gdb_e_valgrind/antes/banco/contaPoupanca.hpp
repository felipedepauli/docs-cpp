#pragma once
#include "conta.hpp"

class ContaPoupanca: public Conta {
    public:
        std::string descricao = "Poupanca";
        ContaPoupanca(Cliente* const cli);
        bool Sacar(double quantia) override;
};