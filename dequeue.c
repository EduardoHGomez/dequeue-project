/*
 * dequeue.c
 *
 *  Created on: 20 mar 2023
 *      Author: jluis
 */
#include "dequeue.h"

DEQUEUE dequeue_create()
{
	/* 
		Función que crea el nodo en memoria dinámica que contiene la información de la cola doblemente terminada.
	*/
}

void dequeue_insr(DEQUEUE d,TYPE e)
{
	/* 
		Función para insertar un nodo en la parte trasera (al final) de la cola doblemente terminada
	*/
}

void dequeue_insf(DEQUEUE d,TYPE e)
{
	/* 
		Función para insertar un nodo al frente (al principio) de la cola doblemente terminada
	*/
}

BOOL dequeue_empty(DEQUEUE d)
{
	/*
		Función que regresa verdadero si la cola doblemente terminada está vacía
	*/
}

int dequeue_size(DEQUEUE d)
{
	/*
		Función que regresa la cantidad de elementos que contiene la cola doblemente terminada
	*/
}

TYPE dequeue_rmf(DEQUEUE d)
{
	/* 
		Función que devuelve el elemento y remueve de la parte frontal de la cola doblemente terminada
	*/
}

TYPE dequeue_rmr(DEQUEUE d)
{
	/* 
		Función que devuelve el elemento y remueve de la parte trasera de la cola doblemente terminada
	*/
}

TYPE dequeue_peekf(DEQUEUE d)
{
	/*
		Función que devuelve el elemento de la parte frontal de la cola doblemente terminada, más no lo remueve
	*/
}

TYPE dequeue_peekr(DEQUEUE d)
{
	/*
		Función que devuelve el elemento de la parte trasera de la cola doblemente terminada, más no lo remueve
	*/
}


void dequeue_destroy(DEQUEUE d)
{
	/* 
		Función que elimina todos los nodos de la cola doblemente terminada, liberando la memoria
	*/
}
