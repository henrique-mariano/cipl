VAL=

SRC= ./src

FLEXFILES= $(SRC)/lex.l

BISONFILES= $(SRC)/bison.y

CFILES= src/list.c src/tree.c src/astcontext.c src/symbol.c lex.yy.c bison.tab.c

FLAGS= -Wall -pedantic -Wpedantic -Werror -lm -lfl -g

NAME= tradutor

PATH_TO_FILE= lex.yy.c

ifneq ("$(wildcard $(PATH_TO_FILE))","")
    FILE_EXISTS = 1
else
    FILE_EXISTS = 0
endif

all: flex bison main

bison: $(BISONFILES)
	bison $(BISONFILES) --defines="lib/bison.h" -Wcounterexamples -Wother

flex: $(FLEXFILES)
	flex $(FLEXFILES)

main: $(OFILES)
	gcc -o $(NAME) -O $(CFILES) $(FLAGS)

move:
ifeq ($(FILE_EXISTS), 1)
	mv lex.yy.c src/lex.yy.c
	mv bison.tab.c src/bison.tab.c
endif

clean:
ifeq ($(OS), Windows_NT)
	rm *.yy.c
	rm *.tab.c
else
	rm *.yy.c
	rm *.tab.c
endif

valgrind: $(VAL)
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="logfile.out" ./tradutor $(VAL)