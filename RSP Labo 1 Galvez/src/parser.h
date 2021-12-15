/*
 * parser.h
 *
 *  Created on: 15 dic. 2021
 *      Author: Tobias Galvez
 */

#ifndef PARSER_H_
#define PARSER_H_


/**
 * @brief Funcion que permite convertir los datos del archivo a los datos de la estructura
 *
 * @param pFile permite recibir el path
 * @param pListPost permite recibir lista de posts
 * @return int devuelve 0 si salio bien, -1 si salio mal
 */
int parser_postFromText(FILE* pFile , LinkedList* pListPost);

#endif /* PARSER_H_ */
