CC = gcc
CFLAGS = -g 
TARGET = chain
OBJS = chain.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

chain.o: chain.c
	$(CC) $(CFLAGS) -c chain.c

clean:
	/bin/rm -f *.o $(TARGET)