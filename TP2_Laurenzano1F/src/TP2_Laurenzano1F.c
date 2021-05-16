/*
 ============================================================================
 Name        : TP2_Laurenzano1F.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#include "ArrayEmployee.h"
#include "validaciones.h"

int main()

{
	setbuf(stdout,NULL);
    char seguir= 's';
    eEmployee empleados[MAX];
    initEmployees( empleados, MAX );

    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int lugarLibre;
    int flag=0;

    do
    {
        switch(menuDeOpciones())
        {
        case 1:
            flag=1;
            lugarLibre=buscarLugarLibre(empleados, MAX);
            if(lugarLibre!= -1)
            {
                printf("Lugar libre = %d\n",lugarLibre);
                getValidString("Ingrese el nombre del empleado:", "Error, ingrese nuevamente:", name);
                getValidString("Ingrese el apellido del empleado:", "Error, ingrese nuevamente:", lastName);
                salary=getValidFloat("Ingrese el salario del empleado:\n","Error, no valido\n", 0, 1000000);
                sector=getValidInt("Ingrese el sector:\n","Error, no valido\n", 1,5);
                addEmployee(empleados, MAX, lugarLibre,  name, lastName, salary, sector);

            }
            else
            {
                printf("No hay lugar libre.\n");
                system("pause");
                system("cls");
            }

            break;
        case 2:
            if(flag==0)
            {

                printf("No hay datos para ser mostrados\n");
            }
            else
            {
                modifyEmployee(empleados,MAX, lugarLibre);
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(flag == 0)
            {
                printf("No hay datos que mostrar\n");
            }
            else
            {
               removeEmployee( empleados, MAX, empleados[MAX].id);
            }
            system("pause");
            system("cls");
            break;
        case 4:
            if(flag == 0)
            {
                printf("No hay datos que mostrar\n");
            }
            else
            {
                sortEmployees(empleados, MAX);
            }
            system("pause");
            system("cls");
            break;
        case 5:
            seguir='n';
            break;
        case 6:
                flag=1;
                addEmployee(empleados, MAX, 1, "Juan", "Perez", 40000, 1);
                addEmployee(empleados, MAX, 2, "Juan", "Garcia", 15000, 2);
                addEmployee(empleados, MAX, 3, "Gustavo", "Laurenzano", 32000, 2);
                addEmployee(empleados, MAX, 4, "Carlos", "Perez", 44000, 3);
                addEmployee(empleados, MAX, 5, "Oscar", "Garcia", 70000, 1);
                addEmployee(empleados, MAX, 6, "Marcela", "Fernandez", 88000, 4);
                addEmployee(empleados, MAX, 7, "Paula", "Perotti", 18000, 4);
                addEmployee(empleados, MAX, 8, "Raul", "Fernandez", 13000, 5);
                addEmployee(empleados, MAX, 9, "Luis", "Fernandez", 19000, 3);
                printf("Hardcodeo realizado con exito!\n");
                system("pause");
                system("cls");
                break;

        default :
            printf("Ingresaste mal el dato\n");
            system("pause");
            system("cls");
        }
    }while(seguir == 's');

    return 0;
}










