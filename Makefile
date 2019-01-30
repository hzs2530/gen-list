CC=gcc
SOURCE=test.c gen_list.c
TARGET=test
LDFLAGS=
INCLUDE= -I .
INCLUDE+=-I /usr/local/include
LIBS=-L /usr/local/lib
all:
	$(CC) -std=c99 $(SOURCE) -o $(TARGET) $(LDFLAGS) $(INCLUDE) $(LIBS) 
clean:
	-rm -f *.o
	-rm -f $(TARGET)
