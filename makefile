SRC= ./src

FLEXFILES= $(SRC)/lex.l

BISONFILES= $(SRC)/bison.y

CFILES= bison.tab.c lex.yy.c

FLAGS= -Wall -pedantic -Wpedantic -Werror -lm -lfl -g

ifeq ($(OS), Windows_NT)
NAME= tradutor
else
NAME= tradutor
endif

all: bison flex main

bison: $(BISONFILES)
	bison $(BISONFILES) --defines="lib/bison.h"


flex: $(FLEXFILES)
	flex $(FLEXFILES)

main: $(OFILES)
	gcc -o $(NAME) -O $(CFILES) $(FLAGS)
clean:
ifeq ($(OS), Windows_NT)
	rm *.yy.c
else
	rm *.yy.c
	rm *.tab.c
endif