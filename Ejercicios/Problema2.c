/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc
Fecha: Mon Apr 19 23:57:40 UTC 2021
Librerias: 
Resumen: Ordenar un vector de 5 elementos, proporcionados por el usuario
Entrada: 5 números
Salida: vector ordenado
*/

//Librerias
#include <stdio.h>
#include <string.h>
//pasos del pseudocódigo
void main(void){
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        printf("ingrese un elemento del vector a ordenar \n");
        scanf("%d",&a[i]);
    }

    int i,j,aux;
    for (i = 1; i < 5; i++)
    {
        j = i;
        aux=a[i];
        while (j > 0 && aux < a[j-1]){
            a[j]=a[j-1];
            j--;
        }
        a[j]=aux;
    }
    printf("El vector ordenado queda como: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d \n",a[i]);
    }

    
}