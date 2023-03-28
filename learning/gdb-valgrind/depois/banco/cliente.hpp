#pragma once
#include <string>


class Cliente {
    public:
        Cliente(std::string nome, long int cpf);
        std::string getDados();
        bool setName(std::string novoNome);

    private:
        std::string nome;
        long int cpf;
};