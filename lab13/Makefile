.PHONY: clean all run

CC = gcc
CFLAGS = -Wall -I./include
TARGET = main
SOURCE_DIR = src/
LIB_NAME = lib_automobil.so

all: $(TARGET)

main.o: $(SOURCE_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/main.c -o main.o

automobil.o: $(SOURCE_DIR)/automobil.c
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/automobil.c -o automobil.o -fPIC

$(LIB_NAME): automobil.o
	$(CC) -shared automobil.o -o $(LIB_NAME)

$(TARGET): main.o $(LIB_NAME)
	$(CC) main.o -o $(TARGET) -L. -lauto -Wl,-rpath,.

clean:
	rm -rf *.o *.so *.a $(TARGET)

run: $(TARGET)
	./$(TARGET)