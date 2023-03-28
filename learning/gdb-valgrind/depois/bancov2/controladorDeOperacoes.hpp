#pragma once
#include "conta.hpp"

class  ControladorOperacoes {

    public:
        enum operacoes {
            DEPOSITO,
            SAQUE,
            EXTRATO,
            GRAVAR_EXTRATO_EM_ARQUIVO
        };

        ControladorOperacoes(Conta* conta);
        void executarTransacao(operacoes op);

    private:
        Conta* m_conta;
        void depositar100();
        void sacar100();
        void extrato();
        void gravaExtratoEmArquivo();

};