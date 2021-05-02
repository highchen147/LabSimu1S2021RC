/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc
Fecha: Wed Apr  7 00:04:18 UTC 2021
Librerias: 
Resumen: Calculadora
Entrada: número del 1 al 4
Salida: números operados
*/

//Librerias
#include <stdio.h>
//funciones

float suma(float a, float b) //función de suma
{
    float c=a+b;
    return c;
}

float resta(float a, float b) //función de resta
{
    float c=a-b;
    return c;
}

float multi(float a, float b) //función de multiplicación
{
    float c=a*b;
    return c;
}

float divi(float a, float b) //función de división
{
    float c=a/b;
    return c;
}
void main(void){ //código principal de la calculadora
    while (1) //este while permite que se use la calculadora las veces que el usuario lo desee
    {
        float a,b; //declaración de variables que sirven para almacenar los operandos
        int modo; //variable que almacena el modo en el que se usa la calculadora 
        printf("Ingrese 1 para suma, 2 para resta, 3 para multiplicación, 4 para división. Ingrese otro número para salir. \n"); //ingreso del modo
        scanf("%d",&modo);
        if (modo != 1 && modo !=2 && modo !=3 && modo != 4) //este if valida si el usuario desea salir de la calculadora
        {
            break;
        }
        printf("Ingrese los dos números a operar separados de un espacio o con enter \n"); //ingreso de los operandos
        scanf("%f %f",&a,&b);
        switch (modo) //este switch permite usar el modo deseado por el usuario
        {
        case 1:
            printf("%f + %f = %f \n\n",a,b,suma(a,b));
            break;
        case 2:
            printf("%f - %f = %f \n\n",a,b,resta(a,b));
            break;
        case 3:
            printf("%f * %f = %f \n\n",a,b,multi(a,b));
            break;
        case 4:
            printf("%f / %f = %f \n\n",a,b,divi(a,b));
        default:
            break;
        }
    
    }
    
    
}
