#include <numeric>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "conta.hpp"

Conta::Conta(Cliente *const cli) : cliente(cli)
{
    saldo = 0;
}

bool Conta::Depositar(double quantia)
{
    Lancamento deposito = {tipoLancamento::CREDITO, quantia, "Deposito"};
    lancamentos.push_back(deposito);
    return true;
};

bool Conta::Sacar(double quantia, double Valortarifa)
{
    double totalADebitar = quantia + Valortarifa;
    if (getSaldo() >= totalADebitar)
    {
        Lancamento saque = {tipoLancamento::DEBITO, quantia, "Saque"};
        lancamentos.push_back(saque);

        if (Valortarifa > 0)
        {
            Lancamento tarifa = {tipoLancamento::DEBITO, Valortarifa, "Tarifa de Saque"};
            lancamentos.push_back(tarifa);
        }

        return true;
    }
    else
    {
        return false;
    }
}

std::string Conta::getInformacoesDaConta() {
    return std::to_string(numeroConta);
}

double Conta::getSaldo()
{
    double soma = 0;
    auto somar = [&soma](Lancamento lancamento)
    {
        if (lancamento.getTipoLancamento() == tipoLancamento::CREDITO)
        {
            soma += lancamento.getValorLancamento();
        }
        else if (lancamento.getTipoLancamento() == tipoLancamento::DEBITO)
        {
            soma -= lancamento.getValorLancamento();
        }
        return soma;
    };

    std::for_each(lancamentos.begin(), lancamentos.end(), somar);
    return soma;
}

std::string Conta::getCliente()
{
    return cliente->getDados();
}

std::string Conta::getExtrato()
{
    std::string extratoFormatado;

    extratoFormatado += "Saldo inicial: R$ " + std::to_string(saldo) + "\n";
    extratoFormatado += "Lancamentos: \n";
    extratoFormatado += "Tipo Valor       Descricao \n";

    for (Lancamento l : lancamentos)
    {
        std::string tipo = l.getTipoLancamento() == tipoLancamento::CREDITO ? "C" : "D";
        char valorFormatado[50];
        snprintf(valorFormatado, sizeof(valorFormatado), " R$ %.2f ", l.getValorLancamento());
        extratoFormatado += tipo + "    " + valorFormatado + l.getDescricaoTrancamento() + "\n";
    }

    extratoFormatado += "\n Saldo Atual: R$ " + std::to_string(getSaldo());

    return extratoFormatado;
}

bool Conta::escreveExtratoEmArquivo()
{
    std::ofstream arquivoSaida;
    arquivoSaida.open("Extrato.txt");
    arquivoSaida << getExtrato();
    arquivoSaida.close();
    return !arquivoSaida.is_open();
}

void Conta::exportaExtrato()
{
    printf("Parent: %d\n", getpid());
    pid_t pid = fork();
    int status = 0;
    if (pid == static_cast<pid_t>(0))
    {
        // child process
        printf("Child: %d\n", getpid());
        escreveExtratoEmArquivo();
    }
    else if (pid < static_cast<pid_t>(0))
    {
        // failed to fork
        fprintf(stderr, "Fork falhou.\n");
    }
    else
    {
        // parent process
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status))
        {
            fprintf(stderr, "Processo finalizado com erro.\n");
        }
        else if (WEXITSTATUS(status))
        {
            fprintf(stdout, "Processo finalizado com sucesso.\n");
        }
    }
}