/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc Problema2.c && ./a.out
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
    //se define un vector con 5 elementos enteros
    int a[5];
    //se le pide al usuario que ingrese el vector mediante un for
    for (int i = 0; i < 5; i++)
    {
        printf("ingrese un elemento del vector a ordenar \n");
        scanf("%d",&a[i]);
    }
    //implementamos el algoritmo de ordenamiento de inserción
    int i,j,aux;
    for (i = 1; i < 5; i++)
    {
        //
        j = i;
        //se almacena en una variable auxiliar el elemento a comparar
        aux=a[i];
        //se crea un ciclo que se repita hasta que se halle un valor menor al elemento auxiliar
        while (j > 0 && aux < a[j-1]){
            //se intercambian valores vecinos
            a[j]=a[j-1];
            j--;
        }
        //se recupera el valor auxiliar
        a[j]=aux;
    }
    printf("El vector ordenado queda como: \n");
    //se usa un ciclo for de 0 a 4 para imprimir el vector
    for (int i = 0; i < 5; i++)
    {
        printf("%d \n",a[i]);
    }

    
}