/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc -o
Fecha: Thu Mar 18 04:48:12 UTC 2021
Librerias: ninguna
Resumen: Encontrar la raíz cuadrada entera de un numero
Entrada: numero
Salida: raiz cuadrada del número
*/

//Librerias
#include <stdio.h>

void main(void){
    float N;
    printf("Escriba el número \n");
    scanf("%f",&N);
    int i=1;
    while(i*i<=N){
        i += 1;
    }
    printf("la raíz entera menor es: %d \n", i-1);
}
