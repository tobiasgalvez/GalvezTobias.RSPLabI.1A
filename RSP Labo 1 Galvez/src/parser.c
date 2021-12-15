/*
 * parser.c
 *
 *  Created on: 15 dic. 2021
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"
#include "utn.h"
#include "post.h"




int parser_postFromText(FILE* pFile , LinkedList* pListPost)
{
	int todoOk = -1;
	char id[50];
	char user[50];
	char likes[50];
	char dislikes[50];
	char followers[50];

	int header = 1;
	int cant = 0;

	ePost* auxiliar = NULL;

	if(pFile!=NULL && pListPost!=NULL)
	{
		do
		{
			cant = fscanf(pFile,"%[^,] , %[^,] , %[^,] ,%[^,], %[^\n]\n",id ,user, likes, dislikes,followers);

			if((cant==5) && (header!=1))
			{
				auxiliar = post_newParametros(id,user, likes, dislikes,followers);
				if(auxiliar!=NULL)
				{
					ll_add(pListPost, auxiliar);
					todoOk=0;
				}
				else
				{
					post_delete(auxiliar);
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
