# cipl

## Autor: Henrique Mendes de Freitas Mariano - 17/0012280

Foi disponibilizado um arquivo makefile para a compilação, mas caso seja necessário compilar de outra forma estes são os comandos (compilando a partir da pasta root):

> $ flex ./src/lex.l
>
> $ gcc -o cipllex.out -O lex.yy.c -Wall -pedantic -Wpedantic -Werror -lm -lfl -g

Para a execução:

> ./cipllex.out tests/teste\_correto.txt
>
> ./cipllex.out tests/teste\_correto2.txt
>
> ./cipllex.out tests/teste\_incorreto.txt
>
> ./cipllex.out tests/teste\_incorreto2.txt