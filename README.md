# cipl

## Autor: Henrique Mendes de Freitas Mariano - 17/0012280

Foi disponibilizado um arquivo makefile para a compilação, mas caso seja necessário compilar de outra forma estes são os comandos (compilando a partir da pasta root):

> $ flex ./src/lex.l
>
> $ bison ./src/bison.y --defines="lib/bison.h" -Wother
>
> $ gcc -o tradutor -O src/list.c src/tree.c src/astcontext.c src/symbol.c src/treenode.c src/context.c src/sem_eval.c lex.yy.c bison.tab.c -Wall -pedantic -Wpedantic -Werror -lm -lfl -g -std=gnu11

Para a execução:

> ./tradutor tests/teste_correto.cipl

## TODO

- [X] Completar gramática
- [X] Estrutura de nó
- [X] Árvore sintática abstrata
- [X] Tabela de símbolos
- [X] Lidar com contextos na árvore
- [X] Escopos
- [X] Tratamento de erros sintáticos
- [X] Tratamento de erros semânticos
- [X] Redeclaração de funções
- [X] Redeclaração de variáveis
- [X] Redeclaração de parâmetros
- [X] Verificar existência de variáveis e funções
- [X] Verificar existência da main
- [X] Verificar se a main não possui parâmetros
- [X] Verificar se a main retorna int
- [X] Verificar os tipos das variáveis e funções
- [X] Verificar tipos nas aritméticas
- [X] Verificar tipo de retorno da função
- [] Verificar os returns das funções
- [] Geração de código
- [X] Operações binárias
- [X] Impressão de string
- [X] Declaração de variável
- [] Declaração de função
- [X] Built-in
- [] Tipo de lista
- [] Operadores binários de lista
- [] Operadores unários de lista
- [] Operadores unários aritiméticos
- [] Chamada de função
- [] return
- [] variaveis globais
