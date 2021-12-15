/*
 * peliculas.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Tobias Galvez
 */

#ifndef PELICULAS_H_
#define PELICULAS_H_

typedef struct
{
	int id;
	char titulo[50];
	char genero[50];
	float duracion;
}ePelicula;



int menu();
/**
 * @brief Funcion que permite guardar id en la estructura
 *
 * @param this
 * @param id
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_setId(ePelicula* this, int id);
/**
 * @brief Funcion que permite guardar el titulo en la estructura
 *
 * @param this
 * @param titulo
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_setTitulo(ePelicula* this, char* titulo);
/**
 * @brief Funcion que permite guardar el genero en la estructura
 *
 * @param this
 * @param genero
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_setGenero(ePelicula* this, char* genero);
/**
 * @brief Funcion que permite guardar duracion en la estructura
 *
 * @param this
 * @param duracion
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_setDuracion(ePelicula* this, float duracion);
/**
 * @brief Funcion que permite devolver a traves de un puntero el id
 *
 * @param this
 * @param id
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_getId(ePelicula* this, int* id);
/**
 * @brief Funcion que permite devolver a traves de un puntero el titulo
 *
 * @param this
 * @param titulo
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_getTitulo(ePelicula* this, char* titulo);
/**
 * @brief Funcion que permite devolver a traves de un puntero el genero
 *
 * @param this
 * @param titulo
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_getGenero(ePelicula* this, char* genero);
/**
 * @brief Funcion que permite devolver a traves de un puntero la duracion
 *
 * @param this
 * @param id
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_getDuracion(ePelicula* this, float* duracion);
/**
 * @brief Funcion que permite verificar si los setters en formato char estan correctos
 *
 * @param this
 * @param idStr
 * @param tituloStr
 * @param generoStr
 * @param duracionStr
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_setVerificacionCaracter(ePelicula* this, char* idStr, char* tituloStr, char* generoStr, char* duracionStr);
/**
 * @brief Funcion que permite verificar que los setters con los valores de estructura esten bien
 *
 * @param this
 * @param id
 * @param titulo
 * @param genero
 * @param duracion
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_setVerificacionEntero(ePelicula* this, int id, char* titulo, char* genero, float duracion);
/**
 * @brief Funcion que permite verificar que las funciones "get" esten correctas
 *
 * @param this
 * @param id
 * @param titulo
 * @param genero
 * @param duracion
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_getVerificacion(ePelicula* this, int* id, char* titulo, char* genero, float* duracion);
/**
 * @brief Funcion que permite crear espacio en memoria para la lista e inicializar en cero la estructura
 *
 * @return puntero
 */
ePelicula* pelicula_new();
/**
 * @brief Funcion que permite crear  espacio en memoria con pelicula_new y utiliza las funciones "set" para los valores que se ingresan por parametros
 *
 * @param idStr char
 * @param tituloStr char
 * @param generoStr char
 * @param duracionStr char
 * @return puntero
 */
ePelicula* pelicula_newParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr);
/**
 * @brief Funcion que permite liberar memoria a traves de un "free()"
 *
 * @param this puntero al elemento
 */
void pelicula_delete(ePelicula* this);
/**
 * @brief Funcion que permite aplicar la nueva duracion de la pelicula
 *
 * @param peliculas
 */
void* pelicula_aplicarDuracion(void* peliculas);
/**
 * @brief Funcion que permite mostrar una pelicula
 *
 * @param this
 * @return 0 si esta bien, -1 si esta mal
 */
int pelicula_printOnePelicula(ePelicula* this);
/**
 * @brief Funcion que permite mostrar una lista de peliculas
 *
 * @param lista
 * @return 0 si esta bien, -1 si esta mal
 */

int pelicula_printList(LinkedList* lista);


#endif /* PELICULAS_H_ */
