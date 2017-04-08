/*
int readlink(char *path, char *buffer, int bufferSize);

readlink() place le contenu du lien symbolique qui s'applique à ‘path’ dans le tampon ‘buffer’ qui a une taille de ‘bufferSize’. Les contenus des liens ne se terminent pas par le caractère nul. La valeurs de retour est le nombre de caractères placés dans le tampon ‘buffer’ en cas de succès. En cas d'échec, la valeur -1 est renvoyé et affecte ‘errno’ pour indiquer l'erreur.

Example d’utilisation de de readlink(): on affiche le lien qui s'applique au fichier "Include ».
*/

#include <stdio.h>
#include <errno.h>

char *path = "include";

#define SYS_ERR -1
#define BUFFERSIZE 256

int main() {
	char buffer[BUFFERSIZE];
	int cc;
	if ((cc = readlink(path, buffer, BUFFERSIZE)) == SYS_ERR) {
		printf("Error number %d\n", errno);
		perror(readlink);
		exit(1);
	}
	buffer[cc] = '\0';
	puts(buffer);
return 0;
}
