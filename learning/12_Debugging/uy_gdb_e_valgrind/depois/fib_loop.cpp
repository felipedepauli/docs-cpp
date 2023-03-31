#include <iostream>
#include <stdio.h>

unsigned long long fib(unsigned long long numeroAtual)
{
    if(numeroAtual == 0) {
        return numeroAtual;
    }

    unsigned long long primeiro = 1, segundo = 2;
    for(unsigned long long i = 3; i <= numeroAtual; i++) 
    {
        unsigned long long proxElemento = primeiro + segundo;
        primeiro = segundo;
        segundo = proxElemento;
    }
    return primeiro;
}

int main()
{
    unsigned long long tamanhoSerie = 50;

    unsigned long long i = 0;
    while (i < tamanhoSerie)
    {
        std::cout << fib(i) << " ";
        i++;
    }
    std::cout << std::endl;

    return 0;
}