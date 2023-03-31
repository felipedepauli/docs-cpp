#include "cliente.hpp"

Cliente::Cliente(std::string nome, long int cpf): nome(nome), cpf(cpf) {

}

bool Cliente::setName(std::string novoNome) {
    this->nome = novoNome;
    return true;
}

std::string Cliente::getDados() {
    return std::string("Nome: " + this->nome + " CPF: " + std::to_string(cpf));
}