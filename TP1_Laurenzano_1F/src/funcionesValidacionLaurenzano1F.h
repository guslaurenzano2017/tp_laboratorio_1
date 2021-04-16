/*
 * funcionesValidacionLaurenzano1F.h
 *
 *  Created on: 16 abr. 2021
 *      Author: Gustavo
 */

#ifndef FUNCIONESVALIDACIONLAURENZANO1F_H_
#define FUNCIONESVALIDACIONLAURENZANO1F_H_

/**
 * \brief obtiene un numero flotante
 * \param pResultado  es el puntero donde se guarda el numero obtenido
 * \param mensaje es el mensaje a mostrar
 * \param mensajeError es el mensaje de error
 * \param minimo es el valor minimo aceptado
 * \param maximo es el valor maximo aceptado
 * \param reintentos es la cantidad de reintentos aceptados
 * \return retorna -1 si no lo consigue y retorna 0 si lo consiguio
 *
 */
int pedirNumFloat(float* pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);


/**
 * \brief Obtiene un numero entero
 * \param pResultado es el puntero donde se guarda el el numero obtenido
 * \param mensaje es el mensaje a mostrar
 * \param mensajeError es el mensaje de error
 * \param minimo es el valor minimo aceptado
 * \param maximo es el valor maximo aceptado
 * \param reintentos es la cantidad de reintentos aceptados
 * \return retorna -1 si no lo consigue y retorna 0 si lo consiguio
 *
 */
int pedirNumInt(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);



/**
 * \brief: muestra la opcion de volver al menu presionando una s y luego enter
 * \param: no recibe parametros
 * \return: no retorna ningun valor
 *
 */
void continuar(void);




#endif /* FUNCIONESVALIDACIONLAURENZANO1F_H_ */
