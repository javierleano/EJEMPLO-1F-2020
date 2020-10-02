#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdalign.h>
#include "array_employee.h"

int initEmployees(Employee* list, int len)
{
    int res=0;
    if(list == NULL || len > LEN)
    {
        res=-1;
    }
    else
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
    }
    return res;
}
int addEmployee(Employee* list, int len, int id, char name[],char
                lastName[],float salary,int sector)
{
    int res=-1;
    if(list == NULL || len > LEN)
    {
        res=-1;
    }

    else
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                list[i].id=id;
                strcpy(list[i].name,name);
                strcpy(list[i].lastName,lastName);
                list[i].salary=salary;
                list[i].sector=sector;
                list[i].isEmpty = 0;
                res = 0;
                break;
            }
        }
        if(res==-1)
        {
            printf("No se pueden ingresar mas Empleados\n");
        }
    }
    return res;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int res=-1;
    if(list == NULL || len > LEN)
    {
        res=-1;
    }
    else
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty == 0)
            {
                res =i;
                break;
            }
        }
    }
    return res;
}
int removeEmployee(Employee* list, int len, int id)
{
    int res=-1;
    if(list == NULL || len > LEN)
    {
        res =-1;
    }
    else
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty == 0 )
            {
                list[i].isEmpty=1;
                res = 0;
                break;
            }
        }
    }
    return res;
}
int sortEmployees(Employee* list, int len, int order)
{
    Employee aux_elem;
    for (int i = 0; i < len- 1; i++)
    {
        for (int j = 1; j < len; j++)
        {
            if (cmpEmployees(list[j],list[j-1],order)>0) //es verdadero si array de j-1 es mayor que array j
            {
                // si el elemento anterior es mayor, hacemos el cambio
                memcpy(&aux_elem,&list[j],sizeof(Employee));
                memcpy (&list[j],&list[j-1],sizeof(Employee));
                memcpy (&list[j-1],&aux_elem,sizeof(Employee));
            }
        }
    }
    return 0;
}
int cmpEmployees (Employee a, Employee b, int order)
{
    int cmp;
    if(a.isEmpty ==1)
    {
        if(order ==1)
        {

            cmp =1;
        }
        cmp = -1;
    }

    else
    {
        // Devuelve Mayor que Cero si B es Mayor
        int cmp = strcmp(b.lastName, a.lastName);

        if(cmp == 0)
        {
            if(b.sector > a.sector)
            {
                cmp = 1;
            }
            else
            {
                cmp = -1;
            }
        }
        if (order == 1)
        {
            cmp*=-1;
        }

    }
    return cmp;
}

void printEmployee(Employee* e)
{
    if(e->isEmpty!=1)
    {
        printf("%8d %15s %15s   %8.2f\t %7d\n",e->id,e->lastName,e->name,e->salary,e->sector);
    }
}

int printEmployees(Employee* list, int length)
{
    printf("      id        Apellido          nombre   salario\t   sector\n");
    for (int i = 0; i < length; i++)
    {
        printEmployee(&list[i]);
    }
    return 0;
}

int mostrarSalario(Employee* list, int len)
{
    int res;
    float acumSalario=0;
    float promedio;
    int   contadorSalario=0;

    for (int i = 0; i < len; i++)
    {
        if(list[i].isEmpty!=1)
        {
            acumSalario+=list[i].salary;
            contadorSalario+=1;
        }
    }
    if(contadorSalario == 0)
    {
        printf("No hay empleados Cargados\n");
        res= 1;
    }
    else
    {
        promedio= acumSalario / contadorSalario;
        contadorSalario=0;

        for (int i = 0; i < len; i++)
        {
            if(list[i].isEmpty!=1 && list[i].salary > promedio)
            {
                contadorSalario+=1;
            }
        }

        printf("El salario Total es : %.2f\n", acumSalario);
        printf("El salario Promedio es : %.2f\n", promedio);
        printf("La cantidad de empleado que Supera el Sueldo Promedio: %d\n", contadorSalario);
        res =0;
    }
    return res;

}

int numeroDecimalValido(char numeroString[])
{
    int res =0;
    int length = strlen (numeroString);
    for (int i=0; i<length; i++)
    {
        if (numeroString[i] == ',')
        {
            numeroString[i] = '.';
            continue;
        }
        if (numeroString[i] == '.')
        {
            continue;
        }
        if (!isdigit(numeroString[i]))
        {
            res =1;
            break;
        }

    }
    return res;
}
int numeroEnteroValido(char numeroString[])
{
    int res=0;
    int length = strlen (numeroString);
    for (int i=0; i<length; i++)
    {
        if (!isdigit(numeroString[i]))
        {
            res=1;
            break;
        }
    }
    return res;
}

int validarCaracteres (char numeroString[])
{
    int res=0;
    int length = strlen (numeroString);
    for (int i=0; i<length; i++)
    {
        if (!isalpha(numeroString[i]))
        {
            res =1;
            break;
        }
    }
    return res;
}

void stringValido (char string[], char mensaje[])
{
    while(1==1)
    {
        printf("%s",mensaje);
        scanf("%s", string);
        if(validarCaracteres(string) == 1)
        {
            printf("Por favor ingrese Solo letras\n");
        }
        else
        {
            break;
        }
    }

}

