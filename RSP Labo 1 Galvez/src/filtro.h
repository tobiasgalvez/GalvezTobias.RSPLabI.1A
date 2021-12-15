/*
 * filtro.h
 *
 *  Created on: 15 dic. 2021
 *      Author: Tobias Galvez
 */

#ifndef FILTRO_H_
#define FILTRO_H_


/** \brief Filtra lista con los mejores posteos (+ de 5000 likes)
 *
 *  \param void *pElement
 *  \return LinkedList* Retorna -1 si no consiguió ningún posteo con + de 5000 likes o retorna 0 si consiguió
 */
int filtroMejoresPosteos(void* pElement);
/** \brief Filtra lista por heaters (+ dislikes que likes)
 *
 *  \param void *pElement
 *  \return LinkedList* Retorna -1 si no consiguió ningún posteo con + dislikes que likes o retorna 0 si consiguió
 */
int filtroPorHeaters(void* pElement);

#endif /* FILTRO_H_ */
