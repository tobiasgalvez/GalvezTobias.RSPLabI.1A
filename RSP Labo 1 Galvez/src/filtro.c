/*
 * filtro.c
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
#include "filtro.h"

int filtroMejoresPosteos(void *pElement) {

	int todoOk = -1;
	ePost *post;
	int likes;

	post = (ePost*) pElement;
	post_getLikes(post, &likes);

	if (likes > 5000) {
		todoOk = 0;
	}
	else
	{
		printf("No hay posteos con más de 5000 likes");
	}
	return todoOk;
}


int filtroPorHeaters(void* pElement)
{
		int todoOk = -1;
		ePost *post;
		int likes;
		int dislikes;

		post = (ePost*) pElement;
		post_getLikes(post, &likes);
		post_getDislikes(post, &dislikes);

		if (dislikes > likes) {
			todoOk = 0;
		}
		else
		{
			printf("No hay posteos con más dislikes que likes");
		}
		return todoOk;
}
