#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char *getLastLine(char *filename) {

	FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    long pos = 1; 
    char *line = NULL;
    size_t lineSize = 0;

    // Se placer à la fin du fichier
    fseek(file, -pos, SEEK_END);

    while (ftell(file) > 0) {
        char ch = fgetc(file);
        if (ch == '\n' && pos != 1) {  // Si on trouve un saut de ligne et ce n'est pas la fin du fichier
            break;
        }
        fseek(file, -++pos, SEEK_END);
    }

    // Récupérer la ligne
    getline(&line, &lineSize, file);

    fclose(file);
    return line;
}


int	main(int ac, char **av) {

	char *lastLine;
	int j;
	char num[4];
	++av;
	for (; *av; ++av) {

		lastLine = getLastLine(*av);

		printf("Valeur de lastLine: %s\n", lastLine);
		j = 6;
		for (; lastLine[j]; ++j) {

			num[j - 6] = lastLine[j];
		}
		num[j - 6] = '\0';

		rename(*av, num);
	}
	return 0;
}