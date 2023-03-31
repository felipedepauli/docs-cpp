```

valgrind --tool=memcheck --leak-check=full
```
There are
- full
- no
- summary
tool=hellgrind

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./executable exampleParam1


Nós podemos ter alguns problemas encontrados pelo Valgrind.

### Invalid read size
Acontece quando se tenta ler algum local da memória que não seja permitido. Motivos pelos quais não se é permitido:
- Memória ainda não alocada
- Espaço da memória menor do que o espaço de leitura (ler mais do que tem permissão)
- Memória já liberada