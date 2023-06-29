CC = gcc
CFLAGS = -Wall
LEX = flex

lexer: lexer.c
	$(CC) $(CFLAGS) -o lexer lexer.c

lexer.c: lexer.l
	$(LEX) -o lexer.c lexer.l

clean:
	rm -f lexer lexer.c
