#/usr/bin/bash

gcc -c dice.c -o dice.o
gcc -c creatures.c -o creatures.o
gcc -c equipment.c -o equipment.o

ar rsc libdice.a dice.o
ar rsc libcreatures.a creatures.o
ar rsc libequipment.a equipment.o

gcc main.c -L. -ldice -lcreatures -lequipment