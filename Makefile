NAME = tcalc
EXE_NAME = $(NAME).exe
C_NAME = $(NAME).c

COMPILER = gcc
FLAGS = -Wall -std=c17

output: $(C_NAME)
	$(COMPILER) $(FLAGS) $^ -o $(EXE_NAME)
run:
	./$(EXE_NAME)

install:
	cp ./$(EXE_NAME) $(HOME)/bin/
