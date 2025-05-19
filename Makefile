CC = gcc
OBJ = main.o dice.o creatures.o equipment.o

%.o: %.c
	$(CC) -c -o $@ $< 

shadowdark: $(OBJ)
	$(CC) -o $@ $^