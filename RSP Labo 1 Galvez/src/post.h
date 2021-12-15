/*
 * post.h
 *
 *  Created on: 15 dic. 2021
 *      Author: Tobias Galvez
 */

#ifndef POST_H_
#define POST_H_

typedef struct
{
	int id;
	char user[20];
	int likes;
	int dislikes;
	int followers;
}ePost;


int menu();
/**
 * @brief Funcion que permite guardar id en la estructura
 *
 * @param this
 * @param id
 * @return 0 si esta bien, -1 si esta mal
 */
int post_setId(ePost *this, int id);
/**
 * @brief Funcion que permite guardar el usuario en la estructura
 *
 * @param this
 * @param user
 * @return 0 si esta bien, -1 si esta mal
 */
int post_setUser(ePost *this, char *user);
/**
 * @brief Funcion que permite guardar likes en la estructura
 *
 * @param this
 * @param user
 * @return 0 si esta bien, -1 si esta mal
 */
int post_setLikes(ePost *this, int likes);
/**
 * @brief Funcion que permite guardar dislikes en la estructura
 *
 * @param this
 * @param dislikes
 * @return 0 si esta bien, -1 si esta mal
 */
int post_setDislikes(ePost *this, int dislikes);
/**
 * @brief Funcion que permite guardar seguidores en la estructura
 *
 * @param this
 * @param followers
 * @return 0 si esta bien, -1 si esta mal
 */
int post_setFollowers(ePost *this, int followers);
/**
 * @brief Funcion que permite devolver a traves de un puntero el id
 *
 * @param this
 * @param id
 * @return 0 si esta bien, -1 si esta mal
 */
int post_getId(ePost *this, int *id);
/**
 * @brief Funcion que permite devolver a traves de un puntero el usuario
 *
 * @param this
 * @param user
 * @return 0 si esta bien, -1 si esta mal
 */
int post_getUser(ePost *this, char *user);
/**
 * @brief Funcion que permite devolver a traves de un puntero los likes
 *
 * @param this
 * @param likes
 * @return 0 si esta bien, -1 si esta mal
 */
int post_getLikes(ePost *this, int *likes);
/**
 * @brief Funcion que permite devolver a traves de un puntero los dislikes
 *
 * @param this
 * @param dislikes
 * @return 0 si esta bien, -1 si esta mal
 */
int post_getDislikes(ePost *this, int *dislikes);
/**
 * @brief Funcion que permite devolver a traves de un puntero los seguidores
 *
 * @param this
 * @param seguidores
 * @return 0 si esta bien, -1 si esta mal
 */
int post_getFollowers(ePost *this, int *followers);
/**
 * @brief Funcion que permite crear espacio en memoria para la lista e inicializar en cero la estructura
 *
 * @return puntero
 */

ePost* post_new();
/**
 * @brief Funcion que permite crear  espacio en memoria con pelicula_new y utiliza las funciones "set" para los valores que se ingresan por parametros
 *
 * @param idStr char
 * @param userStr char
 * @param likesStr char
 * @param dislikesStr char
 * @param followersStr char
 * @return puntero
 */
ePost* post_newParametros(char *idStr, char *userStr, char *likesStr,
		char *dislikesStr, char* followersStr);
/**
 * @brief Funcion que permite liberar memoria a traves de un "free()"
 *
 * @param this puntero al elemento
 */
void post_delete(ePost *this);

int post_asignarEstadisticasAleatorias(void *pElement);



#endif /* POST_H_ */
