#include "funciones.h"

/**
 * \brief Recibe dos números y devuelve la suma
 * \param primerNumero es el primer numero
 * \param segundoNumero es el segundo numero
 * \return Retorna el resultado de la suma
 */
float sumar(float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}

/**
 * \brief Recibe dos números y devuelve la resta
 * \param primerNumero es el primer numero
 * \param segundoNumero es el segundo numero
 * \return Retorna el resultado de la resta
 */
float restar(float primerNumero, float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}

/**
 * \brief Recibe dos números y devuelve la multiplicacion
 * \param primerNumero es el primer numero
 * \param segundoNumero es el segundo numero
 * \return Retorna el resultado de la multiplicacion
 */
float multiplicacion(float primerNumero, float segundoNumero)
{
    float producto;
    producto = primerNumero * segundoNumero;
    return producto;
}
/**
 * \brief Recibe dos números y devuelve la division. si el segundo numero es 0 devuelve 0
 * \param primerNumero es el primer numero
 * \param segundoNumero es el segundo numero
 * \return Retorna el resultado de la division
 */
float dividir(float primerNumero, float segundoNumero)
{
    float cociente;
    if (segundoNumero == 0)
    {
        return 0;
    }
    cociente = primerNumero / segundoNumero;
    return cociente;
}
/**
 * \brief Recibe un números y devuelve la factorial
 * \param numero es el primer numero
 * \return Retorna el resultado de la factorial
 */
double factorial(int numero)
{
    double resultado = 1;

    if(numero == 0 || numero == 1)
    {
        return 1;
    }
    else
    {
        for(int i = 1; i <= numero; i++)
        {

            resultado*= i;
        }
        return resultado;
    }
}

/** \brief valida que el numero sean digitos la coma o punto. caso contrario indica que no ingreso un numero
 * \param numeroString[] char: arreglo de caracteres en donde esta guardado el numero a validar
 * \return no devuelve nada (void)
 */
void numeroValido(char numeroString[])
{
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
            printf ("Ingrese un numero\n");
            return;
        }
    }
}

