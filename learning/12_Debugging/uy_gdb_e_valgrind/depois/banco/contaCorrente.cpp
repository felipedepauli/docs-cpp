#include "contaCorrente.hpp"

ContaCorrente::ContaCorrente(Cliente* const cli): Conta(cli)  {
}

bool ContaCorrente::Sacar(double quantia){
    return Conta::Sacar(quantia, 5);
}