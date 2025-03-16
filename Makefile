CC := gcc
CFLAGS := -I.
DEPS := tictactoe.h

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tictactoe : tictactoe.o
	$(CC) -o tictactoe.exe tictactoe.o

.PHONY : clean

clean :
	rm -f *.o *.exe