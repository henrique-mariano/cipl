VAL=

SRC= ./src

FLEXFILES= $(SRC)/lex.l

BISONFILES= $(SRC)/bison.y

CFILES= bison.tab.c lex.yy.c src/tree.c src/astcontext.c

FLAGS= -Wall -pedantic -Wpedantic -Werror -lm -lfl -g

ifeq ($(OS), Windows_NT)
NAME= tradutor
else
NAME= tradutor
endif

all: flex bison main

bison: $(BISONFILES)
	bison $(BISONFILES) --defines="lib/bison.h" -Wcounterexamples

flex: $(FLEXFILES)
	flex $(FLEXFILES)

main: $(OFILES)
	gcc -o $(NAME) -O $(CFILES) $(FLAGS)
clean:
ifeq ($(OS), Windows_NT)
	rm *.yy.c
	rm *.tab.c
else
	rm *.yy.c
	rm *.tab.c
endif
valgrind:
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="logfile.out" ./tradutor $(VAL)