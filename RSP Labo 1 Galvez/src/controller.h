/*
 * controller.h
 *
 *  Created on: 15 dic. 2021
 *      Author: Tobias Galvez
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char *path, LinkedList *pListaPost);
int controller_listPosts(LinkedList *pListaPost);
int controller_saveAsText(char *path, LinkedList *pListaPost);

int controller_mapEstadisticas(LinkedList *this, int(*pFunc) (void*));

#endif /* CONTROLLER_H_ */
