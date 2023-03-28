#pragma once
#include <vector>

#include "cliente.hpp"
#include "lancamento.hpp"

class Conta {
    public:
        Conta(Cliente* const cli);
        virtual bool Depositar(double quantia);
        virtual double getSaldo();
        virtual std::string getCliente();
        virtual bool Sacar(double quantia) = 0;
        virtual std::string getExtrato();
        virtual void exportaExtrato();
    protected:
        virtual bool Sacar(double quantia,double tarifa);
    
    private:
        int numeroConta;
        Cliente* const cliente;
        double saldo;
        std::vector<Lancamento> lancamentos;
        bool escreveExtratoEmArquivo();
};