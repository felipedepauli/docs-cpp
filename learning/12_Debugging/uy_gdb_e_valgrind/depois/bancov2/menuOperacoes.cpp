#include "menuOperacoes.hpp"
#include <cstdio>
#include <ctype.h>

MenuOperacoes::MenuOperacoes(ControladorOperacoes *operador) : controlador(operador) {}

MenuOperacoes::~MenuOperacoes()
{
    delete controlador;
}

void MenuOperacoes::showMenu()
{
    bool menuAtivo = true;
    while (menuAtivo)
    {
        printf("\nMenu de operacoes, selecione: \n"
               "1 para Deposito\n"
               "2 para Saque\n"
               "3 para Extrato\n"
               "4 para Exportar o extrato\n"
               "5 para sair\n");

        int resposta = 0;
        bool respostaValida = false;
        while (!respostaValida)
        {
            resposta = ::getchar() - '0';
            respostaValida = (resposta > 0 && resposta < 6);
        }

        printf("Voce escolheu: %d\n", resposta);

        switch (resposta)
        {
        case 1:
            controlador->executarTransacao(ControladorOperacoes::DEPOSITO);
            break;

        case 2:
            controlador->executarTransacao(ControladorOperacoes::SAQUE);
            break;
        case 3:
            controlador->executarTransacao(ControladorOperacoes::EXTRATO);
            break;

        case 4:
            controlador->executarTransacao(ControladorOperacoes::GRAVAR_EXTRATO_EM_ARQUIVO);
            break;
        case 5:
            menuAtivo = false;
            break;

        default:
            printf("Reposta invalida");
        }
    }
}

void MenuOperacoes::execute()
{
    std::thread menu(&MenuOperacoes::showMenu, this);
    menu.join();
}
