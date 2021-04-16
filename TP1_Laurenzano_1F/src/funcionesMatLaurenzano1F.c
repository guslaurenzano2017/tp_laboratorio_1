/*
 * funcionesMatLaurenzano1F.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Gustavo
 */

#include <stdio.h>
#include <stdlib.h>


int sumarDosNumeros(float* resultadoSuma,float primerOperando, float segundoOperando)
{

	float suma;
	int retorno = -1;

	if(resultadoSuma != NULL )
	{

	suma= primerOperando + segundoOperando;
	*resultadoSuma = suma;
	retorno = 0;
	}
	return retorno;
}



int restarDosNumeros(float* resultadoResta,float primerOperando, float segundoOperando)
{
	float resta;
	int retorno = -1;

	resta= primerOperando - segundoOperando;
	*resultadoResta = resta;
	retorno = 0;

	return retorno;
}

int multiplicarDosNumeros(float* resultadoMultiplicacion,float primerOperando, float segundoOperando)
{
	float multiplicacion;
	int retorno = -1;

	if(resultadoMultiplicacion != NULL )
	{

	multiplicacion= primerOperando * segundoOperando;
	*resultadoMultiplicacion = multiplicacion;
	retorno = 0;
	}
	return retorno;

}

int dividirDosNumeros(float* resultadoDivision,float primerOperando, float segundoOperando)
{
	float division;
	int retorno = -1;

	if(resultadoDivision != NULL )
	{
if(segundoOperando==0)
{
retorno = -3;

}
else
{
	division= primerOperando / segundoOperando;
	*resultadoDivision = division;
	retorno = 0;
}
	}
	return retorno;
}

int calcularElfactorial(float operando)
{

float numTest1;
float numTest2;
float resul1;
float resul2;
float dif;
float resultado=0;
numTest1=operando;
numTest2=operando;

  if(operando==0)
    {
    	resultado=1;
        return resultado;
    }
    else
    {
    	resul1=(numTest1 - numTest2);
    	resul2 = (numTest1 - (int)numTest2);
    	dif = resul1 - resul2;
    }
  if(operando >=1  && operando <= 30  && dif==0)
    {
        resultado=operando*calcularElfactorial(operando-1);
       return resultado;
    }
  else
  {
	return -1;
  }
}
















