#include <iostream>

#include "contaCorrente.hpp"
#include "contaPoupanca.hpp"

int main()
{
    Cliente *carlos = new Cliente("Carlos almeida", 7425864160);
    Conta *conta1 = new ContaPoupanca(carlos);

    std::cout << conta1->getCliente() << std::endl;

    conta1->Depositar(1000);
 
    conta1->Sacar(900.65);

    std::cout << conta1->getExtrato() << std::endl;

    conta1->exportaExtrato();

    delete carlos;
    delete conta1;

}