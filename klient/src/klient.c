#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include "funkcje.h"

#define MSG_MAX_LEN 300

int main(int argc, char **argv) {

	int cliFD, port_number;
	struct sockaddr_in c_addr;
	char *msgFromServer;
	char msgToServer[MSG_MAX_LEN];

	if (argc < 3) {
		fprintf(stderr, "Uruchomienie: sudo %s adres_serwera(ip) numer_portu\n",
				argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((cliFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Blad podczas otwierania gniazda \n");
	}

	port_number = atoi(argv[2]);
	memset(&c_addr, 0, sizeof(c_addr));
	c_addr.sin_family = AF_INET;
	c_addr.sin_port = htons(port_number);
	if ((inet_aton(argv[1], &c_addr.sin_addr)) == 0) {

