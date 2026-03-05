all: sokoban

# Compilation de l'exécutable à partir du fichier .c

sokoban: sokoban.c
	gcc sokoban.c -o sokoban

clean:
	rm -f sokoban *.o *~

mrproper: clean
	rm -f sokoban
