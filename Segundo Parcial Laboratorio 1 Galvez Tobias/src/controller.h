/*
 * controller.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Tobias Galvez
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H



/** \brief Controla la carga de datos de las peliculas desde el archivo en modo texto.
 *
 * \param path char* nombre del archivo
 * \param pArrayListPelicula LinkedList* lista de peliculas
 * \return int devuelve 0 si salio bien, -1 si salio mal
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPelicula);
/**
 * @brief Controla el funcionamiento de la lista
 *
 * @param pArrayListPelicula lista de peliculas
 * @return int devuelve 0 si salio bien, -1 si salio mal
 */
int controller_listPelicula(LinkedList* pArrayListPelicula);
/**
 * @brief Controla que el ordenamiento este funcionando
 *
 * @param pArrayListPelicula recibe lista de peliculas
 * @return int devuelve 0 si salio bien, -1 si salio mal
 */
int controller_sortPelicula(LinkedList* pArrayListPelicula);
/** \brief Controla el guardado de datos de las peliculas en el archivo en modo texto.
 *
 * \param path char* nombre del archivo
 * \param pArrayListPelicula LinkedList* lista de peliculas
 * \return int devuelve 0 si salio bien,-1 si salio mal
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPelicula);
/**
 * @brief Controla que la funcion ll_map asigne la nueva duracion
 *
 * @param pArrayListPelicula lista de peliculas
 * @return int devuelve 0 si salio bien,-1 si salio mal
 */
int controller_mapDuracion(LinkedList* pArrayListPelicula);



#endif /* CONTROLLER_H_ */
