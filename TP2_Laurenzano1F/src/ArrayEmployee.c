/*
 * ArrayEmployee.c
 *
 *  Created on: 15 may. 2021
 *      Author: Gustavo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"
#include "validaciones.h"

#define TRUE 0
#define FALSE -1

static int generarNextId()
{
    static int id = 0;
    id ++;
    return id;
}

int initEmployees(eEmployee* lista, int len)
{
    int i;
    int retorno=FALSE;
    if( lista != NULL )
    {
        for(i=0; i<len ; i ++)
        {
            lista[i].isEmpty=1;
        }
        retorno = TRUE;
    }

    return retorno;

}

int buscarLugarLibre(eEmployee* lista, int len)
{
    int i;
    int retorno=FALSE;
    if(lista!=NULL)
    {
        for(i=0; i<len ; i ++)
        {
            if(lista[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;

}


int menuDeOpciones()
{
    int opcion;

    printf("*****TP2 Laurenzano*****\n\n");
    printf("*****MENU*****\n\n");
    printf("1- Alta de Empleado\n");
    printf("2- Modifica el empleado\n");
    printf("3- Baja del empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n");
    printf("6- Hardcodeo para prueba\n");
    opcion=getValidInt("Ingrese una opcion:\n","Error,ingrese un numero del 1 al 6\n", 1, 6);
    return opcion;

}

int mostrarUnEmpleado(eEmployee* lista, int indice)
{
    int retorno=FALSE;
    if(lista!=NULL)
    {
        if(lista[indice].isEmpty == 0)
        {
            printf("%d\t    %s\t    %s\t    %f\t    %d \n",lista[indice].id, lista[indice].name, lista[indice].lastName, lista[indice].salary, lista[indice].sector);
            retorno=TRUE;
        }

    }
    return retorno;
}


int printEmployees(eEmployee* lista, int len)
{
    int retorno=FALSE;
    int i;
    if(lista!= NULL)
    {
        printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
        for( i=0; i<len ; i ++ )
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarUnEmpleado(lista, i);
                retorno=TRUE;
            }
        }
    }
    return retorno;
}



int addEmployee(eEmployee* lista, int len, int id, char name[],char lastName[],float salary,int sector)
{
    eEmployee auxEmpleado;
    int lugarLibre=buscarLugarLibre(lista, len);
    int retorno=FALSE;

    if(lista!=NULL)
    {
        if(lugarLibre!= FALSE)
        {
            if(name!=NULL && lastName!=NULL  && salary >0 )
            {
                strcpy(auxEmpleado.name, name);
                strcpy(auxEmpleado.lastName, lastName);
                auxEmpleado.salary=salary;
                auxEmpleado.sector=sector;
                auxEmpleado.id=generarNextId();
                auxEmpleado.isEmpty = 0;
                lista[lugarLibre]=auxEmpleado;

                retorno=TRUE;
            }
            else
            {
                printf("Alguno de los datos esta mal esta mal");
            }
        }
        else
        {
            printf("No hay lugar libre\n");
            system("pause");
        }

    }
    system("cls");
    return retorno;

}


int findEmployeeById(eEmployee* lista, int len, int id)
{
    int retorno=FALSE;
    int i;

    if(lista!=NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == 0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}


int removeEmployee(eEmployee* lista, int len, int id)
{
    int index;
    int i;
    int retorno=FALSE;

    if(lista!=NULL)
    {
    	printEmployees(lista,len);
        id=getValidInt("Ingrese el id a eliminar:\n","Error,ingrese un numero valido\n", 1, 1000000);
        index=findEmployeeById(lista, len, id);

        if(lista[index].isEmpty==0)
        {
            printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t     SECTOR\n");
            mostrarUnEmpleado(lista, index);
        }
        for( i=0; i<len; i++)
        {
            if(index >= 0)
            {
                printf("\n El usuario fue eliminado.\n");
                lista[index].isEmpty = 1;
                break;
            }

            else
            {
                printf("\n No existe ese id.\n");
                break;
            }

            retorno=TRUE;
        }

    }

    return retorno;
}


int modifyEmployee(eEmployee*lista,int len,  int id)
{
    int index;
    int cambiar;
    char newName[31];
    char newLastName[31];
    float newSalary;
    int newSector;
    int retorno=FALSE;
    char continuar='n';

    printEmployees(lista,len);
    id=getValidInt("Ingrese el id a modificar:\n","Error,ingrese un numero valido\n", 1, 1000000);
    index=findEmployeeById(lista, len, id);

    if(lista!=NULL)
    {
        if(index >= 0)
        {
            do
            {
                printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
                mostrarUnEmpleado(lista, index);
                printf("\n1. NOMBRE\n");
                printf("2. APELLIDO\n");
                printf("3. SALARIO\n");
                printf("4. SECTOR\n");
                cambiar=getValidInt("Ingrese la opcion a modificar:\n","Error,ingrese un numero valido\n", 1, 4);
                                switch(cambiar)
                {
                case 1:
                    getValidString("Ingrese nombre:", "Error, ingrese nuevamente:", newName);
                    strcpy(lista[index].name, newName);
                    break;

                case 2:
                    getValidString("Ingrese apellido:", "Error, ingrese nuevamente:", newLastName);
                    strcpy(lista[index].lastName, newLastName);
                    break;
                case 3:
                    newSalary=getValidFloat("Ingrese salario:\n","Error, no valido\n", 0, 1000000);
                    lista[index].salary=newSalary;
                    break;
                case 4:
                    newSector=getValidInt("Ingrese sector del 1 al 5:\n","Error, no valido\n", 1, 5);
                    lista[index].sector=newSector;
                    break;
                default :
                    printf("Dato no valido\n");
                }

                printf("Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&continuar);
                system("pause");
                system("cls");
            }while(continuar=='s' || continuar=='S');
        }
        else if(index < 0)
        {
            printf("No existe ese Id. \n");
        }
        retorno=TRUE;
    }

    return retorno;
}

int promedioSalary(eEmployee* lista, int len)
{
    float suma=0;
    float promedio;
    int i;
    int retorno=FALSE;
    int contadorEmpleados=0;
    int contadorSuperanElpromedio=0;

    if(lista!=NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                suma = suma + lista[i].salary;
                contadorEmpleados ++;
                promedio= suma / contadorEmpleados;
            }
        }


        for( i=0; i<len ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].salary> promedio)
                {
                    contadorSuperanElpromedio ++;
                }
            }

        }
        printf("La suma es %.2f --- El promedio es %.2f --- los que superan el salario promedio son %d\n", suma, promedio, contadorSuperanElpromedio);
        retorno=TRUE;
    }

    return retorno;
}


int sortEmployees(eEmployee* lista, int len)
{
    int retorno=FALSE;
    eEmployee auxiliarEmployees;
    int i, j ;
    int elegir;
    printEmployees(lista, len);

    if(lista!= NULL)
    {

        printf("\n1.Ordenar alfabeticamente ascendente");
              printf("\n2.Total y promedio de los salarios, y cuantos empleados superan el salario promedio. ");
        printf("\nIngrese la opcion :\n");
        elegir=getValidInt("Ingrese sector del 1 al 5:\n","Error, no valido\n", 1, 2);


        switch(elegir)
        {
        case 1:
            for( i =0 ; i<len -1 ; i ++)
            {
                for(j= i+1 ; j<len; j++)
                {

                    if(strcmp(lista[j].lastName,lista[i].lastName)<0)
                    {
                        auxiliarEmployees = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarEmployees;
                    }
                    else if(strcmp(lista[j].lastName,lista[i].lastName)==0 && lista[j].sector<lista[i].sector)
                    {
                        auxiliarEmployees = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarEmployees;
                    }
                }
            }
            printEmployees(lista,len);
            printf("\nOpcion completada con exito.\n");
            break;

        case 2:
            promedioSalary(lista, len);
            printf("\nOpcion completada con exito.\n");
            break;
        default:
            printf("\nIngresaste mal los datos\n");
            break;
        }
        retorno=TRUE;
    }
    return retorno;
}




