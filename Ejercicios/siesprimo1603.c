/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc -o
Fecha: Fri Mar 19 03:53:51 UTC 2021
Librerias: 
Resumen: el programa calcula si un numero es primo o no
Entrada: numero entero
Salida: valor de verdad
*/

//Librerias
#include <stdio.h>
//pasos del pseudocódigo
void main(void){
    int N;
    printf("ingrese un número entero \n");
    scanf("%d",&N);
    int i=2, primo=1;
    while (i<N-1 && primo==1)
    {
        if ((N%i)==0)
        {
            primo=0;
        }
        i += 1;
    }
    if (primo == 0)
    {
        printf("no es primo \n");
    }else{
        printf("es primo \n");
    }
    
}
