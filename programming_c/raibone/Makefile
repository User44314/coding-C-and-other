CC=gcc-14
CFLAG=-std=c11
LOG_FLAG=-DLOG_ON -DLOG_I
DEBUG_FLAG=-g -O0

all: clean rainbow

rainbow: color.o ..|/c/Users/wlight/Documents/coding-C-and-other/programming_c/rainbow.c
	@$(CC) $(CFLAG) $(LOG_FLAG) $(DEBUG_FLAG) $^ -o $@

%.o: ..|/c/Users/wlight/Documents/coding-C-and-other/programming_c/%.c
	@$(CC) $(CFLAG) $(LOG_FLAG) $(DEBUG_FLAG) -c $^ -o $@

clean:
	@rm -f 	*.o
	@rm -f 	*.exe
