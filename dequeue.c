/*
 * dequeue.c
 *
 *  Created on: 20 mar 2023
 *      Author: jluis
 */
#include "dequeue.h"
#include <stdlib.h>

DEQUEUE dequeue_create()
{
    /* 
	Función que crea el nodo en memoria dinámica que contiene la                 información de la cola doblemente terminada.
	*/
    DEQUEUE new = malloc(sizeof(struct STR_DEQUEUE));
    new->front = NULL;
    new->rear = NULL;
    new->size = 0;
        
    return new;
}

void dequeue_insr(DEQUEUE d,TYPE e)
{
	/* 
		Función para insertar un nodo en la parte trasera (al final) de la cola doblemente terminada
	*/
    struct STR_DEQUEUE_NODE *new = malloc(sizeof(struct STR_DEQUEUE_NODE));
    new->next = NULL;
    new->prior = NULL;
    new->elem = e;

    if (d->front == NULL && d->rear == NULL)
    {
        d->front = new;
        d->rear = new;
        d->size += 1;
    }
    else
    {
        new->next = d->rear;
        
        d->rear->prior = new;
        d->rear = new;
        d->size += 1;
    }
}

void dequeue_insf(DEQUEUE d,TYPE e)
{
	/* 
		Función para insertar un nodo al frente (al principio) de la cola doblemente terminada
	*/
    struct STR_DEQUEUE_NODE *new = malloc(sizeof(struct STR_DEQUEUE_NODE));
    new->next = NULL;
    new->prior = NULL;
    new->elem = e;

    if (d->front == NULL && d->rear == NULL)
    {
        d->front = new;
    }
    else
    {   
        new->prior = d->front;
        
        d->front->next = new; 
        d->front = new;
        d->size += 1;
    }
    
}

BOOL dequeue_empty(DEQUEUE d)
{
	/*
		Función que regresa verdadero si la cola doblemente terminada está vacía
	*/
    if (d->front == NULL && d->rear == NULL)
    {
        return 1;
    }
    return 0;
    
}

int dequeue_size(DEQUEUE d)
{
	/*
		Función que regresa la cantidad de elementos que contiene la cola doblemente terminada
	*/
    return d->size;
}

TYPE dequeue_rmf(DEQUEUE d)
{
	/* 
		Función que devuelve el elemento y remueve de la parte frontal de la cola doblemente terminada
	*/
    struct STR_DEQUEUE_NODE *toremove;

    if (dequeue_empty(d))
    {
        return 0;
    }
    else
    {
        toremove = d->front;
        TYPE elem_to_return = toremove->elem;

        d->front = toremove->prior;
        d->front->next = NULL;
        free(toremove);

        d->size -= 1;
        return elem_to_return;
    }
    
}

TYPE dequeue_rmr(DEQUEUE d)
{
	/* 
		Función que devuelve el elemento y remueve de la parte trasera de la cola doblemente terminada
	*/
    struct STR_DEQUEUE_NODE *toremove = d->rear;

    TYPE elem_to_return = toremove->elem;

    if (dequeue_empty(d))
    {
        return 0;
    }
    else
    {
        d->rear = toremove->next;
        d->rear->prior = NULL;
        free(toremove);
    }
    d->size -= 1;
    return elem_to_return;
}

TYPE dequeue_peekf(DEQUEUE d)
{
	/*
		Función que devuelve el elemento de la parte frontal de la cola doblemente terminada, más no lo remueve
	*/
    return d->front->elem;
}

TYPE dequeue_peekr(DEQUEUE d)
{
	/*
		Función que devuelve el elemento de la parte trasera de la cola doblemente terminada, más no lo remueve
	*/
    return d->rear->elem;
}


void dequeue_destroy(DEQUEUE d)
{
	/* 
		Función que elimina todos los nodos de la cola doblemente terminada, liberando la memoria
	*/
    
    while(!dequeue_empty(d))
        {
            dequeue_rmf(d);
        }
    free(d);
}
