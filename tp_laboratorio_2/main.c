#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "array_employee.h"
#define  LARGO 10


Employee lista[LARGO];

Employee* e=NULL;

int main()
{

    int res=initEmployees(lista,LARGO);
    char opciones;
    char nombre[51];
    char apellido[51];
    float salary;
    int sector;
    int id=0;
    int idModif;
    char validacion[51];
    int flagPrimerEmpleado=0;


    do
    {
        printf("-----------------------------------------\n");
        printf("|   Administracion Empleados             |\n");
        printf("-----------------------------------------\n");
        printf("\n1- ALTAS\n");
        printf("2- MODIFICAR\n");
        printf("3- BAJAS\n");
        printf("4- INFORMAR\n");
        printf("5- SALIR\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%c",&opciones);
        fflush(stdin);


        switch(opciones)
        {
        case '1':
            stringValido(nombre,"Ingrese el Nombre:");
            nombre[0]=toupper(nombre[0]);
            stringValido(apellido,"Ingrese el Apellido:");
            apellido[0]=toupper(apellido[0]);

            while(1==1)
            {
                printf("Ingrese el Salario:");
                scanf("%s", validacion);
                if(numeroDecimalValido(validacion) == 1)
                {
                    printf("Por favor ingrese el salario en numeros\n");
                }
                else
                {
                    break;
                }
            }
            salary = atof(validacion);
            while(1==1)
            {
                printf("Ingrese el Sector:");
                scanf("%s", validacion);
                if(numeroEnteroValido(validacion)==1)
                {
                    printf("Por favor ingrese el sector en numeros enteros\n");
                }
                else
                {
                    break;
                }
            }
            sector=atoi(validacion);

            res=addEmployee(lista,LARGO,id,nombre,apellido,salary,sector);
            if(res == 0)
            {
                flagPrimerEmpleado =1;
                printf("Se ha cargado con exito el Empleado con Id: %d\n", id);
                id++;
            }
            break;


        case '2':
            if(flagPrimerEmpleado == 0)
            {
                printf("Primero Debe ingresar un Empleado\n");
                break;
            }
            printf("Ingrese el id:");
            fflush(stdin);
            scanf("%d",&idModif);
            fflush(stdin);
            res=findEmployeeById(lista,LARGO,idModif);
            printf("indice a modificar %d,idmodif %d\n",res,idModif);
            if(res < 0)
            {
                printf("No existe empleado con ese Id\n");
            }
            else
            {

                printf("    A) Nombre (%s)\n",lista[res].name);
                printf("    B) Apellido(%s)\n",lista[res].lastName);
                printf("    C) Salario(%.2f)\n",lista[res].salary);
                printf("    D) Sector(%d)\n",lista[res].sector);
                printf("Ingrese La opcion a modificar: ");
                scanf("%c",&opciones);


                int modif=0;

                switch(opciones)
                {
                case 'A':
                case 'a':
                    stringValido(nombre,"\nIngrese el Nombre:");
                    nombre[0]=toupper(nombre[0]);
                    strcpy(lista[res].name,nombre);
                    modif=1;
                    break;
                case 'B':
                case 'b':
                    stringValido(apellido,"\nIngrese el Apellido:");
                    apellido[0]=toupper(apellido[0]);
                    strcpy(lista[res].lastName,apellido);
                    modif=1;
                    break;

                case 'C':
                case 'c':
                    printf("\nIngrese el Salario:");
                    scanf("%f",&salary);
                    lista[res].salary=salary;
                    modif=1;
                    break;

                case 'D':
                case 'd':
                    printf("\nIngrese el Sector:");
                    scanf("%d",&sector);
                    lista[res].sector=sector;
                    modif=1;
                    break;
                default :
                    printf("Opcion Invalida\n");
                    break;
                }
                if(modif == 1)
                {
                    printf("Se muestran Los datos modificados");
                    printEmployee(&lista[res]);
                }
            }

            break;

        case '3':
            if(flagPrimerEmpleado == 0)
            {
                printf("Primero Debe ingresar un Empleado\n");
                break;
            }
            printf("Ingrese el id:");
            fflush(stdin);
            scanf("%d",&idModif);
            fflush(stdin);
            res=findEmployeeById(lista,LARGO,idModif);
            if(res < 0)
            {
                printf("No existe empleado con ese Id\n");
            }
            else
            {
                printf("Esta seguro que desea eliminar el Empleado de Id %d(S o s Para confirmar): ",idModif);
                fflush(stdin);
                scanf("%c",&opciones);
                fflush(stdin);
                if(opciones == 'S' || opciones =='s')
                {
                    res=removeEmployee(lista,LARGO,idModif);
                    if(res==0)
                    {
                        printf("Se ha borrado con Exito el empleado con ID : %d\n", idModif);
                    }
                    else
                    {
                        printf("El empleado No se pudo borrar\n");
                    }
                }
            }
            break;
        case '4':
            if(flagPrimerEmpleado == 0)
            {
                printf("Primero Debe ingresar un Empleado\n");
                break;
            }
            res=sortEmployees(lista,LARGO,0);
            res=printEmployees(lista,LARGO);
            res=mostrarSalario(lista,LARGO);
            break;
        case '5' :
            return 0;
            break;

        default:
            printf("Ingresar una opcion valida");
            break;
        }
    }
    while(1 == 1);

    return 0;
}

