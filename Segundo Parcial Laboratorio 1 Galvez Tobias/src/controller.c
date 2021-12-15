/*
 * controller.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "UTN.h"
#include "peliculas.h"
#include "parser.h"
#include "controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPelicula)
{
	int todoOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPelicula!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_peliculaFromText(pArchivo, pArrayListPelicula))
			{
				printf("Cargado con exito!!!\n");
				todoOk=0;
			}
		}
		else
		{
			printf("Lo sentimos, hubo un error al abrir el archivo\n");
		}

		fclose(pArchivo);
	}

    return todoOk;
}

int controller_listPelicula(LinkedList* pArrayListPelicula)
{
	int todoOk = -1;

	if(pArrayListPelicula!=NULL)
	{
		printf("Lista de Peliculas\n");
		if(pelicula_printList(pArrayListPelicula)!=0)
		{
			printf("No hay peliculas para mostrar");
			todoOk=0;
		}
	}

    return todoOk;
}

int controller_sortPelicula(LinkedList* pArrayListPelicula)
{
	int todoOk = -1;

	LinkedList* clon = NULL;

	if(pArrayListPelicula!=NULL)
	{
		clon = ll_clone(pArrayListPelicula);

		if(clon!=NULL)
		{
			controller_listPelicula(clon);
		}
	}

	return todoOk;
}



int controller_saveAsText(char* path , LinkedList* pArrayListPelicula)
{
	int todoOk = -1;

	int auxId;
	char auxTitulo[50];
	char auxGenero[50];
	float auxDuracion;


	FILE* pArchivo;
	ePelicula* aux = NULL;

	if(path!=NULL && pArrayListPelicula!=NULL)
	{
		pArchivo = fopen(path,"w");

		int tam = ll_len(pArrayListPelicula);

		if(pArchivo!= NULL && tam>0)
		{
			fprintf(pArchivo,"id,titulo,genero,duracion\n");

			for(int i=0; i<tam ;i++)
			{
				aux = (ePelicula*) ll_get(pArrayListPelicula,i);

				if(aux!=NULL)
				{
					if(!pelicula_getVerificacion(aux,&auxId,auxTitulo,auxGenero,&auxDuracion))
					{

						fprintf(pArchivo,"%d,%s,%s,%2.f\n",auxId,auxTitulo,auxGenero,auxDuracion);
						todoOk=0;
					}
					else
					{
						pelicula_delete(aux);
						printf("ERROR, no se pudo guardar el archivo\n");
					}
				}
			}
		}
		else
		{
			printf("Lo sentimos, hubo un error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

	if(!todoOk)
	{
		printf("Archivo guardado con exito!\n");
	}
	return todoOk;
}



int controller_mapDuracion(LinkedList* pArrayListPelicula)
{
	int todoOk = -1;

	if(pArrayListPelicula!=NULL)
	{
		pArrayListPelicula=ll_map(pArrayListPelicula,pelicula_aplicarDuracion);
		printf("Duracion aplicada con exito!!!!");
		todoOk=0;
	}
	return todoOk;
}
