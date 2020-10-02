#ifndef ARRAY_EMPLOYEE_H_INCLUDED
#define ARRAY_EMPLOYEE_H_INCLUDED
#define LEN 1000


struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;


/** \brief recibe una lista de empleados y la inicializa con empleados vacios
 *
 * \param list Employee* : es la lista de empleados
 * \param len es el largo de la lista
 * \return 0 todo ok, -1 error
 *
 */

int initEmployees(Employee* list, int len);

/** \brief agrega un nuevo empleado a la lista de empleado
 *
 * \param list Employee* : es la lista de empleados
 * \param len  es el largo de la lista
 * \param id   que se le asignara al empleado
 * \param name nombre que se asignara al empleado
 * \param lastName apellido que se le asignara al empleado
 * \param salary salario que se le asignara al empleado
 * \param sector : es el sector que se le asignara al empleado
 * \return 0 todo ok, -1 error
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char
                lastName[],float salary,int sector);


/** \brief Busca un empleado con el id ingresado
 *
 * \param list Employee* es la lista de empleados
 * \param len largo de la lista
 * \param id  es el id del empleado a buscar
 * \return indice al empleado buscado o -1 error
 *
 */
int findEmployeeById(Employee* list, int len,int id);


/** \brief Elimina un empleado con el id ingresado
 *
 * \param list Employee* es la lista de empleados
 * \param len largo de la lista
 * \param id  es el id del empleado a eliminar
 * \return 0 todo ok, -1 error
 *
 */
int removeEmployee(Employee* list, int len, int id);


/** \brief Ordena la lista por apellido y sector
 *
 * \param list Employee* es la lista de empleados
 * \param len largo de la lista
 * \param order : ordena 1 UP, 0 Down
 * \return 0 todo ok, -1 error
 *
 */
int sortEmployees(Employee* list, int len, int order);


/** \brief compara dos empleados por apellido y sector
 *
 * \param  a : empleado 1
 * \param  b : empleado 2
 * \param order : si esta en 1 la comparacion es normal, si esta en 0 invierte la comparacion
 * \return  devuelve mayor que 0 si b es mayor que a si no devuelve menor que 0 para order = 1
 *
 */
int cmpEmployees (Employee a, Employee b, int order);

/** \brief imprime los datos de un empleado
 *
 * \param e Employee* empleados a imprimir
 * \return void
 *
 */
void printEmployee(Employee* e);


/** \brief imprime una lista de empleados
 *
 * \param list Employee* lista de empleados
 * \param length int largo de la lista
 * \return int 0
 *
 */
int printEmployees(Employee* list, int length);

/** \brief muestra la suma del salario de los empleados, el promedio y quien supera el salario promedio
 *
 * \param list Employee* lista de empleados
 * \param len int largo de la lista
 * \return 0 todo ok, 1 cuando no se cargaron empleados
 *
 */
int mostrarSalario(Employee* list, int len);


/** \brief verifica si la cadena contiene digitos "." | ","
 *
 * \param numeroString[] char cadena a verificar
 * \return 0 todo ok, 1 contiene caracteres invalido
 *
 */
int numeroDecimalValido(char numeroString[]);


/** \brief verifica si la cadena contiene solo digitos
 *
 * \param numeroString[] char cadena a verificar
 * \return 0 todo ok, 1 contiene caracteres invalido
 *
 */
int numeroEnteroValido(char numeroString[]);


/** \brief verifica si la cadena contiene letras
 *
 * \param numeroString[] char cadena a verificar
 * \return 0 todo ok, 1 contiene caracteres invalido
 *
 */
int validarCaracteres(char numeroString[]);

/** \brief muestra un mensaje y le pide al usuario que ingrese una cadena de letras, lo repite hasta obtener una cadena valida
 *
 * \param  string cadena de retorno
 * \param  mensaje : mensaje a imprimir
 * \return
 *
 */
void stringValido (char string[], char mensaje[]);


#endif // ARRAY_EMPLOYEE_H_INCLUDED
