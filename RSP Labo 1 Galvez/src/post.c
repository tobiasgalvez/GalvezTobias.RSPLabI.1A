/*
 * post.c
 *
 *  Created on: 15 dic. 2021
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "LinkedList.h"
#include "post.h"
#include "filtro.h"

int menu() {
	int opcion;

	printf("\n***************MENU*********************\n");

	printf("1. Cargar Archivo\n");
	printf("2. Imprimir Lista\n");
	printf("3. Asignar Estadisticas\n");
	printf("4. Filtrar por los mejores posteos\n");
	printf("5. filtrar por heaters\n");
	printf("6. Ordenar por nivel de cantidad de followers\n");
	printf("7. Mostrar más popular: \n");
	printf("8. Salir");

	utn_getEntero(&opcion, 2, "\nIngrese una opcion:",
			"\nERROR, no es una opcion valida", 1, 8);

	return opcion;
}

//SETTERS

int post_setId(ePost *this, int id) {
	int todoOk = -1;

	if (this != NULL && id > 0) {
		this->id = id;
		todoOk = 0;
	}

	return todoOk;
}

int post_setUser(ePost *this, char *user) {
	int todoOk = -1;

	if (this != NULL && user != NULL) {
		strcpy(this->user, user);
		todoOk = 0;
	}

	return todoOk;
}

int post_setLikes(ePost *this, int likes) {
	int todoOk = -1;

	if (this != NULL && likes > 0) {
		this->likes = likes;
		todoOk = 0;
	}

	return todoOk;
}

int post_setDislikes(ePost *this, int dislikes) {
	int todoOk = -1;

	if (this != NULL && dislikes > 0) {
		this->dislikes = dislikes;
		todoOk = 0;
	}

	return todoOk;
}

int post_setFollowers(ePost *this, int followers) {
	int todoOk = -1;

	if (this != NULL && followers > 0) {
		this->followers = followers;
		todoOk = 0;
	}

	return todoOk;
}
//GETTERSS

int post_getId(ePost *this, int *id) {
	int todoOk = -1;

	if (this != NULL && id != NULL) {
		*id = this->id;
		todoOk = 0;
	}

	return todoOk;
}
int post_getUser(ePost *this, char *user) {
	int todoOk = -1;

	if (this != NULL && user != NULL) {
		strcpy(user, this->user);
		todoOk = 0;
	}

	return todoOk;
}

int post_getLikes(ePost *this, int *likes) {
	int todoOk = -1;

	if (this != NULL && likes != NULL) {
		*likes = this->likes;
		todoOk = 0;
	}

	return todoOk;
}

int post_getDislikes(ePost *this, int *dislikes) {
	int todoOk = -1;

	if (this != NULL && dislikes != NULL) {
		*dislikes = this->dislikes;
		todoOk = 0;
	}

	return todoOk;
}

int post_getFollowers(ePost *this, int *followers) {
	int todoOk = -1;

	if (this != NULL && followers != NULL) {
		*followers = this->followers;
		todoOk = 0;
	}

	return todoOk;
}
ePost* post_new() {
	ePost *pPost = NULL;

	pPost = (ePost*) malloc(sizeof(ePost));

	return pPost;
}

ePost* post_newParametros(char *idStr, char *userStr, char *likesStr,
		char *dislikesStr, char *followersStr) {
	ePost *pPostParametros = NULL;
	int auxId;
	int auxLikes;
	int auxDislikes;
	int auxFollowers;

	if (idStr != NULL && userStr != NULL && likesStr != NULL
			&& dislikesStr != NULL && followersStr != NULL) {
		auxId = atoi(idStr);
		auxLikes = atoi(likesStr);
		auxDislikes = atoi(dislikesStr);
		auxFollowers = atoi(followersStr);
		pPostParametros = post_new();

		if (pPostParametros != NULL) {
			post_setId(pPostParametros, auxId);
			post_setUser(pPostParametros, userStr);
			post_setLikes(pPostParametros, auxLikes);
			post_setDislikes(pPostParametros, auxDislikes);
			post_setFollowers(pPostParametros, auxFollowers);
		}
	}

	return pPostParametros;
}

void post_delete(ePost *this) {
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

int post_asignarEstadisticasAleatorias(void *pElement) {

	int todoOk = -1;
	ePost *post = NULL;

	srand(time(NULL));

	if (pElement != NULL) {
		post = (ePost*) pElement;

		post_setLikes(post, rand() % (3000 - 500 + 1) + 500);
		post_setDislikes(post, rand() % (3500 - 300 + 1) + 300);
		post_setFollowers(post, rand() % (20000 - 10000 + 1) + 10000);
		todoOk = 0;
	}

	return todoOk;

}

int archivoMejoresPosteos(LinkedList *listaPost) {

	int todoOk = -1;
	LinkedList *nuevaLista = ll_newLinkedList();

	nuevaLista = ll_filter(listaPost, filtroMejoresPosteos);

	if (controller_saveAsText("mejoresPosteos.csv", nuevaLista) == 0) {
		todoOk = 0;
	}

	printf("\n Archivo generado!!! \n");
	return todoOk;
}

int archivoHeaters(LinkedList *listaPost) {

	int todoOk = -1;
	LinkedList *nuevaLista = ll_newLinkedList();

	nuevaLista = ll_filter(listaPost, filtroPorHeaters);

	if (controller_saveAsText("heaters.csv", nuevaLista) == 0) {
		todoOk = 0;
	}

	printf("\n Archivo generado!!! \n");
	return todoOk;
}



