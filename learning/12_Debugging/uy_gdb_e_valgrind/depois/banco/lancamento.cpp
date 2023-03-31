#include "lancamento.hpp"

Lancamento::Lancamento(tipoLancamento _tipo, double valor, std::string descricao):
    tipo(_tipo), valorLancamento(valor), descricaoLancamento(descricao) {}

tipoLancamento Lancamento::getTipoLancamento() {
    return tipo;
}
double Lancamento::getValorLancamento() {
    return valorLancamento;
}
std::string Lancamento::getDescricaoTrancamento() {
    return descricaoLancamento;
}