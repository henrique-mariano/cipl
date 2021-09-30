# cipl

## Autor: Henrique Mendes de Freitas Mariano - 17/0012280

Foi disponibilizado um arquivo makefile para a compilação, mas caso seja necessário compilar de outra forma estes são os comandos (compilando a partir da pasta root):

> $ flex ./src/lex.l
>
> $ bison ./src/bison.y --defines="lib/bison.h" -Wcounterexamples -Wother
>
> $ gcc -o tradutor -O src/list.c src/astcontext.c src/tree.c bison.tab.c lex.yy.c -Wall -pedantic -Wpedantic -Werror -lm -lfl -g

Para a execução:

> ./tradutor tests/teste_correto.cipl

## TODO

- [X] Completar gramática
- [X] Estrutura de nó
- [X] Árvore sintática abstrata
- [X] Tabela de símbolos
- [X] Lidar com contextos na árvore
- [X] Escopos
- [X] Redeclaração de variáveis
- [X] Redeclaração de função
- [] Verificar existência de variáveis e funções
- [] Verificar os tipos das variáveis e funções
- [] Tratamento de erros