# cipl

## Autor: Henrique Mendes de Freitas Mariano - 17/0012280

Foi disponibilizado um arquivo makefile para a compilação, mas caso seja necessário compilar de outra forma estes são os comandos (compilando a partir da pasta root):

> $ flex ./src/lex.l
>
> $ bison ./src/bison.y --defines="lib/bison.h"  -Wcounterexamples
>
> $ gcc -o tradutor -O bison.tab.c lex.yy.c src/tree.c src/astcontext.c -Wall -pedantic -Wpedantic -Werror -lm -lfl -g

Para a execução:

> ./tradutor arquivo-teste

## TODO

- [X] Completar gramática
- [X] Estrutura de nó
- [] Árvore sintática abstrata
- [] Lidar com contextos na árvore
- [] Tabela de símbolos