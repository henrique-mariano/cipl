SRC= ./src

FLEXFILES= $(SRC)/lex.l

CFILES= lex.yy.c

FLAGS= -Wall -pedantic -Wpedantic -Werror -lm -lfl -g

ifeq ($(OS), Windows_NT)
NAME= cipllex
else
NAME= cipllex.out
endif

all: flex main

flex: $(FLEXFILES)
	flex $(FLEXFILES)

main: $(OFILES)
	gcc -o $(NAME) -O $(CFILES) $(FLAGS)
clean:
ifeq ($(OS), Windows_NT)
	rm *.yy.c
else
	rm *.yy.c
endif