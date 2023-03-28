#include <stdio.h>
#include <cstring>

char* inverter(const char * textoOriginal) {
    int tamTextoOriginal = strlen(textoOriginal);
    char* resultado = new char[tamTextoOriginal + 1];

    for(int i = (tamTextoOriginal - 1), j = 0; i >=0 ; i--, j++)
        resultado[j] = textoOriginal[i];

    
    resultado[tamTextoOriginal] = '\0';

    return resultado;
    }

int main(int argc, char const *argv[])
{
    const char * texto = "Casa";
    const char * textoInvertido = inverter(texto);

    printf("Original: %s, Invertido: %s \n", texto, textoInvertido);
    
    delete[] textoInvertido;

    return 0;
}
