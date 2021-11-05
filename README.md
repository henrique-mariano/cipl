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

- [x] Completar gramática
- [x] Estrutura de nó
- [x] Árvore sintática abstrata
- [x] Tabela de símbolos
- [x] Lidar com contextos na árvore
- [x] Escopos
- [x] Tratamento de erros sintáticos
- [x] Tratamento de erros semânticos
- [x] Redeclaração de funções
- [x] Redeclaração de variáveis
- [x] Redeclaração de parâmetros
- [x] Verificar existência de variáveis e funções
- [x] Verificar existência da main
- [x] Verificar se a main não possui parâmetros
- [x] Verificar se a main retorna int
- [x] Verificar os tipos das variáveis e funções
- [x] Verificar tipos nas aritméticas
- [x] Verificar tipo de retorno da função
- [] Verificar os returns das funções
- [] Geração de código
- [x] Operadores binários aritiméticos
- [x] Impressão de string
- [x] Declaração de variável
- [] Declaração de função
- [x] Built-in
- [] Tipo de lista
- [] Operadores binários de lista
- [] Operadores unários de lista
- [] Operadores unários aritiméticos
- [] Chamada de função
- [] Return
- [] Variáveis globais
