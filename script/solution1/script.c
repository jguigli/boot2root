#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define FINALFILE "solution"

char *getLastLine(char *filename) {

	FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    long pos = 1; 
    char *line = NULL;
    size_t lineSize = 0;

    fseek(file, -pos, SEEK_END);

    while (ftell(file) > 0) {
        char ch = fgetc(file);
        if (ch == '\n' && pos != 1) { 
            break;
        }
        fseek(file, -++pos, SEEK_END);
    }

    getline(&line, &lineSize, file);

    fclose(file);
    return line;
}

void copyContent(char *file_src, FILE *solution) 
{
	FILE *file = fopen(file_src, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char caractere;
    while ((caractere = fgetc(file)) != EOF) {
        fputc(caractere, solution);
    }
    fputc('\n', solution);

    fclose(file);
}

void createFinalFile(int fileNb)
{
    FILE *file = fopen(FINALFILE, "a");
    if (file == NULL) {
        perror("Error while creating file");
        return;
    }
    char buffer[20];
    for (size_t i = 1; i <= fileNb; ++i)
    {
        sprintf(buffer, "%ld", i);
        copyContent(buffer, file);
    }
    fclose(file);
}

char *recoverFinalFile()
{
    FILE *file;
    char *buffer;
    long size_file;

    file = fopen(FINALFILE, "rb");
    if (file == NULL) {
        perror("Error while opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_file = ftell(file);
    rewind(file);

    buffer = (char *)malloc(size_file);
    if (buffer == NULL) {
        perror("Error allocation");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, size_file, file);
    fclose(file);

    return buffer;
}

void checkReturn(char *password, const char *text) 
{
    const char *resultat = text;

    size_t count = 0;
    while ((resultat = strstr(resultat, "return")) != NULL)
    {
        if (resultat[8])
            password[count++] = resultat[8];
        resultat++;
    }
    password[count] = '\0';
    printf("Le mot de passe est : %s\n", password);
}

void displayHash(char *password)
{
    unsigned char resultat[SHA256_DIGEST_LENGTH];
    char hash[2 * SHA256_DIGEST_LENGTH + 1];
    int i;

    SHA256((const unsigned char *)password, strlen(password), resultat);

    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash + (i * 2), "%02x", resultat[i]);
    }

    hash[2 * SHA256_DIGEST_LENGTH] = '\0';

    printf("Le hachage SHA-256 du mot de passe est : %s\n", hash);
}


int	main(int ac, char **av) {

	char *line;
	int j;
	char num[4];
    size_t fileNb = 0;
    char password[12];
    char *contentFinalFile = NULL;


    if (ac < 2)
    {
        printf("Usage ./a.out *.pcap\n");
        return 1;
    }
	++av;
	for (; *av; ++av)
    {
		line = getLastLine(*av);
		printf("File number: %s\n", line);
        ++fileNb;
		j = 6;
		for (; line[j]; ++j) {

			num[j - 6] = line[j];
		}
		num[j - 6] = '\0';
        free(line);
		rename(*av, num);
	}

    createFinalFile(fileNb);
    contentFinalFile = recoverFinalFile();
    checkReturn(password, contentFinalFile);
    free(contentFinalFile);
    displayHash(password);
	return 0;
}
