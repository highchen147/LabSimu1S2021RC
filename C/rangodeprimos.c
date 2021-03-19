/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc -o
Fecha: Fri Mar 19 04:30:12 UTC 2021
Librerias: 
Resumen: el programa lee dos números enteros y muestra los números primos en ese rango
Entrada: dos numeros enteros
Salida: numeros primos en ese rango
*/

//Librerias
#include <stdio.h>
//pasos del pseudocódigo
void main(void){
    int n1,n2,j,primo;
    printf("Escriba el número inicial del rango \n");
    scanf("%d", &n1);
    printf("Escriba el número final del rango \n");
    scanf("%d", &n2);
    int i=n1;
    while (i<=n2)
    {
        //inicio de es_primo
        j=2;
        primo=1;
        while (j<i && primo==1)
        {
            if ((i%j)==0)
            {
                primo=0;
            }
            j += 1;
        }
        //fin de es_primo
        if (primo == 1)
        {
            printf("%d, ", i);
        }
        i += 1;
    }
}