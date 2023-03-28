#include <iostream>

#include "contaCorrente.hpp"
#include "contaPoupanca.hpp"
#include "controladorDeOperacoes.hpp"
#include "menuOperacoes.hpp"

int main()
{
    Cliente *carlos = new Cliente("Carlos almeida", 7425864160);
    Conta *conta1 = new ContaPoupanca(carlos);

    ControladorOperacoes* controlador = new ControladorOperacoes(conta1);
    MenuOperacoes* menu = new MenuOperacoes(controlador);

    menu->execute();
}