/*
 * ArrayEmployee.h
 *
 *  Created on: 15 may. 2021
 *      Author: Gustavo
 */

#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_
#define TRUE 0
#define FALSE -1


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en 1 en todas las posiciones del array.
 * \param lista* eEmployee Puntero del array de empleados
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */
int initEmployees(eEmployee* lista, int len);
/** \brief Indica que posicion del array esta vacia
 * \param lista* eEmployee Puntero del array de empleados
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna el lugar que se encuentra libre
 */
int buscarLugarLibre(eEmployee* lista, int len);


 /** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
*posición libre.
 * \param lista* eEmployee Puntero del array de empleados
 * \param len int tamaño del array
 * \param id int Id generado
 * \param name[] char Nombre generado
 * \param lastName[] char Apellido generado
 * \param salary float Salario generado
 * \param sector int  Sector generado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 **/

int addEmployee(eEmployee* lista, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Muestra el menu de opciones
 * \return int Return, retorna la opcion que se elige
 */
int menuDeOpciones();
/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int tamaño del array
 * \param id int Id a ser registrado
 * \return Return Devuelva la posicion que coincide con el Id ingresado, de lo contrario, devuelve -1 como error
 *
 */
int findEmployeeById(eEmployee* lista, int len , int id);



/** \brief muestra un empleado
  * \param lista eEmployee* Puntero del array de empleados
 * \param len int Largo del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 *
 */
int mostrarUnEmpleado(eEmployee* lista, int indice);

/** \brief Da de baja al empleado que se encuentra por Id
 *
 * \param lista eEmployee* Puntero del array de empleados
 * \param len int largo del array
 * \param id int Id a ser registrado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 *
 */
int removeEmployee(eEmployee* lista, int len, int id);

/** \brief modifica al empleado que se encuentra por Id
 *
 * \param lista eEmployee* Puntero del array de empleados
 * \param len int largo del array
 * \param id int Id a ser registrado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 *
 */
 int modifyEmployee(eEmployee*lista,int len,  int id);

/** \brief Muestra una lista de empleados
 * \param eEmployee* lista Puntero del array de empleados
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */
int printEmployees(eEmployee* lista, int len);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente ,
 * y muestra promedio y suma de los salarios, y empleados que superan el salario promedio
 * \param lista eEmployee* Puntero del array de empleados
 * \param len int Largo del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 *
 */
 int sortEmployees(eEmployee* lista, int len);

/** \brief Calcula el promedio de los salarios, la suma de los salarios y los empleados que superan el salario promedio
 *
 * \param lista* eEmployee Puntero de array de empleados
 * \param len int Largo del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 *
 */
int promedioSalary(eEmployee* lista, int len);


#endif /* ARRAYEMPLOYEE_H_ */
