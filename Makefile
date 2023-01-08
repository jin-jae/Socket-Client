CC=gcc
CFLAGS=-g -Wall
TARGET=client
OBJS=client.o exception.o library.o request.o main.o

all : $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm $(OBJS)
	rm $(TARGET)
