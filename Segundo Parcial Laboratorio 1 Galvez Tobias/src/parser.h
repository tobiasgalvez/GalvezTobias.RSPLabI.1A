/*
 * parser.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Tobias Galvez
 */

#ifndef PARSER_H_
#define PARSER_H_


/**
 * @brief Funcion que permite convertir los datos del archivo a los datos de la estructura
 *
 * @param pFile permite recibir el path
 * @param pArrayListLibro permite recibir lista de peliculas
 * @return int devuelve 0 si salio bien, -1 si salio mal
 */
int parser_peliculaFromText(FILE* pFile , LinkedList* pArrayListPelicula);

#endif /* PARSER_H_ */
