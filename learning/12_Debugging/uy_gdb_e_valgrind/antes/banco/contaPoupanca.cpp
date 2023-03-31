#include "contaPoupanca.hpp"

ContaPoupanca::ContaPoupanca(Cliente* const cli): Conta(cli)  {
}

bool ContaPoupanca::Sacar(double quantia){
    return Conta::Sacar(quantia, 0.0);
}