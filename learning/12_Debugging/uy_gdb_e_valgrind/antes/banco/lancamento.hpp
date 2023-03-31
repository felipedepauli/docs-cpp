#include <string>

enum class tipoLancamento {
    CREDITO,
    DEBITO
};

class Lancamento {
    public:
        Lancamento(tipoLancamento _tipo, double valor, std::string descricao);
        tipoLancamento getTipoLancamento();
        double getValorLancamento();
        std::string getDescricaoTrancamento();


    private:
        tipoLancamento tipo;
        double valorLancamento;
        std::string descricaoLancamento;
};