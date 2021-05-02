/*
Autor: Rodrigo Castillo
Compilador: gcc -o
Compilado: gcc
Fecha: Thu Mar 18 02:21:05 UTC 2021
Librerias: 
Resumen: 
Entrada: 
Salida: 
*/

//Librerias
#include <stdio.h>

void main(void){
    int n=0;
    float med=0, x;
    printf("ingrese una altura \n");
    scanf("%f",&x);
    float max=x, min=x;
    while(x>0){
        n += 1;
        med += x;
        if (x>max){
            max=x;
        }else if(x<min){
            min=x;
        }
        printf("ingrese una altura \n");
        scanf("%f",&x);
    }
    if (n==0){
        printf("No positivos");
    }else{
        float dividir=med/n;
        printf("la media es: %f \n", dividir);
        printf("el máximo es: %f \n", max);
        printf("el mínimo es: %f \n", min);
    }

}