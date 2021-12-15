/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"
#include "utn.h"
#include "post.h"
#include "filtro.h"

int main(void) {

	setbuf(stdout, NULL);
	char seguir = 's';
	int flag = 0;
	char nombreDelArchivo[50];

	LinkedList *listaPosts = ll_newLinkedList();

	do {

		switch (menu()) {
		case 1:
			if (flag == 0) {
				printf("Ingrese nombre del archivo (posts.csv): ");
				fflush(stdin);
				gets(nombreDelArchivo);
				if (controller_loadFromText(nombreDelArchivo, listaPosts) == 0) {
					flag = 1;
				}
			} else {
				printf(
						"No es posible abrir otro archivo porque sobreescribiría al actual\n");
			}
			break;
		case 2:
			if (flag == 0) {
				printf("Primero debe cargar el archivo\n");
				system("cls");
			} else {
				controller_listPosts(listaPosts);
			}
			break;
		case 3:
			controller_mapEstadisticas(listaPosts, post_asignarEstadisticasAleatorias);
			break;

		case 4:
			archivoMejoresPosteos(listaPosts);
			break;

		case 5:
			archivoHeaters(listaPosts);
			break;
		case 8:
			seguir = 'n';
			break;
		default:
			printf("Opcion invalida\n");
		}

		printf("\nPresione cualquier tecla para continuar...\n");
		fflush(stdin);
		getchar();
	} while (seguir == 's');

	ll_deleteLinkedList(listaPosts);

	return EXIT_SUCCESS;
}
