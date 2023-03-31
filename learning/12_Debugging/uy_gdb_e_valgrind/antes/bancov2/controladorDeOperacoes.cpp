#include "controladorDeOperacoes.hpp"
#include <functional>
#include <future>
#include <thread>
#include <iostream>

ControladorOperacoes::ControladorOperacoes(Conta *conta) : m_conta(conta) {}

void ControladorOperacoes::executarTransacao(operacoes op)
{
    std::thread threadTransacao;
    switch (op)
    {
    case DEPOSITO:
        threadTransacao = std::thread(&ControladorOperacoes::depositar100, this);
        printf("\nTransacao de deposito acionada\n");
        break;
    case SAQUE:
       threadTransacao = std::thread(&ControladorOperacoes::sacar100, this);
        printf("\nTransacao de saque acionada\n");
        break;
    case EXTRATO:
       threadTransacao = std::thread(&ControladorOperacoes::extrato, this);
        printf("\nTransacao de extrato acionada\n");
        break;
    case GRAVAR_EXTRATO_EM_ARQUIVO:
       threadTransacao = std::thread(&ControladorOperacoes::gravaExtratoEmArquivo, this);
        printf("\nTransacao de gravacao de extrato em aquivo acionada\n");
        break;
    default:
        printf("Parametro invalido");
        break;
    }

    threadTransacao.join();
}

void ControladorOperacoes::depositar100()
{
    m_conta->Depositar(100);
}
void ControladorOperacoes::sacar100()
{
    m_conta->Sacar(100);
}
void ControladorOperacoes::extrato()
{
    std::cout << m_conta->getExtrato();
}
void ControladorOperacoes::gravaExtratoEmArquivo()
{
    m_conta->exportaExtrato();
}
