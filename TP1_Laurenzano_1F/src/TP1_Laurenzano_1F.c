/*
 ============================================================================
 Name        : TP1_Laurenzano_1F.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatLaurenzano1F.h"
#include "funcionesValidacionLaurenzano1F.h"

int main(void)
{
	setbuf(stdout,NULL);
	float primerOperando=0;
	float segundoOperando=0;
	int opcion=0;
	int respuesta;
	int respuestaN1;
	int respuestaN2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
    float resultadoDivision;
	int res1;
	int res2;
	int res3;
	int res4;
	float res5;
	float res6;
	char cont;
	int ope1Cargado=0;
	int ope2Cargado=0;
	int  validadorDeCalculos=0;

	while(opcion <=6 || opcion >=0)

	{
	                    printf("=============================================\n");
	                    printf("      TP1 GUSTAVO LAURENZANO 1 F\n");
	                    printf("=============================================\n");
			            printf("1- Ingresar el 1er operando (A= %.2f)",primerOperando);
			            printf("\n2- Ingresar el 2do operando (B= %.2f)",segundoOperando);
			            printf("\n3- Calcular todas las operaciones\n");
			            printf("     A) Calcular la suma (A+B)\n");
			            printf("     B) Calcular la resta (A-B)\n");
			            printf("     C) Calcular la division (A/B)\n");
			            printf("     D) Calcular la multiplicacion (A*B)\n");
			            printf("     E) Calcular el factorial (A!)\n");
			            printf("4- Informar todas las operaciones\n");
			            printf("5- Salir\n");
			            printf("=============================================\n");

		respuesta = pedirNumInt(&opcion, "Ingrese una opcion:\n","\nAdvertencia. Si ingresa 5 u otro numero que no este entre el 1 y el 4 terminara la sesion\n ",1,4,1);
		if (respuesta!=0)
				{
			printf("\nFIN DE LA SESION\n REINICIE EL PROGRAMA PARA VOLVER A UTILIZAR LA CALCULADORA");

			break;
				}

		if (respuesta==0)
		        {
			switch(opcion)
				{

					case 1:
						  respuestaN1 = pedirNumFloat(&primerOperando, "Ingrese el primer operando :\n","Error tiene que ser entre 0 a 100000\n",0,100000,2);
								if (respuestaN1==-1)
									{
									  printf("No se obtubo el primer operando ");
									}
								else
								   {
									ope1Cargado=1;
									continue;
								   }
								break;
							case 2:
								  respuestaN2 = pedirNumFloat(&segundoOperando, "Ingrese el segundo operando :\n","Error tiene que ser de 0 a 100000\n",0,100000,2);
								  if( respuestaN2==-1)
									 {
										printf("No se obtuvo el segundo operando ");
									 }
								  else
									 {
									 ope2Cargado=1;
									 continue;
								     }

								     break;

							case 3:
								   if(ope1Cargado !=1 && ope2Cargado!=1)
								     {
									printf("para calcular los resultados primero debe ingresar una opcion valida en el operando A y el operando B");
									 do
									   {
									    continuar();
								        }
									 while(cont !='s');
									    }
								else
								{
									res1= sumarDosNumeros( &resultadoSuma, primerOperando, segundoOperando);
										if(res1==0)
										   {
										   printf("\n\nA) La suma fue calculada con exito\n");

										   }
										   else
											{
											printf("\nA)La suma no se pudo calcular");
											}

									res2= restarDosNumeros( &resultadoResta, primerOperando, segundoOperando);
										if(res2==0)
											{
											printf("B) La resta fue calculada con exito\n");
											}
											else
											{
											 printf("\nB)La resta no se pudo calcular");
											}


									res4= dividirDosNumeros( &resultadoDivision, primerOperando, segundoOperando);
										if(res4==0)
											{
											printf("D) La division fue calculada con exito\n");
											}
										if(res4==-3)
											{
											printf("D) No se puede dividir un numero por cero\n");
											}
										if(res4!=0 && res4!=-3)
											{
											printf("D)La division no se pudo calcular\n");
											}

									res3= multiplicarDosNumeros( &resultadoMultiplicacion, primerOperando, segundoOperando);
										if(res3==0)
											{
											printf("C) La multiplicacion fue calculada con exito\n");
											}
											else
											{
											printf("\nC)La multiplicacion no se pudo calcular");
											}

									res5=calcularElfactorial(primerOperando);
										 if(res5 >0)
											{
											printf("E) El factorial del primer operando(A) fue calculado con exito\n");
											}
											else
											{
											printf("E)El factorial del primer operando (A) no se pudo calcular\n"
												"Esta maquina calcula factorial de numeros enteros del 1 al 30 solamente\n");
											}

									 res6=calcularElfactorial(segundoOperando);
										if(res6 >0)
											{
											printf("El factorial del segundo operando (B) fue calculado con exito\n");
											}
											else
											{
											printf("El factorial del segundo operando (B) no se pudo calcular\n"
													"Esta maquina calcula factorial de numeros enteros del 1 al 30 solamente\n");
											}

									validadorDeCalculos=1;
											 do
											 {
											 printf("\n\nPara regresar al menu ingrese la letra s (minuscula) y presione enter");
											  fflush(stdin);
											  scanf("%c",&cont);
											  }
											while(cont !='s');
								  }
								   break;
							case 4:
								if(validadorDeCalculos!=1)
								            {
												printf("Para mostrar los resultados primero debe ingresar una opcion valida en el"
												"operando A y el operando B y calcular los resultados con la opcion 3");
												do
												{
												  printf("\n\nPara regresar al menu y cargarlos ingrese la letra s (minuscula) y  presione enter: ");
												  fflush(stdin);
												   scanf("%c",&cont);
												}
											while(cont !='s');
											}
								if(res1==0)
								            {
									       printf("\nA)El resultado de la suma es %.2f\n",resultadoSuma);
								            }
											else
											{
												printf("\nA)El resultado de la suma no se pudo calcular\n");
											}

								if(res2==0)
								            {
									        printf("B)El resultado de la resta es %.2f\n",resultadoResta);
							                }
											else
											{
												printf("B)El resultado de la resta no fue calculado\n");
											}



								if(res4==0)
								            {
									        printf("D)El resultado de la division es %.2f\n",resultadoDivision);
								            }

								if(res4==-3)
								            {
									        printf("D)No se puede dividir un numero por cero\n");
								            }

								if(res4!=0 && res4!=-3)
											{
												printf("D)El resultado de la division no fue calculado\n");
											}

								if(res3==0)
										   {
										    printf("C)El resultado de la multiplicacion es %.2f\n",resultadoMultiplicacion);
										   }
											else
											{
											printf("C)El resultado de la multiplicacion no fue calculado\n");
											}




								if(res5>0)
									        {
									           printf("E)El resultado del factorial del primer operando (A) es %.2f\n",res5);
											}
								             else
								            {
									         printf("E)El resultado del factorial del primer operando (A) no fue calculado. "
											"Esta maquina calcula factorial de numeros enteros del 1 al 30 solamente\n");
								            }
								if(res6>0)
								            {
								            printf("El resultado del factorial del segundo operando (B) es %.2f\n",res6);
											}
								            else
								            {
									        printf("El resultado del factorial del segundo operando(B) no fue calculado. "
										     "Esta maquina calcula factorial de numeros enteros del 1 al 30 solamente\n");
									        }
								           do{
											printf("\n\nPara regresar al menu ingrese la letra s (minuscula) y presione enter ");
											fflush(stdin);
											scanf("%c",&cont);
										 	 }
											while(cont !='s');
								break;
						       }
		 }
	}
	return 0;
}




