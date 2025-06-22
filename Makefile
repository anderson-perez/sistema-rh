CC = gcc
TARGET = rh
SOURCE = ./src
INCLUDE = ./INCLUDE
OBJETOS = ./objs

all: obj
	$(CC) $(OBJETOS)/utils.o $(OBJETOS)/menus.o $(OBJETOS)/main.o -o $(TARGET)


obj:
	$(CC) -c $(SOURCE)/utils.c -o $(OBJETOS)/utils.o
	$(CC) -c $(SOURCE)/menus.c -o $(OBJETOS)/menus.o
	$(CC) -c main.c -o $(OBJETOS)/main.o


clear:
	rm $(TARGET)
	rm $(OBJETOS)/*.o
