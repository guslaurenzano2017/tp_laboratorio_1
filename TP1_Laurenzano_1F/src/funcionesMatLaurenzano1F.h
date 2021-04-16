/*
 * funcionesMatLaurenzano1F.h
 *
 *  Created on: 16 abr. 2021
 *      Author: Gustavo
 */

#ifndef FUNCIONESMATLAURENZANO1F_H_
#define FUNCIONESMATLAURENZANO1F_H_


/**
 * \brief suma dos numeros flotantes
 * \param resultadoSuma es el puntero donde se guarda el resultado de la suma
 * \param primerOperando es el primer operando
 * \param segundoOperando es el segundo operando
 * \return retorna -1 si no consigue la suma y un 0 si  pudo conseguir la suma
 *
 */
int sumarDosNumeros(float* resultadoSuma,float primerOperando, float segundoOperando);


/**
 * \brief resta dos numeros flotantes
 * \param resultadoResta es el puntero donde se guarda el resultado
 * \param primerOperando es el primer operando
 * \param segundoOperando es el segundo operando
 * \return retorna -1 si no conseguio hacer la resta y un 0 si  consiguio hacer la resta
 *
 */
int restarDosNumeros(float* resultadoResta,float primerOperando, float segundoOperando);


/**
 * \brief multiplica dos numeros flotantes
 * \param resultadoMultiplicacion es el puntero donde se guarda el resultado
 * \param primerOperando es el primer operando
 * \param segundoOperando es el segundo operando
 * \return retorna -1 si no consiguio hacer la multiplicacion y un 0 si  consiguio hacer la multiplicacion
 *
 */
int multiplicarDosNumeros(float* resultadoMultiplicacion,float primerOperando, float segundoOperando);


/**
 * \brief divide dos numeros flotantes
 * \param resultadoDivision es el puntero donde se guarda el resultado
 * \param primerOperando es el primer operando
 * \param segundoOperando es el segundo operando
 * \return retorna -1 si no consigue hacer la division, 0 si consiguio hacer el resultado de la division y -3 si el segundo es igual a 0
 *
 */
int dividirDosNumeros(float* resultadoDivision,float primerOperando, float segundoOperando);


/**
 * \brief obtiene el factorial de un numero entre el 0 y el 30
 * \param primerOperando es el numera al que se le calcula el factorial
 * \return retorna el factorial del numero ingresado
 *
 */
int calcularElfactorial(float operando);



#endif /* FUNCIONESMATLAURENZANO1F_H_ */
