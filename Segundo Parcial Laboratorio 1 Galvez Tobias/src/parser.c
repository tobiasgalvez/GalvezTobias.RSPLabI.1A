/*
 * parser.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"
#include "controller.h"
#include "parser.h"
#include "UTN.h"


int parser_peliculaFromText(FILE* pFile , LinkedList* pArrayListPelicula)
{
	int todoOk = -1;
	char id[50];
	char titulo[50];
	char genero[50];
	char duracion[50];


	int header = 1;
	int cant = 0;

	ePelicula* auxiliar = NULL;

	if(pFile!=NULL && pArrayListPelicula!=NULL)
	{
		do
		{
			cant = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]\n",id,titulo,genero,duracion);

			if((cant==4) && (header!=1))
			{
				auxiliar = pelicula_newParametros(id,titulo,genero,duracion);
				if(auxiliar!=NULL)
				{
					ll_add(pArrayListPelicula, auxiliar);
					todoOk=0;
				}
				else
				{
					pelicula_delete(auxiliar);
				}
			}
			else
			{
				header=0;
			}
		}
		while(!feof(pFile));
	}

    return todoOk;
}
