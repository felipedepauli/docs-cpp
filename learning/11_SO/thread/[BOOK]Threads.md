# Threads
## 1. Conceitos básicos de Threads
Threads são **unidades básicas** de execução em um processo. Elas permitem que você **execute várias sequências de instruções simultaneamente dentro de um processo**. As threads em um processo compartilham **o mesmo espaço de endereço e recursos**, como descritores de arquivos e variáveis globais, o que as torna mais leves em comparação com processos separados.

Vantagens do uso de threads:

> - Melhor aproveitamento de recursos, como CPU e memória.
> - Melhor desempenho, especialmente em sistemas com múltiplos núcleos ou processadores.
> - Compartilhamento de recursos mais fácil, uma vez que todas as threads em um processo compartilham o mesmo espaço de endereço.

Desafios do uso de threads:

> - Sincronização e proteção adequada dos recursos compartilhados para evitar condições de corrida, impasses (deadlocks) e outras questões de concorrência.
> - Gerenciamento do ciclo de vida das threads e sua comunicação.

Existem várias maneiras de trabalhar com threads em C++ no Linux. A biblioteca mais comum é a pthreads (POSIX threads), que fornece uma API C para criação e gerenciamento de threads. Além disso, a partir do C++11, há suporte embutido para threads na biblioteca padrão C++, que fornece uma API orientada a objetos para trabalhar com threads.
## 2. Criação e gerenciamento de threads em C++ (usando a biblioteca pthread)
A biblioteca **pthread** (POSIX threads) é uma API padrão para trabalhar com threads em sistemas POSIX, como o Linux. A biblioteca fornece funções para criar, gerenciar e sincronizar threads. Vou mostrar como criar e gerenciar threads usando a biblioteca pthread.

Primeiro, inclua a biblioteca pthread no código:
```C++
#include <pthread.h>
```
Depois a função que será executada pela thread.
```C++
#include <iostream>

void* print_thread(void* data) {
    std::cout << "I'm printing inside the thread" << std::endl;
    return nullptr;
}
```
```C++
int main() {
    pthread_t thread_id;
    int status;

    status = pthread_create(&thread_id, NULL, print_thread, NULL);

    if(status != 0) {
        std::cerr << "Erro ao criar a thread" << std::endl;
        return 1;
    }

    // Wait for thread return
    std::cout << "Waiting for thread to return..." << std::endl;
    pthread_join(thread_id, NULL);

    std::cout << "Main and thread end together!>>
    return 0;
}
```

Neste exemplo, criamos uma função chamada print_hello, que será executada pela thread. A função pthread_create é usada para criar a thread e iniciar a execução da função print_hello. A função pthread_join é usada para aguardar a thread terminar antes de prosseguir.

Ao compilar e executar este código, você verá a seguinte saída:

```
Olá, sou uma thread!
Thread finalizada
```
Além dessas funções básicas, a biblioteca pthread fornece outras funções para gerenciar threads, como:

> - pthread_exit: terminar a execução de uma thread.
> - pthread_detach: separar uma thread, permitindo que ela execute de forma independente sem a necessidade de ser unida (join) com a thread principal.
> - pthread_self: obter o identificador da thread atual.
> - pthread_cancel: cancelar a execução de uma thread.

Lembre-se de vincular a biblioteca pthread ao compilar seu código:
```
g++ your_code.cpp -o your_program -lpthread
```

## 3. Sincronização de threads (mutext e condições)
A sincronização de threads é essencial para garantir o acesso seguro a recursos compartilhados e evitar problemas como condições de corrida. As ferramentas comuns de sincronização de threads incluem **mutexes (exclusão mútua) e variáveis de condição**. Vamos ver como usá-los com a biblioteca pthread.

### Mutex
Um mutex é um objeto de sincronização que permite que apenas uma thread acesse um recurso compartilhado por vez. Quando uma thread adquire um mutex, outras threads que tentarem adquirir o mesmo mutex serão bloqueadas até que a primeira thread libere o mutex.

Para usar um mutex, primeiro declare e inicialize-o:

```C++
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
```
Em seguida, use pthread_mutex_lock para bloquear o mutex antes de acessar o recurso compartilhado e pthread_mutex_unlock para desbloqueá-lo após terminar:
```C++
pthread_mutex_lock(&my_mutex);
// Acesso ao recurso compartilhado
pthread_mutex_unlock(&my_mutex);
```
### Variáveis de condição

As variáveis de condição são usadas para sinalizar e aguardar eventos entre threads. Uma thread pode aguardar um evento usando uma variável de condição, enquanto outra thread sinaliza a variável de condição quando o evento ocorre.

Para usar uma variável de condição, primeiro declare e inicialize-a:
```C++
pthread_cond_t my_condition = PTHREAD_COND_INITIALIZER;
```
Uma thread pode esperar por um evento usando pthread_cond_wait, que também requer um mutex bloqueado:
```C++
pthread_mutex_lock(&my_mutex);
pthread_cond_wait(&my_condition, &my_mutex);
// Continuar após receber o sinal
pthread_mutex_unlock(&my_mutex);
```
Outra thread pode sinalizar o evento usando pthread_cond_signal:
```C++
pthread_mutex_lock(&my_mutex);
// Fazer algo que cause o evento
pthread_cond_signal(&my_condition);
pthread_mutex_unlock(&my_mutex);
```
Aqui está um exemplo completo de como usar mutexes e variáveis de condição com a biblioteca pthread:
```C++
#include <iostream>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
bool ready = false;

void* wait_thread(void* data) {
    pthread_mutex_lock(&mutex);
    while (!ready) {
        pthread_cond_wait(&condition, &mutex);
    }
    pthread_mutex_unlock(&mutex);

    std::cout << "Agora estou pronto!" << std::endl;
    return nullptr;
}

void* signal_thread(void* data) {
    pthread_mutex_lock(&mutex);
    ready = true;
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);

    std::cout << "Sinal enviado!" << std::endl;
    return nullptr;
}

int main() {
    pthread_t wait_thread_id;
    pthread_t signal_thread_id;

    pthread_create(&wait_thread_id, NULL, wait_thread, NULL);
    pthread_create(&signal_thread_id, NULL, signal_thread, NULL);

    pthread_join(wait_thread_id, NULL);
    pthread_join(signal_thread_id, NULL);

    return 0;
}
```
Neste exemplo, a função wait_thread espera até que a variável ready seja verdadeira, enquanto a função signal_thread define ready como verdadeira e sinaliza a variável de condição.