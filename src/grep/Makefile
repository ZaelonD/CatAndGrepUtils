COMP = gcc
FLAG = -Wall -Werror -Wextra -std=c11

all: linters s21_grep clean_files

rebuild: clean 
	make all

s21_grep: functions.o flags_functions.o
	$(COMP) $(FLAG) s21_grep.c functions.o flags_functions.o -o s21_grep

functions.o: functions.c functions.h flags.h flags_functions.h
	$(COMP) $(FLAG) -c functions.c

flags_functions.o: flags_functions.c flags_functions.h
	$(COMP) $(FLAG) -c flags_functions.c

clean: 
	rm -rf *.o s21_grep

clean_files:
	rm -rf *.o

test:
	bash test_grep.sh

linters:
	clang-format -style=Google -i *.c *.h

leaks:
	leaks -atExit -- ./s21_grep -nsET test.txt