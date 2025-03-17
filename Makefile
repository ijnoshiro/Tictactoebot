CC = gcc
CFLAGS = -Wall -I.
DEBUGFLAGS = -oo -g
TARGET = tictactoe.exe
SRC = tictactoe.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)
	

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c tictactoe.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.exe
