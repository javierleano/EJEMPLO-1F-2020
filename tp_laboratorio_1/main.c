/*Javier Leaño 1ro F dni 95871422*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#include <conio.h>

int main()
{

    float primerNumero;
    float segundoNumero;
    float suma;
    float resta;
    float multiplicar;
    float division;
    double factorial1;
    double factorial2;
    primerNumero = 0;
    segundoNumero = 0;
    char opciones;
    char primerNumeroString[10];
    char segundoNumeroString[10];


    do
    {
        printf( "\n********* MENU CALCULADORA ************" );
        printf("\n1- Ingresar 1er operando (A = %.2f)\n",primerNumero);
        printf("2- Ingresar 2do operando (B = %.2f)\n",segundoNumero);
        printf("3- Calcular todas las operaciones\n");
        printf("    A) Suma\n");
        printf("    B) Resta\n");
        printf("    C) Division\n");
        printf("    D) multiplicacion\n");
        printf("    F) factorial");
        printf("\n4. Informar resultados\n");
        printf("    A) El resultado de A+B es:\n");
        printf("    B) El resultado de A-B es: \n");
        printf("    C) El resultado de A/B es:\n");
        printf("    D) El resultado de A*B es: \n");
        printf("    F) El factorial de A es:  y El factorial de B es:");
        printf("\n5. Salir\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%c",&opciones);
        fflush(stdin);



        switch(opciones)
        {
        case '1':
            printf("\nIngrese el 1er operando:");
            scanf("%s", primerNumeroString);
            numeroValido(primerNumeroString);
            primerNumero = atof(primerNumeroString);
            break;
        case '2':
            printf("\nIngrese el 2do operando: ");
            scanf("%s", segundoNumeroString);
            numeroValido(segundoNumeroString);
            segundoNumero = atof(segundoNumeroString);
            break;
        case '3':
            suma = sumar(primerNumero,segundoNumero);
            resta = restar(primerNumero,segundoNumero);
            multiplicar = multiplicacion(primerNumero,segundoNumero);
            division = dividir(primerNumero,segundoNumero);
            factorial1 = factorial((int)primerNumero);
            factorial2 = factorial((int)segundoNumero);
            break;
        case '4':
            printf("\nEl resultado de A+B es: %.2f\n", suma);
            printf("El resultado de A-B es: %.2f\n", resta);
            if(segundoNumero == 0)
            {
                printf("No es posible dividir por cero\n");
            }
            else
            {
                printf("El resultado de A/B es: %.2f\n", division);
            }
            printf("El resultado de A*B es: %.2f\n", multiplicar);

            if((primerNumero-(int)primerNumero)> 0)
            {
                printf("el factorial de A no se puede calcular por ser numero decimal");
            }
            else
            {
                printf("El factorial de A es: %.0lf", factorial1);
            }
            if((segundoNumero-(int)segundoNumero)> 0)
            {
                printf(" y el factorial de B no se puede calcular por ser numero decimal");
            }
            else
            {
                printf(" y el factorial de B es: %.0lf", factorial2);
            }
            break;
        case '5' :
            return 0;
            break;
        default:
            printf("Ingresar una opcion valida");
        }
    }
    while(1 == 1);
}



