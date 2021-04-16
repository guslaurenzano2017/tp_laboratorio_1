/*
 * funcionesValidacionLaurenzano1F.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Gustavo
 */

#include <stdio.h>
#include <stdlib.h>




int pedirNumFloat(float* pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float auxFloat;
	if( minimo <= maximo && reintentos >= 0)
	{
		do

		{
			printf("%s",mensaje);
			scanf("%f",&auxFloat);
			if(auxFloat >= minimo && auxFloat <= maximo)
			{
				*pResultado = auxFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}




int pedirNumInt(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int auxInt;
	if(minimo <= maximo && reintentos >= 0)
	{
		do

		{
			printf("%s",mensaje);
			scanf("%d",&auxInt);
			if(auxInt >= minimo && auxInt <= maximo)
			{
				*pResultado = auxInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

void continuar(void)
{
	char cont;
	printf("\n\nPara regresar al menu y cargarlos ingrese la letra s (minuscula) y  presione enter");
	fflush(stdin);
	scanf("%c",&cont);
}



