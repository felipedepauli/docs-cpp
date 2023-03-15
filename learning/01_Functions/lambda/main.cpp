#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template <typename T>
void print(T msg) {
    cout << msg << endl;
}
int main(int argc, char* argv[]) {

//  Função anônima
//  [] Captura de variáveis
//  () Captura de parâmetros
//  {} Corpo da função
    auto maior = [](std::vector<int> n)->int {
        auto m = 0;
        for (int x:n) {
            m = ( m > x ) ? m : x ; 
        }
        return m;
    };

    print(maior({1, 99, 1, 100, 22, 39}));

//  ------------------------------------------------------------------

    int param1, param2, param3, param4;
    param1 = 1;
    param2 = 2;
    param3 = 1;
    param4 = 10;

    auto equation = [param1, param2, param3, param4] (int x) -> int {
        return param1*x^3 + param2*x^2 + param3*x + param4;
    };

    print(equation(2));

    return 0;
}

