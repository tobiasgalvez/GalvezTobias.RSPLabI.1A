/*
 * peliculas.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "UTN.h"
#include "LinkedList.h"
#include "peliculas.h"

int menu()
{
	int opcion;

		printf("\n***************MENU*********************\n");
		printf("1. Cargar Archivo\n");
		printf("2. Imprimir Lista\n");
		printf("3. Asignar Tiempos\n");
		printf("4. Filtrar por tipo\n");
		printf("5. Mostrar duraciones\n");
		printf("6. Guardar Peliculas\n");
		printf("7. Salir");

		utn_getEntero(&opcion, 2, "Ingrese una opcion", "ERROR, no es una opcion valida", 1, 7);

		return opcion;
}



int pelicula_setId(ePelicula* this, int id)
{
	int todoOk = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		todoOk=0;
	}

	return todoOk;
}

int pelicula_setTitulo(ePelicula* this, char* titulo)
{
	int todoOk = -1;

	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo,titulo);
		todoOk=0;
	}

	return todoOk;
}

int pelicula_setGenero(ePelicula* this, char* genero)
{
	int todoOk = -1;

	if(this!=NULL && genero!=NULL)
	{
		strcpy(this->genero, genero);
		todoOk=0;
	}

	return todoOk;
}

int pelicula_setDuracion(ePelicula* this, float duracion)
{
	int todoOk = -1;

	if(this!=NULL && duracion>0)
	{
		this->duracion = duracion;
		todoOk=0;
	}

	return todoOk;
}



int pelicula_getId(ePelicula* this, int* id)
{
	int todoOk = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		todoOk=0;
	}

	return todoOk;
}
int pelicula_getTitulo(ePelicula* this, char* titulo)
{
	int todoOk = -1;

	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo,this->titulo);
		todoOk=0;
	}

	return todoOk;
}

int pelicula_getGenero(ePelicula* this, char* genero)
{
	int todoOk = -1;

	if(this!=NULL && genero!=NULL)
	{
		strcpy(genero,this->genero);
		todoOk=0;
	}

	return todoOk;
}

int pelicula_getDuracion(ePelicula* this, float* duracion)
{
	int todoOk = -1;

	if(this!=NULL && duracion!=NULL)
	{
		*duracion = this->duracion;
		todoOk=0;
	}

	return todoOk;
}


int pelicula_setVerificacionCaracter(ePelicula* this, char* idStr, char* tituloStr, char* generoStr, char* duracionStr)
{
	int todoOk = -1;

	if(this!=NULL && idStr!=NULL && tituloStr!=NULL && generoStr!=NULL && duracionStr!=NULL)
	{
		if((!(pelicula_setId(this,atoi(idStr))) &&
			!(pelicula_setTitulo(this,tituloStr)) &&
			!(pelicula_setGenero(this,generoStr)) &&
			!(pelicula_setDuracion(this,atof(duracionStr)))))
		{
			todoOk=0;
		}
	}

	return todoOk;
}

int pelicula_setVerificacionEntero(ePelicula* this, int id, char* titulo, char* genero, float duracion)
{
	int todoOk = -1;

	if(this!=NULL && id>0 && titulo!=NULL && genero!=NULL && duracion>0)
	{
		if((!(pelicula_setId(this,id)) &&
			!(pelicula_setTitulo(this,titulo)) &&
			!(pelicula_setGenero(this,genero)) &&
			!(pelicula_setDuracion(this,duracion))))
		{
			todoOk=0;
		}
	}

	return todoOk;
}

int pelicula_getVerificacion(ePelicula* this, int* id, char* titulo, char* genero, float* duracion)
{
	int todoOk = -1;

	if(this!=NULL && id!=NULL && titulo!=NULL && genero!=NULL && duracion!=NULL)
	{
		if((!(pelicula_getId(this,id)) &&
			!(pelicula_getTitulo(this,titulo)) &&
			!(pelicula_getGenero(this,genero)) &&
			!(pelicula_getDuracion(this,duracion))))
		{
			todoOk=0;
		}
	}

	return todoOk;
}


ePelicula* pelicula_new()
{
	ePelicula* pPelicula = NULL;
	int id;
	char titulo[50];
	char genero[50];
	float duracion;


	id=0;
	strcpy(titulo,"\0");
	strcpy(genero,"\0");
	duracion=0;
	//INICIALIZO TODO EN 0

	pPelicula = (ePelicula*) malloc(sizeof(ePelicula));

	if(pPelicula!=NULL)
	{
		pelicula_setVerificacionEntero(pPelicula,id,titulo,genero,duracion);
	}

	return pPelicula;
}


ePelicula* pelicula_newParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr)
{
	ePelicula* pPeliculaParametros = NULL;

	if(idStr!=NULL && tituloStr!=NULL && generoStr!=NULL && duracionStr!=NULL)
	{
		pPeliculaParametros = pelicula_new();

		if(pPeliculaParametros!=NULL)
		{
			if((pelicula_setVerificacionCaracter(pPeliculaParametros,idStr,tituloStr,generoStr,duracionStr))!=0)
			{
				pelicula_delete(pPeliculaParametros);
			}
		}
	}

	return pPeliculaParametros;
}


void pelicula_delete(ePelicula* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}


void* pelicula_aplicarDuracion(void* peliculas)
{
	ePelicula* pElement = NULL;
	int auxId;
	float nuevaDuracion;



	int min = 100;
	int max = 240;

	srand(time(NULL));

	nuevaDuracion = rand() % (max - min +1) + min;

	if(peliculas!=NULL)
	{
		pElement= (ePelicula*) peliculas;
		if(!pelicula_getId(pElement,&auxId))
		{
			pelicula_setDuracion(pElement,nuevaDuracion);
		}
	}

	return pElement;
}



int pelicula_printOnePelicula(ePelicula* this)
{
	int todoOk = -1;
	int auxId;
	char auxTitulo[50];
	char auxGenero[50];
	float auxDuracion;


	if(this!=NULL)
	{
		if(!pelicula_getVerificacion(this,&auxId,auxTitulo,auxGenero,&auxDuracion))
		{

			printf("%d\t\t%s\t%s\t\t%.2f\n",auxId
										   ,auxTitulo
										   ,auxGenero
										   ,auxDuracion);

			todoOk=0;
		}
		else
		{
			printf("Error al intentar mostrar la pelicula");
		}
	}

	return todoOk;
}


int pelicula_printList(LinkedList* lista)
{
	int todoOk = -1;
	ePelicula* aux = NULL;
		int tam = ll_len(lista);

	if(lista!=NULL && tam > 0)
	{
			printf(" ********************************LISTA DE PELICULAS*****************************\n");
			printf("\n ID                      TITULO               GENERO                   DURACION \n");

			for(int i=0; i<tam ;i++)
			{
				aux = (ePelicula*) ll_get(lista,i);

				if(aux != NULL)
				{
					pelicula_printOnePelicula(aux);
					todoOk=0;
				}
			}

	}

	return todoOk;
}
