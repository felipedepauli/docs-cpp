#include <vector>
#include <thread>
#include "controladorDeOperacoes.hpp"

class MenuOperacoes {
    public:
        MenuOperacoes(ControladorOperacoes* operador);
        ~MenuOperacoes();
        void execute();
        std::string teste();
        void showMenu();

    private:
        ControladorOperacoes* controlador;

};