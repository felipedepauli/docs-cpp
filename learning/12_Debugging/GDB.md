�C��  �C��   �r     �r    ؛r           ��y    x�r    ��y   ��y    ��r    ��y   ��y    ��r    ��y   p�y    ��r    p�y  x�y    ��r    x�y   ��y    Țr    ��y����y            ��y   ���    ���    ���                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    `` 
You can look the process ID (PID) of the process that you are running inside the GDB. You have to use the following command:
```
info inferiors

``` 

If you want to pass argments to the binary, you have to execute the gdb using --args and the arguments.
```
g++ -ggdb args.cpp -o args.o
gdb --args ./args.o 20
```
In this example, when you run the program inside GDB, you are going to have a loop from 0 to 20 instead to 10000.


If you want to enter in a fucntion, you have to use step.

```
step
```

Sometimes, you can enter in a function and get stucked inside it. You can go out of it using finish. There is also a situation which you get stucked inside a loop. You can get out of it using until. The until command say: go on until the line X.

GUI for GDB:
```
<ctrl> + x + a
```

You know need to know what is the value of a variable of interesting. Print it!
```
print variable
```
```
info args           // function's arguments
info locals         // all local variables
info breakpoints    // program's breakpoints
delete 1            // delete the breakpoint 1 (del)
```

This is amazing. As you saw, it's possible to look up to local variables. If you want to watch one or a couple of them, you can use display to fix it at each next, showing its updated value.
```
display myVar
```
To undo that, you can look at all display variables and then use undisplay.
```
info display
undisplay 2 (or whatever number it is)
```

```
layout          // Print all options
layout src      // Show the default view
layout reg      // Show src and registers
tui reg         // Show all registers types
tui reg general // Set the default type of registers to show
```


```
tty /dev/pts/7 
```
## 2. Stack
### 2.1 O que é

A gente conhece bem a nossa Stack. Não? Então vamos lá.

A stack (pilha) é uma área de memória que armazena informações sobre as funções em execução em um programa. Quando uma função é chamada, suas informações, como variáveis locais e o endereço de retorno (para onde a execução deve voltar após a conclusão da função), são empilhadas na stack. As funções são empilhadas de maneira hierárquica, de acordo com a sequência de chamadas.

Aqui está um breve resumo de como as funções são empilhadas:

> - Quando uma função é chamada, um novo quadro de pilha (stack frame) é criado.
> - O endereço de retorno (para onde a execução deve voltar após a conclusão da função) é armazenado no quadro de pilha.
> - Os argumentos da função e as variáveis locais são armazenados no quadro de pilha.
> - Se a função chamar outras funções, novos quadros de pilha serão adicionados à stack.
> - Quando uma função termina, seu quadro de pilha é desempilhado e o endereço de retorno é usado para retomar a execução na função chamadora.

### 2.2 Usando o GDB para visualizar a stack

O GDB oferece várias maneiras de visualizar e navegar pela stack durante a depuração.

- backtrace (ou bt): exibe a pilha de chamadas atual, mostrando a sequência de chamadas de função que levou ao ponto de execução atual.
```gdb
(gdb) backtrace
```
- frame FRAME_NUMBER: seleciona um quadro de pilha específico por número. Isso permite que você inspecione variáveis e outros detalhes nesse quadro de pilha.
```gdb
(gdb) frame 2
```
- up e down: navegue pelos quadros de pilha. O comando up move-se para o quadro de pilha chamador, enquanto o comando down move-se para o quadro de pilha chamado.
```gdb
(gdb) up
(gdb) down
```
- info locals: exibe as variáveis locais no quadro de pilha atual.
```gdb
(gdb) info locals
```
- info args: exibe os argumentos da função no quadro de pilha atual.
```gdb
(gdb) info args
```
Ao usar esses comandos, você pode explorar a stack e entender melhor o estado do seu programa em diferentes pontos de execução. Isso é especialmente útil para rastrear a origem de bugs e entender o fluxo de execução do seu código.

```gdb
(gdb) bt full
```




## 3. Debugging de códigos com várias threads usando o GDB
### 3.1 Configurando o ambiente

O GDB (GNU Debugger) oferece suporte para depurar programas com várias threads. Vou apresentar como configurar o ambiente, os comandos básicos do GDB para depurar threads e algumas dicas e truques ao depurar threads com o GDB.

Configurando o ambiente

Para começar, compile seu código com a opção -g para incluir informações de depuração:
```
g++ -g your_code.cpp -o your_program -lpthread
```

Em seguida, inicie o GDB com seu programa:

```
gdb your_program
```
```gdb
(gdb) backtrace full
```
```gdb
(gdb) shell
```

### 3.2 Comandos básicos do GDB para depurar threads
> - __info threads:__ exibe informações sobre todas as threads no programa, como IDs, estados e funções atuais.
> - __thread THREAD_ID:__ seleciona uma thread específica pelo ID para depuração. Você pode obter IDs de threads usando o comando info threads.
> - __break FUNCTION_NAME:__ insere um breakpoint em uma função específica. Quando uma thread atinge o breakpoint, a execução é interrompida e você pode inspecionar o estado do programa.
> - break FILE:LINE_NUMBER: insere um breakpoint em um número de linha específico em um arquivo.
> - break Class::Function (como mencionado anteriormente): insere um breakpoint em um método de classe específico.
> - continue: continua a execução do programa após atingir um breakpoint.
> - next: executa a próxima instrução na thread atual, sem entrar nas funções chamadas.
> - step: executa a próxima instrução na thread atual, entrando em funções chamadas se houver alguma.
> - finish: continua a execução até a thread atual sair da função atual.


### 3.3 Dicas e truques ao depurar threads com o GDB

1. Ao usar breakpoints em um programa multithread, é importante saber que o GDB irá parar todas as threads quando um breakpoint for atingido. Isso pode ser útil para examinar o estado de todas as threads, mas também pode ser confuso, pois você precisará identificar qual thread atingiu o breakpoint.
2. O GDB oferece a opção de configurar breakpoints específicos para threads usando a opção thread THREAD_ID após o comando break. Por exemplo, o código a seguir fará com que o breakpoint seja acionado apenas quando a thread especificada atingir a linha de código correspondente.

```
break FILE:LINE_NUMBER thread THREAD_ID
```
3. Ao depurar programas multithread, é importante estar ciente de possíveis condições de corrida e impasses (deadlocks). O GDB pode não revelar esses problemas se você não configurar breakpoints adequadamente. Tente colocar breakpoints em locais críticos, como acesso a recursos compartilhados, para ajudar a identificar esses problemas.

4. Lembre-se de que a ordem de execução das threads pode variar entre as execuções do programa. Portanto, é importante testar várias vezes para garantir a correção do programa em todos os cenários possíveis.

5. Se você tiver problemas para depurar um programa multithread com o GDB, considere usar ferramentas de depuração especializadas em concorrência, como o Helgrind (parte da suíte Valgrind) ou o ThreadSanitizer.



