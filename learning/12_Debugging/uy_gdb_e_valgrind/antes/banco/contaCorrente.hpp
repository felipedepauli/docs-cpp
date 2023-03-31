#pragma once
#include "conta.hpp"

class ContaCorrente: public Conta {
    public:
        std::string descricao = "Corrente";
        ContaCorrente(Cliente* const cli);
        bool Sacar(double quantia) override;
};