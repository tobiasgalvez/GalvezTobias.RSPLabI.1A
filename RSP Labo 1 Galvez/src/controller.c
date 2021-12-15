/*
 * controller.c
 *
 *  Created on: 15 dic. 2021
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "UTN.h"
#include "post.h"
#include "parser.h"
#include "controller.h"

int controller_loadFromText(char *path, LinkedList *pListaPost) {

	int todoOk = -1;
	FILE *pArchivo;

	if (pListaPost != NULL && path != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo == NULL) {
			printf("Lo sentimos, hubo un error al abrir el archivo\n");

		} else {
			todoOk = 0;
			printf("Ingreso al archivo exitoso!!!");
			parser_postFromText(pArchivo, pListaPost);
			fclose(pArchivo);

		}

	}

	return todoOk;
}

int controller_listPosts(LinkedList *pListaPost) {
	int todoOk = -1;
	ePost *listaPost;

	int cant;

	cant = ll_len(pListaPost);

	printf("Id\tUser\tLikes\tDislikes\tFollowers");

	if (pListaPost != NULL && cant > 0) {

		for (int i = 0; i < cant; i++) {
			listaPost = (ePost*) ll_get(pListaPost, i);
			printf("\n%d\t %s\t %d\t %d\t%d\n", listaPost->id,
					listaPost->user, listaPost->likes,
					listaPost->dislikes, listaPost->followers);
			todoOk = 0;
		}

	}

	return todoOk;
}

int controller_saveAsText(char *path, LinkedList *pListaPost) {
	int todoOk = -1;
	FILE *pArchivo;
	ePost *post;

	int cant;

	cant = ll_len(pListaPost);

	pArchivo = fopen(path, "w");

	if (cant > 0) {
		fprintf(pArchivo, "id,user,likes,dislikes,followers\n");

		for (int i = 0; i < cant; i++) {
			post = ll_get(pListaPost, i);
			fprintf(pArchivo, "%d,%s,%d,%d,%d\n", post->id, post->user,
					post->likes, post->dislikes, post->followers);
			todoOk = 0;

		}
	}

	fclose(pArchivo);
	return todoOk;
}


int controller_mapEstadisticas(LinkedList *this, int(*pFunc) (void*)) {
	int todoOk = -1;
	int tam;

	LinkedList *nuevaLista;
	tam = ll_len(this);

	if (this != NULL) {
		for (int i = 0; i < tam; i++) {
			nuevaLista = ll_map(this, post_asignarEstadisticasAleatorias);

		}
		if (nuevaLista != NULL) {
			controller_listPosts(nuevaLista);
			todoOk = 0;
			printf("\nEstadisticas aplicadas con exito!!!!");
		}

	}
	return todoOk;
}

